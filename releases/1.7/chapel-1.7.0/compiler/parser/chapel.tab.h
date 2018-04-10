/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENT = 258,
     IMAGLITERAL = 259,
     INTLITERAL = 260,
     REALLITERAL = 261,
     STRINGLITERAL = 262,
     EXTERNCODE = 263,
     TALIGN = 264,
     TATOMIC = 265,
     TBEGIN = 266,
     TBREAK = 267,
     TBY = 268,
     TCLASS = 269,
     TCOBEGIN = 270,
     TCOFORALL = 271,
     TCONFIG = 272,
     TCONST = 273,
     TCONTINUE = 274,
     TDELETE = 275,
     TDMAPPED = 276,
     TDO = 277,
     TDOMAIN = 278,
     TELSE = 279,
     TENUM = 280,
     TEXPORT = 281,
     TEXTERN = 282,
     TFOR = 283,
     TFORALL = 284,
     TIF = 285,
     TIN = 286,
     TINDEX = 287,
     TINLINE = 288,
     TINOUT = 289,
     TITER = 290,
     TLABEL = 291,
     TLAMBDA = 292,
     TLET = 293,
     TLOCAL = 294,
     TMINUSMINUS = 295,
     TMODULE = 296,
     TNEW = 297,
     TNIL = 298,
     TON = 299,
     TOTHERWISE = 300,
     TOUT = 301,
     TPARAM = 302,
     TPLUSPLUS = 303,
     TPRAGMA = 304,
     TPRIMITIVE = 305,
     TPRIMITIVELOOP = 306,
     TPROC = 307,
     TRECORD = 308,
     TREDUCE = 309,
     TREF = 310,
     TRETURN = 311,
     TSCAN = 312,
     TSELECT = 313,
     TSERIAL = 314,
     TSINGLE = 315,
     TSPARSE = 316,
     TSUBDOMAIN = 317,
     TSYNC = 318,
     TTHEN = 319,
     TTYPE = 320,
     TUNDERSCORE = 321,
     TUNION = 322,
     TUSE = 323,
     TVAR = 324,
     TWHEN = 325,
     TWHERE = 326,
     TWHILE = 327,
     TYIELD = 328,
     TZIP = 329,
     TALIAS = 330,
     TAND = 331,
     TASSIGN = 332,
     TASSIGNBAND = 333,
     TASSIGNBOR = 334,
     TASSIGNBXOR = 335,
     TASSIGNDIVIDE = 336,
     TASSIGNEXP = 337,
     TASSIGNLAND = 338,
     TASSIGNLOR = 339,
     TASSIGNMINUS = 340,
     TASSIGNMOD = 341,
     TASSIGNMULTIPLY = 342,
     TASSIGNPLUS = 343,
     TASSIGNSL = 344,
     TASSIGNSR = 345,
     TBAND = 346,
     TBNOT = 347,
     TBOR = 348,
     TBXOR = 349,
     TCOLON = 350,
     TCOMMA = 351,
     TDIVIDE = 352,
     TDOT = 353,
     TDOTDOT = 354,
     TDOTDOTDOT = 355,
     TEQUAL = 356,
     TEXP = 357,
     TGREATER = 358,
     TGREATEREQUAL = 359,
     THASH = 360,
     TLESS = 361,
     TLESSEQUAL = 362,
     TMINUS = 363,
     TMOD = 364,
     TNOT = 365,
     TNOTEQUAL = 366,
     TOR = 367,
     TPLUS = 368,
     TQUESTION = 369,
     TSEMI = 370,
     TSHIFTLEFT = 371,
     TSHIFTRIGHT = 372,
     TSTAR = 373,
     TSWAP = 374,
     TIO = 375,
     TLCBR = 376,
     TRCBR = 377,
     TLP = 378,
     TRP = 379,
     TLSBR = 380,
     TRSBR = 381,
     TNOELSE = 382,
     TUMINUS = 383,
     TUPLUS = 384
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 42 "chapel.ypp"

  const char* pch;
  Vec<const char*>* vpch;
  RetTag retTag;
  bool b;
  IntentTag pt;
  Expr* pexpr;
  DefExpr* pdefexpr;
  CallExpr* pcallexpr;
  BlockStmt* pblockstmt;
  Type* ptype;
  EnumType* penumtype;
  FnSymbol* pfnsymbol;
  Flag flag;
  ProcIter procIter;
  FlagSet* flagSet;



/* Line 2068 of yacc.c  */
#line 199 "chapel.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

