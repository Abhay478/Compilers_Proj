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
     KW_CYCLIC = 277,
     KW_BIG_RATIONAL = 278,
     KW_COMPLEX = 279,
     KW_SYMMETRIC = 280,
     KW_ALTERNATING = 281,
     KW_DIHEDRAL = 282,
     KW_INV_MAT = 283,
     KW_BIGINT = 284,
     KW_MATRIX = 285,
     KW_POLYNOMIAL = 286,
     KW_VEC = 287,
     KW_BUF = 288,
     IDENT = 289,
     PRIMITIVE_DTYPE = 290,
     LIT_INT = 291,
     LIT_FLOAT = 292,
     LIT_STR = 293,
     LIT_CHAR = 294,
     LOGICAL_AND = 295,
     LOGICAL_OR = 296,
     LOGICAL_NOT = 297,
     EQ = 298,
     NEQ = 299,
     GT = 300,
     LT = 301,
     GTEQ = 302,
     LTEQ = 303,
     KW_TRUE = 304,
     KW_FALSE = 305
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
#define KW_CYCLIC 277
#define KW_BIG_RATIONAL 278
#define KW_COMPLEX 279
#define KW_SYMMETRIC 280
#define KW_ALTERNATING 281
#define KW_DIHEDRAL 282
#define KW_INV_MAT 283
#define KW_BIGINT 284
#define KW_MATRIX 285
#define KW_POLYNOMIAL 286
#define KW_VEC 287
#define KW_BUF 288
#define IDENT 289
#define PRIMITIVE_DTYPE 290
#define LIT_INT 291
#define LIT_FLOAT 292
#define LIT_STR 293
#define LIT_CHAR 294
#define LOGICAL_AND 295
#define LOGICAL_OR 296
#define LOGICAL_NOT 297
#define EQ 298
#define NEQ 299
#define GT 300
#define LT 301
#define GTEQ 302
#define LTEQ 303
#define KW_TRUE 304
#define KW_FALSE 305




/* Copy the first part of user declarations.  */
#line 1 "temp_yacc.y"

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
#line 214 "y.tab.c"

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  373

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    65,     2,     2,
      52,    53,    63,    61,    54,    62,    55,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    51,
      56,    59,    57,     2,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,    69,    70,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    14,    16,    19,    21,
      23,    25,    31,    34,    37,    39,    41,    45,    47,    51,
      53,    57,    58,    60,    62,    67,    72,    77,    82,    89,
      91,    98,   103,   108,   113,   119,   128,   134,   140,   146,
     152,   158,   161,   163,   172,   178,   184,   190,   196,   202,
     208,   212,   216,   218,   220,   222,   226,   230,   234,   236,
     240,   244,   248,   250,   252,   256,   259,   261,   263,   265,
     267,   269,   271,   273,   275,   279,   281,   284,   286,   290,
     292,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     313,   319,   324,   329,   333,   337,   339,   343,   347,   350,
     355,   359,   363,   367,   369,   375,   379,   385,   393,   401,
     413,   425,   433,   435,   437,   448,   456,   462,   468,   474,
     476,   487,   497,   506,   524,   537,   550,   561,   573,   585
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    73,    72,    -1,   112,    -1,    80,    51,
      -1,    82,    51,    -1,    92,    -1,    91,    51,    -1,   100,
      -1,   104,    -1,   102,    -1,     9,    52,    74,    53,    51,
      -1,    20,    51,    -1,    21,    51,    -1,   106,    -1,    38,
      -1,    38,    54,    74,    -1,    83,    -1,    83,    54,    74,
      -1,    34,    -1,    34,    55,    34,    -1,    -1,    23,    -1,
      24,    -1,    22,    56,    36,    57,    -1,    25,    56,    36,
      57,    -1,    26,    56,    36,    57,    -1,    27,    56,    36,
      57,    -1,    28,    56,    36,    54,    34,    57,    -1,    29,
      -1,    30,    56,    36,    54,    34,    57,    -1,    31,    56,
      34,    57,    -1,    32,    56,    34,    57,    -1,    32,    56,
      35,    57,    -1,    10,    75,    58,    35,    81,    -1,    10,
      75,    58,    33,    56,    35,    57,    81,    -1,    10,    75,
      58,    34,    81,    -1,    10,    75,    58,    77,    81,    -1,
      10,    75,    58,    78,    81,    -1,    10,    75,    58,    76,
      81,    -1,    10,    75,    58,    79,    81,    -1,    59,    83,
      -1,   112,    -1,    54,    75,    58,    33,    56,    35,    57,
      81,    -1,    54,    75,    58,    35,    81,    -1,    54,    75,
      58,    34,    81,    -1,    54,    75,    58,    77,    81,    -1,
      54,    75,    58,    78,    81,    -1,    54,    75,    58,    76,
      81,    -1,    54,    75,    58,    79,    81,    -1,    75,    59,
      83,    -1,    96,    59,    83,    -1,    84,    -1,    88,    -1,
      98,    -1,    75,    60,    75,    -1,    84,    61,    85,    -1,
      84,    62,    85,    -1,    85,    -1,    85,    63,    86,    -1,
      85,    64,    86,    -1,    85,    65,    86,    -1,    86,    -1,
      75,    -1,    52,    84,    53,    -1,    62,    86,    -1,    87,
      -1,    93,    -1,    96,    -1,    95,    -1,    39,    -1,    37,
      -1,    36,    -1,    38,    -1,    89,    90,    88,    -1,    89,
      -1,    42,    88,    -1,    84,    -1,    52,    88,    53,    -1,
      49,    -1,    50,    -1,    57,    -1,    56,    -1,    47,    -1,
      48,    -1,    43,    -1,    44,    -1,    40,    -1,    41,    -1,
      11,    83,    -1,    75,    52,    94,    53,    51,    -1,    75,
      52,    53,    51,    -1,    75,    52,    94,    53,    -1,    75,
      52,    53,    -1,    83,    54,    94,    -1,    83,    -1,    75,
      61,    61,    -1,    75,    62,    62,    -1,    75,    97,    -1,
      66,    36,    67,    97,    -1,    66,    36,    67,    -1,    66,
      99,    67,    -1,    87,    54,    99,    -1,    87,    -1,    12,
      52,    88,    53,   101,    -1,    68,    72,    69,    -1,    68,
      72,    69,    13,   100,    -1,    68,    72,    69,    13,    68,
      72,    69,    -1,    14,    52,    88,    53,    68,    72,    69,
      -1,    15,    52,    82,    51,    88,    51,   103,    53,    68,
      72,    69,    -1,    15,    52,    80,    51,    88,    51,   103,
      53,    68,    72,    69,    -1,    15,    34,    16,    34,    68,
      72,    69,    -1,    95,    -1,   112,    -1,    17,    52,    83,
      53,    68,   105,    19,    58,    72,    69,    -1,    17,    52,
      83,    53,    68,   105,    69,    -1,    18,    39,    58,    72,
     105,    -1,    18,    36,    58,    72,   105,    -1,    18,    37,
      58,    72,   105,    -1,   112,    -1,     3,    34,     4,     5,
      68,   107,   109,   110,    69,    51,    -1,     3,    34,     4,
       6,    68,   108,   109,    69,    51,    -1,     3,    34,     4,
       7,    68,   111,    69,    51,    -1,     3,    34,     4,     8,
      68,     7,    59,    52,    34,    53,    51,   107,   110,   109,
     108,    69,    51,    -1,    52,    34,    59,    34,    61,    34,
      53,    59,    57,    68,    72,    69,    -1,    52,    34,    59,
      34,    63,    34,    53,    59,    57,    68,    72,    69,    -1,
      52,    34,    59,    36,    53,    59,    57,    68,    72,    69,
      -1,    52,    34,    59,    62,    34,    53,    59,    57,    68,
      72,    69,    -1,    52,    34,    59,    70,    34,    53,    59,
      57,    68,    72,    69,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    14,    14,    15,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    31,    32,    33,    34,    37,
      38,    41,    42,    43,    46,    47,    48,    49,    50,    53,
      54,    55,    58,    59,    62,    63,    64,    65,    66,    67,
      68,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      83,    84,    87,    88,    94,    95,    98,    99,   100,   104,
     105,   106,   107,   110,   111,   112,   113,   114,   115,   116,
     119,   120,   121,   122,   125,   126,   127,   130,   133,   134,
     135,   138,   139,   140,   141,   142,   143,   144,   145,   148,
     151,   152,   155,   156,   159,   160,   163,   164,   167,   170,
     171,   174,   177,   178,   181,   184,   185,   186,   193,   194,
     195,   196,   199,   200,   203,   204,   207,   208,   209,   210,
     213,   214,   215,   216,   219,   222,   225,   228,   231,   234
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
  "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_CONTINUE", "KW_CYCLIC",
  "KW_BIG_RATIONAL", "KW_COMPLEX", "KW_SYMMETRIC", "KW_ALTERNATING",
  "KW_DIHEDRAL", "KW_INV_MAT", "KW_BIGINT", "KW_MATRIX", "KW_POLYNOMIAL",
  "KW_VEC", "KW_BUF", "IDENT", "PRIMITIVE_DTYPE", "LIT_INT", "LIT_FLOAT",
  "LIT_STR", "LIT_CHAR", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "EQ",
  "NEQ", "GT", "LT", "GTEQ", "LTEQ", "KW_TRUE", "KW_FALSE", "';'", "'('",
  "')'", "','", "'.'", "'<'", "'>'", "':'", "'='", "'@'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'['", "']'", "'{'", "'}'", "'~'", "$accept",
  "statements", "statement", "print_param_list", "var", "field_data_type",
  "group_data_type", "ring_data_type", "space_data_type", "declaration",
  "A", "assignment", "expression", "arithmetic_expr", "term", "factor",
  "constant", "logical_expr", "B", "logical_op", "return_stmt",
  "call_stmt_standalone", "call_stmt", "pass_param_list",
  "unary_operation", "array_access", "C", "array_decl", "array_list",
  "if_else_conditional", "D", "loop_stmt", "V", "switch_case",
  "switch_case_blocks", "archetype_claim", "group_closure_rule",
  "ring_closure_rule", "identity_rule", "group_inverse_rule",
  "field_inverse_rule", "epsilon", 0
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
     305,    59,    40,    41,    44,    46,    60,    62,    58,    61,
      64,    43,    45,    42,    47,    37,    91,    93,   123,   125,
     126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    77,    77,    77,    78,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    97,
      97,    98,    99,    99,   100,   101,   101,   101,   102,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   106,   106,   107,   108,   109,   110,   111,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     5,     2,     2,     1,     1,     3,     1,     3,     1,
       3,     0,     1,     1,     4,     4,     4,     4,     6,     1,
       6,     4,     4,     4,     5,     8,     5,     5,     5,     5,
       5,     2,     1,     8,     5,     5,     5,     5,     5,     5,
       3,     3,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     4,     4,     3,     3,     1,     3,     3,     2,     4,
       3,     3,     3,     1,     5,     3,     5,     7,     7,    11,
      11,     7,     1,     1,    10,     7,     5,     5,     5,     1,
      10,     9,     8,    17,    12,    12,    10,    11,    11,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,   129,     0,     0,     0,     0,     6,     0,
       8,    10,     9,    14,     3,     0,     0,     0,    72,    71,
      73,    70,     0,    79,    80,     0,     0,     0,    63,    89,
      77,    58,    62,    66,    53,    75,    67,    69,    68,    54,
       0,     0,     0,     0,     0,    12,    13,     0,     1,     2,
       0,     0,     0,    98,     4,     5,     7,     0,     0,    73,
       0,    17,    21,    63,    77,    76,    77,     0,     0,    65,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    85,    86,    83,    84,    82,    81,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,    95,
       0,    50,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,    29,     0,
       0,     0,     0,   129,   129,   129,   129,   129,   129,    64,
      78,     0,     0,   101,    93,     0,    55,    96,    97,    56,
      57,    59,    60,    61,    74,     0,     0,     0,     0,     0,
       0,    91,     0,     0,   100,     0,     0,     0,     0,    16,
      11,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    42,    34,    39,    37,    38,    40,
     102,    92,   129,   104,   129,   129,     0,     0,   129,    94,
      90,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   129,   129,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,     0,     0,    31,    32,    33,   129,    21,   105,   108,
     111,     0,   112,     0,   113,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,    35,     0,   129,   129,   129,   129,   129,   129,
       0,     0,     0,   129,   129,   129,   129,     0,     0,     0,
       0,     0,   121,     0,     0,    28,    30,     0,    45,    44,
      48,    46,    47,    49,   129,   106,   129,   129,   129,   129,
     129,     0,     0,     0,     0,   120,     0,     0,     0,     0,
       0,     0,     0,   117,   118,   116,   114,     0,     0,     0,
       0,     0,     0,   129,   107,   110,   109,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,   129,     0,   129,     0,     0,   129,
       0,     0,     0,   126,   129,     0,   128,     0,   124,     0,
     125,   123,   127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    70,    14,   135,   136,   137,   138,    15,
     183,    16,    71,    40,    41,    42,    43,    44,    45,    99,
      17,    18,    46,   110,    47,    48,    63,    49,    81,    20,
     193,    21,   253,    22,   227,    23,   203,   205,   231,   264,
     207,    24
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -197
static const yytype_int16 yypact[] =
{
     120,    22,   -40,    29,   263,   -10,    18,    -5,    28,    17,
      32,    30,   104,   120,    43,    82,    85,   110,  -197,    69,
    -197,  -197,  -197,  -197,  -197,   161,   284,   109,  -197,  -197,
    -197,  -197,   324,  -197,  -197,   324,   -11,   113,   112,  -197,
      64,    33,  -197,  -197,  -197,   156,  -197,  -197,  -197,  -197,
     324,   324,   155,    14,   263,  -197,  -197,   141,  -197,  -197,
     181,   263,   145,  -197,  -197,  -197,  -197,   263,   219,   -20,
     131,   133,   365,   -17,    13,  -197,    16,   149,   -11,  -197,
     139,   144,   202,    29,   137,   154,   -11,   -11,   -11,   -11,
     -11,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,   324,
     168,   169,   198,   -28,   184,   186,   189,  -197,   194,   192,
     195,  -197,   182,  -197,   185,   188,   190,   191,   284,   199,
     284,   201,  -197,  -197,   204,   205,   206,   207,  -197,   209,
     210,   211,   213,   -22,   -22,   -22,   -22,   -22,   -22,  -197,
    -197,    16,   113,  -197,  -197,   217,  -197,  -197,  -197,    33,
      33,  -197,  -197,  -197,  -197,   208,   212,   214,   324,   324,
     220,  -197,   263,   224,   215,   225,   226,   227,   280,  -197,
    -197,  -197,   253,   254,   255,   257,   260,   262,   269,    73,
     273,    29,   263,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,   120,  -197,   120,   120,   258,   259,   293,  -197,
    -197,  -197,   282,   265,   285,   265,   290,   245,   268,   271,
     274,   275,   278,   276,   283,   281,   286,   288,   291,   295,
    -197,   272,   296,   298,    29,    29,   140,     3,  -197,   309,
     306,   297,   310,   301,   312,   304,   305,  -197,  -197,  -197,
    -197,   338,   341,  -197,  -197,  -197,   -22,   379,   364,  -197,
    -197,    77,  -197,   325,  -197,   326,   322,   323,   327,   357,
    -197,   348,   358,   349,   315,   382,   367,   350,  -197,   385,
     366,   368,  -197,   370,   -22,   -22,   -22,   -22,   -22,   -22,
       8,   353,   354,   120,   120,   120,   120,   363,   391,   369,
     378,   371,  -197,   396,   380,  -197,  -197,   397,  -197,  -197,
    -197,  -197,  -197,  -197,   120,  -197,   120,   120,   293,   293,
     293,   362,   401,   383,   375,  -197,   404,   386,   389,   384,
     373,   374,   376,  -197,  -197,  -197,  -197,   393,   388,   410,
     395,   390,   225,   -22,  -197,  -197,  -197,   392,   398,   399,
     394,   400,   297,  -197,   402,   403,   405,   406,   407,   265,
     408,   120,   409,   411,   120,   226,   120,   381,   412,   120,
     387,   413,   414,  -197,   120,   415,  -197,   416,  -197,   417,
    -197,  -197,  -197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,   -12,  -197,   -68,     4,   218,   221,   222,   223,   419,
    -132,   420,     6,    11,   119,    23,   -26,    49,  -197,  -197,
    -197,  -197,  -197,   -61,   -15,     0,   294,  -197,   318,   174,
    -197,  -197,   236,  -197,  -189,  -197,   130,   122,  -196,   132,
    -197,  -119
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      19,    59,   185,   186,   187,   188,   189,    27,    38,   233,
      39,    80,    26,    19,   184,   184,   184,   184,   184,   184,
       5,   145,   259,    11,     3,    28,    29,    30,    31,    52,
      38,    61,   181,   -15,   118,    82,    73,   182,    62,    73,
      73,    78,    50,    74,    84,    85,    76,    53,    11,    62,
     169,    36,   171,    19,    73,    73,    25,   103,    38,    79,
     106,    74,    74,    11,    38,    38,   109,   111,    55,   139,
      51,    38,   260,   113,    86,    87,   304,    86,    87,   228,
      54,    75,    73,    56,    77,    57,    38,   146,   109,   141,
      73,    73,    73,    73,    73,    60,    88,    89,    90,   100,
     101,   199,    61,    73,    58,   254,   254,   216,   217,    62,
      74,   151,   152,   153,   272,   -52,    80,   -52,   -52,   323,
     324,   325,    38,     1,    38,    86,    87,   184,    67,     2,
       3,     4,     5,    64,     6,     7,    65,     8,    84,    85,
       9,    10,   298,   299,   300,   301,   302,   303,   154,    28,
      29,    30,    31,   355,    11,   184,   184,   184,   184,   184,
     184,    66,    73,    73,    82,    68,    38,    72,   109,    74,
      74,   102,    83,    84,    85,   107,   256,   257,    62,   258,
     221,   112,   222,   223,   119,   219,    38,   120,   220,   228,
     228,   228,    19,   142,    19,    19,    91,    92,   147,    93,
      94,   343,   140,    95,    96,   149,   150,   196,   197,   252,
     252,   143,    97,    98,   184,    11,   148,    28,    29,    30,
      31,   155,   156,    32,   114,   115,   116,   117,   251,   251,
      33,    34,   157,    35,   108,   158,    11,   159,    28,    29,
      30,    31,   160,    36,    32,   161,   162,    37,   163,   164,
     170,    33,    34,   165,    35,   144,   166,   172,   167,   168,
     173,   174,   175,   176,    36,   177,   178,   179,    37,   180,
     191,   308,   309,   310,   311,   200,   192,   202,   204,   206,
     194,    62,   195,    19,    19,    19,    19,   208,   198,   209,
     210,   211,   320,   212,   321,   322,   213,    11,   214,    28,
      29,    30,    31,   215,    19,    32,    19,    19,   218,   224,
     225,   226,    33,    34,   235,    35,   229,   230,    11,   232,
      28,    29,    69,    31,   234,    36,    32,   236,   237,    37,
     241,   238,   239,    33,    34,   240,    35,   242,   243,   357,
     262,   248,   360,   244,   362,   245,    36,   365,   246,   263,
      37,    19,   369,   247,    19,   268,    19,   269,    11,    19,
      28,    29,    30,    31,    19,   249,    32,   250,   261,   265,
     266,   267,   270,    33,    34,   271,    35,   280,   281,   282,
     283,   284,   287,   289,   290,   285,    36,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   273,   274,   275,   286,   291,   288,   292,   294,
     293,   306,   307,   295,   312,   296,   297,   313,   314,   315,
     317,   326,   319,   318,   316,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   339,   336,   337,   338,   340,   341,
     363,   344,   346,   347,   305,   345,   366,   348,   201,   350,
     190,   255,   342,   353,   352,   276,   358,   371,   277,   278,
     279,   351,   104,   105,   349,   354,   356,   361,     0,   359,
     364,     0,   367,   368,   370,     0,   372
};

static const yytype_int16 yycheck[] =
{
       0,    13,   134,   135,   136,   137,   138,     3,     4,   205,
       4,    37,    52,    13,   133,   134,   135,   136,   137,   138,
      12,    82,    19,    34,    10,    36,    37,    38,    39,    34,
      26,    59,    54,    53,    54,    52,    32,    59,    66,    35,
      36,    52,    52,    32,    61,    62,    35,    52,    34,    66,
     118,    62,   120,    53,    50,    51,    34,    53,    54,    36,
      54,    50,    51,    34,    60,    61,    60,    61,    51,    53,
      52,    67,    69,    67,    61,    62,    68,    61,    62,   198,
      52,    32,    78,    51,    35,    55,    82,    83,    82,    78,
      86,    87,    88,    89,    90,    52,    63,    64,    65,    50,
      51,   162,    59,    99,     0,   224,   225,    34,    35,    66,
      99,    88,    89,    90,   246,    51,   142,    53,    54,   308,
     309,   310,   118,     3,   120,    61,    62,   246,    59,     9,
      10,    11,    12,    51,    14,    15,    51,    17,    61,    62,
      20,    21,   274,   275,   276,   277,   278,   279,    99,    36,
      37,    38,    39,   349,    34,   274,   275,   276,   277,   278,
     279,    51,   158,   159,    52,     4,   162,    58,   162,   158,
     159,    16,    60,    61,    62,    34,    36,    37,    66,    39,
     192,    36,   194,   195,    53,   181,   182,    54,   182,   308,
     309,   310,   192,    54,   194,   195,    40,    41,    61,    43,
      44,   333,    53,    47,    48,    86,    87,   158,   159,   224,
     225,    67,    56,    57,   333,    34,    62,    36,    37,    38,
      39,    53,    53,    42,     5,     6,     7,     8,   224,   225,
      49,    50,    34,    52,    53,    51,    34,    51,    36,    37,
      38,    39,    53,    62,    42,    51,    54,    66,    53,    67,
      51,    49,    50,    68,    52,    53,    68,    56,    68,    68,
      56,    56,    56,    56,    62,    56,    56,    56,    66,    56,
      53,   283,   284,   285,   286,    51,    68,    52,    52,    52,
      68,    66,    68,   283,   284,   285,   286,     7,    68,    36,
      36,    36,   304,    36,   306,   307,    36,    34,    36,    36,
      37,    38,    39,    34,   304,    42,   306,   307,    35,    51,
      51,    18,    49,    50,    69,    52,    34,    52,    34,    34,
      36,    37,    38,    39,    34,    62,    42,    59,    57,    66,
      54,    57,    57,    49,    50,    57,    52,    54,    57,   351,
      34,    69,   354,    57,   356,    57,    62,   359,    57,    52,
      66,   351,   364,    58,   354,    51,   356,    52,    34,   359,
      36,    37,    38,    39,   364,    69,    42,    69,    59,    59,
      69,    59,    34,    49,    50,    34,    52,    13,    53,    53,
      58,    58,    34,    34,    69,    58,    62,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    58,    34,    59,    51,    34,
      70,    68,    68,    57,    61,    57,    56,    36,    59,    51,
      34,    69,    35,    53,    63,    34,    53,    62,    34,    53,
      51,    57,    69,    69,    34,    69,    53,    59,    53,    59,
      69,    59,    53,    59,   280,    57,    69,    57,   164,    57,
     142,   225,   332,    57,    59,   247,    57,    51,   247,   247,
     247,    68,    53,    53,   342,    68,    68,   355,    -1,    68,
      68,    -1,    69,    69,    69,    -1,    69
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    14,    15,    17,    20,
      21,    34,    72,    73,    75,    80,    82,    91,    92,    96,
     100,   102,   104,   106,   112,    34,    52,    75,    36,    37,
      38,    39,    42,    49,    50,    52,    62,    66,    75,    83,
      84,    85,    86,    87,    88,    89,    93,    95,    96,    98,
      52,    52,    34,    52,    52,    51,    51,    55,     0,    72,
      52,    59,    66,    97,    51,    51,    51,    59,     4,    38,
      74,    83,    58,    75,    84,    88,    84,    88,    52,    86,
      87,    99,    52,    60,    61,    62,    61,    62,    63,    64,
      65,    40,    41,    43,    44,    47,    48,    56,    57,    90,
      88,    88,    16,    75,    80,    82,    83,    34,    53,    83,
      94,    83,    36,    83,     5,     6,     7,     8,    54,    53,
      54,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    76,    77,    78,    79,    53,
      53,    84,    54,    67,    53,    94,    75,    61,    62,    85,
      85,    86,    86,    86,    88,    53,    53,    34,    51,    51,
      53,    51,    54,    53,    67,    68,    68,    68,    68,    74,
      51,    74,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    54,    59,    81,   112,    81,    81,    81,    81,    81,
      99,    53,    68,   101,    68,    68,    88,    88,    68,    94,
      51,    97,    52,   107,    52,   108,    52,   111,     7,    36,
      36,    36,    36,    36,    36,    34,    34,    35,    35,    75,
      83,    72,    72,    72,    51,    51,    18,   105,   112,    34,
      52,   109,    34,   109,    34,    69,    59,    57,    57,    57,
      57,    54,    54,    57,    57,    57,    57,    58,    69,    69,
      69,    75,    95,   103,   112,   103,    36,    37,    39,    19,
      69,    59,    34,    52,   110,    59,    69,    59,    51,    52,
      34,    34,    81,    33,    34,    35,    76,    77,    78,    79,
      13,    53,    53,    58,    58,    58,    58,    34,    59,    34,
      69,    34,    51,    70,    34,    57,    57,    56,    81,    81,
      81,    81,    81,    81,    68,   100,    68,    68,    72,    72,
      72,    72,    61,    36,    59,    51,    63,    34,    53,    35,
      72,    72,    72,   105,   105,   105,    69,    34,    53,    62,
      34,    53,    51,    57,    69,    69,    69,    53,    59,    34,
      53,    59,   107,    81,    59,    57,    53,    59,    57,   110,
      57,    68,    59,    57,    68,   109,    68,    72,    57,    68,
      72,   108,    72,    69,    68,    72,    69,    69,    69,    72,
      69,    51,    69
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
        case 56:
#line 98 "temp_yacc.y"
    {printf("Rule: arithmetic_expr : arithmetic_expr \'+\' term\n");;}
    break;

  case 57:
#line 99 "temp_yacc.y"
    {printf("Rule: arithmetic_expr : arithmetic_expr \'-\' term\n");;}
    break;

  case 58:
#line 100 "temp_yacc.y"
    {printf("Rule: arithmetic_expr : term\n");;}
    break;

  case 59:
#line 104 "temp_yacc.y"
    {printf("Rule: term : term \'*\' factor\n");;}
    break;

  case 60:
#line 105 "temp_yacc.y"
    {printf("Rule: term : term \'/\' factor\n");;}
    break;

  case 61:
#line 106 "temp_yacc.y"
    {printf("Rule: term : term \'\%\' factor\n");;}
    break;

  case 62:
#line 107 "temp_yacc.y"
    {printf("Rule: term : factor\n");;}
    break;

  case 63:
#line 110 "temp_yacc.y"
    {printf("Rule: factor : var\n");;}
    break;

  case 64:
#line 111 "temp_yacc.y"
    {printf("Rule: factor : \'(\' arithmetic_expr \')\'\n");;}
    break;

  case 66:
#line 113 "temp_yacc.y"
    {printf("Rule: factor : constant\n");;}
    break;

  case 67:
#line 114 "temp_yacc.y"
    {printf("Rule: factor : call_stmt\n");;}
    break;

  case 68:
#line 115 "temp_yacc.y"
    {printf("Rule: factor : array_access\n");;}
    break;

  case 69:
#line 116 "temp_yacc.y"
    {printf("Rule: factor : unary_operation\n");;}
    break;

  case 120:
#line 213 "temp_yacc.y"
    {printf("Group claim rule\n");;}
    break;

  case 124:
#line 219 "temp_yacc.y"
    {printf("Group_closure_rule\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1820 "y.tab.c"
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


#line 236 "temp_yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

