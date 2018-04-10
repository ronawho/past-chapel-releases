/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 12 "chapel.ypp"


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdint.h>
#include "lexyacc.h" // all #includes here, for make depend
#include "driver.h"

  static int query_uid = 1;
  int captureTokens;
  char captureString[1024];

 
#define YYLLOC_DEFAULT(Current, Rhs, N)                                 \
  if (N) {                                                              \
        (Current).first_line   = (Rhs)[1].first_line;                   \
        if ((Current).first_line) yystartlineno = (Current).first_line; \
        (Current).first_column = (Rhs)[1].first_column;                 \
        (Current).last_line    = (Rhs)[N].last_line;                    \
        (Current).last_column  = (Rhs)[N].last_column;                  \
        (Current).comment = NULL;                                       \
  } else  {                                                             \
    (Current) = yylloc;                                                 \
  }                                                                     \



/* Line 268 of yacc.c  */
#line 100 "chapel.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 285 "chapel.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 310 "chapel.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10543

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  130
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  402
/* YYNRULES -- Number of states.  */
#define YYNSTATES  756

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   384

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    14,    16,    19,
      22,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    49,    52,    55,    59,    62,    66,    70,    74,
      77,    81,    85,    88,    92,    96,    98,   103,   108,   113,
     118,   123,   128,   133,   138,   143,   148,   153,   158,   163,
     168,   173,   176,   180,   181,   183,   185,   188,   190,   193,
     197,   199,   201,   203,   205,   207,   209,   212,   218,   222,
     228,   234,   238,   244,   250,   256,   260,   264,   271,   277,
     283,   287,   294,   301,   306,   311,   316,   320,   327,   333,
     339,   340,   343,   347,   350,   357,   365,   366,   368,   370,
     372,   374,   375,   378,   379,   382,   386,   392,   394,   397,
     401,   403,   407,   408,   409,   418,   419,   421,   423,   426,
     428,   431,   432,   433,   443,   447,   453,   455,   458,   460,
     462,   464,   466,   468,   470,   472,   474,   476,   478,   480,
     482,   484,   486,   488,   490,   492,   494,   496,   498,   500,
     502,   504,   506,   508,   510,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   531,   535,   539,   540,   542,
     546,   551,   556,   563,   570,   571,   573,   575,   577,   579,
     581,   583,   585,   586,   588,   590,   592,   593,   595,   597,
     599,   601,   603,   605,   607,   609,   612,   614,   615,   617,
     620,   623,   624,   627,   632,   638,   640,   644,   649,   654,
     657,   662,   663,   666,   669,   674,   679,   684,   685,   687,
     689,   691,   695,   699,   704,   710,   712,   714,   718,   720,
     723,   727,   728,   731,   732,   737,   738,   741,   744,   746,
     751,   756,   763,   765,   766,   768,   770,   774,   779,   783,
     788,   795,   796,   799,   802,   805,   808,   811,   814,   816,
     818,   822,   826,   828,   830,   832,   834,   837,   841,   843,
     847,   848,   850,   852,   856,   860,   864,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   887,   892,   897,   902,
     908,   911,   914,   921,   928,   933,   943,   953,   961,   968,
     975,   980,   990,  1000,  1008,  1013,  1020,  1027,  1037,  1047,
    1054,  1056,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1074,
    1076,  1080,  1083,  1088,  1090,  1092,  1094,  1096,  1098,  1100,
    1102,  1104,  1109,  1113,  1117,  1120,  1123,  1125,  1127,  1129,
    1131,  1133,  1135,  1137,  1142,  1147,  1152,  1156,  1160,  1164,
    1168,  1170,  1172,  1174,  1176,  1180,  1184,  1188,  1192,  1198,
    1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,
    1242,  1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,  1278,
    1282,  1286,  1290,  1293,  1296,  1299,  1302,  1305,  1308,  1312,
    1316,  1320,  1324,  1328,  1332,  1336,  1340,  1342,  1344,  1346,
    1348,  1350,  1352
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     131,     0,    -1,   132,    -1,    -1,   132,   133,    -1,   136,
      -1,   135,   136,    -1,   133,    -1,   134,   133,    -1,    49,
       7,    -1,   135,    49,     7,    -1,   137,    -1,   138,    -1,
     143,    -1,   144,    -1,   147,    -1,   183,    -1,   145,    -1,
     148,    -1,   151,    -1,   142,    -1,   213,   115,    -1,    10,
     136,    -1,    11,   136,    -1,    12,   139,   115,    -1,    15,
     138,    -1,    19,   139,   115,    -1,    20,   217,   115,    -1,
      36,   140,   136,    -1,    39,   136,    -1,    44,   217,   141,
      -1,    59,   217,   141,    -1,    63,   136,    -1,    68,   201,
     115,    -1,    73,   217,   115,    -1,     1,    -1,   218,    77,
     217,   115,    -1,   218,    88,   217,   115,    -1,   218,    85,
     217,   115,    -1,   218,    87,   217,   115,    -1,   218,    81,
     217,   115,    -1,   218,    86,   217,   115,    -1,   218,    82,
     217,   115,    -1,   218,    78,   217,   115,    -1,   218,    79,
     217,   115,    -1,   218,    80,   217,   115,    -1,   218,    90,
     217,   115,    -1,   218,    89,   217,   115,    -1,   218,   119,
     217,   115,    -1,   218,    83,   217,   115,    -1,   218,    84,
     217,   115,    -1,   121,   122,    -1,   121,   134,   122,    -1,
      -1,   140,    -1,     3,    -1,    22,   136,    -1,   138,    -1,
      56,   115,    -1,    56,   217,   115,    -1,   115,    -1,   164,
      -1,   152,    -1,   157,    -1,   185,    -1,   188,    -1,    27,
       8,    -1,    22,   136,    72,   217,   115,    -1,    72,   217,
     141,    -1,    16,   217,    31,   217,   141,    -1,    16,   217,
      31,   146,   141,    -1,    16,   217,   141,    -1,    51,   123,
     205,   124,   141,    -1,    28,   217,    31,   217,   141,    -1,
      28,   217,    31,   146,   141,    -1,    28,   217,   141,    -1,
      28,   146,   141,    -1,    28,    47,   140,    31,   217,   141,
      -1,    29,   217,    31,   217,   141,    -1,    29,   217,    31,
     146,   141,    -1,    29,   217,   141,    -1,   125,   201,    31,
     217,   126,   136,    -1,   125,   201,    31,   146,   126,   136,
      -1,   125,   201,   126,   136,    -1,    74,   123,   201,   124,
      -1,    30,   217,    64,   136,    -1,    30,   217,   138,    -1,
      30,   217,    64,   136,    24,   136,    -1,    30,   217,   138,
      24,   136,    -1,    58,   217,   121,   149,   122,    -1,    -1,
     149,   150,    -1,    70,   201,   141,    -1,    45,   136,    -1,
      65,    58,   201,   121,   149,   122,    -1,   153,   154,   140,
     155,   121,   156,   122,    -1,    -1,    27,    -1,    14,    -1,
      53,    -1,    67,    -1,    -1,    95,   201,    -1,    -1,   156,
     143,    -1,   156,   135,   143,    -1,    25,   140,   121,   158,
     122,    -1,   159,    -1,   158,    96,    -1,   158,    96,   159,
      -1,   140,    -1,   140,    77,   217,    -1,    -1,    -1,    37,
     161,   170,   162,   176,   196,   182,   178,    -1,    -1,    33,
      -1,    26,    -1,    26,   140,    -1,    27,    -1,    27,   140,
      -1,    -1,    -1,   163,   175,   165,   167,   166,   176,   196,
     182,   177,    -1,   174,   168,   169,    -1,   174,   140,    98,
     168,   169,    -1,   140,    -1,    92,   140,    -1,    77,    -1,
      91,    -1,    93,    -1,    94,    -1,    92,    -1,   101,    -1,
     111,    -1,   107,    -1,   104,    -1,   106,    -1,   103,    -1,
     113,    -1,   108,    -1,   118,    -1,    97,    -1,   116,    -1,
     117,    -1,   109,    -1,   102,    -1,   110,    -1,    13,    -1,
     105,    -1,     9,    -1,    88,    -1,    85,    -1,    87,    -1,
      81,    -1,    86,    -1,    82,    -1,    78,    -1,    79,    -1,
      80,    -1,    90,    -1,    89,    -1,   119,    -1,   120,    -1,
      -1,   123,   171,   124,    -1,   123,   171,   124,    -1,    -1,
     172,    -1,   171,    96,   172,    -1,   173,   140,   200,   194,
      -1,   173,   140,   200,   181,    -1,   173,   123,   193,   124,
     200,   194,    -1,   173,   123,   193,   124,   200,   181,    -1,
      -1,    31,    -1,    34,    -1,    46,    -1,    18,    -1,    47,
      -1,    55,    -1,    65,    -1,    -1,    47,    -1,    52,    -1,
      35,    -1,    -1,    18,    -1,    69,    -1,    47,    -1,    65,
      -1,   115,    -1,   178,    -1,   138,    -1,   142,    -1,   114,
     140,    -1,   114,    -1,    -1,   179,    -1,   100,   217,    -1,
     100,   180,    -1,    -1,    71,   217,    -1,   184,   140,   121,
     122,    -1,   184,   140,   121,   134,   122,    -1,    41,    -1,
      65,   186,   115,    -1,    17,    65,   186,   115,    -1,    27,
      65,   186,   115,    -1,   140,   187,    -1,   140,   187,    96,
     186,    -1,    -1,    77,   209,    -1,    77,   197,    -1,   189,
      47,   190,   115,    -1,   189,    18,   190,   115,    -1,   189,
      69,   190,   115,    -1,    -1,    17,    -1,    27,    -1,   191,
      -1,   190,    96,   191,    -1,   140,   196,   194,    -1,   140,
     195,    75,   217,    -1,   123,   193,   124,   196,   194,    -1,
      66,    -1,   140,    -1,   123,   193,   124,    -1,   192,    -1,
     192,    96,    -1,   192,    96,   193,    -1,    -1,    77,   217,
      -1,    -1,    95,   125,   201,   126,    -1,    -1,    95,   209,
      -1,    95,   197,    -1,     1,    -1,   125,   201,   126,   209,
      -1,   125,   201,   126,   197,    -1,   125,   201,    31,   217,
     126,   209,    -1,     1,    -1,    -1,   209,    -1,   179,    -1,
     125,   126,   198,    -1,   125,   201,   126,   198,    -1,   125,
     126,   199,    -1,   125,   201,   126,   199,    -1,   125,   201,
      31,   217,   126,   198,    -1,    -1,    95,   209,    -1,    95,
     179,    -1,    95,    23,    -1,    95,    60,    -1,    95,    63,
      -1,    95,   199,    -1,   217,    -1,   179,    -1,   201,    96,
     217,    -1,   201,    96,   179,    -1,    66,    -1,   217,    -1,
     179,    -1,   202,    -1,   202,    96,    -1,   202,    96,   204,
      -1,   202,    -1,   204,    96,   202,    -1,    -1,   206,    -1,
     207,    -1,   206,    96,   207,    -1,   140,    77,   179,    -1,
     140,    77,   217,    -1,   140,    75,   217,    -1,   179,    -1,
     217,    -1,   140,    -1,   212,    -1,   218,    -1,   211,    -1,
     226,    -1,   225,    -1,    60,   217,    -1,    32,   123,   205,
     124,    -1,    23,   123,   205,   124,    -1,    62,   123,   205,
     124,    -1,    61,    62,   123,   205,   124,    -1,    10,   217,
      -1,    63,   217,    -1,    28,   217,    31,   217,    22,   217,
      -1,    28,   217,    31,   146,    22,   217,    -1,    28,   217,
      22,   217,    -1,    28,   217,    31,   217,    22,    30,   217,
      64,   217,    -1,    28,   217,    31,   146,    22,    30,   217,
      64,   217,    -1,    28,   217,    22,    30,   217,    64,   217,
      -1,    29,   217,    31,   217,    22,   217,    -1,    29,   217,
      31,   146,    22,   217,    -1,    29,   217,    22,   217,    -1,
      29,   217,    31,   217,    22,    30,   217,    64,   217,    -1,
      29,   217,    31,   146,    22,    30,   217,    64,   217,    -1,
      29,   217,    22,    30,   217,    64,   217,    -1,   125,   201,
     126,   217,    -1,   125,   201,    31,   217,   126,   217,    -1,
     125,   201,    31,   146,   126,   217,    -1,   125,   201,    31,
     217,   126,    30,   217,    64,   217,    -1,   125,   201,    31,
     146,   126,    30,   217,    64,   217,    -1,    30,   217,    64,
     217,    24,   217,    -1,    43,    -1,   212,    -1,   208,    -1,
     221,    -1,   220,    -1,   160,    -1,   215,    -1,   216,    -1,
     214,   120,   217,    -1,   218,    -1,   214,   120,   217,    -1,
      42,   217,    -1,    38,   190,    31,   217,    -1,   223,    -1,
     209,    -1,   210,    -1,   227,    -1,   228,    -1,   160,    -1,
     215,    -1,   216,    -1,   123,   100,   217,   124,    -1,   217,
      95,   217,    -1,   217,    99,   217,    -1,   217,    99,    -1,
      99,   217,    -1,    99,    -1,   208,    -1,   220,    -1,   221,
      -1,   222,    -1,   218,    -1,   160,    -1,   219,   123,   205,
     124,    -1,   219,   125,   205,   126,    -1,    50,   123,   205,
     124,    -1,   217,    98,   140,    -1,   217,    98,    65,    -1,
     217,    98,    23,    -1,   123,   203,   124,    -1,     5,    -1,
       6,    -1,     4,    -1,     7,    -1,   121,   201,   122,    -1,
     125,   201,   126,    -1,   125,   224,   126,    -1,   217,    75,
     217,    -1,   224,    96,   217,    75,   217,    -1,   217,   113,
     217,    -1,   217,   108,   217,    -1,   217,   118,   217,    -1,
     217,    97,   217,    -1,   217,   116,   217,    -1,   217,   117,
     217,    -1,   217,   109,   217,    -1,   217,   101,   217,    -1,
     217,   111,   217,    -1,   217,   107,   217,    -1,   217,   104,
     217,    -1,   217,   106,   217,    -1,   217,   103,   217,    -1,
     217,    91,   217,    -1,   217,    93,   217,    -1,   217,    94,
     217,    -1,   217,    76,   217,    -1,   217,   112,   217,    -1,
     217,   102,   217,    -1,   217,    13,   217,    -1,   217,     9,
     217,    -1,   217,   105,   217,    -1,   217,    21,   217,    -1,
     113,   217,    -1,   108,   217,    -1,    40,   217,    -1,    48,
     217,    -1,   110,   217,    -1,    92,   217,    -1,   217,    54,
     217,    -1,   217,    54,   146,    -1,   229,    54,   217,    -1,
     229,    54,   146,    -1,   217,    57,   217,    -1,   217,    57,
     146,    -1,   229,    57,   217,    -1,   229,    57,   146,    -1,
     113,    -1,   118,    -1,    76,    -1,   112,    -1,    91,    -1,
      93,    -1,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   190,   191,   196,   197,   202,   203,   208,
     209,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   267,   268,   272,   273,   277,   281,   282,   286,   287,
     291,   292,   293,   294,   295,   296,   300,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   335,   341,   351,   355,   356,   357,   358,   362,
     367,   368,   372,   374,   379,   386,   392,   393,   397,   399,
     401,   405,   406,   411,   412,   414,   419,   429,   436,   440,
     448,   449,   454,   459,   453,   484,   485,   487,   489,   491,
     493,   498,   504,   497,   534,   543,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   600,   601,   605,   609,   610,   611,
     615,   617,   619,   621,   626,   627,   628,   629,   630,   631,
     632,   633,   637,   638,   642,   643,   647,   648,   649,   650,
     651,   655,   656,   660,   661,   665,   667,   672,   673,   677,
     678,   682,   683,   687,   689,   694,   699,   701,   703,   708,
     715,   726,   727,   729,   734,   738,   742,   749,   750,   751,
     755,   756,   764,   766,   772,   777,   779,   781,   786,   788,
     790,   797,   798,   802,   803,   808,   809,   810,   811,   831,
     835,   839,   847,   851,   852,   853,   857,   859,   865,   867,
     869,   874,   875,   876,   877,   878,   879,   880,   886,   887,
     888,   889,   893,   894,   895,   899,   900,   901,   905,   906,
     910,   911,   915,   916,   920,   921,   922,   923,   924,   928,
     939,   940,   941,   942,   943,   944,   946,   948,   950,   952,
     954,   956,   961,   963,   965,   967,   969,   971,   973,   975,
     977,   979,   981,   983,   985,   992,   998,  1004,  1010,  1019,
    1024,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1044,
    1045,  1050,  1055,  1063,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1073,  1075,  1077,  1079,  1081,  1086,  1087,  1088,
    1089,  1100,  1101,  1105,  1106,  1107,  1111,  1112,  1113,  1120,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1137,  1138,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1175,  1176,  1177,  1178,  1179,  1180,  1184,  1185,
    1186,  1187,  1191,  1192,  1193,  1194,  1199,  1200,  1201,  1202,
    1203,  1204,  1205
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIDENT", "IMAGLITERAL", "INTLITERAL",
  "REALLITERAL", "STRINGLITERAL", "EXTERNCODE", "TALIGN", "TATOMIC",
  "TBEGIN", "TBREAK", "TBY", "TCLASS", "TCOBEGIN", "TCOFORALL", "TCONFIG",
  "TCONST", "TCONTINUE", "TDELETE", "TDMAPPED", "TDO", "TDOMAIN", "TELSE",
  "TENUM", "TEXPORT", "TEXTERN", "TFOR", "TFORALL", "TIF", "TIN", "TINDEX",
  "TINLINE", "TINOUT", "TITER", "TLABEL", "TLAMBDA", "TLET", "TLOCAL",
  "TMINUSMINUS", "TMODULE", "TNEW", "TNIL", "TON", "TOTHERWISE", "TOUT",
  "TPARAM", "TPLUSPLUS", "TPRAGMA", "TPRIMITIVE", "TPRIMITIVELOOP",
  "TPROC", "TRECORD", "TREDUCE", "TREF", "TRETURN", "TSCAN", "TSELECT",
  "TSERIAL", "TSINGLE", "TSPARSE", "TSUBDOMAIN", "TSYNC", "TTHEN", "TTYPE",
  "TUNDERSCORE", "TUNION", "TUSE", "TVAR", "TWHEN", "TWHERE", "TWHILE",
  "TYIELD", "TZIP", "TALIAS", "TAND", "TASSIGN", "TASSIGNBAND",
  "TASSIGNBOR", "TASSIGNBXOR", "TASSIGNDIVIDE", "TASSIGNEXP",
  "TASSIGNLAND", "TASSIGNLOR", "TASSIGNMINUS", "TASSIGNMOD",
  "TASSIGNMULTIPLY", "TASSIGNPLUS", "TASSIGNSL", "TASSIGNSR", "TBAND",
  "TBNOT", "TBOR", "TBXOR", "TCOLON", "TCOMMA", "TDIVIDE", "TDOT",
  "TDOTDOT", "TDOTDOTDOT", "TEQUAL", "TEXP", "TGREATER", "TGREATEREQUAL",
  "THASH", "TLESS", "TLESSEQUAL", "TMINUS", "TMOD", "TNOT", "TNOTEQUAL",
  "TOR", "TPLUS", "TQUESTION", "TSEMI", "TSHIFTLEFT", "TSHIFTRIGHT",
  "TSTAR", "TSWAP", "TIO", "TLCBR", "TRCBR", "TLP", "TRP", "TLSBR",
  "TRSBR", "TNOELSE", "TUMINUS", "TUPLUS", "$accept", "program",
  "toplevel_stmt_ls", "toplevel_stmt", "stmt_ls", "pragma_ls", "stmt",
  "assignment_stmt", "block_stmt", "opt_ident", "ident", "do_stmt",
  "return_stmt", "class_level_stmt", "extern_block_stmt", "loop_stmt",
  "zippered_iterator", "if_stmt", "select_stmt", "when_stmt_ls",
  "when_stmt", "type_select_stmt", "class_decl_stmt", "opt_extern",
  "class_tag", "opt_inherit", "class_level_stmt_ls", "enum_decl_stmt",
  "enum_ls", "enum_item", "lambda_decl_expr", "$@1", "$@2", "linkage_spec",
  "fn_decl_stmt", "$@3", "$@4", "fn_decl_stmt_inner", "fn_ident",
  "opt_formal_ls", "req_formal_ls", "formal_ls", "formal",
  "opt_intent_tag", "opt_this_intent_tag", "proc_or_iter", "opt_ret_tag",
  "opt_function_body_stmt", "function_body_stmt", "query_expr",
  "opt_query_expr", "var_arg_expr", "opt_where_part", "module_decl_stmt",
  "module", "type_alias_decl_stmt", "type_alias_decl_stmt_inner",
  "opt_init_type", "var_decl_stmt", "opt_config", "var_decl_stmt_inner_ls",
  "var_decl_stmt_inner", "tuple_var_decl_component",
  "tuple_var_decl_stmt_inner_ls", "opt_init_expr", "opt_reindex_expr",
  "opt_type", "array_type", "opt_formal_array_elt_type",
  "formal_array_type", "opt_formal_type", "expr_ls", "tuple_component",
  "tuple_guts", "tuple_expr_ls", "opt_actual_ls", "actual_ls",
  "actual_expr", "ident_expr", "type_level_expr", "for_expr", "cond_expr",
  "nil_expr", "stmt_level_expr", "io_expr", "new_expr", "let_expr", "expr",
  "lhs_expr", "fun_expr", "call_expr", "dot_expr", "parenthesized_expr",
  "literal_expr", "assoc_expr_ls", "binary_op_expr", "unary_op_expr",
  "reduce_expr", "scan_expr", "reduce_scan_op_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   130,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   141,   141,   142,   142,
     143,   143,   143,   143,   143,   143,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   147,   147,   147,   147,   148,
     149,   149,   150,   150,   151,   152,   153,   153,   154,   154,
     154,   155,   155,   156,   156,   156,   157,   158,   158,   158,
     159,   159,   161,   162,   160,   163,   163,   163,   163,   163,
     163,   165,   166,   164,   167,   167,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   169,   169,   170,   171,   171,   171,
     172,   172,   172,   172,   173,   173,   173,   173,   173,   173,
     173,   173,   174,   174,   175,   175,   176,   176,   176,   176,
     176,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     181,   182,   182,   183,   183,   184,   185,   185,   185,   186,
     186,   187,   187,   187,   188,   188,   188,   189,   189,   189,
     190,   190,   191,   191,   191,   192,   192,   192,   193,   193,
     193,   194,   194,   195,   195,   196,   196,   196,   196,   197,
     197,   197,   197,   198,   198,   198,   199,   199,   199,   199,
     199,   200,   200,   200,   200,   200,   200,   200,   201,   201,
     201,   201,   202,   202,   202,   203,   203,   203,   204,   204,
     205,   205,   206,   206,   207,   207,   207,   207,   207,   208,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   211,
     212,   213,   213,   213,   213,   213,   213,   213,   213,   214,
     214,   215,   216,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   218,   218,   218,
     218,   219,   219,   220,   220,   220,   221,   221,   221,   222,
     223,   223,   223,   223,   223,   223,   223,   224,   224,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   226,   226,   226,   226,   226,   226,   227,   227,
     227,   227,   228,   228,   228,   228,   229,   229,   229,   229,
     229,   229,   229
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     2,     3,     3,     3,     2,
       3,     3,     2,     3,     3,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     3,     0,     1,     1,     2,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     2,     5,     3,     5,
       5,     3,     5,     5,     5,     3,     3,     6,     5,     5,
       3,     6,     6,     4,     4,     4,     3,     6,     5,     5,
       0,     2,     3,     2,     6,     7,     0,     1,     1,     1,
       1,     0,     2,     0,     2,     3,     5,     1,     2,     3,
       1,     3,     0,     0,     8,     0,     1,     1,     2,     1,
       2,     0,     0,     9,     3,     5,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     3,     0,     1,     3,
       4,     4,     6,     6,     0,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     1,     2,
       2,     0,     2,     4,     5,     1,     3,     4,     4,     2,
       4,     0,     2,     2,     4,     4,     4,     0,     1,     1,
       1,     3,     3,     4,     5,     1,     1,     3,     1,     2,
       3,     0,     2,     0,     4,     0,     2,     2,     1,     4,
       4,     6,     1,     0,     1,     1,     3,     4,     3,     4,
       6,     0,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     2,     3,     1,     3,
       0,     1,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     5,
       2,     2,     6,     6,     4,     9,     9,     7,     6,     6,
       4,     9,     9,     7,     4,     6,     6,     9,     9,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     0,     1,    35,    55,   352,   350,   351,   353,
       0,     0,    53,     0,     0,   218,    53,     0,     0,     0,
       0,   117,    97,     0,     0,     0,     0,   116,     0,   112,
       0,     0,     0,   205,     0,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   398,   400,     0,   401,   402,   336,     0,     0,
     399,   396,    60,   397,     0,     0,     0,     4,     0,     5,
      11,    12,   279,    20,    13,    14,    17,    15,    18,    19,
      62,     0,    63,   328,     0,    61,    16,     0,    64,    65,
       0,   337,   324,   325,   282,   280,     0,     0,   329,   330,
       0,   281,     0,   338,   339,   340,   323,   284,   283,   326,
     327,     0,    22,   290,    23,     0,    54,     0,    25,     0,
       0,     0,     0,     0,     0,     0,   328,   337,   280,   329,
     330,     0,   281,   338,   339,     0,     0,     0,     0,   270,
       0,   118,    66,     0,   120,     0,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,     0,   220,    29,   384,
     321,     0,   385,     9,   270,   270,    58,     0,     0,     0,
     285,     0,   270,    32,   291,     0,   211,     0,   196,   259,
       0,   258,     0,     0,   387,   335,   383,   386,   382,    51,
       7,     0,     0,   262,     0,   264,   265,     0,   263,     0,
     258,     0,     0,     6,    98,    99,   100,     0,   185,   184,
     121,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   270,     0,     0,    24,     0,     0,     0,     0,     0,
       0,    57,    71,     0,    26,    27,     0,   279,   277,     0,
     271,   272,   278,     0,     0,     0,     0,    76,     0,     0,
      75,     0,     0,    80,     0,    86,     0,    28,   167,   113,
     225,     0,   226,   228,     0,   238,     0,     0,   231,     0,
       0,    30,     0,     0,    59,    90,    31,   270,     0,     0,
       0,   209,   206,   195,     0,    33,    68,    34,    52,     8,
     354,     0,   266,   349,     0,     0,     0,     0,   356,    10,
     101,   182,     0,     0,     0,     0,   318,   379,   378,   381,
     389,   388,   393,   392,   375,   372,   373,   374,   332,   362,
     348,   347,   346,   333,   366,   377,   371,   369,   380,   370,
     368,   360,   365,   367,   376,   359,   363,   364,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,   390,   395,   394,
       0,     0,     0,     0,     0,     0,   355,    56,     0,     0,
     207,     0,     0,     0,   287,     0,   110,     0,   107,   208,
       0,     0,     0,   294,     0,     0,     0,   300,     0,     0,
      85,     0,     0,   286,   178,   175,   176,   177,   179,   180,
     181,     0,   168,     0,   186,     0,   229,     0,   242,     0,
     237,   324,     0,     0,   222,   322,   221,   345,     0,     0,
       0,   288,    90,     0,   213,   324,     0,   261,   260,   331,
     268,   267,     0,     0,    83,   304,   357,     0,     0,     0,
     183,   122,     0,   203,     0,   215,   214,   216,    36,    43,
      44,    45,    40,    42,    49,    50,    38,    41,    39,    37,
      47,    46,    48,   343,   344,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    69,    67,   276,   274,   275,   273,
       0,   108,   106,     0,    84,     0,     0,    74,     0,    73,
       0,     0,    79,     0,    78,     0,     0,    88,   174,   166,
       0,   251,   187,   189,   190,   188,     0,   227,   230,     0,
     231,     0,   223,   232,    72,     0,     0,    89,    91,   289,
       0,     0,   210,     0,     0,     0,     0,   102,   103,   186,
     150,   148,   128,   157,   158,   159,   154,   156,   152,   155,
     153,   151,   161,   160,   129,   132,   130,   131,   142,   133,
     146,   138,   136,   149,   137,   135,   140,   145,   147,   134,
     139,   143,   144,   141,   162,   163,   126,   164,   204,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   109,    77,
       0,     0,   293,     0,   292,     0,     0,   299,     0,   298,
      87,   309,   169,     0,     0,   231,   201,   224,     0,     0,
      93,     0,    94,     0,   269,     0,    82,   306,     0,    81,
     305,   358,    96,     0,   127,     0,   167,   124,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,   303,
       0,     0,   251,   254,   255,   256,     0,   253,   257,   324,
     197,   171,   170,     0,     0,     0,   240,   324,    92,     0,
       0,    97,     0,    95,    96,   104,   201,   126,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   243,     0,   198,   200,   199,   202,   193,   194,   114,
       0,     0,     0,   105,     0,   125,   165,     0,     0,     0,
       0,     0,     0,   296,   295,   302,   301,   173,   172,   245,
     246,   248,   324,     0,   355,   324,   308,   307,   191,   123,
     192,     0,   247,   249,   243,   250
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   190,   191,    68,   430,    70,    71,   115,
      72,   272,    73,    74,    75,    76,   511,    77,    78,   459,
     558,    79,    80,    81,   207,   479,   652,    82,   417,   418,
     126,   153,   444,    84,    85,   341,   569,   481,   607,   657,
     299,   441,   442,   443,   482,   210,   546,   749,   719,   179,
     714,   681,   684,    86,    87,    88,   177,   321,    89,    90,
     156,   157,   303,   304,   454,   307,   308,   450,   740,   678,
     635,   192,   196,   197,   471,   279,   280,   281,   127,    92,
      93,    94,   128,    96,    97,   129,   130,   100,   132,   102,
     133,   134,   105,   106,   201,   107,   108,   109,   110,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -649
static const yytype_int16 yypact[] =
{
    -649,   121,  2043,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    3077,  3077,    76,   -96,  5495,    57,    76,  5495,  3077,    11,
      76,    76,   639,  4703,  5495,  5495,    12,  -649,    76,  -649,
       3,  3077,  5495,  -649,  5495,  -649,  5495,  5495,   133,    58,
     139,  4901,  5495,  5495,  5495,   201,   174,  3077,     9,  5000,
    5495,  5495,  -649,  -649,  5495,  -649,  -649,  6386,  5495,  5495,
    -649,  5495,  -649,  -649,  2339,  4604,  5000,  -649,  2954,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,    86,  -649,   142,   236,  -649,  -649,    76,  -649,  -649,
     149,   157,  -649,  -649,  -649,   176,   189,   185,   202,   203,
   10267,  1809,   -39,   213,   220,  -649,  -649,  -649,  -649,  -649,
    -649,   252,  -649, 10267,  -649,   221,  -649,  2462,  -649,  5495,
    5495,  5495,  5495,  5495,  5000,  5000,    69,  -649,  -649,  -649,
    -649,  6887,   170,  -649,  -649,    76,   228,  8122,   283,  5000,
     237,  -649,  -649,    76,  -649,    76,   240,     6,  6952,  7017,
    7082,  5000,  3077,   245,    14,    28,    50,  -649,  -649,   280,
     268,  7147,   280,  -649,  5000,  5000,  -649,  8187,  7862,  7147,
   10267,   246,  5000,  -649, 10267,  5000,   290,   255,    76,  -649,
      78, 10267,  7147,  8252,   259,  2093,   280,   259,   280,  -649,
    -649,  2585,    60,  -649,  5495,  -649,   275,   248, 10267,    22,
    8317,   -34,   366,  -649,  -649,  -649,  -649,    76,  -649,  -649,
    -649,   253,     3,     3,     3,  -649,  5495,  5495,  5495,  5495,
    5099,  5099,  5495,  5495,  5495,  5495,  5495,  5495,    93,  6386,
    5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,
    5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,
    5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,  5495,
    5000,  5000,  5099,  5099,  -649,  7992,  8057,  8382,    34,  3077,
    5099,  -649,  -649,   261,  -649,  -649,  5495,   287,  -649,   260,
     289,  -649, 10267,    76,   264,   355,  5000,  -649,  3200,  5099,
    -649,  3323,  5099,  -649,  3077,   363,   273,  -649,    43,  -649,
    -649,    14,  -649,   303,   277,  -649,  4307,   313,   329,  5495,
       3,  -649,   284,   291,  -649,  -649,  -649,  5000,   293,    79,
    4406,   311,  -649,  -649,  5000,  -649,  -649,  -649,  -649,  -649,
    -649,  6822,  4802,  -649,  5099,  2216,  5495,  5495,  -649,  -649,
     316,   367,  2708,    89,    90,   168,  7927,  1087,  1087,   250,
    -649,   250,  -649,   250, 10360, 10425, 10390,  1608,   268,   259,
    -649,  -649,  -649,  2093,  1637,   250,   476,   476,  1087,   476,
     476,   280,   259,  1637, 10332,   280,   648,   648,   259,  8447,
    8512,  8577,  8642,  8707,  8772,  8837,  8902,  8967,  9032,  9097,
    9162,  9227,  9292,  9357,   295,   294,  -649,   250,  -649,   250,
    5594,  5099,  5693,  5099,  5495,  5099,  6584,  -649,     6,  7147,
    -649,  9422,  5495,  5000,  -649,  5000,   336,    77,  -649,  -649,
    5495,   -58,  5495, 10267,    21,  7212,  5495, 10267,    36,  7277,
     398,  9487,  3077,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,    63,  -649,     8,   114,   299,    14,    56,  -649,  5000,
    -649,   244,  5495,  5495,  -649,  1087,  -649,  -649,     6,   -25,
     300,  -649,  -649,  5000,  -649,   172,    76,  -649, 10267,  -649,
    -649,   330,   301,  6561,  -649, 10267, 10267,  9552,  5000,   308,
    -649,  -649,  1906,  -649,  2831,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  5495,   403,  9617,  5495,   409,
    9682,   307,  6627,  -649,  -649,  -649, 10267,  -649, 10267,  -649,
    5495,    76,  -649,  7147,  -649,  7342,  3446,  -649,  3569,  -649,
    7407,  3692,  -649,  3815,  -649,  3077,  5495,  -649,   243,  -649,
      14,   339,  -649,  -649,  -649,  -649,     7,  -649,  -649,  4406,
     329,    42, 10267, 10267,  -649,  3077,  5000,  -649,  -649,  -649,
      23,    51,  -649,  4802,  3938,  4061,  5495,   340,  -649,   114,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,    76,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   337,   314,  -649,  9747,
    5792,  5891,  9812,  5990,  6089,  6188,  6287, 10267,  -649,  -649,
    3077,  5495, 10267,  5495, 10267,  3077,  5495, 10267,  5495, 10267,
    -649, 10267,  -649,   317,  5198,    95,   369,  -649,  5099,  1760,
    -649,    -1,  -649,  4184,  -649,  5495,  -649, 10267,  5495,  -649,
   10267, 10267,   444,     4,  -649,  1906,    43,  -649,  5495,  5495,
    5495,  5495,  5495,  5495,  5495,  5495,  9487,  7472,  7537,  9487,
    7602,  7667,   339,    11,  5495,  5495,  4505,  -649,  -649,   196,
    5000,  -649,  -649,  5495,    -4,  6692,  -649,   461,  -649,  7732,
    7797,   572,    76,  -649,   455,  -649,   369,  -649,   314,    74,
    9877,  9942, 10007, 10072, 10137, 10202,  3077,  3077,  3077,  3077,
      95,  5297,    54,  -649,  -649, 10267, 10267,  -649,  -649,  -649,
    6287,  3077,  3077,  -649,   -14,  -649,  -649,  5495,  5495,  5495,
    5495,  5495,  5495,  9487,  9487,  9487,  9487,  -649,  -649,  -649,
    -649,  -649,   304,  5099,  6485,   481,  9487,  9487,  -649,  -649,
    -649,  6757,  -649,  -649,  5396,  -649
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -649,  -649,  -649,     0,    96,  -206,  1416,  -649,   952,   432,
    1524,   -78,  -648,  -588,  -649,  -649,    49,  -649,  -649,   -13,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   -70,
     292,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -200,  -242,
    -649,  -199,   -80,  -649,  -649,  -649,  -110,  -649,  -264,   851,
    -649,  -247,  -231,  -649,  -649,  -649,  -134,  -649,  -649,  -649,
     -11,   156,  -649,  -282,  -547,  -649,  -397,  -310,  -566,  -575,
    -205,   -31,  -309,  -649,  -649,    25,  -649,    59,   504,  -290,
    -649,  -649,   612,  -649,  -649,   737,   804,   -10,   867,  -649,
     939,   965,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -356
static const yytype_int16 yytable[] =
{
     113,   273,    67,   637,   131,   305,     5,   137,   305,   284,
     464,     5,     5,   148,   149,   150,   451,     5,   180,   445,
     555,   269,   159,   470,   160,   117,   161,   162,   269,   305,
     465,   167,   168,   169,   170,   199,   718,   174,   324,   181,
     182,   183,    41,   526,   184,   556,  -174,   185,   186,   187,
     550,   188,    41,   334,   181,   198,   200,   305,   531,  -235,
    -235,   434,   337,  -235,   695,   405,   524,   175,   555,   287,
     290,   293,   147,   638,   435,  -235,   718,   436,  -235,     5,
     300,   309,   638,   311,   260,   743,   261,  -235,   682,   437,
     438,   316,   338,   556,   268,   324,     5,   557,   439,   549,
     204,   748,   549,  -233,   326,  -235,   723,   117,   440,   113,
     265,   266,   267,   174,   181,   200,   360,   117,   324,  -235,
     117,     3,   135,   306,  -235,  -235,   154,   117,  -235,   282,
     324,   540,   542,  -235,   139,   151,   741,   301,   324,   205,
     163,   282,   117,  -235,   319,   642,   310,   324,   335,   636,
     324,   549,  -235,   206,   282,   282,   324,   117,   361,   538,
     406,   543,   282,   738,   548,   181,  -174,   212,   639,   753,
     538,  -235,   453,   521,   324,   324,   296,   643,   752,   544,
     744,   164,   330,   545,   331,   310,   310,   539,   755,   312,
     313,   329,  -342,   325,  -342,   680,   213,   318,   726,   522,
     462,   343,   344,   345,   485,   486,   346,   347,   348,   349,
     351,   353,   354,   355,   356,   357,   358,   359,   214,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     282,   282,   397,   399,   644,   421,   696,  -315,   633,   451,
     409,   434,   165,   171,   310,  -342,   411,  -342,  -212,   350,
     352,   208,  -312,  -252,   435,  -236,   181,   436,   423,   425,
     219,   427,   429,   487,   431,   394,   395,  -212,   209,   437,
     438,  -311,  -252,  -341,    83,  -341,  -252,   172,   439,   455,
    -236,   219,    83,    83,   215,   216,   262,   282,   440,   263,
      83,   396,   398,   220,   468,  -236,   221,  -316,  -317,   408,
    -252,  -236,   198,    83,   473,   475,   476,   477,  -314,   686,
     513,   514,   562,   686,   220,  -313,   264,   221,   424,    83,
    -236,   428,   460,   274,   679,   226,   527,   529,   228,   687,
     532,   534,   231,   687,   226,   276,    83,   228,   283,  -236,
      83,   231,   412,   286,   413,  -236,   228,   320,   298,   317,
     322,   332,   333,   339,   342,   226,   410,   227,   228,   419,
     554,  -244,   231,   472,   414,   415,   420,   432,   452,   238,
     423,   507,   427,   510,   431,   512,   475,   433,   244,   446,
    -244,   447,   516,   518,  -244,   282,   453,   466,   457,    83,
     523,   478,   525,   520,   480,   458,   530,   461,   551,   503,
     504,   742,   535,   547,   559,   610,   563,   564,  -244,   568,
     745,   613,   561,   615,   634,   655,   324,   656,   484,   200,
     683,   672,   552,   553,    83,   619,   694,   567,   136,   560,
     506,   618,   509,   200,   742,   698,   725,   699,   632,   653,
     750,    15,  -217,   737,   742,   724,   456,   710,   181,    20,
      21,   691,    15,  -217,   519,     0,     0,    27,     0,  -115,
      20,    21,   691,    83,   329,     0,     0,     0,    27,     0,
    -115,  -217,  -239,    38,     0,   609,  -115,   219,   612,     0,
       0,     0,  -217,     0,   202,     0,    91,  -115,     0,   692,
     617,     0,  -241,  -217,    91,    91,   622,  -239,   624,     0,
     692,   627,    91,   629,  -217,   641,   631,     0,     0,     0,
     220,     0,  -239,   221,     0,    91,     0,  -241,  -239,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,    91,  -241,   198,   647,   650,   651,  -239,  -241,    62,
       0,    83,     0,   688,     0,     0,   693,     0,    91,     0,
      62,   226,    91,   227,   228,     5,  -239,  -241,   231,     0,
      83,     0,  -239,    83,   237,   238,    83,     0,     0,   241,
    -219,     0,   242,   243,   244,     0,  -241,     0,     0,     0,
     622,   624,  -241,   627,   629,   647,   650,  -119,     0,     0,
     666,   667,     0,   668,    95,   669,   670,     0,   671,  -219,
       0,    91,    95,    95,  -119,     0,     0,    83,   685,   475,
      95,     0,     0,   475,    83,   689,     0,   143,   690,     0,
       0,  -219,     5,    95,     0,   712,     0,   142,   666,   700,
     701,   669,   702,   703,   704,   705,    91,  -219,     0,    95,
       0,     0,     0,     0,   170,   174,   200,     0,     0,   219,
     715,     0,     0,   716,  -119,     0,    95,     0,     0,     0,
      95,     0,     0,     0,     0,     0,  -219,     0,     0,     0,
       0,  -119,     0,     0,     0,    91,   733,   734,   735,   736,
       0,     0,   220,     0,   143,   221,     0,     0,  -219,     0,
     650,   746,   747,     0,     0,     0,     0,   733,   734,   735,
     736,   746,   747,     0,    83,     0,     0,     0,     0,    95,
       0,     0,     0,   751,   475,     0,     0,     0,     0,    98,
       0,     0,     0,   226,   650,   227,   228,    98,    98,     0,
     231,     0,     0,     0,     0,    98,   237,   238,     0,     0,
       0,   241,     0,     0,    95,     0,   244,     0,    98,     0,
       0,     0,     0,    91,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    91,     0,     0,    91,     0,
       0,    98,     0,    95,     0,    98,    99,     0,     0,     0,
       0,     0,     0,     0,    99,    99,     0,     0,    83,     0,
      83,     0,    99,    83,     0,    83,     0,    83,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,    91,    83,     0,     0,
       0,    99,     0,     0,    98,     0,    83,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   101,
       0,     0,    99,     0,     0,     0,     0,   101,   101,     0,
       0,    95,     0,     0,     0,   101,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
      95,     0,     0,    95,     0,     0,    95,     0,     0,     0,
       0,     0,    83,     0,   101,     0,   195,    83,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,    98,     0,
       0,   101,     0,     0,     0,   101,    91,     0,     0,     0,
       0,   103,     0,     0,     0,     0,     0,    95,     0,   103,
     103,     0,     0,     0,    95,     0,    99,   103,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   104,     0,     0,
     103,     0,     0,     0,     0,   104,   104,     0,     0,     0,
       0,     0,     0,   104,   101,     0,   103,     0,    91,     0,
     278,     0,     0,     0,     0,    99,   104,     0,    83,    83,
      83,    83,   278,   103,     0,     0,    98,   103,     0,     0,
       0,     0,   104,    83,    83,   278,   278,     0,     0,   101,
       0,     0,     0,   278,     0,    98,     0,     0,    98,   104,
      91,    98,    91,   104,     0,    91,     0,    91,     0,    91,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,   101,    91,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    91,
       0,     0,    98,    99,     0,     0,     0,     0,     0,    98,
       0,     0,   104,   271,     0,     0,     0,     0,     0,     0,
       0,   103,    99,     0,     0,    99,    95,     0,    99,   271,
     271,   271,   295,     0,     0,     0,     0,     0,   219,     0,
       0,   278,   278,   271,     0,     0,     0,   104,     0,     0,
       0,   271,     0,     0,    91,     0,     0,     0,     0,    91,
     103,     0,     0,     0,   271,     0,   101,     0,    95,    99,
      95,   220,     0,    95,   221,    95,    99,    95,     0,     0,
       0,     0,     0,     0,     0,   101,   104,     0,   101,     0,
       0,   101,     0,   222,     0,     0,     0,    95,   278,    98,
       0,     0,     0,     0,     0,   467,    95,    95,   223,     0,
     224,   225,   226,   195,   227,   228,   229,     0,   230,   231,
     232,   233,     0,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   101,   242,   243,   244,     0,     0,   103,   101,
      91,    91,    91,    91,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,    91,    91,   103,     0,     0,
     103,     0,    95,   103,   104,     0,    99,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,   104,     0,     0,   104,
       0,     0,     0,    98,   517,    98,   278,     0,    98,     0,
      98,     0,    98,     0,   103,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,   101,
     104,    98,    98,     0,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    95,
      95,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,    99,    95,    95,    99,     0,    99,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,    98,     0,    99,
     271,   271,    98,     0,     0,     0,     0,     0,    99,    99,
       0,   103,     0,     0,     0,     0,   271,   271,     0,     0,
     271,   271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,   101,     0,   104,   101,     0,
     101,     0,   101,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   195,     0,     0,     0,    69,     0,
       0,     0,   101,   103,    99,     0,   112,   114,     0,    99,
       0,   101,   101,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    98,    98,    98,   158,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    98,
       0,     0,     0,   173,     0,   103,     0,   103,     0,     0,
     103,     0,   103,     0,   103,   271,     0,   295,     0,     0,
      69,     0,   295,     0,   203,   677,     0,   101,     0,     0,
       0,   104,   101,   104,   103,     0,   104,     0,   104,     0,
     104,     0,     0,   103,   103,     0,     0,     0,     0,     0,
      99,    99,    99,    99,     0,     0,     0,     0,     0,     0,
     104,     0,     0,     0,     0,    99,    99,     0,     0,   104,
     104,   713,     0,    69,     0,     0,   116,     0,     0,     0,
     116,     0,     0,     0,   140,   141,   144,     0,     0,     0,
       0,     0,   152,     0,   155,     0,     0,     0,     0,   103,
       0,     0,   739,     0,   103,     0,     0,     0,   297,     0,
       0,     0,   176,   101,   101,   101,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,   101,   101,
     104,     0,     0,   271,     0,   739,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   739,     0,    69,     0,     0,
       0,   211,     0,     0,     0,     0,     0,     0,     0,   295,
     295,     0,   295,   295,     0,     0,     0,     0,     0,   219,
       0,     0,     0,     0,     0,     0,   717,     0,     0,     0,
       0,   295,   295,     0,     0,   103,   103,   103,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   176,
     103,   103,   220,   277,     0,   221,     0,   176,     0,   285,
       0,   104,   104,   104,   104,   277,   717,     0,   302,     0,
       0,     0,     0,     0,     0,   407,   104,   104,   277,   277,
       0,   220,     0,     0,   221,     0,   277,     0,     0,   223,
       0,     0,   323,   226,   407,   227,   228,   407,     0,   230,
     231,   232,   233,     0,   235,   236,   237,   238,     0,   239,
       0,   241,     0,     0,   242,   243,   244,     0,     0,     0,
       0,   340,   226,     0,   227,   228,   155,   155,   155,   231,
     232,   233,     0,   235,   236,   237,   238,     0,     0,     0,
     241,   474,   362,   242,   243,   244,     0,     0,    69,     0,
       0,   448,     0,     5,     6,     7,     8,     9,     0,  -355,
     119,     0,     0,  -355,     0,     0,     0,     0,     0,     0,
       0,  -355,     0,    19,   277,   277,     0,     0,   120,   121,
     122,     0,    26,     0,     0,     0,     0,    29,    30,     0,
      32,     0,    34,    35,     0,     0,     0,   416,    37,     0,
      39,     0,     0,     0,  -355,     0,     0,  -355,     0,     0,
      44,    45,    46,   123,     0,   302,     0,     0,     0,     0,
       0,     0,     0,     0,   155,  -234,  -355,     0,     0,     0,
       0,   277,     0,     0,     0,     0,     0,     0,   537,     0,
       0,  -355,    54,  -355,  -355,  -355,     0,  -355,  -355,  -355,
       0,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,  -355,
      59,  -355,  -355,  -355,     0,     0,  -355,  -355,  -355,     0,
       0,   124,     0,    65,     0,   463,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,   570,     0,     0,     0,   571,
       0,     0,     0,     0,     0,     0,     0,     0,   259,  -319,
       0,     0,  -341,     0,  -341,     0,     0,     0,     0,   277,
       0,     0,   407,     0,   407,     0,     0,   407,     0,   407,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   541,     0,     0,
     302,   640,     0,     0,     0,     0,     0,     0,     0,     0,
     646,   649,     0,   572,   573,   574,   575,   576,   577,     0,
     176,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,     0,     0,   588,     0,     0,   606,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,     0,   600,
       0,     0,   601,   602,   603,   604,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -2,     4,   416,     5,     6,     7,     8,
       9,     0,     0,    10,    11,    12,     0,   -96,    13,    14,
      15,  -217,    16,    17,   302,    18,    19,     0,    20,    21,
      22,    23,    24,    25,     0,    26,    27,     0,  -115,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
    -217,    37,    38,    39,    40,  -115,   -96,     0,     0,    41,
       0,    42,    43,    44,    45,    46,    47,     0,    48,   654,
     -96,    49,  -217,     0,   219,    50,    51,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,     0,     0,     0,     0,   220,     0,     0,
     221,    58,     0,    59,     0,    60,    61,     0,    62,     0,
       0,    63,     0,     0,    64,     0,    65,     0,    66,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   697,
       0,     0,     0,     0,   223,     0,   224,   225,   226,     0,
     227,   228,     0,     0,   230,   231,   232,   233,     0,   235,
     236,   237,   238,     0,   239,   240,   241,     0,     0,   242,
     243,   244,     0,     0,     0,   144,   176,     4,     0,     5,
       6,     7,     8,     9,     0,  -355,    10,    11,    12,  -355,
     -96,    13,    14,    15,  -217,    16,    17,  -355,    18,    19,
    -355,    20,    21,    22,    23,    24,    25,     0,    26,    27,
       0,  -115,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,  -217,    37,     0,    39,    40,  -115,   -96,
    -355,     0,    41,  -355,    42,    43,    44,    45,    46,    47,
       0,    48,     0,   -96,    49,  -217,     0,     0,    50,    51,
       0,     0,  -355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -355,    54,  -355,
    -355,  -355,  -355,  -355,  -355,  -355,     0,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,  -355,  -355,    59,  -355,  -355,  -355,
       0,    62,  -355,  -355,  -355,     0,     0,    64,  -355,    65,
       4,    66,     5,     6,     7,     8,     9,     0,     0,    10,
      11,    12,     0,   -96,    13,    14,    15,  -217,    16,    17,
       0,    18,    19,     0,    20,    21,    22,    23,    24,    25,
       0,    26,    27,     0,  -115,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,  -217,    37,    38,    39,
      40,  -115,   -96,     0,     0,    41,     0,    42,    43,    44,
      45,    46,    47,     0,    48,     0,   -96,    49,  -217,     0,
       0,    50,    51,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    59,
       0,    60,    61,   178,    62,     0,     0,    63,     0,     0,
      64,   189,    65,     4,    66,     5,     6,     7,     8,     9,
       0,     0,    10,    11,    12,     0,   -96,    13,    14,    15,
    -217,    16,    17,     0,    18,    19,     0,    20,    21,    22,
      23,    24,    25,     0,    26,    27,     0,  -115,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,  -217,
      37,    38,    39,    40,  -115,   -96,     0,     0,    41,     0,
      42,    43,    44,    45,    46,    47,     0,    48,     0,   -96,
      49,  -217,     0,     0,    50,    51,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    59,     0,    60,    61,     0,    62,     0,     0,
      63,     0,     0,    64,   189,    65,     4,    66,     5,     6,
       7,     8,     9,     0,     0,    10,    11,    12,     0,   -96,
      13,    14,    15,  -217,    16,    17,     0,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,    26,    27,     0,
    -115,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,  -217,    37,    38,    39,    40,  -115,   -96,     0,
       0,    41,     0,    42,    43,    44,    45,    46,    47,     0,
      48,     0,   -96,    49,  -217,     0,     0,    50,    51,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    59,     0,    60,    61,     0,
      62,     0,     0,    63,     0,     0,    64,   328,    65,     4,
      66,     5,     6,     7,     8,     9,     0,     0,    10,    11,
      12,     0,   -96,    13,    14,    15,  -217,    16,    17,     0,
      18,    19,     0,    20,    21,    22,    23,    24,    25,     0,
      26,    27,     0,  -115,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,  -217,    37,    38,    39,    40,
    -115,   -96,     0,     0,    41,     0,    42,    43,    44,    45,
      46,    47,     0,    48,     0,   -96,    49,  -217,     0,     0,
      50,    51,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    59,     0,
      60,    61,     0,    62,     0,     0,    63,     0,     0,    64,
     483,    65,     4,    66,     5,     6,     7,     8,     9,     0,
       0,    10,    11,    12,     0,   -96,    13,    14,    15,  -217,
      16,    17,     0,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,    26,    27,     0,  -115,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,  -217,    37,
      38,    39,    40,  -115,   -96,     0,     0,    41,     0,    42,
      43,    44,    45,    46,    47,     0,    48,     0,   -96,    49,
    -217,     0,     0,    50,    51,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    59,     0,    60,    61,     0,    62,     0,     0,    63,
       0,     0,    64,   608,    65,     4,    66,     5,     6,     7,
       8,     9,     0,     0,    10,    11,    12,     0,   -96,    13,
      14,    15,  -217,    16,    17,     0,    18,    19,     0,    20,
      21,    22,    23,    24,    25,     0,    26,    27,     0,  -115,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,  -217,    37,   202,    39,    40,  -115,   -96,     0,     0,
      41,     0,    42,    43,    44,    45,    46,    47,     0,    48,
       0,   -96,    49,  -217,     0,     0,    50,    51,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    59,     0,    60,    61,     0,    62,
       0,     0,    63,     0,     0,    64,     0,    65,     4,    66,
       5,     6,     7,     8,     9,     0,     0,    10,    11,    12,
       0,   -96,    13,    14,    15,  -217,    16,    17,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,    26,
      27,     0,  -115,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,  -217,    37,     0,    39,    40,  -115,
     -96,     0,     0,    41,     0,    42,    43,    44,    45,    46,
      47,     0,    48,     0,   -96,    49,  -217,     0,     0,    50,
      51,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,    59,     0,    60,
      61,     0,    62,     0,     0,    63,     0,     0,    64,     0,
      65,     4,    66,     5,     6,     7,     8,     9,     0,     0,
      10,    11,    12,     0,   -96,    13,    14,    15,  -217,    16,
      17,     0,    18,    19,     0,    20,    21,    22,    23,    24,
     422,     0,    26,    27,     0,  -115,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,  -217,    37,     0,
      39,    40,  -115,   -96,     0,     0,    41,     0,    42,    43,
      44,    45,    46,    47,     0,    48,     0,   -96,    49,  -217,
       0,     0,    50,    51,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,     0,
      59,     0,    60,    61,     0,    62,     0,     0,    63,     0,
       0,    64,     0,    65,     4,    66,     5,     6,     7,     8,
       9,     0,     0,    10,    11,    12,     0,   -96,    13,    14,
      15,  -217,    16,    17,     0,    18,    19,     0,    20,    21,
      22,    23,    24,   426,     0,    26,    27,     0,  -115,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
    -217,    37,     0,    39,    40,  -115,   -96,     0,     0,    41,
       0,    42,    43,    44,    45,    46,    47,     0,    48,     0,
     -96,    49,  -217,     0,     0,    50,    51,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,    59,     0,    60,    61,     0,    62,     0,
       0,    63,     0,     0,    64,     0,    65,     4,    66,     5,
       6,     7,     8,     9,     0,     0,    10,    11,    12,     0,
     -96,    13,    14,    15,  -217,    16,    17,     0,    18,    19,
       0,    20,    21,    22,    23,    24,   621,     0,    26,    27,
       0,  -115,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,  -217,    37,     0,    39,    40,  -115,   -96,
       0,     0,    41,     0,    42,    43,    44,    45,    46,    47,
       0,    48,     0,   -96,    49,  -217,     0,     0,    50,    51,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    59,     0,    60,    61,
       0,    62,     0,     0,    63,     0,     0,    64,     0,    65,
       4,    66,     5,     6,     7,     8,     9,     0,     0,    10,
      11,    12,     0,   -96,    13,    14,    15,  -217,    16,    17,
       0,    18,    19,     0,    20,    21,    22,    23,    24,   623,
       0,    26,    27,     0,  -115,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,  -217,    37,     0,    39,
      40,  -115,   -96,     0,     0,    41,     0,    42,    43,    44,
      45,    46,    47,     0,    48,     0,   -96,    49,  -217,     0,
       0,    50,    51,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    59,
       0,    60,    61,     0,    62,     0,     0,    63,     0,     0,
      64,     0,    65,     4,    66,     5,     6,     7,     8,     9,
       0,     0,    10,    11,    12,     0,   -96,    13,    14,    15,
    -217,    16,    17,     0,    18,    19,     0,    20,    21,    22,
      23,    24,   626,     0,    26,    27,     0,  -115,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,  -217,
      37,     0,    39,    40,  -115,   -96,     0,     0,    41,     0,
      42,    43,    44,    45,    46,    47,     0,    48,     0,   -96,
      49,  -217,     0,     0,    50,    51,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    59,     0,    60,    61,     0,    62,     0,     0,
      63,     0,     0,    64,     0,    65,     4,    66,     5,     6,
       7,     8,     9,     0,     0,    10,    11,    12,     0,   -96,
      13,    14,    15,  -217,    16,    17,     0,    18,    19,     0,
      20,    21,    22,    23,    24,   628,     0,    26,    27,     0,
    -115,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,  -217,    37,     0,    39,    40,  -115,   -96,     0,
       0,    41,     0,    42,    43,    44,    45,    46,    47,     0,
      48,     0,   -96,    49,  -217,     0,     0,    50,    51,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,    59,     0,    60,    61,     0,
      62,     0,     0,    63,     0,     0,    64,     0,    65,     4,
      66,     5,     6,     7,     8,     9,     0,     0,    10,    11,
      12,     0,   -96,    13,    14,    15,  -217,    16,    17,     0,
      18,    19,     0,    20,    21,    22,    23,    24,   645,     0,
      26,    27,     0,  -115,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,  -217,    37,     0,    39,    40,
    -115,   -96,     0,     0,    41,     0,    42,    43,    44,    45,
      46,    47,     0,    48,     0,   -96,    49,  -217,     0,     0,
      50,    51,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    59,     0,
      60,    61,     0,    62,     0,     0,    63,     0,     0,    64,
       0,    65,     4,    66,     5,     6,     7,     8,     9,     0,
       0,    10,    11,    12,     0,   -96,    13,    14,    15,  -217,
      16,    17,     0,    18,    19,     0,    20,    21,    22,    23,
      24,   648,     0,    26,    27,     0,  -115,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,  -217,    37,
       0,    39,    40,  -115,   -96,     0,     0,    41,     0,    42,
      43,    44,    45,    46,    47,     0,    48,     0,   -96,    49,
    -217,     0,     0,    50,    51,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,    59,     0,    60,    61,     0,    62,     0,     0,    63,
       0,     0,    64,     0,    65,   448,    66,     5,     6,     7,
       8,     9,     0,  -355,   119,     0,     0,  -355,     0,     0,
       0,     0,     0,     0,     0,  -355,     0,    19,     0,     0,
       0,     0,   120,   121,   122,     0,    26,     0,     0,     0,
       0,    29,    30,     0,    32,     0,    34,    35,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,  -355,     0,
       0,  -355,     0,     0,    44,    45,    46,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -355,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -355,    54,  -355,  -355,  -355,
       0,  -355,  -355,  -355,     0,  -355,  -355,  -355,  -355,  -355,
    -355,  -355,  -355,  -355,    59,  -355,  -355,  -355,     0,     0,
    -355,  -355,  -355,     0,     0,   124,     0,    65,   448,   463,
       5,     6,     7,     8,     9,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,   120,   121,   122,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,    46,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,   448,     0,     5,
       6,     7,     8,     9,     0,    58,   119,    59,     0,    60,
      61,     0,     0,     0,     0,    63,     0,     0,   124,    19,
      65,     0,   449,     0,   120,   121,   122,     0,    26,     0,
       0,     0,     0,    29,    30,     0,    32,     0,    34,    35,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,     0,     0,     5,     6,
       7,     8,     9,     0,    58,   119,    59,     0,    60,    61,
       0,     0,     0,     0,    63,     0,     0,   124,    19,    65,
       0,   463,     0,   120,   121,   122,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,    46,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,     0,     0,     5,     6,     7,
       8,     9,     0,    58,   119,    59,     0,    60,    61,   178,
       0,     0,     0,    63,     0,     0,   124,    19,    65,     0,
     125,   711,   120,   121,   122,     0,    26,     0,     0,     0,
       0,    29,    30,     0,    32,     0,    34,    35,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,   123,     0,     0,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,     0,
       0,     0,     0,    57,   194,     0,     5,     6,     7,     8,
       9,     0,    58,   119,    59,     0,    60,    61,   178,     0,
       0,     0,    63,     0,     0,   124,    19,    65,     0,   125,
       0,   120,   121,   122,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
     145,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,    46,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,     0,     0,     5,     6,     7,     8,     9,
       0,    58,   119,    59,     0,    60,    61,     0,     0,     0,
       0,    63,     0,     0,   124,    19,    65,     0,   125,     0,
     120,   121,   122,     0,    26,     0,     0,     0,     0,    29,
      30,     0,    32,     0,    34,    35,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,    46,   123,     0,     0,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,     0,     0,     5,     6,     7,     8,     9,     0,
      58,   119,    59,     0,    60,    61,   178,     0,     0,     0,
      63,     0,     0,   124,    19,    65,     0,   125,     0,   120,
     121,   122,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,    46,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,     0,     0,     5,     6,     7,     8,     9,     0,    58,
     119,    59,     0,    60,    61,     0,   166,     0,     0,    63,
       0,     0,   124,    19,    65,     0,   125,     0,   120,   121,
     122,     0,    26,     0,     0,     0,     0,    29,    30,     0,
      32,     0,    34,    35,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,    46,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
       0,     0,     5,     6,     7,     8,     9,     0,    58,   119,
      59,     0,    60,    61,   178,     0,     0,     0,    63,     0,
       0,   124,    19,    65,     0,   125,     0,   120,   121,   122,
       0,    26,     0,     0,     0,     0,    29,    30,     0,    32,
       0,    34,    35,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,     0,     0,     0,     0,    57,     0,
       0,     5,     6,     7,     8,     9,     0,    58,   119,    59,
       0,    60,    61,     0,     0,     0,     0,    63,     0,     0,
     124,   673,    65,     0,   125,     0,   120,   121,   122,     0,
      26,     0,     0,     0,     0,    29,    30,     0,    32,     0,
      34,    35,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   674,    45,
      46,   675,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,     0,     0,
       5,     6,     7,     8,     9,     0,    58,   119,    59,     0,
      60,    61,   178,     0,     0,     0,    63,     0,     0,   124,
      19,    65,     0,   676,     0,   120,   121,   122,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,    46,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,     0,     0,     5,
       6,     7,     8,     9,     0,    58,   119,    59,     0,    60,
      61,   178,     0,     0,     0,    63,     0,     0,   124,    19,
      65,     0,   676,     0,   120,   121,   665,     0,    26,     0,
       0,     0,     0,    29,    30,     0,    32,     0,    34,    35,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,     0,     0,     0,     0,    57,     0,     0,     5,     6,
       7,     8,     9,     0,    58,   119,    59,     0,    60,    61,
     178,     0,     0,     0,    63,     0,     0,   124,    19,    65,
       0,   125,     0,   120,   121,   122,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,    46,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,    54,    55,    56,
       0,     0,     0,     0,    57,     0,     0,     5,     6,     7,
       8,     9,     0,    58,   119,    59,     0,    60,    61,     0,
       0,     0,     0,    63,     0,     0,   124,    19,    65,     0,
     125,     0,   120,   121,   505,     0,    26,     0,     0,     0,
       0,    29,    30,     0,    32,     0,    34,    35,     0,     0,
       0,     0,    37,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    55,    56,     0,
       0,     0,     0,    57,     0,     0,     5,     6,     7,     8,
       9,     0,    58,   119,    59,     0,    60,    61,     0,     0,
       0,     0,    63,     0,     0,   124,    19,    65,     0,   125,
       0,   120,   121,   508,     0,    26,     0,     0,     0,     0,
      29,    30,     0,    32,     0,    34,    35,     0,     0,     0,
       0,    37,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,    46,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54,    55,    56,     0,     0,
       0,     0,    57,     0,     0,     5,     6,     7,     8,     9,
       0,    58,   119,    59,     0,    60,    61,     0,     0,     0,
       0,    63,     0,     0,   124,    19,    65,     0,   125,     0,
     120,   121,   659,     0,    26,     0,     0,     0,     0,    29,
      30,     0,    32,     0,    34,    35,     0,     0,     0,     0,
      37,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,    46,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,     0,     0,     0,
       0,    57,     0,     0,     5,     6,     7,     8,     9,     0,
      58,   119,    59,     0,    60,    61,     0,     0,     0,     0,
      63,     0,     0,   124,    19,    65,     0,   125,     0,   120,
     121,   660,     0,    26,     0,     0,     0,     0,    29,    30,
       0,    32,     0,    34,    35,     0,     0,     0,     0,    37,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,    46,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,     0,     0,     0,     0,
      57,     0,     0,     5,     6,     7,     8,     9,     0,    58,
     119,    59,     0,    60,    61,     0,     0,     0,     0,    63,
       0,     0,   124,    19,    65,     0,   125,     0,   120,   121,
     662,     0,    26,     0,     0,     0,     0,    29,    30,     0,
      32,     0,    34,    35,     0,     0,     0,     0,    37,     0,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,    46,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,     0,     0,     0,     0,    57,
       0,     0,     5,     6,     7,     8,     9,     0,    58,   119,
      59,     0,    60,    61,     0,     0,     0,     0,    63,     0,
       0,   124,    19,    65,     0,   125,     0,   120,   121,   663,
       0,    26,     0,     0,     0,     0,    29,    30,     0,    32,
       0,    34,    35,     0,     0,     0,     0,    37,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,     0,     0,     0,     0,    57,     0,
       0,     5,     6,     7,     8,     9,     0,    58,   119,    59,
       0,    60,    61,     0,     0,     0,     0,    63,     0,     0,
     124,    19,    65,     0,   125,     0,   120,   121,   664,     0,
      26,     0,     0,     0,     0,    29,    30,     0,    32,     0,
      34,    35,     0,     0,     0,     0,    37,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    45,
      46,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,     0,    57,     0,     0,
       5,     6,     7,     8,     9,     0,    58,   119,    59,     0,
      60,    61,     0,     0,     0,     0,    63,     0,     0,   124,
      19,    65,     0,   125,     0,   120,   121,   665,     0,    26,
       0,     0,     0,     0,    29,    30,     0,    32,     0,    34,
      35,     0,     0,     0,     0,    37,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,    46,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,     0,     0,     0,     0,    57,     0,     0,     5,
       6,     7,     8,     9,     0,    58,   119,    59,     0,    60,
      61,     0,     0,     0,     0,    63,     0,     0,   124,    19,
      65,     0,   125,     0,   120,   121,   122,     0,    26,     0,
       0,     0,     0,    29,    30,     0,    32,     0,    34,    35,
       0,     0,     0,     0,    37,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,     0,    58,   119,    59,     0,    60,    61,
       0,     0,     0,     0,    63,     0,     0,   124,    19,    65,
       0,   125,     0,   120,   121,   122,     0,    26,     0,     0,
       0,     0,    29,    30,     0,    32,     0,    34,    35,     0,
       0,     0,     0,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,    46,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -243,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,     0,   218,     0,     0,    54,     0,     0,
       0,  -243,   219,     0,     0,  -243,     0,     5,     6,     7,
       8,     9,     0,     0,   119,    59,     0,     0,     0,   178,
       0,     0,     0,     0,     0,     0,   124,    19,    65,  -243,
     676,     0,   120,   121,   122,   220,    26,     0,   221,     0,
       0,    29,    30,     0,    32,     0,    34,    35,     0,     0,
       0,     0,    37,     0,    39,     0,   217,   222,     0,     0,
     218,     0,     0,     0,    44,    45,    46,   123,   219,     0,
       0,     0,   223,     0,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     0,   239,   240,   241,     0,    54,   242,   243,   244,
       0,   220,     0,     0,   221,     0,     0,   565,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,    65,     0,   125,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,   720,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,   269,
       0,     0,     0,   223,     0,   224,   225,   226,   270,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,   288,     0,     0,     0,   223,     0,
     224,   225,   226,   289,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,   291,
       0,     0,     0,   223,     0,   224,   225,   226,   292,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,   269,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,   528,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,   533,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,   625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,   706,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,   707,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,   708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,   709,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,   721,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   117,   221,     0,     0,     0,     0,     0,
       0,   722,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,   117,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,   315,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,   400,     0,     0,     0,   223,     0,
     224,   225,   226,   401,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,  -320,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,   402,
       0,     0,     0,   223,     0,   224,   225,   226,   403,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   275,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   314,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   327,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   336,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,   404,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   488,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   489,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   490,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   491,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   492,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   493,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   494,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   495,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   496,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   497,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   498,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   499,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   500,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   501,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,   502,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,   536,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,   515,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   566,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,   611,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,   614,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,   658,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,   661,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,   727,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,   728,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,   729,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,   730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,   731,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,   222,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,     0,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,   732,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   222,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,   229,     0,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   241,     0,     0,   242,   243,
     244,   220,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,     0,   223,     0,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     241,   219,     0,   242,   243,   244,   220,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,   219,     0,     0,   220,     0,     0,   221,     0,     0,
       0,     0,     0,   223,     0,   224,   225,   226,     0,   227,
     228,     0,     0,   230,   231,   232,   233,     0,   235,   236,
     237,   238,     0,   239,   220,   241,   219,   221,   242,   243,
     244,   223,     0,   224,   225,   226,     0,   227,   228,     0,
       0,   230,   231,   232,   233,     0,   235,   236,   237,   238,
       0,   239,     0,   241,     0,     0,   242,   243,   244,   220,
       0,   223,   221,     0,   225,   226,     0,   227,   228,     0,
       0,   230,   231,   232,   233,     0,   235,   236,   237,   238,
       0,   239,     0,   241,     0,     0,   242,   243,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,     0,   227,   228,     0,     0,   230,   231,   232,   233,
       0,   235,   236,   237,   238,     0,   239,     0,   241,     0,
       0,   242,   243,   244
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-649))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      10,   135,     2,   550,    14,     1,     3,    17,     1,   143,
     320,     3,     3,    23,    24,    25,   306,     3,    49,   301,
      45,    22,    32,   332,    34,   121,    36,    37,    22,     1,
     320,    41,    42,    43,    44,    66,   684,    47,    96,    49,
      50,    51,    56,    22,    54,    70,     3,    57,    58,    59,
     447,    61,    56,    31,    64,    65,    66,     1,    22,    31,
      56,    18,    96,    56,   652,    31,   124,    58,    45,   147,
     148,   149,    23,    31,    31,    71,   724,    34,    71,     3,
      66,    31,    31,   161,   123,    31,   125,    31,   635,    46,
      47,   169,   126,    70,   125,    96,     3,   122,    55,    95,
      14,   115,    95,    75,   182,    77,   694,   121,    65,   119,
     120,   121,   122,   123,   124,   125,    23,   121,    96,   115,
     121,     0,    65,    95,    96,   121,   123,   121,   121,   139,
      96,   123,    18,    77,   123,   123,   711,   123,    96,    53,
       7,   151,   121,   115,   175,   122,    96,    96,   126,   546,
      96,    95,    96,    67,   164,   165,    96,   121,    65,    96,
     126,    47,   172,   710,   446,   175,   123,    18,   126,   744,
      96,   115,    77,    96,    96,    96,   151,   126,   744,    65,
     126,   123,   122,    69,   194,    96,    96,   124,   754,   164,
     165,   191,   123,   115,   125,   100,    47,   172,   124,   122,
     121,   212,   213,   214,   115,   115,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    69,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   563,   286,   653,   115,   540,   549,
     270,    18,   123,    62,    96,   123,   276,   125,    96,   220,
     221,    35,   115,    77,    31,    31,   286,    34,   288,   289,
      21,   291,   292,   115,   294,   260,   261,   115,    52,    46,
      47,   115,    96,   123,     2,   125,   100,   123,    55,   309,
      56,    21,    10,    11,   115,   120,    54,   317,    65,    57,
      18,   262,   263,    54,   324,    71,    57,   115,   115,   270,
     124,    77,   332,    31,   334,   335,   336,   337,   115,   639,
     408,   409,   466,   643,    54,   115,   115,    57,   289,    47,
      96,   292,   317,   115,   634,    95,   424,   425,    98,   639,
     428,   429,   102,   643,    95,    72,    64,    98,   121,   115,
      68,   102,    75,   123,    77,   121,    98,    77,   123,   123,
     115,    96,   124,     7,   121,    95,   115,    97,    98,   115,
     458,    77,   102,   334,   124,    96,    31,    24,    75,   109,
     400,   401,   402,   403,   404,   405,   406,   124,   118,    96,
      96,   124,   412,   413,   100,   415,    77,    96,   124,   117,
     420,    95,   422,    77,    47,   124,   426,   124,   449,   124,
     126,   711,    24,   124,   124,    22,    96,   126,   124,   121,
     720,    22,   463,   126,    95,    98,    96,   123,   342,   449,
      71,   124,   452,   453,   152,   523,   652,   478,    16,   462,
     401,   521,   403,   463,   744,   655,   698,   656,   538,   569,
     724,    17,    18,   710,   754,   696,   310,   672,   478,    25,
      26,    27,    17,    18,   415,    -1,    -1,    33,    -1,    35,
      25,    26,    27,   191,   484,    -1,    -1,    -1,    33,    -1,
      35,    47,    31,    49,    -1,   505,    52,    21,   508,    -1,
      -1,    -1,    47,    -1,    49,    -1,     2,    52,    -1,    65,
     520,    -1,    31,    69,    10,    11,   526,    56,   528,    -1,
      65,   531,    18,   533,    69,   556,   536,    -1,    -1,    -1,
      54,    -1,    71,    57,    -1,    31,    -1,    56,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    47,    71,   563,   564,   565,   566,    96,    77,   115,
      -1,   269,    -1,   641,    -1,    -1,   122,    -1,    64,    -1,
     115,    95,    68,    97,    98,     3,   115,    96,   102,    -1,
     288,    -1,   121,   291,   108,   109,   294,    -1,    -1,   113,
      18,    -1,   116,   117,   118,    -1,   115,    -1,    -1,    -1,
     610,   611,   121,   613,   614,   615,   616,    35,    -1,    -1,
     620,   621,    -1,   623,     2,   625,   626,    -1,   628,    47,
      -1,   117,    10,    11,    52,    -1,    -1,   335,   638,   639,
      18,    -1,    -1,   643,   342,   645,    -1,    65,   648,    -1,
      -1,    69,     3,    31,    -1,   676,    -1,     8,   658,   659,
     660,   661,   662,   663,   664,   665,   152,    18,    -1,    47,
      -1,    -1,    -1,    -1,   674,   675,   676,    -1,    -1,    21,
     680,    -1,    -1,   683,    35,    -1,    64,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,   191,   706,   707,   708,   709,
      -1,    -1,    54,    -1,    65,    57,    -1,    -1,    69,    -1,
     720,   721,   722,    -1,    -1,    -1,    -1,   727,   728,   729,
     730,   731,   732,    -1,   432,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   743,   744,    -1,    -1,    -1,    -1,     2,
      -1,    -1,    -1,    95,   754,    97,    98,    10,    11,    -1,
     102,    -1,    -1,    -1,    -1,    18,   108,   109,    -1,    -1,
      -1,   113,    -1,    -1,   152,    -1,   118,    -1,    31,    -1,
      -1,    -1,    -1,   269,    -1,    -1,   484,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   288,    -1,    -1,   291,    -1,    -1,   294,    -1,
      -1,    64,    -1,   191,    -1,    68,     2,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    -1,    -1,   526,    -1,
     528,    -1,    18,   531,    -1,   533,    -1,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,   335,
      -1,    -1,    -1,    -1,    -1,    -1,   342,   555,    -1,    -1,
      -1,    47,    -1,    -1,   117,    -1,   564,   565,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,     2,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    10,    11,    -1,
      -1,   269,    -1,    -1,    -1,    18,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
     288,    -1,    -1,   291,    -1,    -1,   294,    -1,    -1,    -1,
      -1,    -1,   620,    -1,    47,    -1,    65,   625,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    64,    -1,    -1,    -1,    68,   432,    -1,    -1,    -1,
      -1,     2,    -1,    -1,    -1,    -1,    -1,   335,    -1,    10,
      11,    -1,    -1,    -1,   342,    -1,   152,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,     2,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    18,   117,    -1,    47,    -1,   484,    -1,
     139,    -1,    -1,    -1,    -1,   191,    31,    -1,   706,   707,
     708,   709,   151,    64,    -1,    -1,   269,    68,    -1,    -1,
      -1,    -1,    47,   721,   722,   164,   165,    -1,    -1,   152,
      -1,    -1,    -1,   172,    -1,   288,    -1,    -1,   291,    64,
     526,   294,   528,    68,    -1,   531,    -1,   533,    -1,   535,
      -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,   191,   555,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,   565,
      -1,    -1,   335,   269,    -1,    -1,    -1,    -1,    -1,   342,
      -1,    -1,   117,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,   288,    -1,    -1,   291,   484,    -1,   294,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,   260,   261,   161,    -1,    -1,    -1,   152,    -1,    -1,
      -1,   169,    -1,    -1,   620,    -1,    -1,    -1,    -1,   625,
     191,    -1,    -1,    -1,   182,    -1,   269,    -1,   526,   335,
     528,    54,    -1,   531,    57,   533,   342,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,   191,    -1,   291,    -1,
      -1,   294,    -1,    76,    -1,    -1,    -1,   555,   317,   432,
      -1,    -1,    -1,    -1,    -1,   324,   564,   565,    91,    -1,
      93,    94,    95,   332,    97,    98,    99,    -1,   101,   102,
     103,   104,    -1,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   335,   116,   117,   118,    -1,    -1,   269,   342,
     706,   707,   708,   709,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,    -1,   721,   722,   288,    -1,    -1,
     291,    -1,   620,   294,   269,    -1,   432,   625,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,    -1,    -1,   291,    -1,    -1,   294,
      -1,    -1,    -1,   526,   413,   528,   415,    -1,   531,    -1,
     533,    -1,   535,    -1,   335,    -1,    -1,    -1,    -1,    -1,
      -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,   484,    -1,
      -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,   432,
     335,   564,   565,    -1,    -1,    -1,    -1,   342,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   706,   707,
     708,   709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,   528,   721,   722,   531,    -1,   533,    -1,   535,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,    -1,    -1,    -1,   620,    -1,   555,
     408,   409,   625,    -1,    -1,    -1,    -1,    -1,   564,   565,
      -1,   432,    -1,    -1,    -1,    -1,   424,   425,    -1,    -1,
     428,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   526,    -1,   528,    -1,   432,   531,    -1,
     533,    -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,    -1,    -1,    -1,   563,    -1,    -1,    -1,     2,    -1,
      -1,    -1,   555,   484,   620,    -1,    10,    11,    -1,   625,
      -1,   564,   565,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   706,   707,   708,   709,    31,    -1,   484,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,   722,
      -1,    -1,    -1,    47,    -1,   526,    -1,   528,    -1,    -1,
     531,    -1,   533,    -1,   535,   523,    -1,   525,    -1,    -1,
      64,    -1,   530,    -1,    68,   634,    -1,   620,    -1,    -1,
      -1,   526,   625,   528,   555,    -1,   531,    -1,   533,    -1,
     535,    -1,    -1,   564,   565,    -1,    -1,    -1,    -1,    -1,
     706,   707,   708,   709,    -1,    -1,    -1,    -1,    -1,    -1,
     555,    -1,    -1,    -1,    -1,   721,   722,    -1,    -1,   564,
     565,   680,    -1,   117,    -1,    -1,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,   620,
      -1,    -1,   711,    -1,   625,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    48,   706,   707,   708,   709,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   620,    -1,    -1,   721,   722,
     625,    -1,    -1,   641,    -1,   744,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   754,    -1,   191,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   667,
     668,    -1,   670,   671,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,    -1,    -1,
      -1,   689,   690,    -1,    -1,   706,   707,   708,   709,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,   135,
     721,   722,    54,   139,    -1,    57,    -1,   143,    -1,   145,
      -1,   706,   707,   708,   709,   151,   724,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   721,   722,   164,   165,
      -1,    54,    -1,    -1,    57,    -1,   172,    -1,    -1,    91,
      -1,    -1,   178,    95,   288,    97,    98,   291,    -1,   101,
     102,   103,   104,    -1,   106,   107,   108,   109,    -1,   111,
      -1,   113,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,
      -1,   207,    95,    -1,    97,    98,   212,   213,   214,   102,
     103,   104,    -1,   106,   107,   108,   109,    -1,    -1,    -1,
     113,   335,   228,   116,   117,   118,    -1,    -1,   342,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    23,   260,   261,    -1,    -1,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,   283,    48,    -1,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,
      60,    61,    62,    63,    -1,   301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   310,    75,    76,    -1,    -1,    -1,
      -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,
      -1,    91,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,   117,   118,    -1,
      -1,   121,    -1,   123,    -1,   125,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,   415,
      -1,    -1,   526,    -1,   528,    -1,    -1,   531,    -1,   533,
      -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
     446,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,   565,    -1,    77,    78,    79,    80,    81,    82,    -1,
     466,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    -1,    -1,   482,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,   113,
      -1,    -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,   521,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,   540,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    -1,    65,   585,
      67,    68,    69,    -1,    21,    72,    73,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      57,   108,    -1,   110,    -1,   112,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,   121,    -1,   123,    -1,   125,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   655,
      -1,    -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,
      97,    98,    -1,    -1,   101,   102,   103,   104,    -1,   106,
     107,   108,   109,    -1,   111,   112,   113,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,   691,   692,     1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    65,    -1,    67,    68,    69,    -1,    -1,    72,    73,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,   115,   116,   117,   118,    -1,    -1,   121,   122,   123,
       1,   125,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    -1,    65,    -1,    67,    68,    69,    -1,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,   115,    -1,    -1,   118,    -1,    -1,
     121,   122,   123,     1,   125,     3,     4,     5,     6,     7,
      -1,    -1,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    -1,    65,    -1,    67,
      68,    69,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,    -1,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,   121,   122,   123,     1,   125,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    -1,
      65,    -1,    67,    68,    69,    -1,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,    -1,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,   121,   122,   123,     1,
     125,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    -1,    65,    -1,    67,    68,    69,    -1,    -1,
      72,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,
     122,   123,     1,   125,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    -1,    65,    -1,    67,    68,
      69,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,    -1,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,   121,   122,   123,     1,   125,     3,     4,     5,
       6,     7,    -1,    -1,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      56,    -1,    58,    59,    60,    61,    62,    63,    -1,    65,
      -1,    67,    68,    69,    -1,    -1,    72,    73,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,    -1,   112,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,   121,    -1,   123,     1,   125,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    -1,    50,    51,    52,
      53,    -1,    -1,    56,    -1,    58,    59,    60,    61,    62,
      63,    -1,    65,    -1,    67,    68,    69,    -1,    -1,    72,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,
     123,     1,   125,     3,     4,     5,     6,     7,    -1,    -1,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    -1,    65,    -1,    67,    68,    69,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     110,    -1,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,   121,    -1,   123,     1,   125,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    58,    59,    60,    61,    62,    63,    -1,    65,    -1,
      67,    68,    69,    -1,    -1,    72,    73,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,   110,    -1,   112,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,   121,    -1,   123,     1,   125,     3,
       4,     5,     6,     7,    -1,    -1,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    58,    59,    60,    61,    62,    63,
      -1,    65,    -1,    67,    68,    69,    -1,    -1,    72,    73,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,   123,
       1,   125,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    58,    59,    60,
      61,    62,    63,    -1,    65,    -1,    67,    68,    69,    -1,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
     121,    -1,   123,     1,   125,     3,     4,     5,     6,     7,
      -1,    -1,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      48,    -1,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    -1,    65,    -1,    67,
      68,    69,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,    -1,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,   121,    -1,   123,     1,   125,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    -1,
      65,    -1,    67,    68,    69,    -1,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,    -1,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,   121,    -1,   123,     1,
     125,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    -1,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    -1,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    58,    59,    60,    61,
      62,    63,    -1,    65,    -1,    67,    68,    69,    -1,    -1,
      72,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,   121,
      -1,   123,     1,   125,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    50,    51,    52,    53,    -1,    -1,    56,    -1,    58,
      59,    60,    61,    62,    63,    -1,    65,    -1,    67,    68,
      69,    -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,    -1,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,   121,    -1,   123,     1,   125,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
     116,   117,   118,    -1,    -1,   121,    -1,   123,     1,   125,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    99,     1,    -1,     3,
       4,     5,     6,     7,    -1,   108,    10,   110,    -1,   112,
     113,    -1,    -1,    -1,    -1,   118,    -1,    -1,   121,    23,
     123,    -1,   125,    -1,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    99,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   108,    10,   110,    -1,   112,   113,
      -1,    -1,    -1,    -1,   118,    -1,    -1,   121,    23,   123,
      -1,   125,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,    -1,    -1,     3,     4,     5,
       6,     7,    -1,   108,    10,   110,    -1,   112,   113,   114,
      -1,    -1,    -1,   118,    -1,    -1,   121,    23,   123,    -1,
     125,   126,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,
      -1,    -1,    -1,    99,   100,    -1,     3,     4,     5,     6,
       7,    -1,   108,    10,   110,    -1,   112,   113,   114,    -1,
      -1,    -1,   118,    -1,    -1,   121,    23,   123,    -1,   125,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,     3,     4,     5,     6,     7,
      -1,   108,    10,   110,    -1,   112,   113,    -1,    -1,    -1,
      -1,   118,    -1,    -1,   121,    23,   123,    -1,   125,    -1,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     108,    10,   110,    -1,   112,   113,   114,    -1,    -1,    -1,
     118,    -1,    -1,   121,    23,   123,    -1,   125,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,     3,     4,     5,     6,     7,    -1,   108,
      10,   110,    -1,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,   121,    23,   123,    -1,   125,    -1,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,     3,     4,     5,     6,     7,    -1,   108,    10,
     110,    -1,   112,   113,   114,    -1,    -1,    -1,   118,    -1,
      -1,   121,    23,   123,    -1,   125,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,
      -1,     3,     4,     5,     6,     7,    -1,   108,    10,   110,
      -1,   112,   113,    -1,    -1,    -1,    -1,   118,    -1,    -1,
     121,    23,   123,    -1,   125,    -1,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   108,    10,   110,    -1,
     112,   113,   114,    -1,    -1,    -1,   118,    -1,    -1,   121,
      23,   123,    -1,   125,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,     3,
       4,     5,     6,     7,    -1,   108,    10,   110,    -1,   112,
     113,   114,    -1,    -1,    -1,   118,    -1,    -1,   121,    23,
     123,    -1,   125,    -1,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    99,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   108,    10,   110,    -1,   112,   113,
     114,    -1,    -1,    -1,   118,    -1,    -1,   121,    23,   123,
      -1,   125,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    99,    -1,    -1,     3,     4,     5,
       6,     7,    -1,   108,    10,   110,    -1,   112,   113,    -1,
      -1,    -1,    -1,   118,    -1,    -1,   121,    23,   123,    -1,
     125,    -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,
      -1,    -1,    -1,    99,    -1,    -1,     3,     4,     5,     6,
       7,    -1,   108,    10,   110,    -1,   112,   113,    -1,    -1,
      -1,    -1,   118,    -1,    -1,   121,    23,   123,    -1,   125,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,     3,     4,     5,     6,     7,
      -1,   108,    10,   110,    -1,   112,   113,    -1,    -1,    -1,
      -1,   118,    -1,    -1,   121,    23,   123,    -1,   125,    -1,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,
      -1,    99,    -1,    -1,     3,     4,     5,     6,     7,    -1,
     108,    10,   110,    -1,   112,   113,    -1,    -1,    -1,    -1,
     118,    -1,    -1,   121,    23,   123,    -1,   125,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,
      99,    -1,    -1,     3,     4,     5,     6,     7,    -1,   108,
      10,   110,    -1,   112,   113,    -1,    -1,    -1,    -1,   118,
      -1,    -1,   121,    23,   123,    -1,   125,    -1,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,
      -1,    -1,     3,     4,     5,     6,     7,    -1,   108,    10,
     110,    -1,   112,   113,    -1,    -1,    -1,    -1,   118,    -1,
      -1,   121,    23,   123,    -1,   125,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,
      -1,     3,     4,     5,     6,     7,    -1,   108,    10,   110,
      -1,   112,   113,    -1,    -1,    -1,    -1,   118,    -1,    -1,
     121,    23,   123,    -1,   125,    -1,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   108,    10,   110,    -1,
     112,   113,    -1,    -1,    -1,    -1,   118,    -1,    -1,   121,
      23,   123,    -1,   125,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    99,    -1,    -1,     3,
       4,     5,     6,     7,    -1,   108,    10,   110,    -1,   112,
     113,    -1,    -1,    -1,    -1,   118,    -1,    -1,   121,    23,
     123,    -1,   125,    -1,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   108,    10,   110,    -1,   112,   113,
      -1,    -1,    -1,    -1,   118,    -1,    -1,   121,    23,   123,
      -1,   125,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    13,    -1,    -1,    92,    -1,    -1,
      -1,    96,    21,    -1,    -1,   100,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    10,   110,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    23,   123,   124,
     125,    -1,    28,    29,    30,    54,    32,    -1,    57,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,     9,    76,    -1,    -1,
      13,    -1,    -1,    -1,    60,    61,    62,    63,    21,    -1,
      -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,    98,
      99,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    -1,   111,   112,   113,    -1,    92,   116,   117,   118,
      -1,    54,    -1,    -1,    57,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,   123,    -1,   125,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    31,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    31,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    31,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,   121,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,   121,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    31,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,   120,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    31,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    75,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,   115,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    24,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,   115,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    75,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    76,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    76,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,   112,   113,    -1,    -1,   116,   117,
     118,    54,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,    -1,   111,   112,
     113,    21,    -1,   116,   117,   118,    54,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    21,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    97,
      98,    -1,    -1,   101,   102,   103,   104,    -1,   106,   107,
     108,   109,    -1,   111,    54,   113,    21,    57,   116,   117,
     118,    91,    -1,    93,    94,    95,    -1,    97,    98,    -1,
      -1,   101,   102,   103,   104,    -1,   106,   107,   108,   109,
      -1,   111,    -1,   113,    -1,    -1,   116,   117,   118,    54,
      -1,    91,    57,    -1,    94,    95,    -1,    97,    98,    -1,
      -1,   101,   102,   103,   104,    -1,   106,   107,   108,   109,
      -1,   111,    -1,   113,    -1,    -1,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    97,    98,    -1,    -1,   101,   102,   103,   104,
      -1,   106,   107,   108,   109,    -1,   111,    -1,   113,    -1,
      -1,   116,   117,   118
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   131,   132,     0,     1,     3,     4,     5,     6,     7,
      10,    11,    12,    15,    16,    17,    19,    20,    22,    23,
      25,    26,    27,    28,    29,    30,    32,    33,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    48,    49,    50,
      51,    56,    58,    59,    60,    61,    62,    63,    65,    68,
      72,    73,    76,    91,    92,    93,    94,    99,   108,   110,
     112,   113,   115,   118,   121,   123,   125,   133,   135,   136,
     137,   138,   140,   142,   143,   144,   145,   147,   148,   151,
     152,   153,   157,   160,   163,   164,   183,   184,   185,   188,
     189,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   225,   226,   227,
     228,   229,   136,   217,   136,   139,   140,   121,   138,    10,
      28,    29,    30,    63,   121,   125,   160,   208,   212,   215,
     216,   217,   218,   220,   221,    65,   139,   217,   136,   123,
     140,   140,     8,    65,   140,    47,    74,   146,   217,   217,
     217,   123,   140,   161,   123,   140,   190,   191,   136,   217,
     217,   217,   217,     7,   123,   123,   115,   217,   217,   217,
     217,    62,   123,   136,   217,    58,   140,   186,   114,   179,
     201,   217,   217,   217,   217,   217,   217,   217,   217,   122,
     133,   134,   201,    66,   100,   179,   202,   203,   217,   201,
     217,   224,    49,   136,    14,    53,    67,   154,    35,    52,
     175,   140,    18,    47,    69,   115,   120,     9,    13,    21,
      54,    57,    76,    91,    93,    94,    95,    97,    98,    99,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   111,
     112,   113,   116,   117,   118,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   119,
     123,   125,    54,    57,   115,   217,   217,   217,   201,    22,
      31,   138,   141,   186,   115,   115,    72,   140,   179,   205,
     206,   207,   217,   121,   186,   140,   123,   141,    22,    31,
     141,    22,    31,   141,    64,   138,   205,   136,   123,   170,
      66,   123,   140,   192,   193,     1,    95,   195,   196,    31,
      96,   141,   205,   205,   115,   121,   141,   123,   205,   201,
      77,   187,   115,   140,    96,   115,   141,   115,   122,   133,
     122,   217,    96,   124,    31,   126,    75,    96,   126,     7,
     140,   165,   121,   190,   190,   190,   217,   217,   217,   217,
     146,   217,   146,   217,   217,   217,   217,   217,   217,   217,
      23,    65,   140,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   205,   205,   146,   217,   146,   217,
      22,    31,    22,    31,    64,    31,   126,   136,   146,   217,
     115,   217,    75,    77,   124,    96,   140,   158,   159,   115,
      31,   201,    30,   217,   146,   217,    30,   217,   146,   217,
     136,   217,    24,   124,    18,    31,    34,    46,    47,    55,
      65,   171,   172,   173,   162,   193,    96,   124,     1,   125,
     197,   209,    75,    77,   194,   217,   191,   124,   124,   149,
     205,   124,   121,   125,   197,   209,    96,   179,   217,   124,
     202,   204,   146,   217,   136,   217,   217,   217,    95,   155,
      47,   167,   174,   122,   134,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   124,   126,    30,   146,   217,    30,   146,
     217,   146,   217,   141,   141,   115,   217,   179,   217,   207,
      77,    96,   122,   217,   124,   217,    22,   141,    22,   141,
     217,    22,   141,    22,   141,    24,    24,   136,    96,   124,
     123,   140,    18,    47,    65,    69,   176,   124,   193,    95,
     196,   201,   217,   217,   141,    45,    70,   122,   150,   124,
     149,   201,   186,    96,   126,   126,    75,   201,   121,   166,
       9,    13,    77,    78,    79,    80,    81,    82,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    97,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     113,   116,   117,   118,   119,   120,   140,   168,   122,   217,
      22,    22,   217,    22,    22,   126,   126,   217,   159,   141,
      64,    30,   217,    30,   217,    64,    30,   217,    30,   217,
     136,   217,   172,   193,    95,   200,   196,   194,    31,   126,
     136,   201,   122,   126,   202,    30,   136,   217,    30,   136,
     217,   217,   156,   176,   140,    98,   123,   169,    64,    30,
      30,    64,    30,    30,    30,    30,   217,   217,   217,   217,
     217,   217,   124,    23,    60,    63,   125,   179,   199,   209,
     100,   181,   194,    71,   182,   217,   197,   209,   141,   217,
     217,    27,    65,   122,   135,   143,   196,   140,   168,   171,
     217,   217,   217,   217,   217,   217,    64,    64,    64,    64,
     200,   126,   201,   179,   180,   217,   217,   138,   142,   178,
     126,    64,    64,   143,   182,   169,   124,    64,    64,    64,
      64,    64,    64,   217,   217,   217,   217,   181,   194,   179,
     198,   199,   209,    31,   126,   209,   217,   217,   115,   177,
     178,   217,   198,   199,   126,   198
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 185 "chapel.ypp"
    { (void)(yylsp[(1) - (1)]).first_line; yyblock = (yyval.pblockstmt); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 190 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); resetTempID(); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 191 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pblockstmt)); resetTempID(); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 197 "chapel.ypp"
    { (yyval.pblockstmt) = buildPragmaStmt( (yyvsp[(1) - (2)].vpch), (yyvsp[(2) - (2)].pblockstmt) ); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 202 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); (yyval.pblockstmt)->insertAtTail((yyvsp[(1) - (1)].pblockstmt)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 203 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 208 "chapel.ypp"
    { (yyval.vpch) = new Vec<const char*>(); (yyval.vpch)->add(astr((yyvsp[(2) - (2)].pch))); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 209 "chapel.ypp"
    { (yyvsp[(1) - (3)].vpch)->add(astr((yyvsp[(3) - (3)].pch))); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 223 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[(1) - (2)].pexpr)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 224 "chapel.ypp"
    { (yyval.pblockstmt) = buildAtomicStmt((yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 225 "chapel.ypp"
    { (yyval.pblockstmt) = buildBeginStmt((yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 226 "chapel.ypp"
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_BREAK, (yyvsp[(2) - (3)].pch)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 227 "chapel.ypp"
    { (yyval.pblockstmt) = buildCobeginStmt((yyvsp[(2) - (2)].pblockstmt));  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 228 "chapel.ypp"
    { (yyval.pblockstmt) = buildGotoStmt(GOTO_CONTINUE, (yyvsp[(2) - (3)].pch)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 229 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_DELETE, (yyvsp[(2) - (3)].pexpr)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 230 "chapel.ypp"
    { (yyval.pblockstmt) = buildLabelStmt((yyvsp[(2) - (3)].pch), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 231 "chapel.ypp"
    { (yyval.pblockstmt) = buildLocalStmt((yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 232 "chapel.ypp"
    { (yyval.pblockstmt) = buildOnStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 233 "chapel.ypp"
    { (yyval.pblockstmt) = buildSerialStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 234 "chapel.ypp"
    { (yyval.pblockstmt) = buildSyncStmt((yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 235 "chapel.ypp"
    { (yyval.pblockstmt) = buildUseStmt((yyvsp[(2) - (3)].pcallexpr)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 236 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_YIELD, (yyvsp[(2) - (3)].pexpr)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 237 "chapel.ypp"
    { printf("syntax error"); clean_exit(1); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 241 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "="); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 242 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "+="); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 243 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "-="); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 244 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "*="); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 245 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "/="); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 246 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "%="); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 247 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "**="); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 248 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "&="); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 249 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "|="); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 250 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "^="); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 251 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), ">>="); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 252 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "<<="); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 253 "chapel.ypp"
    { (yyval.pblockstmt) = buildAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr), "<=>"); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 254 "chapel.ypp"
    { (yyval.pblockstmt) = buildLAndAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 255 "chapel.ypp"
    { (yyval.pblockstmt) = buildLOrAssignment((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pexpr)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 267 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 268 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(2) - (3)].pblockstmt); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 272 "chapel.ypp"
    { (yyval.pch) = NULL; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 277 "chapel.ypp"
    { (yyval.pch) = astr(yytext); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 281 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(2) - (2)].pblockstmt); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 282 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(1) - (1)].pblockstmt); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 286 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, new SymExpr(gVoid)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 287 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveStmt(PRIM_RETURN, (yyvsp[(2) - (3)].pexpr)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 291 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new BlockStmt()); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 301 "chapel.ypp"
    {
#ifdef HAVE_LLVM
      if (externC) {
        (yyval.pblockstmt) = buildExternBlockStmt(astr((yyvsp[(2) - (2)].pch)));
      } else {
        USR_FATAL(new BlockStmt(), "extern block syntax is turned off. Use --extern-c flag to turn on.");
      }
#else
      USR_FATAL(new BlockStmt(), "Chapel must be built with llvm in order to use the extern block syntax");
#endif
    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 315 "chapel.ypp"
    { (yyval.pblockstmt) = buildDoWhileLoopStmt((yyvsp[(4) - (5)].pexpr), (yyvsp[(2) - (5)].pblockstmt)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 316 "chapel.ypp"
    { (yyval.pblockstmt) = buildWhileDoLoopStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 317 "chapel.ypp"
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 318 "chapel.ypp"
    { (yyval.pblockstmt) = buildCoforallLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt), true); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 319 "chapel.ypp"
    { (yyval.pblockstmt) = buildCoforallLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 320 "chapel.ypp"
    { (yyval.pblockstmt) = buildPrimitiveLoopStmt((yyvsp[(3) - (5)].pcallexpr), (yyvsp[(5) - (5)].pblockstmt)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 321 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt)); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 322 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt), false, true); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 323 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 324 "chapel.ypp"
    { (yyval.pblockstmt) = buildForLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt), false, true); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 325 "chapel.ypp"
    { (yyval.pblockstmt) = buildParamForLoopStmt((yyvsp[(3) - (6)].pch), (yyvsp[(5) - (6)].pexpr), (yyvsp[(6) - (6)].pblockstmt)); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 326 "chapel.ypp"
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt)); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 327 "chapel.ypp"
    { (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pblockstmt), true); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 328 "chapel.ypp"
    { (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 330 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), new BlockStmt((yyvsp[(6) - (6)].pblockstmt)));
    }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 336 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pblockstmt) = buildForallLoopStmt((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), new BlockStmt((yyvsp[(6) - (6)].pblockstmt)), true);
    }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 342 "chapel.ypp"
    {
      if ((yyvsp[(2) - (4)].pcallexpr)->argList.length > 1)
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), new BlockStmt((yyvsp[(4) - (4)].pblockstmt)));
      else
        (yyval.pblockstmt) = buildForallLoopStmt(NULL, (yyvsp[(2) - (4)].pcallexpr)->get(1)->remove(), new BlockStmt((yyvsp[(4) - (4)].pblockstmt)));
    }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 351 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_tuple", (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 355 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (4)].pexpr), (yyvsp[(4) - (4)].pblockstmt)); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 356 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (3)].pexpr), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 357 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pblockstmt), (yyvsp[(6) - (6)].pblockstmt)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 358 "chapel.ypp"
    { (yyval.pblockstmt) = buildIfStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(3) - (5)].pblockstmt), (yyvsp[(5) - (5)].pblockstmt)); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 363 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(buildSelectStmt((yyvsp[(2) - (5)].pexpr), (yyvsp[(4) - (5)].pblockstmt))); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 367 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 368 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pexpr)); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 373 "chapel.ypp"
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN, (yyvsp[(2) - (3)].pcallexpr)), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 375 "chapel.ypp"
    { (yyval.pexpr) = new CondStmt(new CallExpr(PRIM_WHEN), (yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 380 "chapel.ypp"
    { (yyval.pblockstmt) = buildTypeSelectStmt((yyvsp[(3) - (6)].pcallexpr), (yyvsp[(5) - (6)].pblockstmt)); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 387 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(buildClassDefExpr((yyvsp[(3) - (7)].pch), (yyvsp[(2) - (7)].ptype), (yyvsp[(4) - (7)].pcallexpr), (yyvsp[(6) - (7)].pblockstmt), (yyvsp[(1) - (7)].flag), (yylsp[(1) - (7)]).comment));
      yylloc.comment = NULL; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 392 "chapel.ypp"
    { (yyval.flag) = FLAG_UNKNOWN; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 393 "chapel.ypp"
    { (yyval.flag) = FLAG_EXTERN; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 397 "chapel.ypp"
    { (yyval.ptype) = new ClassType(CLASS_CLASS); (yyloc).comment = yylloc.comment; 
             yylloc.comment = NULL;}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 399 "chapel.ypp"
    { (yyval.ptype) = new ClassType(CLASS_RECORD); (yyloc).comment = yylloc.comment; 
             yylloc.comment = NULL;}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 401 "chapel.ypp"
    { (yyval.ptype) = new ClassType(CLASS_UNION); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 405 "chapel.ypp"
    { (yyval.pcallexpr) = NULL; }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 406 "chapel.ypp"
    { (yyval.pcallexpr) = (yyvsp[(2) - (2)].pcallexpr); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 411 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt(); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 413 "chapel.ypp"
    { (yyvsp[(1) - (2)].pblockstmt)->insertAtTail((yyvsp[(2) - (2)].pblockstmt)); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 415 "chapel.ypp"
    { (yyvsp[(1) - (3)].pblockstmt)->insertAtTail(buildPragmaStmt((yyvsp[(2) - (3)].vpch), (yyvsp[(3) - (3)].pblockstmt))); }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 420 "chapel.ypp"
    {
      EnumType* pdt = (yyvsp[(4) - (5)].penumtype);
      TypeSymbol* pst = new TypeSymbol((yyvsp[(2) - (5)].pch), pdt);
      (yyvsp[(4) - (5)].penumtype)->symbol = pst;
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(pst));
    }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 430 "chapel.ypp"
    {
      (yyval.penumtype) = new EnumType();
      (yyvsp[(1) - (1)].pdefexpr)->sym->type = (yyval.penumtype);
      (yyval.penumtype)->constants.insertAtTail((yyvsp[(1) - (1)].pdefexpr));
      (yyval.penumtype)->defaultValue = (yyvsp[(1) - (1)].pdefexpr)->sym;
    }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 437 "chapel.ypp"
    {
      (yyval.penumtype) = (yyvsp[(1) - (2)].penumtype);
    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 441 "chapel.ypp"
    {
      (yyvsp[(1) - (3)].penumtype)->constants.insertAtTail((yyvsp[(3) - (3)].pdefexpr));
      (yyvsp[(3) - (3)].pdefexpr)->sym->type = (yyvsp[(1) - (3)].penumtype);
    }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 448 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[(1) - (1)].pch))); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 449 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new EnumSymbol((yyvsp[(1) - (3)].pch)), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 454 "chapel.ypp"
    {
      captureTokens = 1;
      captureString[0] = '\0';
    }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 459 "chapel.ypp"
    {
      captureTokens = 0;
      (yyvsp[(3) - (3)].pfnsymbol)->userString = astr(captureString);
    }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 464 "chapel.ypp"
    {
      (yyvsp[(3) - (8)].pfnsymbol)->retTag = (yyvsp[(5) - (8)].retTag);
      if ((yyvsp[(5) - (8)].retTag) == RET_VAR)
        USR_FATAL("'var' return types are not allowed in lambdas");
      if ((yyvsp[(5) - (8)].retTag) == RET_PARAM)
        USR_FATAL("'param' return types are not allowed in lambdas");
      if ((yyvsp[(5) - (8)].retTag) == RET_TYPE)
        USR_FATAL("'type' return types are not allowed in lambdas");
      if ((yyvsp[(6) - (8)].pexpr))
        (yyvsp[(3) - (8)].pfnsymbol)->retExprType = new BlockStmt((yyvsp[(6) - (8)].pexpr), BLOCK_SCOPELESS);
      if ((yyvsp[(7) - (8)].pexpr))
        (yyvsp[(3) - (8)].pfnsymbol)->where = new BlockStmt((yyvsp[(7) - (8)].pexpr));
      (yyvsp[(3) - (8)].pfnsymbol)->insertAtTail((yyvsp[(8) - (8)].pblockstmt));
      (yyval.pexpr) = new DefExpr(buildLambda((yyvsp[(3) - (8)].pfnsymbol)));
    }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 484 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 485 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); (yyval.pfnsymbol)->addFlag(FLAG_INLINE); 
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 487 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); (yyval.pfnsymbol)->addFlag(FLAG_EXPORT);  
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 489 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol((yyvsp[(2) - (2)].pch)); (yyval.pfnsymbol)->addFlag(FLAG_EXPORT);  
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 491 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol(""); (yyval.pfnsymbol)->addFlag(FLAG_EXTERN);  
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 493 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol((yyvsp[(2) - (2)].pch)); (yyval.pfnsymbol)->addFlag(FLAG_EXTERN);  
                  (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 498 "chapel.ypp"
    {
      // Sets up to capture tokens while parsing the next grammar nonterminal.
      captureTokens = 1;
      captureString[0] = '\0';
    }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 504 "chapel.ypp"
    {
      // Stop capturing and save the result.
      captureTokens = 0;

      (yyvsp[(4) - (4)].pfnsymbol)->userString = astr(captureString);
    }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 511 "chapel.ypp"
    {
      FnSymbol* fn = (yyvsp[(4) - (9)].pfnsymbol);

      fn->copyFlags((yyvsp[(1) - (9)].pfnsymbol));
      // The user explicitly named this function (controls mangling).
      if ((yyvsp[(1) - (9)].pfnsymbol)->hasFlag(FLAG_EXPORT) || (yyvsp[(1) - (9)].pfnsymbol)->hasFlag(FLAG_EXTERN))
        fn->addFlag(FLAG_USER_NAMED);
      if (*(yyvsp[(1) - (9)].pfnsymbol)->name)
        fn->cname = (yyvsp[(1) - (9)].pfnsymbol)->name;

      if ((yyvsp[(2) - (9)].procIter) == ProcIter_ITER)
      {
        if (fn->hasFlag(FLAG_EXTERN))
          USR_FATAL_CONT(fn, "'iter' is not legal with 'extern'");
        fn->addFlag(FLAG_ITERATOR_FN);
      }

      (yyval.pblockstmt) = buildFunctionDecl((yyvsp[(4) - (9)].pfnsymbol), (yyvsp[(6) - (9)].retTag), (yyvsp[(7) - (9)].pexpr), (yyvsp[(8) - (9)].pexpr), (yyvsp[(9) - (9)].pblockstmt), (yylsp[(1) - (9)]).comment);
      yylloc.comment = NULL;
    }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 535 "chapel.ypp"
    {
      (yyval.pfnsymbol) = (yyvsp[(3) - (3)].pfnsymbol);
      (yyval.pfnsymbol)->thisTag = (yyvsp[(1) - (3)].pt);
      (yyval.pfnsymbol)->name = astr((yyvsp[(2) - (3)].pch));
      (yyval.pfnsymbol)->cname = (yyval.pfnsymbol)->name;
      if ((yyvsp[(2) - (3)].pch)[0] == '~' && (yyvsp[(2) - (3)].pch)[1] != '\0')
        (yyval.pfnsymbol)->addFlag(FLAG_DESTRUCTOR);
    }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 544 "chapel.ypp"
    {
      (yyval.pfnsymbol) = (yyvsp[(5) - (5)].pfnsymbol);
      (yyval.pfnsymbol)->thisTag = (yyvsp[(1) - (5)].pt);
      (yyval.pfnsymbol)->name = astr((yyvsp[(4) - (5)].pch));
      (yyval.pfnsymbol)->cname = (yyval.pfnsymbol)->name;
      if ((yyvsp[(4) - (5)].pch)[0] == '~' && (yyvsp[(4) - (5)].pch)[1] != '\0')
        (yyval.pfnsymbol)->addFlag(FLAG_DESTRUCTOR);
      (yyval.pfnsymbol)->_this = new ArgSymbol((yyvsp[(1) - (5)].pt), "this", dtUnknown, new UnresolvedSymExpr((yyvsp[(2) - (5)].pch)));
      (yyval.pfnsymbol)->_this->addFlag(FLAG_ARG_THIS);
      (yyval.pfnsymbol)->insertFormalAtHead(new DefExpr((yyval.pfnsymbol)->_this));
      (yyval.pfnsymbol)->insertFormalAtHead(new DefExpr(new ArgSymbol(INTENT_BLANK, "_mt", dtMethodToken)));
    }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 560 "chapel.ypp"
    { (yyval.pch) = astr("~", (yyvsp[(2) - (2)].pch)); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 561 "chapel.ypp"
    { (yyval.pch) = "="; }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 562 "chapel.ypp"
    { (yyval.pch) = "&"; }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 563 "chapel.ypp"
    { (yyval.pch) = "|"; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 564 "chapel.ypp"
    { (yyval.pch) = "^"; }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 565 "chapel.ypp"
    { (yyval.pch) = "~"; }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 566 "chapel.ypp"
    { (yyval.pch) = "=="; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 567 "chapel.ypp"
    { (yyval.pch) = "!="; }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 568 "chapel.ypp"
    { (yyval.pch) = "<="; }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 569 "chapel.ypp"
    { (yyval.pch) = ">="; }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 570 "chapel.ypp"
    { (yyval.pch) = "<"; }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 571 "chapel.ypp"
    { (yyval.pch) = ">"; }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 572 "chapel.ypp"
    { (yyval.pch) = "+"; }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 573 "chapel.ypp"
    { (yyval.pch) = "-"; }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 574 "chapel.ypp"
    { (yyval.pch) = "*"; }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 575 "chapel.ypp"
    { (yyval.pch) = "/"; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 576 "chapel.ypp"
    { (yyval.pch) = "<<"; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 577 "chapel.ypp"
    { (yyval.pch) = ">>"; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 578 "chapel.ypp"
    { (yyval.pch) = "%"; }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 579 "chapel.ypp"
    { (yyval.pch) = "**"; }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 580 "chapel.ypp"
    { (yyval.pch) = "!"; }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 581 "chapel.ypp"
    { (yyval.pch) = "by"; }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 582 "chapel.ypp"
    { (yyval.pch) = "#"; }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 583 "chapel.ypp"
    { (yyval.pch) = "align"; }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 584 "chapel.ypp"
    { (yyval.pch) = "+="; }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 585 "chapel.ypp"
    { (yyval.pch) = "-="; }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 586 "chapel.ypp"
    { (yyval.pch) = "*="; }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 587 "chapel.ypp"
    { (yyval.pch) = "/="; }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 588 "chapel.ypp"
    { (yyval.pch) = "%="; }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 589 "chapel.ypp"
    { (yyval.pch) = "**="; }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 590 "chapel.ypp"
    { (yyval.pch) = "&="; }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 591 "chapel.ypp"
    { (yyval.pch) = "|="; }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 592 "chapel.ypp"
    { (yyval.pch) = "^="; }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 593 "chapel.ypp"
    { (yyval.pch) = ">>="; }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 594 "chapel.ypp"
    { (yyval.pch) = "<<="; }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 595 "chapel.ypp"
    { (yyval.pch) = "<=>"; }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 596 "chapel.ypp"
    { (yyval.pch) = "<~>"; }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 600 "chapel.ypp"
    { (yyval.pfnsymbol) = new FnSymbol("_"); (yyval.pfnsymbol)->addFlag(FLAG_NO_PARENS); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 601 "chapel.ypp"
    { (yyval.pfnsymbol) = (yyvsp[(2) - (3)].pfnsymbol); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 605 "chapel.ypp"
    { (yyval.pfnsymbol) = (yyvsp[(2) - (3)].pfnsymbol); }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 609 "chapel.ypp"
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, NULL); }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 610 "chapel.ypp"
    { (yyval.pfnsymbol) = buildFunctionFormal(NULL, (yyvsp[(1) - (1)].pdefexpr)); }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 611 "chapel.ypp"
    { (yyval.pfnsymbol) = buildFunctionFormal((yyvsp[(1) - (3)].pfnsymbol), (yyvsp[(3) - (3)].pdefexpr)); }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 616 "chapel.ypp"
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pch), (yyvsp[(3) - (4)].pexpr), (yyvsp[(4) - (4)].pexpr), NULL); }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 618 "chapel.ypp"
    { (yyval.pdefexpr) = buildArgDefExpr((yyvsp[(1) - (4)].pt), (yyvsp[(2) - (4)].pch), (yyvsp[(3) - (4)].pexpr), NULL, (yyvsp[(4) - (4)].pexpr)); }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 620 "chapel.ypp"
    { (yyval.pdefexpr) = buildTupleArgDefExpr((yyvsp[(1) - (6)].pt), (yyvsp[(3) - (6)].pblockstmt), (yyvsp[(5) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)); }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 622 "chapel.ypp"
    { USR_FATAL("variable-length argument may not be grouped in a tuple"); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 626 "chapel.ypp"
    { (yyval.pt) = INTENT_BLANK; }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 627 "chapel.ypp"
    { (yyval.pt) = INTENT_IN; }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 628 "chapel.ypp"
    { (yyval.pt) = INTENT_INOUT; }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 629 "chapel.ypp"
    { (yyval.pt) = INTENT_OUT; }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 630 "chapel.ypp"
    { (yyval.pt) = INTENT_CONST; }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 631 "chapel.ypp"
    { (yyval.pt) = INTENT_PARAM; }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 632 "chapel.ypp"
    { (yyval.pt) = INTENT_REF; }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 633 "chapel.ypp"
    { (yyval.pt) = INTENT_TYPE; }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 637 "chapel.ypp"
    { (yyval.pt) = INTENT_BLANK; }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 638 "chapel.ypp"
    { (yyval.pt) = INTENT_PARAM; }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 642 "chapel.ypp"
    { (yyval.procIter) = ProcIter_PROC; }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 643 "chapel.ypp"
    { (yyval.procIter) = ProcIter_ITER; }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 647 "chapel.ypp"
    { (yyval.retTag) = RET_VALUE; }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 648 "chapel.ypp"
    { (yyval.retTag) = RET_VALUE; }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 649 "chapel.ypp"
    { (yyval.retTag) = RET_VAR; }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 650 "chapel.ypp"
    { (yyval.retTag) = RET_PARAM; }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 651 "chapel.ypp"
    { (yyval.retTag) = RET_TYPE; }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 655 "chapel.ypp"
    { (yyval.pblockstmt) = NULL; }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 661 "chapel.ypp"
    { (yyval.pblockstmt) = new BlockStmt((yyvsp[(1) - (1)].pblockstmt)); }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 666 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol((yyvsp[(2) - (2)].pch))); }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 668 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 672 "chapel.ypp"
    { (yyval.pdefexpr) = new DefExpr(new VarSymbol(astr("chpl__query", istr(query_uid++)))); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 677 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 678 "chapel.ypp"
    { (yyvsp[(2) - (2)].pdefexpr)->sym->addFlag(FLAG_PARAM); (yyval.pexpr) = (yyvsp[(2) - (2)].pdefexpr); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 682 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 683 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 688 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[(2) - (4)].pch), new BlockStmt(), yyfilename, (yylsp[(1) - (4)]).comment))); }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 690 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(buildModule((yyvsp[(2) - (5)].pch), (yyvsp[(4) - (5)].pblockstmt), yyfilename, (yylsp[(1) - (5)]).comment))); }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 695 "chapel.ypp"
    {(yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 700 "chapel.ypp"
    { (yyval.pblockstmt) = (yyvsp[(2) - (3)].pblockstmt); }
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 702 "chapel.ypp"
    { (yyval.pblockstmt) = handleConfigTypes((yyvsp[(3) - (4)].pblockstmt)); }
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 704 "chapel.ypp"
    { (yyval.pblockstmt) = convertTypesToExtern((yyvsp[(3) - (4)].pblockstmt)); }
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 709 "chapel.ypp"
    {
      VarSymbol* var = new VarSymbol((yyvsp[(1) - (2)].pch));
      var->addFlag(FLAG_TYPE_VARIABLE);
      DefExpr* def = new DefExpr(var, (yyvsp[(2) - (2)].pexpr));
      (yyval.pblockstmt) = buildChapelStmt(def);
    }
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 716 "chapel.ypp"
    {
      VarSymbol* var = new VarSymbol((yyvsp[(1) - (4)].pch));
      var->addFlag(FLAG_TYPE_VARIABLE);
      DefExpr* def = new DefExpr(var, (yyvsp[(2) - (4)].pexpr));
      (yyvsp[(4) - (4)].pblockstmt)->insertAtHead(def);
      (yyval.pblockstmt) = buildChapelStmt((yyvsp[(4) - (4)].pblockstmt));
    }
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 726 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 728 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 730 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExprFromArrayType((yyvsp[(2) - (2)].pcallexpr)); }
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 735 "chapel.ypp"
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[(3) - (4)].pblockstmt), (yyvsp[(1) - (4)].flag), FLAG_PARAM, (yylsp[(1) - (4)]).comment);
    }
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 739 "chapel.ypp"
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[(3) - (4)].pblockstmt), (yyvsp[(1) - (4)].flag), FLAG_CONST, (yylsp[(1) - (4)]).comment);
    }
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 743 "chapel.ypp"
    {
      (yyval.pblockstmt) = buildVarDecls((yyvsp[(3) - (4)].pblockstmt), (yyvsp[(1) - (4)].flag), FLAG_UNKNOWN, (yylsp[(1) - (4)]).comment);
    }
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 749 "chapel.ypp"
    { (yyval.flag) = FLAG_UNKNOWN; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 750 "chapel.ypp"
    { (yyval.flag) = FLAG_CONFIG; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 751 "chapel.ypp"
    { (yyval.flag) = FLAG_EXTERN; (yyloc).comment = yylloc.comment; yylloc.comment = NULL;}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 757 "chapel.ypp"
    {
      for_alist(expr, (yyvsp[(3) - (3)].pblockstmt)->body)
        (yyvsp[(1) - (3)].pblockstmt)->insertAtTail(expr->remove());
    }
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 765 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt(new DefExpr(new VarSymbol((yyvsp[(1) - (3)].pch)), (yyvsp[(3) - (3)].pexpr), (yyvsp[(2) - (3)].pexpr))); }
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 767 "chapel.ypp"
    {
      VarSymbol* var = new VarSymbol((yyvsp[(1) - (4)].pch));
      var->addFlag(FLAG_ARRAY_ALIAS);
      (yyval.pblockstmt) = buildChapelStmt(new DefExpr(var, (yyvsp[(4) - (4)].pexpr), (yyvsp[(2) - (4)].pexpr)));
    }
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 773 "chapel.ypp"
    { (yyval.pblockstmt) = buildTupleVarDeclStmt((yyvsp[(2) - (5)].pblockstmt), (yyvsp[(4) - (5)].pexpr), (yyvsp[(5) - (5)].pexpr)); }
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 778 "chapel.ypp"
    { (yyval.pexpr) = new DefExpr(new VarSymbol("chpl__tuple_blank")); }
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 780 "chapel.ypp"
    { (yyval.pexpr) = new DefExpr(new VarSymbol((yyvsp[(1) - (1)].pch))); }
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 782 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (3)].pblockstmt); }
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 787 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[(1) - (1)].pexpr)); }
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 789 "chapel.ypp"
    { (yyval.pblockstmt) = buildChapelStmt((yyvsp[(1) - (2)].pexpr)); }
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 791 "chapel.ypp"
    { (yyval.pblockstmt) = ((yyvsp[(3) - (3)].pblockstmt)->insertAtHead((yyvsp[(1) - (3)].pexpr)), (yyvsp[(3) - (3)].pblockstmt)); }
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 797 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 798 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 802 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 804 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 808 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 809 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 810 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pcallexpr); }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 811 "chapel.ypp"
    {printf("bad type specification"); }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 832 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), (yyvsp[(4) - (4)].pexpr)); 
    }
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 836 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), (yyvsp[(4) - (4)].pcallexpr)); 
    }
    break;

  case 241:

/* Line 1806 of yacc.c  */
#line 840 "chapel.ypp"
    { 
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pcallexpr) = new CallExpr("chpl__buildArrayRuntimeType",
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(4) - (6)].pexpr)), (yyvsp[(6) - (6)].pexpr), (yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(),
             new CallExpr("chpl__buildDomainExpr", (yyvsp[(4) - (6)].pexpr)->copy()));
    }
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 847 "chapel.ypp"
    {printf("bad array type specification"); clean_exit(1); }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 851 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 852 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pexpr); }
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 853 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pdefexpr); }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 858 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 860 "chapel.ypp"
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[(2) - (4)].pcallexpr), (yyvsp[(4) - (4)].pexpr)); }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 866 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayRuntimeType", gNil, (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 868 "chapel.ypp"
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[(2) - (4)].pcallexpr), (yyvsp[(4) - (4)].pexpr)); }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 870 "chapel.ypp"
    { (yyval.pexpr) = buildFormalArrayType((yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), (yyvsp[(2) - (6)].pcallexpr)); }
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 874 "chapel.ypp"
    { (yyval.pexpr) = NULL; }
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 875 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 876 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pdefexpr); }
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 877 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("_domain"); }
    break;

  case 255:

/* Line 1806 of yacc.c  */
#line 878 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr( "_singlevar"); }
    break;

  case 256:

/* Line 1806 of yacc.c  */
#line 879 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr( "_syncvar"); }
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 880 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(2) - (2)].pexpr); }
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 886 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); }
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 887 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pdefexpr)); }
    break;

  case 260:

/* Line 1806 of yacc.c  */
#line 888 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); }
    break;

  case 261:

/* Line 1806 of yacc.c  */
#line 889 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pdefexpr)); }
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 893 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("chpl__tuple_blank"); }
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 894 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pexpr); }
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 895 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pdefexpr); }
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 899 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); }
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 900 "chapel.ypp"
    { (yyval.pcallexpr) = buildOneTuple((yyvsp[(1) - (2)].pexpr)); }
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 901 "chapel.ypp"
    { (yyval.pcallexpr) = ((yyvsp[(3) - (3)].pcallexpr)->insertAtHead((yyvsp[(1) - (3)].pexpr)), (yyvsp[(3) - (3)].pcallexpr)); }
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 905 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); }
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 906 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); }
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 910 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST); }
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 915 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (1)].pexpr)); }
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 916 "chapel.ypp"
    { (yyvsp[(1) - (3)].pcallexpr)->insertAtTail((yyvsp[(3) - (3)].pexpr)); }
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 920 "chapel.ypp"
    { (yyval.pexpr) = buildNamedActual((yyvsp[(1) - (3)].pch), (yyvsp[(3) - (3)].pdefexpr)); }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 921 "chapel.ypp"
    { (yyval.pexpr) = buildNamedActual((yyvsp[(1) - (3)].pch), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 922 "chapel.ypp"
    { (yyval.pexpr) = buildNamedAliasActual((yyvsp[(1) - (3)].pch), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 923 "chapel.ypp"
    { (yyval.pexpr) = (yyvsp[(1) - (1)].pdefexpr); }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 928 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr((yyvsp[(1) - (1)].pch)); }
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 945 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr( "_singlevar", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 947 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildIndexType", (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 949 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 951 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildSubDomainType", (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 953 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildSparseDomainRuntimeType", new UnresolvedSymExpr("defaultDist"), (yyvsp[(4) - (5)].pcallexpr)); }
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 955 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__atomicType", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 957 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr( "_syncvar", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 962 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)); }
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 964 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, false, true); }
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 966 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[(2) - (4)].pexpr), (yyvsp[(4) - (4)].pexpr)); }
    break;

  case 295:

/* Line 1806 of yacc.c  */
#line 968 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr)); }
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 970 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr), false, true); }
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 972 "chapel.ypp"
    { (yyval.pexpr) = buildForLoopExpr(NULL, (yyvsp[(2) - (7)].pexpr), (yyvsp[(7) - (7)].pexpr), (yyvsp[(5) - (7)].pexpr)); }
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 974 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)); }
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 976 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, false, true); }
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 978 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[(2) - (4)].pexpr), (yyvsp[(4) - (4)].pexpr)); }
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 980 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr)); }
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 982 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pexpr), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr), false, true); }
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 984 "chapel.ypp"
    { (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[(2) - (7)].pexpr), (yyvsp[(7) - (7)].pexpr), (yyvsp[(5) - (7)].pexpr)); }
    break;

  case 304:

/* Line 1806 of yacc.c  */
#line 986 "chapel.ypp"
    {
      if ((yyvsp[(2) - (4)].pcallexpr)->argList.length > 1)
        (yyval.pexpr) = buildForallLoopExpr(NULL, new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (4)].pcallexpr)), (yyvsp[(4) - (4)].pexpr), NULL, true);
      else
        (yyval.pexpr) = buildForallLoopExpr(NULL, (yyvsp[(2) - (4)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (4)].pexpr), NULL, true);
    }
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 993 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, true);
    }
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 999 "chapel.ypp"
    {
      if ((yyvsp[(2) - (6)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (6)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (6)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr), NULL, false, true);
    }
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1005 "chapel.ypp"
    {
      if ((yyvsp[(2) - (9)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (9)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr));
    }
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1011 "chapel.ypp"
    {
      if ((yyvsp[(2) - (9)].pcallexpr)->argList.length != 1)
        USR_FATAL((yyvsp[(4) - (9)].pexpr), "invalid index expression");
      (yyval.pexpr) = buildForallLoopExpr((yyvsp[(2) - (9)].pcallexpr)->get(1)->remove(), (yyvsp[(4) - (9)].pexpr), (yyvsp[(9) - (9)].pexpr), (yyvsp[(7) - (9)].pexpr), false, true);
    }
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1020 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(new DefExpr(buildIfExpr((yyvsp[(2) - (6)].pexpr), (yyvsp[(4) - (6)].pexpr), (yyvsp[(6) - (6)].pexpr)))); }
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1024 "chapel.ypp"
    { (yyval.pexpr) = new SymExpr(gNil); }
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1040 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1046 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<~>", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1051 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(PRIM_NEW, (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1056 "chapel.ypp"
    { (yyval.pexpr) = buildLetExpr((yyvsp[(2) - (4)].pblockstmt), (yyvsp[(4) - (4)].pexpr)); }
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1072 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(PRIM_TUPLE_EXPAND, (yyvsp[(3) - (4)].pexpr)); }
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1074 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_cast", (yyvsp[(3) - (3)].pexpr), (yyvsp[(1) - (3)].pexpr)); }
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1076 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1078 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", buildDotExpr("BoundedRangeType", "boundedLow"), (yyvsp[(1) - (2)].pexpr)); }
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1080 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", buildDotExpr("BoundedRangeType", "boundedHigh"), (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1082 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("_build_range", buildDotExpr("BoundedRangeType", "boundedNone")); }
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 1105 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 1106 "chapel.ypp"
    { (yyval.pexpr) = buildSquareCallExpr((yyvsp[(1) - (4)].pexpr), (yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 1107 "chapel.ypp"
    { (yyval.pexpr) = buildPrimitiveExpr((yyvsp[(3) - (4)].pcallexpr)); }
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 1111 "chapel.ypp"
    { (yyval.pexpr) = buildDotExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pch)); }
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 1112 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(PRIM_TYPEOF, (yyvsp[(1) - (3)].pexpr)); }
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 1113 "chapel.ypp"
    { (yyval.pexpr) = buildDotExpr((yyvsp[(1) - (3)].pexpr), "_dom"); }
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 1120 "chapel.ypp"
    { (yyval.pexpr) = buildParenExpr((yyvsp[(2) - (3)].pcallexpr)); }
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 1124 "chapel.ypp"
    { (yyval.pexpr) = buildIntLiteral(yytext); }
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 1125 "chapel.ypp"
    { (yyval.pexpr) = buildRealLiteral(yytext); }
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 1126 "chapel.ypp"
    { (yyval.pexpr) = buildImagLiteral(yytext); }
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 1127 "chapel.ypp"
    { (yyval.pexpr) = buildStringLiteral((yyvsp[(1) - (1)].pch)); }
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 1128 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildDomainExpr", (yyvsp[(2) - (3)].pcallexpr)); }
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 1129 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("chpl__buildArrayExpr", (yyvsp[(2) - (3)].pcallexpr)); }
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 1131 "chapel.ypp"
    {
      (yyval.pexpr) = new CallExpr("chpl__buildAssociativeArrayExpr", (yyvsp[(2) - (3)].pcallexpr));
    }
    break;

  case 357:

/* Line 1806 of yacc.c  */
#line 1137 "chapel.ypp"
    { (yyval.pcallexpr) = new CallExpr(PRIM_ACTUALS_LIST, (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 1138 "chapel.ypp"
    { (yyvsp[(1) - (5)].pcallexpr)->insertAtTail((yyvsp[(3) - (5)].pexpr)); (yyvsp[(1) - (5)].pcallexpr)->insertAtTail((yyvsp[(5) - (5)].pexpr)); }
    break;

  case 359:

/* Line 1806 of yacc.c  */
#line 1142 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 1143 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 1144 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("*", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 1145 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("/", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 1146 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<<", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 1147 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(">>", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 1148 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("%", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 1149 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("==", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 1150 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("!=", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 1151 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<=", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 1152 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(">=", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 1153 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("<", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 1154 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr(">", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 1155 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("&", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 1156 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("|", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 1157 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("^", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 1158 "chapel.ypp"
    { (yyval.pexpr) = buildLogicalAndExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 1159 "chapel.ypp"
    { (yyval.pexpr) = buildLogicalOrExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 1160 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("**", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 1161 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("by", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 1162 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("align", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 1163 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("#", (yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 1165 "chapel.ypp"
    {
      if (strcmp(CHPL_TARGET_PLATFORM, "cray-xmt")) {
        (yyval.pexpr) = new CallExpr("chpl__distributed", (yyvsp[(3) - (3)].pexpr), (yyvsp[(1) - (3)].pexpr));
      } else {
        (yyval.pexpr) = (yyvsp[(1) - (3)].pexpr);
      }
    }
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 1175 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("+", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 1176 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("-", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 1177 "chapel.ypp"
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[(2) - (2)].pexpr), '-'); }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 1178 "chapel.ypp"
    { (yyval.pexpr) = buildPreDecIncWarning((yyvsp[(2) - (2)].pexpr), '+'); }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 1179 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("!", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 1180 "chapel.ypp"
    { (yyval.pexpr) = new CallExpr("~", (yyvsp[(2) - (2)].pexpr)); }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 1184 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 1185 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); }
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 1186 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 1187 "chapel.ypp"
    { (yyval.pexpr) = buildReduceExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 1191 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 1192 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 1193 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr)); }
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 1194 "chapel.ypp"
    { (yyval.pexpr) = buildScanExpr((yyvsp[(1) - (3)].pexpr), (yyvsp[(3) - (3)].pexpr), true); }
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 1199 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("SumReduceScanOp"); }
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 1200 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("ProductReduceScanOp"); }
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 1201 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalAndReduceScanOp"); }
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 1202 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("LogicalOrReduceScanOp"); }
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 1203 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseAndReduceScanOp"); }
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 1204 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseOrReduceScanOp"); }
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 1205 "chapel.ypp"
    { (yyval.pexpr) = new UnresolvedSymExpr("BitwiseXorReduceScanOp"); }
    break;



/* Line 1806 of yacc.c  */
#line 6904 "chapel.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1208 "chapel.ypp"


