/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CLAIM = 258,
     KW_IS = 259,
     KW_GROUP = 260,
     KW_RING = 261,
     KW_FIELD = 262,
     KW_SPACE = 263,
     KW_PRINT = 264,
     KW_LET = 265,
     KW_RETURN = 266,
     KW_IF = 267,
     KW_ELSE = 268,
     KW_WHILE = 269,
     KW_FOR = 270,
     KW_IN = 271,
     KW_SWITCH = 272,
     KW_CASE = 273,
     KW_DEFAULT = 274,
     KW_BREAK = 275,
     KW_CONTINUE = 276,
     KW_FN = 277,
     KW_MORPH = 278,
     KW_FORGE = 279,
     KW_STRUCT = 280,
     KW_ENUM = 281,
     KW_CYCLIC = 282,
     KW_BIG_RATIONAL = 283,
     KW_COMPLEX = 284,
     KW_SYMMETRIC = 285,
     KW_ALTERNATING = 286,
     KW_DIHEDRAL = 287,
     KW_INV_MAT = 288,
     KW_BIGINT = 289,
     KW_MATRIX = 290,
     KW_POLYNOMIAL = 291,
     KW_VEC = 292,
     KW_BUF = 293,
     IDENT = 294,
     PRIMITIVE_DTYPE = 295,
     LIT_INT = 296,
     LIT_FLOAT = 297,
     LIT_STR = 298,
     LIT_CHAR = 299,
     log_op = 300,
     rel_op = 301,
     KW_TRUE = 302,
     KW_FALSE = 303,
     GROUP = 304,
     RING = 305,
     FIELD = 306,
     SPACE = 307,
     INCR = 308,
     DECR = 309,
     ARROW = 310,
     VARIANT = 311,
     SLICE = 312
   };
#endif
/* Tokens.  */
#define KW_CLAIM 258
#define KW_IS 259
#define KW_GROUP 260
#define KW_RING 261
#define KW_FIELD 262
#define KW_SPACE 263
#define KW_PRINT 264
#define KW_LET 265
#define KW_RETURN 266
#define KW_IF 267
#define KW_ELSE 268
#define KW_WHILE 269
#define KW_FOR 270
#define KW_IN 271
#define KW_SWITCH 272
#define KW_CASE 273
#define KW_DEFAULT 274
#define KW_BREAK 275
#define KW_CONTINUE 276
#define KW_FN 277
#define KW_MORPH 278
#define KW_FORGE 279
#define KW_STRUCT 280
#define KW_ENUM 281
#define KW_CYCLIC 282
#define KW_BIG_RATIONAL 283
#define KW_COMPLEX 284
#define KW_SYMMETRIC 285
#define KW_ALTERNATING 286
#define KW_DIHEDRAL 287
#define KW_INV_MAT 288
#define KW_BIGINT 289
#define KW_MATRIX 290
#define KW_POLYNOMIAL 291
#define KW_VEC 292
#define KW_BUF 293
#define IDENT 294
#define PRIMITIVE_DTYPE 295
#define LIT_INT 296
#define LIT_FLOAT 297
#define LIT_STR 298
#define LIT_CHAR 299
#define log_op 300
#define rel_op 301
#define KW_TRUE 302
#define KW_FALSE 303
#define GROUP 304
#define RING 305
#define FIELD 306
#define SPACE 307
#define INCR 308
#define DECR 309
#define ARROW 310
#define VARIANT 311
#define SLICE 312




/* Copy the first part of user declarations.  */
#line 1 "code/yacc.y"

#include <stdio.h>

int yylex();
void yyerror(const char* s);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 228 "code/y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   691

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNRULES -- Number of states.  */
#define YYNSTATES  369

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    65,    74,     2,
      69,    70,    63,    61,    73,    62,    67,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    78,    68,
      59,    75,    58,     2,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,    72,    79,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    17,    20,    22,
      25,    28,    30,    33,    35,    37,    39,    45,    48,    51,
      53,    57,    59,    63,    67,    69,    71,    76,    81,    86,
      91,    98,   100,   107,   112,   117,   120,   123,   125,   130,
     132,   134,   136,   138,   140,   143,   145,   148,   151,   153,
     155,   158,   161,   165,   169,   171,   173,   175,   177,   181,
     185,   189,   193,   197,   201,   205,   208,   212,   216,   220,
     222,   224,   226,   228,   230,   232,   234,   238,   240,   243,
     249,   254,   259,   263,   267,   269,   272,   275,   278,   282,
     288,   292,   294,   300,   302,   306,   310,   316,   326,   336,
     342,   344,   346,   357,   365,   371,   377,   383,   385,   396,
     406,   415,   433,   443,   453,   461,   470,   479,   484,   492,
     494,   496,   500,   504,   510,   512,   516,   522,   524,   528,
     537,   541,   545,   547
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      81,     0,    -1,    82,    -1,    81,   118,    -1,    81,   123,
      -1,    81,   127,    -1,    81,   125,    -1,    83,    82,    -1,
     130,    -1,    90,    68,    -1,    95,    68,    -1,    99,    -1,
      98,    68,    -1,   106,    -1,   110,    -1,   108,    -1,     9,
      69,   101,    70,    68,    -1,    20,    68,    -1,    21,    68,
      -1,   112,    -1,    71,    82,    72,    -1,    39,    -1,    85,
      67,    39,    -1,    39,    56,    39,    -1,    28,    -1,    29,
      -1,    27,    59,    41,    58,    -1,    30,    59,    41,    58,
      -1,    31,    59,    41,    58,    -1,    32,    59,    41,    58,
      -1,    33,    59,    41,    73,    92,    58,    -1,    34,    -1,
      35,    59,    41,    73,    92,    58,    -1,    36,    59,    92,
      58,    -1,    37,    59,    92,    58,    -1,    10,    91,    -1,
     122,    93,    -1,    40,    -1,    38,    59,    40,    58,    -1,
      39,    -1,    87,    -1,    88,    -1,    86,    -1,    89,    -1,
      74,    92,    -1,   128,    -1,    75,    94,    -1,    73,    91,
      -1,   130,    -1,    97,    -1,    74,    94,    -1,    63,    94,
      -1,    85,    75,    97,    -1,   103,    75,    97,    -1,    44,
      -1,    42,    -1,    41,    -1,    43,    -1,    97,    61,    97,
      -1,    97,    62,    97,    -1,    97,    63,    97,    -1,    97,
      64,    97,    -1,    97,    65,    97,    -1,    69,    97,    70,
      -1,    97,    45,    97,    -1,    60,    97,    -1,    97,    46,
      97,    -1,    97,    58,    97,    -1,    97,    59,    97,    -1,
      85,    -1,    96,    -1,   102,    -1,   103,    -1,   100,    -1,
      47,    -1,    48,    -1,    97,    66,    97,    -1,   104,    -1,
      11,    97,    -1,    92,    69,   101,    70,    68,    -1,    92,
      69,    70,    68,    -1,    92,    69,   101,    70,    -1,    92,
      69,    70,    -1,    97,    73,   101,    -1,    97,    -1,    85,
      53,    -1,    85,    54,    -1,    85,   104,    -1,    76,   105,
      77,    -1,    76,    97,    57,    97,    77,    -1,    96,    73,
     105,    -1,    96,    -1,    12,    69,    97,    70,   107,    -1,
      84,    -1,    84,    13,   106,    -1,    84,    13,    84,    -1,
      14,    69,    97,    70,    84,    -1,    15,    69,    95,    68,
      97,    68,   109,    70,    84,    -1,    15,    69,    90,    68,
      97,    68,   109,    70,    84,    -1,    15,    39,    16,    39,
      84,    -1,   102,    -1,   130,    -1,    17,    69,    97,    70,
      71,   111,    19,    78,    82,    72,    -1,    17,    69,    97,
      70,    71,   111,    72,    -1,    18,    44,    78,    82,   111,
      -1,    18,    41,    78,    82,   111,    -1,    18,    42,    78,
      82,   111,    -1,   130,    -1,     3,    39,     4,     5,    71,
     113,   115,   116,    72,    68,    -1,     3,    39,     4,     6,
      71,   114,   115,    72,    68,    -1,     3,    39,     4,     7,
      71,   117,    72,    68,    -1,     3,    39,     4,     8,    71,
       7,    75,    69,    39,    70,    68,   113,   116,   115,   114,
      72,    68,    -1,    69,    39,    75,    39,    61,    39,    70,
      55,    84,    -1,    69,    39,    75,    39,    63,    39,    70,
      55,    84,    -1,    69,    39,    75,    41,    70,    55,    84,
      -1,    69,    39,    75,    62,    39,    70,    55,    84,    -1,
      69,    39,    75,    79,    39,    70,    55,    84,    -1,   119,
      71,   120,    72,    -1,    22,    39,    69,   121,    70,    78,
      92,    -1,    82,    -1,   122,    -1,   121,    73,   122,    -1,
      85,    78,    92,    -1,    25,    39,    71,   124,    72,    -1,
      39,    -1,   122,    73,    39,    -1,    26,    39,    71,   126,
      72,    -1,    39,    -1,   126,    73,    39,    -1,    24,    92,
      69,   121,    70,    71,    82,    72,    -1,    69,   129,    70,
      -1,   129,    73,    92,    -1,    92,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    24,    24,    25,    26,    27,    28,    30,    31,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      47,    50,    51,    52,    55,    56,    59,    60,    61,    62,
      63,    66,    67,    68,    71,    75,    78,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    91,    92,    93,    95,
      96,    97,   100,   101,   104,   105,   106,   107,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     121,   121,   121,   121,   122,   122,   123,   124,   127,   130,
     131,   134,   135,   138,   139,   142,   143,   146,   149,   150,
     153,   154,   157,   160,   161,   162,   165,   166,   167,   168,
     171,   172,   175,   176,   179,   180,   181,   182,   185,   186,
     187,   188,   191,   194,   197,   200,   203,   206,   209,   212,
     215,   216,   219,   222,   224,   225,   227,   229,   230,   232,
     234,   236,   237,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CLAIM", "KW_IS", "KW_GROUP",
  "KW_RING", "KW_FIELD", "KW_SPACE", "KW_PRINT", "KW_LET", "KW_RETURN",
  "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_IN", "KW_SWITCH",
  "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_CONTINUE", "KW_FN", "KW_MORPH",
  "KW_FORGE", "KW_STRUCT", "KW_ENUM", "KW_CYCLIC", "KW_BIG_RATIONAL",
  "KW_COMPLEX", "KW_SYMMETRIC", "KW_ALTERNATING", "KW_DIHEDRAL",
  "KW_INV_MAT", "KW_BIGINT", "KW_MATRIX", "KW_POLYNOMIAL", "KW_VEC",
  "KW_BUF", "IDENT", "PRIMITIVE_DTYPE", "LIT_INT", "LIT_FLOAT", "LIT_STR",
  "LIT_CHAR", "log_op", "rel_op", "KW_TRUE", "KW_FALSE", "GROUP", "RING",
  "FIELD", "SPACE", "INCR", "DECR", "ARROW", "VARIANT", "SLICE", "'>'",
  "'<'", "'!'", "'+'", "'-'", "'*'", "'/'", "'%'", "'@'", "'.'", "';'",
  "'('", "')'", "'{'", "'}'", "','", "'&'", "'='", "'['", "']'", "':'",
  "'~'", "$accept", "P", "statements", "statement", "body", "var",
  "field_data_type", "group_data_type", "ring_data_type",
  "space_data_type", "declaration", "decl_tail", "type", "decl_cntd",
  "RHS", "assignment", "constant", "expression", "return_stmt",
  "call_stmt", "call", "pass_param_list", "unary_operation",
  "array_access", "array_decl", "array_list", "conditional", "if_body",
  "loop_stmt", "loop_mut", "switch_case", "sc_blocks", "archetype_claim",
  "additive_rule", "mult_rule", "identity_rule", "negation_rule",
  "inverse_rule", "function", "function_header", "function_body",
  "parameter_list", "typ_var", "struct", "attr_list", "enum",
  "variant_list", "forge", "cart", "typ_list", "epsilon", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,    62,    60,
      33,    43,    45,    42,    47,    37,    64,    46,    59,    40,
      41,   123,   125,    44,    38,    61,    91,    93,    58,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    85,    85,    85,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    88,    89,    90,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   104,   104,
     105,   105,   106,   107,   107,   107,   108,   108,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   112,   112,
     112,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   121,   122,   123,   124,   124,   125,   126,   126,   127,
     128,   129,   129,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     2,     1,     1,     1,     5,     2,     2,     1,
       3,     1,     3,     3,     1,     1,     4,     4,     4,     4,
       6,     1,     6,     4,     4,     2,     2,     1,     4,     1,
       1,     1,     1,     1,     2,     1,     2,     2,     1,     1,
       2,     2,     3,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     5,
       4,     4,     3,     3,     1,     2,     2,     2,     3,     5,
       3,     1,     5,     1,     3,     3,     5,     9,     9,     5,
       1,     1,    10,     7,     5,     5,     5,     1,    10,     9,
       8,    17,     9,     9,     7,     8,     8,     4,     7,     1,
       1,     3,     3,     5,     1,     3,     5,     1,     3,     8,
       3,     3,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,     0,    31,     0,
       0,     0,     0,    21,    37,     0,     0,     0,     2,   133,
       0,    42,    40,    41,    43,     0,     0,     0,     0,    11,
       0,    13,    15,    14,    19,    45,     8,     0,     0,    21,
       0,    35,   133,    56,    55,    57,    54,    74,    75,     0,
       0,     0,    69,     0,    70,    78,    73,    71,    72,    77,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,   132,     0,
      44,     1,     0,     0,     0,     0,     3,     0,     4,     6,
       5,     7,     0,     0,    87,     9,     0,    10,    12,     0,
       0,    84,     0,     0,     0,     0,    36,    48,    65,   132,
       0,    70,     0,     0,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,   130,     0,     0,     0,     0,     0,   133,
      22,    52,     0,     0,    53,     0,     0,     0,     0,     0,
       0,   122,    47,     0,     0,    46,    49,    63,     0,     0,
      88,    82,     0,    64,    66,    67,    68,    58,    59,    60,
      61,    62,    76,     0,     0,     0,     0,     0,     0,    26,
      27,    28,    29,     0,     0,    33,    34,    38,   131,     0,
       0,     0,     0,   119,     0,    80,     0,     0,     0,     0,
       0,    83,    16,    51,     0,    50,    91,    90,     0,    81,
     133,    93,    92,    96,    99,     0,     0,   133,     0,     0,
       0,   120,     0,    21,     0,     0,   127,     0,   117,    79,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
     133,   133,     0,     0,   107,    30,    32,     0,     0,     0,
       0,   123,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    95,    94,     0,   100,     0,   101,     0,
       0,     0,     0,     0,   103,     0,   121,   133,   125,   128,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,   133,   133,   133,   133,   118,     0,     0,     0,     0,
       0,     0,   109,     0,     0,    98,    97,   133,   133,   133,
       0,   129,     0,     0,     0,   108,     0,     0,     0,   105,
     106,   104,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,   116,
       0,   112,     0,   113,     0,   115,     0,     0,   111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,   231,    62,    31,    32,    33,    34,
      35,    51,    63,   116,   175,    37,    64,   111,    38,    39,
      66,   112,    67,    68,    69,   123,    41,   232,    42,   287,
      43,   263,    44,   251,   253,   276,   303,   255,    96,    97,
     214,   240,    52,    98,   245,    99,   247,   100,    45,    89,
      46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -245
static const yytype_int16 yypact[] =
{
     320,    22,    -7,    43,   485,    52,    59,   -15,    75,    81,
      87,    92,  -245,  -245,    98,   109,   110,   111,  -245,   112,
     113,   114,   116,   -41,  -245,    11,    11,    72,  -245,   320,
     -12,  -245,  -245,  -245,  -245,   120,   121,   124,   125,  -245,
      36,  -245,  -245,  -245,  -245,  -245,  -245,   191,   485,   140,
      -8,  -245,   -39,  -245,  -245,  -245,  -245,  -245,  -245,   485,
     485,   485,    25,   128,  -245,   625,  -245,  -245,  -245,  -245,
     485,   485,   183,    17,   485,  -245,  -245,   159,   160,   164,
     165,   166,   167,    11,    11,   169,   173,  -245,  -245,    -2,
    -245,  -245,   177,    11,   178,   179,  -245,   148,  -245,  -245,
    -245,  -245,   181,   485,  -245,  -245,   335,  -245,  -245,   485,
      68,    41,   151,    11,    43,   385,  -245,  -245,    77,   128,
     504,   -60,   616,   147,  -245,  -245,   435,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   526,   536,   186,
     158,   161,   558,   174,   175,   182,   184,   154,   168,   185,
     189,   192,  -245,  -245,    11,   162,   170,   187,   188,   320,
    -245,   625,   176,   193,   625,   195,   197,   199,   200,   485,
     194,  -245,  -245,   385,   385,  -245,   625,  -245,    47,   485,
    -245,  -245,   203,    71,    77,    77,    77,    61,    61,   171,
     171,   171,  -245,   204,   204,   204,   485,   485,   205,  -245,
    -245,  -245,  -245,    11,    11,  -245,  -245,  -245,  -245,    43,
      43,   218,   221,  -245,   202,  -245,   212,   213,   219,   220,
     254,  -245,  -245,  -245,   128,  -245,   208,  -245,   190,  -245,
     320,   274,  -245,  -245,  -245,   568,   592,   272,   233,   234,
      42,  -245,    83,   -40,   223,   222,  -245,   -54,  -245,  -245,
     259,   224,   260,   224,   261,   230,   228,  -245,   232,    -6,
      43,    43,   106,    -5,  -245,  -245,  -245,   229,    43,   235,
     269,  -245,  -245,   270,   249,   271,   256,   251,   255,   253,
     265,   267,  -245,  -245,  -245,   -32,  -245,   268,  -245,   273,
     264,   266,   283,   302,  -245,    11,  -245,   320,  -245,  -245,
     300,   306,   307,   312,   346,   277,   308,  -245,   347,   204,
     204,   320,   320,   320,   320,  -245,   316,   329,   350,   317,
     325,   333,  -245,   358,   328,  -245,  -245,   272,   272,   272,
     327,  -245,   361,   331,   340,  -245,   364,   336,   339,  -245,
    -245,  -245,  -245,   338,   355,   391,   365,   376,   213,   379,
     204,   366,   382,   204,   256,   204,  -245,   383,   204,  -245,
     224,  -245,   204,  -245,   219,  -245,   367,   372,  -245
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,   -28,  -245,  -164,     4,  -245,  -245,  -245,  -245,
     368,   330,     0,  -245,  -116,   369,   -56,    49,  -245,  -245,
    -245,  -103,   -95,     8,   -10,   275,   196,  -245,  -245,   225,
    -245,  -167,  -245,    95,    82,  -244,    93,  -245,  -245,  -245,
    -245,   239,  -199,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
     -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -125
static const yytype_int16 yytable[] =
{
      36,   101,   117,   163,    30,   121,     5,    50,    40,   278,
     241,   241,   244,   178,   293,    86,    86,   -91,   272,   273,
     104,   124,   125,   182,    72,    88,    90,     3,   -39,    36,
     233,   234,  -124,    30,   114,   102,   115,    40,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      87,    24,   104,    65,    73,   102,    49,   223,   225,   102,
     119,    47,    48,   103,    61,   230,   221,   294,   153,   296,
     113,   154,    91,   165,   166,   167,   168,    30,   124,   125,
      25,    40,    49,   149,   150,    26,   127,   128,    53,    54,
      55,    56,   102,   156,    92,   283,    93,    94,    95,   129,
     130,    61,   131,   132,   133,   134,   135,   136,   118,   120,
     122,   109,   267,   171,   169,   268,   364,   128,    50,   137,
     138,    70,   226,   142,   133,   134,   135,   136,    71,   129,
     130,   213,   131,   132,   133,   134,   135,   136,   131,   132,
     133,   134,   135,   136,    74,   325,   326,   290,   291,    75,
     292,    77,   161,   269,   208,    76,   268,    78,   164,    36,
     339,   340,   341,    30,   176,   286,   286,    40,    79,    80,
      81,    82,    83,    84,   224,    85,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   356,   264,   105,   359,
     106,   361,   107,   108,   363,   110,    86,   126,   365,   139,
     143,   144,   258,   238,   239,   145,   146,   147,   148,   151,
     288,   288,   152,    50,    50,    50,   155,   157,   158,   159,
     160,   170,   176,   176,   180,   195,   196,   203,   228,   197,
      36,   209,   199,   200,    30,   127,   128,   136,    40,   210,
     201,   204,   202,   205,   215,   235,   236,   206,   129,   130,
     207,   131,   132,   133,   134,   135,   136,   243,   211,   212,
     246,   256,   222,   216,   285,   285,   217,   257,   218,   316,
     219,   220,    50,   229,   248,   230,   237,   264,   264,   264,
     249,   178,   250,   327,   328,   329,   330,   259,   252,   254,
     262,   265,   266,   275,   271,   315,   270,    36,   274,   277,
     279,    30,   280,   281,   282,    40,   297,   295,   298,   299,
     301,    36,    36,    36,    36,    30,    30,    30,    30,    40,
      40,    40,    40,     1,   300,   302,   304,   305,   306,     2,
       3,     4,     5,   307,     6,     7,   308,     8,   309,   317,
       9,    10,   311,   310,   312,   322,   319,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   313,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    53,    54,    55,    56,
     314,   318,    57,    58,   320,   321,   324,   323,   331,    25,
     332,   333,   334,   335,    26,    59,   336,   337,   338,   342,
     343,   344,   345,   346,    60,   162,   347,   348,   349,    26,
     350,    61,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    53,    54,    55,    56,
     351,   353,    57,    58,   355,   352,   357,   358,   362,   367,
     368,   140,   141,   354,   172,    59,   366,   360,   173,   242,
       0,     0,     0,   227,    60,   284,     0,     0,     0,   174,
       0,    61,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    53,    54,    55,    56,
       0,     0,    57,    58,     0,     0,   289,     0,     0,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,    60,   181,     0,     0,     0,    26,
       0,    61,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    53,    54,    55,    56,
       0,     0,    57,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,     0,     0,     0,   127,
     128,     0,     0,     0,    60,     0,     0,     0,     0,    26,
       0,    61,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   127,   128,     0,   177,     0,     0,     0,     0,     0,
       0,   127,   128,     0,   129,   130,     0,   131,   132,   133,
     134,   135,   136,     0,   129,   130,   193,   131,   132,   133,
     134,   135,   136,   127,   128,     0,   194,     0,     0,     0,
       0,     0,     0,   127,   128,     0,   129,   130,     0,   131,
     132,   133,   134,   135,   136,     0,   129,   130,   198,   131,
     132,   133,   134,   135,   136,     0,   260,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,   131,   132,   133,   134,   135,   136,     0,
     261,   127,   128,     0,     0,     0,     0,     0,     0,     0,
     127,   128,     0,   179,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   129,   130,     0,   131,   132,   133,   134,
     135,   136
};

static const yytype_int16 yycheck[] =
{
       0,    29,    52,   106,     0,    61,    12,     3,     0,   253,
     209,   210,   211,    73,    19,    56,    56,    77,    72,    73,
      30,    53,    54,   126,    39,    25,    26,    10,    69,    29,
     194,   195,    72,    29,    73,    67,    75,    29,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    62,     4,    69,    67,    39,   173,   174,    67,
      60,    39,    69,    75,    76,    71,   169,    72,    70,   268,
      78,    73,     0,     5,     6,     7,     8,    73,    53,    54,
      69,    73,    39,    83,    84,    74,    45,    46,    41,    42,
      43,    44,    67,    93,    22,   259,    24,    25,    26,    58,
      59,    76,    61,    62,    63,    64,    65,    66,    59,    60,
      61,    75,    70,   113,    73,    73,   360,    46,   114,    70,
      71,    69,   178,    74,    63,    64,    65,    66,    69,    58,
      59,   159,    61,    62,    63,    64,    65,    66,    61,    62,
      63,    64,    65,    66,    69,   309,   310,    41,    42,    68,
      44,    59,   103,    70,   154,    68,    73,    59,   109,   159,
     327,   328,   329,   159,   115,   260,   261,   159,    59,    59,
      59,    59,    59,    59,   174,    59,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   350,   237,    68,   353,
      69,   355,    68,    68,   358,     4,    56,    69,   362,    16,
      41,    41,   230,   203,   204,    41,    41,    41,    41,    40,
     260,   261,    39,   209,   210,   211,    39,    39,    39,    71,
      39,    70,   173,   174,    77,    39,    68,    73,   179,    68,
     230,    69,    58,    58,   230,    45,    46,    66,   230,    69,
      58,    73,    58,    58,    68,   196,   197,    58,    58,    59,
      58,    61,    62,    63,    64,    65,    66,    39,    71,    71,
      39,     7,    68,    70,   260,   261,    71,    77,    71,   297,
      71,    71,   268,    70,    72,    71,    71,   327,   328,   329,
      68,    73,    69,   311,   312,   313,   314,    13,    69,    69,
      18,    58,    58,    69,    72,   295,    73,   297,    39,    39,
      39,   297,    72,    75,    72,   297,    71,    78,    39,    39,
      39,   311,   312,   313,   314,   311,   312,   313,   314,   311,
     312,   313,   314,     3,    75,    69,    75,    72,    75,     9,
      10,    11,    12,    68,    14,    15,    69,    17,    70,    39,
      20,    21,    78,    70,    78,    68,    39,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    78,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      78,    75,    47,    48,    72,    39,    39,    79,    72,    69,
      61,    41,    75,    68,    74,    60,    63,    39,    70,    72,
      39,    70,    62,    39,    69,    70,    70,    68,    70,    74,
      55,    76,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      39,    55,    47,    48,    55,    70,    70,    55,    55,    72,
      68,    73,    73,   348,   114,    60,   364,   354,    63,   210,
      -1,    -1,    -1,   178,    69,   259,    -1,    -1,    -1,    74,
      -1,    76,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    74,
      -1,    76,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    74,
      -1,    76,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    45,    46,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    -1,    58,    59,    70,    61,    62,    63,
      64,    65,    66,    45,    46,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    -1,    58,    59,    70,    61,
      62,    63,    64,    65,    66,    -1,    68,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    -1,
      68,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    66,    58,    59,    -1,    61,    62,    63,    64,
      65,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    14,    15,    17,    20,
      21,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    69,    74,    81,    82,    83,
      85,    86,    87,    88,    89,    90,    92,    95,    98,    99,
     103,   106,   108,   110,   112,   128,   130,    39,    69,    39,
      85,    91,   122,    41,    42,    43,    44,    47,    48,    60,
      69,    76,    85,    92,    96,    97,   100,   102,   103,   104,
      69,    69,    39,    69,    69,    68,    68,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    56,    39,    92,   129,
      92,     0,    22,    24,    25,    26,   118,   119,   123,   125,
     127,    82,    67,    75,   104,    68,    69,    68,    68,    75,
       4,    97,   101,    78,    73,    75,    93,   130,    97,    92,
      97,    96,    97,   105,    53,    54,    69,    45,    46,    58,
      59,    61,    62,    63,    64,    65,    66,    97,    97,    16,
      90,    95,    97,    41,    41,    41,    41,    41,    41,    92,
      92,    40,    39,    70,    73,    39,    92,    39,    39,    71,
      39,    97,    70,   101,    97,     5,     6,     7,     8,    73,
      70,    92,    91,    63,    74,    94,    97,    70,    73,    57,
      77,    70,   101,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    70,    70,    39,    68,    68,    70,    58,
      58,    58,    58,    73,    73,    58,    58,    58,    92,    69,
      69,    71,    71,    82,   120,    68,    70,    71,    71,    71,
      71,   101,    68,    94,    92,    94,    96,   105,    97,    70,
      71,    84,   107,    84,    84,    97,    97,    71,    92,    92,
     121,   122,   121,    39,   122,   124,    39,   126,    72,    68,
      69,   113,    69,   114,    69,   117,     7,    77,    82,    13,
      68,    68,    18,   111,   130,    58,    58,    70,    73,    70,
      73,    72,    72,    73,    39,    69,   115,    39,   115,    39,
      72,    75,    72,    84,   106,    85,   102,   109,   130,   109,
      41,    42,    44,    19,    72,    78,   122,    71,    39,    39,
      75,    39,    69,   116,    75,    72,    75,    68,    69,    70,
      70,    78,    78,    78,    78,    92,    82,    39,    75,    39,
      72,    39,    68,    79,    39,    84,    84,    82,    82,    82,
      82,    72,    61,    41,    75,    68,    63,    39,    70,   111,
     111,   111,    72,    39,    70,    62,    39,    70,    68,    70,
      55,    39,    70,    55,   113,    55,    84,    70,    55,    84,
     116,    84,    55,    84,   115,    84,   114,    72,    68
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 108:
#line 185 "code/yacc.y"
    {printf("Group claim rule\n");;}
    break;

  case 112:
#line 191 "code/yacc.y"
    {printf("Group_closure_rule\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1813 "code/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 241 "code/yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

