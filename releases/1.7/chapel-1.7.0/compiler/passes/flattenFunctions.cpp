/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#include "alist.h"
#include "astutil.h"
#include "expr.h"
#include "passes.h"
#include "stmt.h"


//
// returns true if the symbol is defined in an outer function to fn
// third argument not used at call site
//
static bool
isOuterVar(Symbol* sym, FnSymbol* fn, Symbol* parent = NULL) {
  if (!parent)
    parent = fn->defPoint->parentSymbol;
  if (!isFnSymbol(parent))
    return false;
  else if (sym->defPoint->parentSymbol == parent)
    return true;
  else
    return isOuterVar(sym, fn, parent->defPoint->parentSymbol);
}


//
// finds outer vars directly used in a function
//
static void
findOuterVars(FnSymbol* fn, SymbolMap* uses) {
  Vec<BaseAST*> asts;
  collect_asts(fn, asts);
  forv_Vec(BaseAST, ast, asts) {
    if (SymExpr* symExpr = toSymExpr(ast)) {
      Symbol* sym = symExpr->var;
      if (toVarSymbol(sym) || toArgSymbol(sym))
        if (isOuterVar(sym, fn))
          uses->put(sym,gNil);
    }
  }
}


// Is this type OK to pass by value (e.g. it's reasonably-sized)?
static bool
passableByVal(Type* type) {
  if (is_bool_type(type)    ||
      is_int_type(type)     ||
      is_uint_type(type)    ||
      is_real_type(type)    ||
      is_imag_type(type)    ||
      is_complex_type(type) ||
      is_enum_type(type)    ||
      isClass(type)         ||
      type == dtTaskID      ||
      // For now, allow ranges as a special case, not records in general.
      type->symbol->hasFlag(FLAG_RANGE) ||
      0)
    return true;

  // TODO: allow reasonably-sized records.
  // TODO: allow reasonably-sized tuples - heterogeneous and homogeneous.

  return false;
}


// Should we pass 'sym' by reference?
static bool
passByRef(Symbol* sym) {

  if (sym->hasFlag(FLAG_DISTRIBUTION) ||
      sym->hasFlag(FLAG_DOMAIN) ||
      sym->hasFlag(FLAG_ARRAY)
  ) {
    // These values *are* constant. E.g the symbol with FLAG_ARRAY
    // stores a pointer to the corresponding array descriptor.  Since
    // each Chapel variable corresponds to a single Chapel array
    // throughout the variable's lifetime, the descriptor object stays
    // the same, and so does a pointer to it. The contents of that
    // object *can* change, however.
    return false;
  }

  Type* type = sym->type;

  // These simply document the current state.
  INT_ASSERT(type->symbol->hasFlag(FLAG_REF) == (type->refType == NULL));
  // Coforall vars are constant, but are not marked so.
  // todo - mark them with FLAG_CONST and remove this assert,
  //        as well as the special case for FLAG_COFORALL_INDEX_VAR.
  INT_ASSERT(!sym->hasFlag(FLAG_COFORALL_INDEX_VAR) ||
             !sym->hasFlag(FLAG_CONST));

  if (sym->hasFlag(FLAG_CONST) ||
      sym->hasFlag(FLAG_COFORALL_INDEX_VAR)  // These are constant, too.
  ) {
    if (passableByVal(type)) {
       return false;
    }
  }

  // If the above did not fire, pass it by ref if there is a refType.
  //
  // Here is why. We used to create the refType only if we needed it
  // for passing by ref.  It may be that we now add ref types by default
  // for various primitive types (and maybe other stuff), so this check
  // below might be too conservative.  But, it was (and still is) a way to
  // avoid doing more analysis (i.e., distinguishing between defs and uses).
  // Some of unnecessary by-ref passing never happens because of the above
  // checks for const-ness. Some others are reverted to by-value passing
  // in the remoteValueForwarding pass.
  //
  if (type->refType) {
    return true;
  } else {
    return false;
  }
}


static void
addVarsToFormals(FnSymbol* fn, SymbolMap* vars) {
  form_Map(SymbolMapElem, e, *vars) {
    if (Symbol* sym = e->key) {
      Type* type = sym->type;
      if (passByRef(sym))
        /* NOTE: This is still conservative.  This avoids passing
           coforall index vars by reference for non-var iterators.
           David came up with an example with nested functions and no
           iterators that would unnecessarily pass coforall index vars
           by reference.  With further analysis, we could figure out
           whether this variable is actually going to be returned as
           an LHS expr. */
        type = type->refType;
      SET_LINENO(sym);
      ArgSymbol* arg = new ArgSymbol(INTENT_BLANK, sym->name, type);
      if (sym->hasFlag(FLAG_ARG_THIS))
        arg->addFlag(FLAG_ARG_THIS);
      fn->insertFormalAtTail(new DefExpr(arg));
      vars->put(sym, arg);
    }
  }
}

static void
replaceVarUsesWithFormals(FnSymbol* fn, SymbolMap* vars) {
  Vec<BaseAST*> asts;
  collect_asts(fn->body, asts);
  form_Map(SymbolMapElem, e, *vars) {
    if (Symbol* sym = e->key) {
      ArgSymbol* arg = toArgSymbol(e->value);
      Type* type = arg->type;
      forv_Vec(BaseAST, ast, asts) {
        if (SymExpr* se = toSymExpr(ast)) {
          if (se->var == sym) {
            if (type == sym->type) {
              se->var = arg;
            } else {
              CallExpr* call = toCallExpr(se->parentExpr);
              INT_ASSERT(call);
              FnSymbol* fn = call->isResolved();
              if ((call->isPrimitive(PRIM_MOVE) && call->get(1) == se) ||
                  (call->isPrimitive(PRIM_SET_MEMBER) && call->get(1) == se) ||
                  (call->isPrimitive(PRIM_GET_MEMBER)) ||
                  (call->isPrimitive(PRIM_GET_MEMBER_VALUE)) ||
                  (call->isPrimitive(PRIM_WIDE_GET_LOCALE)) ||
                  (call->isPrimitive(PRIM_WIDE_GET_NODE)) ||
                  (call->isPrimitive(PRIM_WIDE_GET_SUBLOC)) ||
                  (fn && arg->type == actual_to_formal(se)->type)) {
                se->var = arg; // do not dereference argument in these cases
              } else if (call->isPrimitive(PRIM_ADDR_OF)) {
                SET_LINENO(se);
                call->replace(new SymExpr(arg));
              } else {
                SET_LINENO(se);
                VarSymbol* tmp = newTemp(sym->type);
                se->getStmtExpr()->insertBefore(new DefExpr(tmp));
                se->getStmtExpr()->insertBefore(new CallExpr(PRIM_MOVE, tmp, new CallExpr(PRIM_DEREF, arg)));
                se->var = tmp;
              }
            }
          }
        }
      }
    }
  }
}


static void
addVarsToActuals(CallExpr* call, SymbolMap* vars, bool outerCall) {
  form_Map(SymbolMapElem, e, *vars) {
    if (Symbol* sym = e->key) {
      SET_LINENO(sym);
      if (!outerCall && passByRef(sym)) {
        /* NOTE: See note above in addVarsToFormals() */
        VarSymbol* tmp = newTemp(sym->type->refType);
        call->getStmtExpr()->insertBefore(new DefExpr(tmp));
        call->getStmtExpr()->insertBefore(new CallExpr(PRIM_MOVE, tmp, new CallExpr(PRIM_ADDR_OF, sym)));
        call->insertAtTail(tmp);
      } else {
        call->insertAtTail(sym);
      }
    }
  }
}


void
flattenNestedFunctions(Vec<FnSymbol*>& nestedFunctions) {
  compute_call_sites();

  Vec<FnSymbol*> nestedFunctionSet;
  forv_Vec(FnSymbol, fn, nestedFunctions)
    nestedFunctionSet.set_add(fn);

  Map<FnSymbol*,SymbolMap*> args_map;
  forv_Vec(FnSymbol, fn, nestedFunctions) {
    SymbolMap* uses = new SymbolMap();
    findOuterVars(fn, uses);
    args_map.put(fn, uses);
  }

  // iterate to get outer vars in a function based on outer vars in
  // functions it calls
  bool change;
  do {
    change = false;
    forv_Vec(FnSymbol, fn, nestedFunctions) {
      Vec<BaseAST*> asts;
      collect_top_asts(fn, asts);
      SymbolMap* uses = args_map.get(fn);
      forv_Vec(BaseAST, ast, asts) {
        if (CallExpr* call = toCallExpr(ast)) {
          if (call->isResolved()) {
            if (FnSymbol* fcall = call->findFnSymbol()) {
              SymbolMap* call_uses = args_map.get(fcall);
              if (call_uses) {
                form_Map(SymbolMapElem, e, *call_uses) {
                  if (isOuterVar(e->key, fn) && !uses->get(e->key)) {
                    uses->put(e->key, gNil);
                    change = true;
                  }
                }
              }
            }
          }
        }
      }
    }
  } while (change);

  // update all call sites of nested functions this must be done
  // before updating the function so that the outer var actuals can be
  // updated with the outer var functions when the formals are updated
  // (in nested functions that call one another)
  forv_Vec(FnSymbol, fn, nestedFunctions) {
    SymbolMap* uses = args_map.get(fn);
    forv_Vec(CallExpr, call, *fn->calledBy) {

      //
      // call not in a nested function; handle the toFollower/toLeader cases
      //
      bool outerCall = false;
      if (FnSymbol* parent = toFnSymbol(call->parentSymbol)) {
        if (!nestedFunctionSet.set_in(parent)) {
          form_Map(SymbolMapElem, use, *uses) {
            if (use->key->defPoint->parentSymbol != parent &&
                !isOuterVar(use->key, parent))
              outerCall = true;
          }
          if (outerCall) {
            nestedFunctionSet.set_add(parent);
            nestedFunctions.add(parent);
            SymbolMap* usesCopy = new SymbolMap();
            form_Map(SymbolMapElem, use, *uses) {
              usesCopy->put(use->key, gNil);
            }
            args_map.put(parent, usesCopy);
          }
        }
      }

      addVarsToActuals(call, uses, outerCall);
    }
  }

  // move nested functions to module level
  forv_Vec(FnSymbol, fn, nestedFunctions) {
    if (isFnSymbol(fn->defPoint->parentSymbol)) {
      ModuleSymbol* mod = fn->getModule();
      Expr* def = fn->defPoint;
      def->remove();
      mod->block->insertAtTail(def);
    }
  }

  // add extra formals to nested functions
  forv_Vec(FnSymbol, fn, nestedFunctions)
    addVarsToFormals(fn, args_map.get(fn));

  // replace outer variable uses with added formals
  forv_Vec(FnSymbol, fn, nestedFunctions)
    replaceVarUsesWithFormals(fn, args_map.get(fn));

  //
  // remove types from functions
  //
  forv_Vec(TypeSymbol, ts, gTypeSymbols) {
    if (FnSymbol* fn = toFnSymbol(ts->defPoint->parentSymbol))
      fn->defPoint->insertBefore(ts->defPoint->remove());
  }
}


void flattenFunctions(void) {
  Vec<FnSymbol*> nestedFunctions;
  forv_Vec(FnSymbol, fn, gFnSymbols) {
    if (isFnSymbol(fn->defPoint->parentSymbol))
      nestedFunctions.add(fn);
  }

  flattenNestedFunctions(nestedFunctions);
}
