/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>
  
#include <cctype>
#include <cstring>
#include <cstdio>

#include "astutil.h"
#include "driver.h"
#include "expr.h"
#include "files.h"
#include "mysystem.h"
#include "passes.h"
#include "stmt.h"
#include "stringutil.h"
#include "symbol.h"
#include "type.h"

#include "codegen.h"
#include "clangSupport.h"

#include "build.h"
#include "scopeResolve.h"

typedef Type ChapelType;

#ifndef HAVE_LLVM

void readExternC(void) {
  // Do nothing if we don't have LLVM support.
}

void cleanupExternC(void) {
  // Do nothing if we don't have LLVM support.
}

#else

using namespace clang;
using namespace llvm;

#define GLOBAL_PTR_SPACE 100
#define GLOBAL_PTR_SIZE 16
#define GLOBAL_PTR_ABI_ALIGN 8
#define GLOBAL_PTR_PREF_ALIGN 8

// TODO - add functionality to clang so that we don't
// have to have what are basically copies of
// ModuleBuilder.cpp 
// ( and BackendUtil.cpp but we used PassManagerBuilder::addGlobalExtension)
//
// This one is not normally included by clang clients
// and not normally installed in the include directory.
#include "CodeGenModule.h"
#include "CGRecordLayout.h"
#include "clang/CodeGen/BackendUtil.h"


static
void setupClangContext(GenInfo* info, ASTContext* Ctx)
{
  std::string layout;

  info->Ctx = Ctx;
  if( ! info->parseOnly ) {
    info->module->setTargetTriple(
        info->Ctx->getTargetInfo().getTriple().getTriple());
  }

  info->targetLayout = info->Ctx->getTargetInfo().getTargetDescription();
  layout = info->targetLayout;

  info->targetData =
    new LLVM_TARGET_DATA(info->Ctx->getTargetInfo().getTargetDescription());
  if( ! info->parseOnly ) {
    info->cgBuilder = new CodeGen::CodeGenModule(*Ctx,
                              info->codegenOptions,
                              *info->module,
                              *info->targetData, *info->Diags);
  }
}


static
VarSymbol *handleMacro(IdentifierInfo* id, MacroInfo* macro)
{
  GenInfo* info = gGenInfo;
  Preprocessor &preproc = info->Clang->getPreprocessor();
  VarSymbol* ret = NULL;

  const bool debugPrint = false;

  if( debugPrint) printf("Adding macro %s\n", id->getName().str().c_str());

  //Handling only simple string or integer defines
  if(macro->getNumArgs() > 0) {
    return ret; // TODO -- handle macro functions.
  }

  // Check that we have a single token surrounded by any
  // number of parens. ie 1, (1), ((1))
  Token tok; // the main token.
  size_t left_parens = 0;
  size_t right_parens = 0;
  ssize_t ntokens = macro->getNumTokens();
  ssize_t t_idx;
  if( ntokens > 0 ) {
      MacroInfo::tokens_iterator ti = macro->tokens_end() - 1;
      for( t_idx = ntokens - 1; t_idx >= 0; t_idx-- ) {
        tok = *ti;
        if(tok.getKind() == tok::r_paren) right_parens++;
        else break;
        --ti;
      }
  }

  {
    MacroInfo::tokens_iterator ti = macro->tokens_begin();
    for( t_idx = 0; t_idx < ntokens; t_idx++ ) {
      tok = *ti;
      if(tok.getKind() == tok::l_paren) left_parens++;
      else break;
      ++ti;
    }
  }
  if( left_parens == right_parens &&
      ntokens - left_parens - right_parens == 1 ) {
    // OK!
  } else {
    return ret; // we don't handle complicated expressions like A+B
  }


  switch(tok.getKind()) {
    case tok::numeric_constant: {
      std::string numString (tok.getLiteralData(), tok.getLength());
      if( debugPrint) printf("num = %s\n", numString.c_str());

      if(numString.find('.') == std::string::npos) {
        IF1_int_type size = INT_SIZE_32;

        if(tolower(numString[numString.length() - 1]) == 'l') {
          numString[numString.length() - 1] = '\0';
          size = INT_SIZE_64;
        }

        if(tolower(numString[numString.length() - 1]) == 'u') {
          numString[numString.length() - 1] = '\0';
          ret = new_UIntSymbol(strtoul(numString.c_str(), NULL, 0), size);
        }
        else {
          ret = new_IntSymbol(strtol(numString.c_str(), NULL, 0), size);
        }
      }
      else {
        IF1_float_type size = FLOAT_SIZE_64;

        if(tolower(numString[numString.length() - 1]) == 'l') {
          numString[numString.length() - 1] = '\0';
        }

        ret = new_RealSymbol("real", strtod(numString.c_str(), NULL), size);
      }
      break;
    }
    case tok::string_literal: {
      std::string body = std::string(tok.getLiteralData(), tok.getLength());
      if( debugPrint) printf("str = %s\n", body.c_str());
      ret = new_StringSymbol(body.c_str());
      break;
    }
    case tok::identifier: {
      IdentifierInfo* tokId = tok.getIdentifierInfo();
      std::string idName = tokId->getName();
      if( debugPrint) {
        printf("id = %s\n", idName.c_str());
      }
      VarSymbol* var = info->lvt->getVarSymbol(idName);
      if( var ) {
        // We've already got something here...
        ret = var;
      } else {
        // Check to see if it's another macro.
        MacroInfo* otherMacro = preproc.getMacroInfo(tokId);
        if( otherMacro && otherMacro != macro ) {
          ret = handleMacro(tokId, otherMacro);
        } else {
          // It must be referring to a variable.
          // FUTURE TODO - create an extern VarSymbol for
          //   Chapel to that variable..
          // The simple code below doesn't quite manage.
          //ret = new VarSymbol(astr(idName.c_str()), dtUnknown);
          //ret->addFlag(FLAG_EXTERN);
        }
      }
      break;
    }
    default:
      break;
  }

  if( ret ) {
    info->lvt->addGlobalVarSymbol(id->getName(), ret);
  }
  return ret;
}
static
void readMacrosClang(void) {
  GenInfo* info = gGenInfo;
  LayeredValueTable *lvt = info->lvt;

  SET_LINENO(rootModule);

  // Pre-populate with important INTxx_MIN/MAX from stdint.h
  // because we have trouble reading these because they have
  // special stuff to get the right constant width, but they
  // are all known integer values.
  lvt->addGlobalVarSymbol("NULL", new_IntSymbol(0, INT_SIZE_64));
  lvt->addGlobalVarSymbol("INT8_MIN", new_IntSymbol(INT8_MIN, INT_SIZE_8));
  lvt->addGlobalVarSymbol("INT8_MAX", new_IntSymbol(INT8_MAX, INT_SIZE_8));
  lvt->addGlobalVarSymbol("UINT8_MAX", new_IntSymbol(UINT8_MAX, INT_SIZE_8));
  lvt->addGlobalVarSymbol("INT16_MIN", new_IntSymbol(INT16_MIN, INT_SIZE_16));
  lvt->addGlobalVarSymbol("INT16_MAX", new_IntSymbol(INT16_MAX, INT_SIZE_16));
  lvt->addGlobalVarSymbol("UINT16_MAX", new_IntSymbol(UINT16_MAX, INT_SIZE_16));
  lvt->addGlobalVarSymbol("INT32_MIN", new_IntSymbol(INT32_MIN, INT_SIZE_32));
  lvt->addGlobalVarSymbol("INT32_MAX", new_IntSymbol(INT32_MAX, INT_SIZE_32));
  lvt->addGlobalVarSymbol("UINT32_MAX", new_IntSymbol(UINT32_MAX, INT_SIZE_32));
  lvt->addGlobalVarSymbol("INT64_MIN", new_IntSymbol(INT64_MIN, INT_SIZE_64));
  lvt->addGlobalVarSymbol("INT64_MAX", new_IntSymbol(INT64_MAX, INT_SIZE_64));
  lvt->addGlobalVarSymbol("UINT64_MAX", new_IntSymbol(UINT64_MAX, INT_SIZE_64));

  //printf("Running ReadMacrosAction\n");
  Preprocessor &preproc = info->Clang->getPreprocessor();
  // Identify macro-functions and macro-values.
  // Later, if we see a use of a macro-function, we can
  //  compile it to a static/inline function with args types based an use
  // how will we know the return type?
  //   expr->getType() stmt->getRetValue()->getType.... 
  //     ... add function wrapping macro with wrong type
  //         parse/analyze squelching errors; get the macro expression type;
  //         correct the type and recompile to LLVM
  //         See ClangExpressionParser.cpp in lldb which parses
  //          a C expression from a command line... we need to
  //          do something similar.
  for(Preprocessor::macro_iterator i = preproc.macro_begin();
      i != preproc.macro_end();
      i++) {

    handleMacro(i->first, i->second);
  }
};

class CCodeGenConsumer : public ASTConsumer {
  private:
    GenInfo* info;
  public:
    CCodeGenConsumer() : ASTConsumer(), info(gGenInfo) {
      //info->module = new llvm::Module(info->moduleName, info->llvmContext);
    }

    virtual ~CCodeGenConsumer() { }

    // mostly taken from ModuleBuilder.cpp
     virtual void Initialize(ASTContext &Context) {
       // This does setTargetTriple, setDataLayout, initialize targetData
       // and cgBuilder.
       setupClangContext(info, &Context);
     }

     virtual void HandleCXXStaticMemberVarInstantiation(VarDecl *VD) {
       // Custom to Chapel
       if( info->parseOnly ) return;
       // End custom to Chapel
       info->cgBuilder->HandleCXXStaticMemberVarInstantiation(VD);
     }

     virtual bool HandleTopLevelDecl(DeclGroupRef DG) {
       // Make sure to emit all elements of a Decl.
       for (DeclGroupRef::iterator I = DG.begin(), E = DG.end(); I != E; ++I) {
         // Custom to Chapel
         if(TypedefDecl *td = dyn_cast<TypedefDecl>(*I)) {
           const clang::Type *ctype= td->getUnderlyingType().getTypePtrOrNull();
           //printf("Adding typedef %s\n", td->getNameAsString().c_str());
           if(ctype != NULL) {
             info->lvt->addGlobalCDecl(td);
           }
         } else if(FunctionDecl *fd = dyn_cast<FunctionDecl>(*I)) {
           info->lvt->addGlobalCDecl(fd);
         } else if(VarDecl *vd = dyn_cast<VarDecl>(*I)) {
           info->lvt->addGlobalCDecl(vd);
         } else if(clang::RecordDecl *rd = dyn_cast<RecordDecl>(*I)) {
           //Allow structs without typedefs
           info->lvt->addGlobalCDecl(rd); 
         }
         if( info->parseOnly ) continue;
         // End custom to Chapel

         info->cgBuilder->EmitTopLevelDecl(*I);
       }

       return true;
     }

     /// HandleTagDeclDefinition - This callback is invoked each time a TagDecl
     /// to (e.g. struct, union, enum, class) is completed. This allows the
     /// client hack on the type, which can occur at any point in the file
     /// (because these can be defined in declspecs).
     virtual void HandleTagDeclDefinition(TagDecl *D) {
       // Custom to Chapel - make a note of C globals
       if(EnumDecl *ed = dyn_cast<EnumDecl>(D)) {
          // Add the enum type
          info->lvt->addGlobalCDecl(ed);
          // Add the enum values
          for(EnumDecl::enumerator_iterator e = ed->enumerator_begin();
              e != ed->enumerator_end();
              e++) {
            info->lvt->addGlobalCDecl(*e); // & goes away with newer clang
          }
       } else if(RecordDecl *rd = dyn_cast<RecordDecl>(D)) {
          const clang::Type *ctype = rd->getTypeForDecl();

          if(ctype != NULL && rd->getDefinition() != NULL) {
            info->lvt->addGlobalCDecl(rd);
          }
       }
       if( info->parseOnly ) return;
       // End Custom to Chapel

       info->cgBuilder->UpdateCompletedType(D);

       // In C++, we may have member functions that need to be emitted at this 
       // point.
       if (info->Ctx->getLangOpts().CPlusPlus && !D->isDependentContext()) {
         for (DeclContext::decl_iterator M = D->decls_begin(),
                                      MEnd = D->decls_end();
              M != MEnd; ++M)
           if (CXXMethodDecl *Method = dyn_cast<CXXMethodDecl>(*M))
             if (Method->doesThisDeclarationHaveABody() &&
                 (Method->hasAttr<UsedAttr>() ||
                  Method->hasAttr<ConstructorAttr>()))
               info->cgBuilder->EmitTopLevelDecl(Method);
       }


     }

     virtual void HandleTranslationUnit(ASTContext &Ctx) {
       if (info->Diags->hasErrorOccurred()) {
         return;
       }

       /* custom to Chapel -
          we don't release the builder now, because
          we want to add a bunch of uses of functions
          that may not have been codegened yet.
       if (info->cgBuilder)
         cgBuilder->Release();
       */
     }

     virtual void CompleteTentativeDefinition(VarDecl *D) {
       if (info->Diags->hasErrorOccurred())
         return;

       // Custom to Chapel
       if( info->parseOnly ) return;
       // End Custom to Chapel
       
       info->cgBuilder->EmitTentativeDefinition(D);
     }

     virtual void HandleVTable(CXXRecordDecl *RD, bool DefinitionRequired) {
       if (info->Diags->hasErrorOccurred())
         return;

       // Custom to Chapel
       if( info->parseOnly ) return;
       // End Custom to Chapel

       info->cgBuilder->EmitVTable(RD, DefinitionRequired);
     }
};

class CCodeGenAction : public ASTFrontendAction {
 public:
  CCodeGenAction() { }
 protected:
  virtual ASTConsumer *CreateASTConsumer(CompilerInstance &CI,
                                                 StringRef InFile);
};

ASTConsumer *
CCodeGenAction::CreateASTConsumer(CompilerInstance &CI,
                                  StringRef InFile) {
  return new CCodeGenConsumer();
};

static void cleanupClang(GenInfo* info)
{
  if( info->cgBuilder ) {
    info->cgBuilder->Release();
    delete info->cgBuilder;
    info->cgBuilder = NULL;
  }
  delete info->targetData;
  info->targetData = NULL;
  delete info->Clang;
  info->Clang = NULL;
  delete info->cgAction;
  info->cgAction = NULL;
  info->Diags.reset();
  info->DiagID.reset();
}

void setupClang(GenInfo* info, std::string mainFile)
{
  std::string clangexe = info->clangInstallDir + "/bin/clang";
  std::vector<const char*> clangArgs;
  for( size_t i = 0; i < info->clangCCArgs.size(); ++i ) {
    clangArgs.push_back(info->clangCCArgs[i].c_str());
  }
  for( size_t i = 0; i < info->clangLDArgs.size(); ++i ) {
    clangArgs.push_back(info->clangLDArgs[i].c_str());
  }
  for( size_t i = 0; i < info->clangOtherArgs.size(); ++i ) {
    clangArgs.push_back(info->clangOtherArgs[i].c_str());
  }

  if (llvmCodegen)
    clangArgs.push_back("-emit-llvm");
  //clangArgs.push_back("-c");
  clangArgs.push_back(mainFile.c_str()); // chpl - always compile rt file

  info->diagOptions = new DiagnosticOptions();
  info->DiagClient= new TextDiagnosticPrinter(errs(),&*info->diagOptions);
  info->DiagID = new DiagnosticIDs();
#if HAVE_LLVM_VER >= 32
  info->Diags = new DiagnosticsEngine(
      info->DiagID, &*info->diagOptions, info->DiagClient);
#else
  info->Diags = new DiagnosticsEngine(info->DiagID, info->DiagClient);
#endif

  CompilerInvocation* CI =
    createInvocationFromCommandLine(clangArgs, info->Diags);

  // Get the codegen options from the clang command line.
  info->codegenOptions = CI->getCodeGenOpts();

  // if --fast is given, we should be at least at -O3.
  if(fFastFlag && info->codegenOptions.OptimizationLevel < 3) {
    info->codegenOptions.OptimizationLevel = 3;
  }


  {
    // Make sure we include clang's internal header dir
    sys::Path P(clangexe);
    if (!P.isEmpty()) {
      P.eraseComponent();  // Remove /clang from foo/bin/clang
      P.eraseComponent();  // Remove /bin   from foo/bin

      // Get foo/lib/clang/<version>/
      P.appendComponent("lib");
      P.appendComponent("clang");
      P.appendComponent(CLANG_VERSION_STRING);
    }
    CI->getHeaderSearchOpts().ResourceDir = P.str();
    sys::Path P2(P);
    P.appendComponent("include");
    CI->getHeaderSearchOpts().AddPath(
        P.str(), frontend::System,false, false, false, true, false);
  }

  // Create a compiler instance to handle the actual work.
  info->Clang = new CompilerInstance();
  info->Clang->setInvocation(CI);

  // Save the TargetOptions and LangOptions since these
  // are used during machine code generation.
  info->clangTargetOptions = info->Clang->getTargetOpts();
  info->clangLangOptions = info->Clang->getLangOpts();

  // Create the compilers actual diagnostics engine.
  // Create the compilers actual diagnostics engine.
  info->Clang->createDiagnostics(int(clangArgs.size()),&clangArgs[0]);
  if (!info->Clang->hasDiagnostics())
    INT_FATAL("Bad diagnostics from clang");
}


void finishCodegenLLVM() {
  GenInfo* info = gGenInfo;

  // Finish up our cleanup optimizers...
  info->FPM_postgen->doFinalization();

  // We don't need our postgen function pass manager anymore.
  delete info->FPM_postgen;
  info->FPM_postgen = NULL;

  // Now finish any Clang code generation.
  cleanupClang(info);

  // Verify the LLVM module.
  if( developer ) {
    if(verifyModule(*info->module,PrintMessageAction)){
      INT_FATAL("LLVM module verification failed");
    }
  }
}

void prepareCodegenLLVM()
{
  GenInfo *info = gGenInfo;

  FunctionPassManager *fpm = new FunctionPassManager(info->module);

  PassManagerBuilder PMBuilder;

  // Set up the optimizer pipeline.
  // Start with registering info about how the
  // target lays out data structures.
  fpm->add(new DataLayout(info->module));

  if( fFastFlag ) {
    PMBuilder.OptLevel = 2;
    PMBuilder.populateFunctionPassManager(*fpm);
  }

  info->FPM_postgen = fpm;

  info->FPM_postgen->doInitialization();
}

static void handleErrorLLVM(void* user_data, const std::string& reason)
{
  INT_FATAL("llvm fatal error: %s", reason.c_str());
}

struct ExternBlockInfo {
  GenInfo* gen_info;
  fileinfo file;
  ExternBlockInfo() : gen_info(NULL), file() { }
  ~ExternBlockInfo() { }
};

typedef std::set<ModuleSymbol*> module_set_t;
typedef module_set_t::iterator module_set_iterator_t;

module_set_t gModulesWithExternBlocks;

bool lookupInExternBlock(ModuleSymbol* module, const char* name,
                         clang::NamedDecl** cDecl,
                         ChapelType** chplType)
{
  if( ! module->extern_info ) return false;
  *cDecl = module->extern_info->gen_info->lvt->getCDecl(name);
  VarSymbol* var = module->extern_info->gen_info->lvt->getVarSymbol(name);
  if( var ) *chplType = var->typeInfo();
  return ( (*chplType) || (*cDecl) );
}
bool alreadyConvertedExtern(ModuleSymbol* module, const char* name)
{
  return module->extern_info->gen_info->lvt->isAlreadyInChapelAST(name);
}
bool setAlreadyConvertedExtern(ModuleSymbol* module, const char* name)
{
  return module->extern_info->gen_info->lvt->markAddedToChapelAST(name);
}


void runClang(const char* just_parse_filename) {
  static bool is_installed_fatal_error_handler = false;

  /* TODO -- note that clang/examples/clang-interpreter/main.cpp 
             includes an example for getting the executable path,
             so that we could automatically set CHPL_HOME. */
  std::string home(CHPL_HOME);
  std::string compileline = home + "/util/config/compileline";
  if( debugCCode ) compileline += " DEBUG=1";
  if( optimizeCCode ) compileline += " OPTIMIZE=1";
  std::string readargsfrom = compileline +
                              " --llvm-install-dir --includes-and-defines";
  std::vector<std::string> args;
  std::vector<std::string> clangCCArgs;
  std::vector<std::string> clangLDArgs;
  std::vector<std::string> clangOtherArgs;
  std::string clangInstallDir;

  // Add cflags,etc that used to be put into the Makefile
  // (see codegen_makefile in files.cpp)
  if (ccwarnings) {
    // Could add warning arguments here. to clangCCArgs
  }

  if (debugCCode) {
    clangCCArgs.push_back("-g");
  }

  if (optimizeCCode) {
    clangCCArgs.push_back("-O3");
  }

  if (fieeefloat) {
    // believe clang is always ieee float
  } else {
    clangCCArgs.push_back("-ffast-math");
  }

  forv_Vec(const char*, dirName, incDirs) {
    clangCCArgs.push_back(std::string("-I") + dirName);
  }
  clangCCArgs.push_back(std::string("-I") + getIntermediateDirName());

  clangCCArgs.push_back(ccflags);

  clangLDArgs.push_back(ldflags);

  for (int i=0; i<numLibFlags; i++)
    clangLDArgs.push_back(libFlag[i]);

  clangCCArgs.push_back("-DCHPL_GEN_CODE");

  // Gather information from readargsfrom into clangArgs.
  readArgsFromCommand(readargsfrom.c_str(), args);
  clangInstallDir = args[0];
  for( size_t i = 1; i < args.size(); ++i ) {
    clangOtherArgs.push_back(args[i]);
  }

  // Always include sys_basic because it might change the
  // behaviour of macros!
  clangOtherArgs.push_back("-include");
  clangOtherArgs.push_back("sys_basic.h");

  if (!just_parse_filename) {
    // Running clang to compile all runtime and extern blocks

    // Include header files from the command line.
    {
      int filenum = 0;
      while (const char* inputFilename = nthFilename(filenum++)) {
        if (isCHeader(inputFilename)) {
          clangOtherArgs.push_back("-include");
          clangOtherArgs.push_back(inputFilename);
        }
      }
    }
    // Include extern C blocks
    if( externC && gAllExternCode.filename ) {
      clangOtherArgs.push_back("-include");
      clangOtherArgs.push_back(gAllExternCode.filename);
    }
  } else {
    // Just running clang to parse the extern blocks for this module.
    clangOtherArgs.push_back("-include");
    clangOtherArgs.push_back(just_parse_filename);
  }

  if( printSystemCommands ) {
    printf("<internal clang> ");
    for( size_t i = 0; i < clangCCArgs.size(); i++ ) {
      printf("%s ", clangCCArgs[i].c_str());
    }
    for( size_t i = 0; i < clangOtherArgs.size(); i++ ) {
      printf("%s ", clangOtherArgs[i].c_str());
    }
    printf("\n");
  }

  // Initialize gGenInfo
  // Toggle LLVM code generation in our clang run;
  // turn it off if we just wanted to parse some C.
  gGenInfo = new GenInfo(clangInstallDir,
                         compileline, clangCCArgs, clangLDArgs, clangOtherArgs,
                         just_parse_filename != NULL);

  if( llvmCodegen || externC )
  {
    GenInfo *info = gGenInfo;

    // Install an LLVM Fatal Error Handler.
    if (!is_installed_fatal_error_handler) {
      is_installed_fatal_error_handler = true;
      install_fatal_error_handler(handleErrorLLVM);
    }

    // Run the Start Generation action
    // Now initialize a code generator...
    // this will enable us to ask for addresses of static (inline) functions
    // and cause them to be emitted eventually.
    info->cgAction = new CCodeGenAction();
    if (!info->Clang->ExecuteAction(*info->cgAction)) {
      if (just_parse_filename) {
        USR_FATAL("error running clang on extern block");
      } else {
        USR_FATAL("error running clang during code generation");
      }
    }

    if( ! info->parseOnly ) {
      // This seems to be needed, even though it is strange.
      // (otherwise we segfault in info->builder->CreateGlobalString)
      
      // Some IRBuilder methods, codegenning a string,
      // need a basic block in order to get to the module
      // so we create a dummy function to code generate into
      llvm::Type * voidTy =  llvm::Type::getVoidTy(info->module->getContext());
      std::vector<llvm::Type*> args;
      llvm::FunctionType * FT = llvm::FunctionType::get(voidTy, args, false);
      Function * F =
        Function::Create(FT, Function::InternalLinkage,
                         "chplDummyFunction", info->module);
      llvm::BasicBlock *block =
        llvm::BasicBlock::Create(info->module->getContext(), "entry", F);
      info->builder->SetInsertPoint(block);
    }
    // read macros. May call IRBuilder methods to codegen a string,
    // so needs to happen after we set the insert point.
    readMacrosClang();

    if( ! info->parseOnly ) {
      info->builder->CreateRetVoid();
    }
  }
}

static
void saveExternBlock(ModuleSymbol* module, const char* extern_code)
{
  if( ! gAllExternCode.filename ) {
    openCFile(&gAllExternCode, "extern-code", "c");
    INT_ASSERT(gAllExternCode.fptr);
  }

  if( ! module->extern_info ) {
    // Figure out what file to place the C code into.
    module->extern_info = new ExternBlockInfo();
    const char* name = astr("extern_block_", module->cname);
    openCFile(&module->extern_info->file, name, "c");
    // Could put #ifndef/define/endif wrapper start here.
  }
  FILE* f = module->extern_info->file.fptr;
  INT_ASSERT(f);
  // Append the C code to that file.
  fputs(extern_code, f);
  // Always make sure it ends in a close semi (solves errors)
  fputs("\n;\n", f);
  // Add this module to the set of modules needing extern compilation.
  std::pair<module_set_iterator_t,bool> already_there;
  already_there = gModulesWithExternBlocks.insert(module);
  if( already_there.second ) {
    // A new element was added to the map ->
    //   first time we have worked with this module.
    // Add a #include of this module's extern block code to the
    //   global extern code file.
    fprintf(gAllExternCode.fptr,
           "#include \"%s\"\n", module->extern_info->file.filename);
  }
}


void readExternC(void) {
  // Handle extern C blocks.
  forv_Vec(ExternBlockStmt, eb, gExternBlockStmts) {
    // Figure out the parent module symbol.
    ModuleSymbol* module = eb->getModule();
    saveExternBlock(module, eb->c_code);
  }

  // Close extern_c_file.
  if( gAllExternCode.fptr ) closefile(&gAllExternCode);
  // Close any extern files for any modules we had generated code for.
  module_set_iterator_t it;
  for( it = gModulesWithExternBlocks.begin();
       it != gModulesWithExternBlocks.end();
       ++it ) {
    ModuleSymbol* module = *it;
    INT_ASSERT(module->extern_info);
    // Could put #ifndef/define/endif wrapper end here.
    closefile(&module->extern_info->file);
    // Now parse the extern C code for that module.
    runClang(module->extern_info->file.filename);
    // Now swap what went into the global layered value table
    // into the module's own layered value table.
    module->extern_info->gen_info = gGenInfo;
    gGenInfo = NULL;
  }
}

void cleanupExternC(void) {
  module_set_iterator_t it;
  for( it = gModulesWithExternBlocks.begin();
       it != gModulesWithExternBlocks.end();
       ++it ) {
    ModuleSymbol* module = *it;
    INT_ASSERT(module->extern_info);
    cleanupClang(module->extern_info->gen_info);
    delete module->extern_info->gen_info;
    delete module->extern_info;
    // Remove all ExternBlockStmts from this module.
    forv_Vec(ExternBlockStmt, eb, gExternBlockStmts) {
      eb->remove();
    }
    gExternBlockStmts.clear();
  }
}

Function* getFunctionLLVM(const char* name)
{
  GenInfo* info = gGenInfo;
  Function* fn = info->module->getFunction(name);
  if( fn ) return fn;

  GenRet got = info->lvt->getValue(name);
  if( got.val ) {
    fn = cast<Function>(got.val);
    return fn;
  }

  return NULL;
}

llvm::Type* getTypeLLVM(const char* name)
{
  GenInfo* info = gGenInfo;
  llvm::Type* t = info->module->getTypeByName(name);
  if( t ) return t;

  t = info->lvt->getType(name);
  if( t ) return t;

  return NULL;
}
// should support TypedefDecl,EnumDecl,RecordDecl
llvm::Type* codegenCType(const TypeDecl* td)
{
  GenInfo* info = gGenInfo;
  CodeGen::CodeGenTypes & cdt = info->cgBuilder->getTypes();
  QualType qType;

  // handle TypedefDecl
  if( const TypedefNameDecl* tnd = dyn_cast<TypedefNameDecl>(td) ) {
    qType = tnd->getCanonicalDecl()->getUnderlyingType();
    // had const Type *ctype = td->getUnderlyingType().getTypePtrOrNull();
    //could also do:
    //  qType =
    //   tnd->getCanonicalDecl()->getTypeForDecl()->getCanonicalTypeInternal();
  } else if( const EnumDecl* ed = dyn_cast<EnumDecl>(td) ) {
    qType = ed->getCanonicalDecl()->getIntegerType();
    // could also use getPromotionType()
    //could also do:
    //  qType =
    //   tnd->getCanonicalDecl()->getTypeForDecl()->getCanonicalTypeInternal();
  } else if( const RecordDecl* rd = dyn_cast<RecordDecl>(td) ) {
    RecordDecl *def = rd->getDefinition();
    INT_ASSERT(def);
    qType=def->getCanonicalDecl()->getTypeForDecl()->getCanonicalTypeInternal();
  } else {
    INT_FATAL("Unknown clang type declaration");
  }
  return cdt.ConvertTypeForMem(qType);
}

// should support FunctionDecl,VarDecl,EnumConstantDecl
GenRet codegenCValue(const ValueDecl *vd)
{
  GenInfo* info = gGenInfo;
  GenRet ret;

  if( info->cfile ) {
    ret.c = vd->getName();
    return ret;
  }

  if(const FunctionDecl *fd = dyn_cast<FunctionDecl>(vd)) {
    // It's a function decl.
    ret.val = info->cgBuilder->GetAddrOfFunction(fd);
    ret.isLVPtr = GEN_VAL;
  } else if(const VarDecl *vard = dyn_cast<VarDecl>(vd)) {
    // It's a (global) variable decl
    ret.val = info->cgBuilder->GetAddrOfGlobalVar(vard);
    ret.isLVPtr = GEN_PTR;
  } else if(const EnumConstantDecl *ed = dyn_cast<EnumConstantDecl>(vd)) {
    // It's a constant enum value
    APInt v = ed->getInitVal();

    ret.isUnsigned = ! ed->getType()->hasSignedIntegerRepresentation();
    CodeGen::CodeGenTypes & cdt = info->cgBuilder->getTypes();
    llvm::Type* type = cdt.ConvertTypeForMem(ed->getType());
    ret.val = ConstantInt::get(type, v);
    ret.isLVPtr = GEN_VAL;
  } else {
    INT_FATAL("Unknown clang value declaration");
  }
  return ret;
}

LayeredValueTable::LayeredValueTable(){
  layers.push_front(map_type());
}

void LayeredValueTable::addLayer(){
  layers.push_front(map_type());
}

void LayeredValueTable::removeLayer(){
  if(layers.size() != 1) {
    layers.pop_front();
  }
}


void LayeredValueTable::addValue(
    StringRef name, Value *value, uint8_t isLVPtr, bool isUnsigned) {
  Storage store;
  store.u.value = value;
  store.isLVPtr = isLVPtr;
  store.isUnsigned = isUnsigned;
  (layers.front())[name] = store;
}

void LayeredValueTable::addGlobalValue(
    StringRef name, Value *value, uint8_t isLVPtr, bool isUnsigned) {
  Storage store;
  store.u.value = value;
  store.isLVPtr = isLVPtr;
  store.isUnsigned = isUnsigned;
  (layers.back())[name] = store;
}

void LayeredValueTable::addGlobalValue(StringRef name, GenRet gend) {
  addGlobalValue(name, gend.val, gend.isLVPtr, gend.isUnsigned);
}

void LayeredValueTable::addGlobalType(StringRef name, llvm::Type *type) {
  Storage store;
  store.u.type = type;
  /*fprintf(stderr, "Adding global type %s ", name.str().c_str());
  type->dump();
  fprintf(stderr, "\n");
  */
  (layers.back())[name] = store;
}

void LayeredValueTable::addGlobalCDecl(NamedDecl* cdecl) {
  Storage store;
  store.u.cdecl = cdecl;
  (layers.back())[cdecl->getName()] = store;
}

void LayeredValueTable::addGlobalVarSymbol(llvm::StringRef name, VarSymbol* var)
{
  Storage store;
  store.u.chplVar = var;
  (layers.back())[name] = store;
}

void LayeredValueTable::addBlock(StringRef name, llvm::BasicBlock *block) {
  Storage store;
  store.u.block = block;

  layer_iterator blockLayer = --layers.end();
  if(layers.size() > 1) {
    blockLayer = --blockLayer;
  }
  (*blockLayer)[name] = store;
}

GenRet LayeredValueTable::getValue(StringRef name) {
  if(Storage *store = get(name)) {
    if( std::string(name) == std::string("QIO_FILE_PTR_NULL") ) {
      gdbShouldBreakHere();
    }
    if( store->u.value && isa<Value>(store->u.value) ) {
      GenRet ret;
      ret.val = store->u.value;
      ret.isLVPtr = store->isLVPtr;
      ret.isUnsigned = store->isUnsigned;
      return ret;
    }
    if( store->u.cdecl && isa<NamedDecl>(store->u.cdecl) ) {
      // we have a clang named decl.
      // maybe TypedefDecl,EnumDecl,RecordDecl,FunctionDecl,
      // VarDecl,EnumConstantDecl
      if( isa<ValueDecl>(store->u.cdecl) ) {
        ValueDecl* vd = cast<ValueDecl>(store->u.cdecl);

        // Convert it to an LLVM value
        // should support FunctionDecl,VarDecl,EnumConstantDecl
        return codegenCValue(vd);
      }
    }
    if( store->u.chplVar && isVarSymbol(store->u.chplVar) ) {
      VarSymbol* var = store->u.chplVar;
      GenRet ret = var; // code generate it!
      return ret;
    }
  }
  GenRet ret;
  return ret;
}

llvm::BasicBlock *LayeredValueTable::getBlock(StringRef name) {
  if(Storage *store = get(name)) {
    if( store->u.block && isa<llvm::BasicBlock>(store->u.block) )
      return store->u.block;
  }
  return NULL;
}

llvm::Type *LayeredValueTable::getType(StringRef name) {
  if(Storage *store = get(name)) {
    if( store->u.type && isa<llvm::Type>(store->u.type) )
      return store->u.type;
    if( store->u.cdecl && isa<NamedDecl>(store->u.cdecl) ) {
      // we have a clang named decl.
      // maybe TypedefDecl,EnumDecl,RecordDecl,FunctionDecl,
      // VarDecl,EnumConstantDecl
      if( isa<TypeDecl>(store->u.cdecl) ) {
        TypeDecl* td = cast<TypeDecl>(store->u.cdecl);
        // Convert it to an LLVM type.
        // should support TypedefDecl,EnumDecl,RecordDecl
        return codegenCType(td);
      }
    }
  }
  return NULL;
}

NamedDecl* LayeredValueTable::getCDecl(StringRef name) {
  if(Storage *store = get(name)) {
    if( store->u.cdecl && isa<NamedDecl>(store->u.cdecl) ) {
      // we have a clang named decl.
      // maybe TypedefDecl,EnumDecl,RecordDecl,FunctionDecl,
      // VarDecl,EnumConstantDecl
      return store->u.cdecl;
    }
  }
  return NULL;
}

VarSymbol* LayeredValueTable::getVarSymbol(StringRef name) {
  if(Storage *store = get(name)) {
    if( store->u.chplVar && isVarSymbol(store->u.chplVar) ) {
      // we have a Chapel Var Symbol.
      // maybe immediate number or string, possibly variable reference.
      // These come from macros.
      return store->u.chplVar;
    }
  }
  return NULL;
}

LayeredValueTable::Storage* LayeredValueTable::get(StringRef name) {
  for(layer_iterator i = layers.begin(); i != layers.end(); ++i) {
    value_iterator j = i->find(name);

    if(j != i->end())
    {
      return &j->second;
    }
  }

  return NULL;
}

bool LayeredValueTable::isAlreadyInChapelAST(llvm::StringRef name)
{
  if(Storage *store = get(name)) {
    return store->addedToChapelAST;
  }
  return false;
}

bool LayeredValueTable::markAddedToChapelAST(llvm::StringRef name)
{
  if(Storage *store = get(name)) {
    if( store->addedToChapelAST ) return false;
    store->addedToChapelAST = true;
    return true;
  } else {
    // Otherwise, make a new entry.
    Storage store;
    store.addedToChapelAST = true;
    (layers.back())[name] = store;
    return true;
  }
}

void LayeredValueTable::swap(LayeredValueTable* other)
{
  this->layers.swap(other->layers);
}

int getCRecordMemberGEP(const char* typeName, const char* fieldName)
{
  GenInfo* info = gGenInfo;
  NamedDecl* d = info->lvt->getCDecl(typeName);
  int ret;
  INT_ASSERT(d);
  if( isa<TypedefDecl>(d) ) {
    TypedefDecl* td = cast<TypedefDecl>(d);
    const clang::Type* t = td->getUnderlyingType().getTypePtr();
    while( t->isPointerType() ) {
      t = t->getPointeeType().getTypePtr();
    }
    const RecordType* rt = t->getAsStructureType();
    INT_ASSERT(rt);
    d = rt->getDecl();
    // getAsUnionType also available, but we don't support extern unions
  }
  INT_ASSERT(isa<RecordDecl>(d));
  RecordDecl* rec = cast<RecordDecl>(d);
  // Find the field decl.
  RecordDecl::field_iterator it;
  FieldDecl* field = NULL;
  for( it = rec->field_begin(); it != rec->field_end(); ++it ) {
    if( fieldName == it->getName() ) {
      field = *it;
      break;
    }
  }
  INT_ASSERT(field);
  ret=info->cgBuilder->getTypes().getCGRecordLayout(rec).getLLVMFieldNo(field);
  return ret;
}

bool isBuiltinExternCFunction(const char* cname)
{
  if( 0 == strcmp(cname, "sizeof") ) return true;
  else return false;
}


void makeBinaryLLVM(void) {
  GenInfo* info = gGenInfo;

  std::string moduleFilename = genIntermediateFilename("chpl__module.bc");
  std::string preOptFilename = genIntermediateFilename("chpl__module-nopt.bc");

  if( saveCDir[0] != '\0' ) {
    // Save the generated LLVM before optimization.
    std::string errorInfo;
    OwningPtr<tool_output_file> output (
        new tool_output_file(preOptFilename.c_str(),
                             errorInfo,
                             raw_fd_ostream::F_Binary));
    WriteBitcodeToFile(info->module, output->os());
    output->keep();
    output->os().flush();
  }

  std::string errorInfo;
  OwningPtr<tool_output_file> output (
      new tool_output_file(moduleFilename.c_str(),
                           errorInfo,
                           raw_fd_ostream::F_Binary));
 
  EmitBackendOutput(*info->Diags, info->codegenOptions,
                    info->clangTargetOptions, info->clangLangOptions,
                    info->module, Backend_EmitBC, &output->os());
  output->keep();
  output->os().flush();


  std::string options = "";

  std::string home(CHPL_HOME);
  std::string compileline = info->compileline;
  compileline += " --llvm-install-dir --main.o --libraries";
  std::vector<std::string> args;
  readArgsFromCommand(compileline.c_str(), args);

  std::string clangInstall = args[0];
  std::string maino = args[1];
  std::vector<std::string> dotOFiles;

  // Gather C flags for compiling C files.
  std::string cargs;
  for( size_t i = 0; i < info->clangCCArgs.size(); ++i ) {
    cargs += " ";
    cargs += info->clangCCArgs[i];
  }

  // Compile any C files.
  int filenum = 0;
  while (const char* inputFilename = nthFilename(filenum++)) {
    if (isCSource(inputFilename)) {
      const char* objFilename = objectFileForCFile(inputFilename);
      mysystem(astr(clangInstall.c_str(),
                    "/bin/clang -c -o ", objFilename,
                    " ", inputFilename, cargs.c_str()),
               "Compile C File");
      dotOFiles.push_back(objFilename);
    } else if( isObjFile(inputFilename) ) {
      dotOFiles.push_back(inputFilename);
    }
  }

  if(debugCCode) {
    options += " -g";
  }

  // Run linker...
  std::string command = clangInstall + "/bin/clang " + options + " " +
                        moduleFilename + " " + maino +
                        " -o " + executableFilename;
  for( size_t i = 0; i < dotOFiles.size(); i++ ) {
    command += " ";
    command += dotOFiles[i];
  }

  // 0 is llvm install dir, 1 is main.o
  for(size_t i = 2; i < args.size(); ++i) {
    command += " ";
    command += args[i];
  }

  mysystem(command.c_str(), "Make Binary - Linking");
}

#endif