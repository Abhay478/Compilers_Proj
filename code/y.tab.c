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
     VARIANT = 311
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
#line 226 "code/y.tab.c"

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  343

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,     2,     2,    63,     2,     2,
      68,    69,    61,    59,    72,    60,    66,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    67,
      58,    73,    57,     2,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,    71,    77,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    17,    19,    22,
      25,    27,    30,    32,    34,    36,    42,    45,    48,    50,
      54,    56,    60,    64,    65,    67,    69,    74,    79,    84,
      89,    96,    98,   105,   110,   115,   120,   123,   126,   128,
     133,   135,   137,   139,   141,   143,   146,   149,   151,   155,
     159,   161,   163,   165,   167,   171,   175,   179,   183,   187,
     191,   195,   198,   202,   206,   210,   212,   214,   216,   218,
     220,   222,   224,   228,   230,   233,   239,   244,   249,   253,
     257,   259,   262,   265,   268,   273,   277,   281,   285,   287,
     293,   295,   299,   303,   309,   319,   329,   335,   337,   339,
     350,   358,   364,   370,   376,   378,   389,   399,   408,   426,
     436,   446,   454,   463,   472,   477,   485,   487,   489,   493,
     497,   503,   505,   509,   515,   517,   521
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      79,     0,    -1,    80,    -1,    79,   116,    -1,    79,   121,
      -1,    79,   123,    -1,    81,    80,    -1,   125,    -1,    88,
      67,    -1,    92,    67,    -1,    96,    -1,    95,    67,    -1,
     104,    -1,   108,    -1,   106,    -1,     9,    68,    98,    69,
      67,    -1,    20,    67,    -1,    21,    67,    -1,   110,    -1,
      70,    80,    71,    -1,    39,    -1,    83,    66,    39,    -1,
      39,    56,    39,    -1,    -1,    28,    -1,    29,    -1,    27,
      58,    41,    57,    -1,    30,    58,    41,    57,    -1,    31,
      58,    41,    57,    -1,    32,    58,    41,    57,    -1,    33,
      58,    41,    72,    39,    57,    -1,    34,    -1,    35,    58,
      41,    72,    39,    57,    -1,    36,    58,    39,    57,    -1,
      37,    58,    39,    57,    -1,    37,    58,    40,    57,    -1,
      10,    89,    -1,   120,    91,    -1,    40,    -1,    38,    58,
      40,    57,    -1,    39,    -1,    85,    -1,    86,    -1,    84,
      -1,    87,    -1,    73,    94,    -1,    72,    89,    -1,   125,
      -1,    83,    73,    94,    -1,   100,    73,    94,    -1,    44,
      -1,    42,    -1,    41,    -1,    43,    -1,    94,    59,    94,
      -1,    94,    60,    94,    -1,    94,    61,    94,    -1,    94,
      62,    94,    -1,    94,    63,    94,    -1,    68,    94,    69,
      -1,    94,    45,    94,    -1,    65,    94,    -1,    94,    46,
      94,    -1,    94,    57,    94,    -1,    94,    58,    94,    -1,
      83,    -1,    93,    -1,    99,    -1,   100,    -1,    97,    -1,
      47,    -1,    48,    -1,    94,    64,    94,    -1,   102,    -1,
      11,    94,    -1,    83,    68,    98,    69,    67,    -1,    83,
      68,    69,    67,    -1,    83,    68,    98,    69,    -1,    83,
      68,    69,    -1,    94,    72,    98,    -1,    94,    -1,    83,
      53,    -1,    83,    54,    -1,    83,   101,    -1,    74,    41,
      75,   101,    -1,    74,    41,    75,    -1,    74,   103,    75,
      -1,    93,    72,   103,    -1,    93,    -1,    12,    68,    94,
      69,   105,    -1,    82,    -1,    82,    13,   104,    -1,    82,
      13,    82,    -1,    14,    68,    94,    69,    82,    -1,    15,
      68,    92,    67,    94,    67,   107,    69,    82,    -1,    15,
      68,    88,    67,    94,    67,   107,    69,    82,    -1,    15,
      39,    16,    39,    82,    -1,    99,    -1,   125,    -1,    17,
      68,    94,    69,    70,   109,    19,    76,    80,    71,    -1,
      17,    68,    94,    69,    70,   109,    71,    -1,    18,    44,
      76,    80,   109,    -1,    18,    41,    76,    80,   109,    -1,
      18,    42,    76,    80,   109,    -1,   125,    -1,     3,    39,
       4,     5,    70,   111,   113,   114,    71,    67,    -1,     3,
      39,     4,     6,    70,   112,   113,    71,    67,    -1,     3,
      39,     4,     7,    70,   115,    71,    67,    -1,     3,    39,
       4,     8,    70,     7,    73,    68,    39,    69,    67,   111,
     114,   113,   112,    71,    67,    -1,    68,    39,    73,    39,
      59,    39,    69,    55,    82,    -1,    68,    39,    73,    39,
      61,    39,    69,    55,    82,    -1,    68,    39,    73,    41,
      69,    55,    82,    -1,    68,    39,    73,    60,    39,    69,
      55,    82,    -1,    68,    39,    73,    77,    39,    69,    55,
      82,    -1,   117,    70,   118,    71,    -1,    22,    39,    68,
     119,    69,    76,    90,    -1,    80,    -1,   120,    -1,   119,
      72,   120,    -1,    83,    76,    90,    -1,    25,    39,    70,
     122,    71,    -1,    39,    -1,   120,    72,    39,    -1,    26,
      39,    70,   124,    71,    -1,    39,    -1,   124,    72,    39,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    20,    20,    21,    22,    23,    25,    26,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      45,    46,    47,    50,    51,    52,    55,    56,    57,    58,
      59,    62,    63,    64,    67,    68,    71,    74,    76,    77,
      78,    79,    80,    81,    82,    85,    86,    87,    90,    91,
      94,    95,    96,    97,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   111,   111,   111,   111,
     112,   112,   113,   119,   194,   197,   198,   201,   202,   205,
     206,   209,   210,   213,   216,   217,   220,   223,   224,   227,
     230,   231,   232,   239,   240,   241,   242,   245,   246,   249,
     250,   253,   254,   255,   256,   259,   260,   261,   262,   265,
     268,   271,   274,   277,   280,   283,   286,   289,   290,   293,
     296,   298,   299,   301,   303,   304,   306
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
  "FIELD", "SPACE", "INCR", "DECR", "ARROW", "VARIANT", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'@'", "'!'", "'.'", "';'", "'('",
  "')'", "'{'", "'}'", "','", "'='", "'['", "']'", "':'", "'~'", "$accept",
  "P", "statements", "statement", "body", "var", "field_data_type",
  "group_data_type", "ring_data_type", "space_data_type", "declaration",
  "decl_tail", "type", "decl_cntd", "assignment", "constant", "expression",
  "return_stmt", "call_stmt_standalone", "call_stmt", "pass_param_list",
  "unary_operation", "array_access", "C", "array_decl", "array_list",
  "if_else_conditional", "if_body", "loop_stmt", "V", "switch_case",
  "switch_case_blocks", "archetype_claim", "group_closure_rule",
  "ring_closure_rule", "identity_rule", "group_inverse_rule",
  "field_inverse_rule", "function", "function_header", "function_body",
  "parameter_list", "typ_var", "struct", "attr_list", "enum",
  "variant_list", "epsilon", 0
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
     305,   306,   307,   308,   309,   310,   311,    62,    60,    43,
      45,    42,    47,    37,    64,    33,    46,    59,    40,    41,
     123,   125,    44,    61,    91,    93,    58,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    79,    79,    80,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      83,    83,    83,    84,    84,    84,    85,    85,    85,    85,
      85,    86,    86,    86,    87,    87,    88,    89,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   101,   102,   103,   103,   104,
     105,   105,   105,   106,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   110,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   119,   120,
     121,   122,   122,   123,   124,   124,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     1,     2,     2,
       1,     2,     1,     1,     1,     5,     2,     2,     1,     3,
       1,     3,     3,     0,     1,     1,     4,     4,     4,     4,
       6,     1,     6,     4,     4,     4,     2,     2,     1,     4,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     5,     4,     4,     3,     3,
       1,     2,     2,     2,     4,     3,     3,     3,     1,     5,
       1,     3,     3,     5,     9,     9,     5,     1,     1,    10,
       7,     5,     5,     5,     1,    10,     9,     8,    17,     9,
       9,     7,     8,     8,     4,     7,     1,     1,     3,     3,
       5,     1,     3,     5,     1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     2,   126,     0,     0,     0,     0,    10,
       0,    12,    14,    13,    18,     7,     0,     0,     0,    36,
     126,    52,    51,    53,    50,    70,    71,     0,     0,     0,
      65,    66,    74,    69,    67,    68,    73,     0,     0,     0,
       0,     0,    16,    17,     0,     1,     0,     0,     0,     3,
       0,     4,     5,     6,     0,     0,     0,     0,    83,     8,
       9,    11,     0,     0,    80,     0,    23,     0,     0,    37,
      47,    61,     0,    88,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,   126,
      21,     0,     0,    48,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,    31,
       0,     0,     0,     0,    40,    38,    43,    41,    42,    44,
     119,    46,    45,    59,     0,    86,    78,     0,    60,    62,
      63,    64,    54,    55,    56,    57,    58,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,    76,
       0,    85,     0,     0,     0,     0,    79,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    77,   126,
      90,    89,    93,    96,     0,     0,   126,     0,   117,    20,
       0,     0,   124,     0,   114,    75,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,   126,     0,     0,
     104,     0,     0,     0,   120,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
       0,    33,    34,    35,    39,    19,    92,    91,     0,    97,
       0,    98,     0,     0,     0,     0,     0,   100,    23,   118,
     122,   125,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,   126,   126,   126,   126,   115,
       0,     0,     0,     0,     0,   106,     0,     0,    30,    32,
      95,    94,   126,   126,   126,     0,     0,     0,     0,   105,
       0,     0,     0,   102,   103,   101,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,   113,     0,   109,     0,   110,     0,   112,
       0,     0,   108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,   190,    40,   136,   137,   138,   139,
      16,    29,   140,    79,    17,    41,    74,    18,    19,    43,
      75,    44,    45,    68,    46,    84,    21,   191,    22,   260,
      23,   229,    24,   208,   210,   239,   275,   212,    59,    60,
     168,   197,    30,    61,   201,    62,   203,    25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -205
static const yytype_int16 yypact[] =
{
      12,    -8,   -21,    19,   114,   -12,    -7,   -20,     7,     2,
      41,    10,    17,  -205,    12,    31,    56,    62,    87,  -205,
      69,  -205,  -205,  -205,  -205,  -205,    81,   114,   -46,  -205,
     -35,  -205,  -205,  -205,  -205,  -205,  -205,   114,   114,    40,
       6,  -205,   316,  -205,  -205,  -205,  -205,   114,   114,    63,
      18,   114,  -205,  -205,   124,  -205,   129,   130,   131,  -205,
     103,  -205,  -205,  -205,   135,    59,   114,   137,  -205,  -205,
    -205,  -205,   114,   143,   146,   112,   354,    19,   114,  -205,
    -205,  -205,   176,   111,   110,  -205,  -205,    78,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   196,   236,
     147,   -11,   120,   123,   256,  -205,   126,   125,   127,    12,
    -205,   132,   142,   316,   121,   316,   128,   144,   145,   149,
     114,   133,   154,  -205,  -205,   155,   158,   159,   162,  -205,
     165,   166,   167,   170,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,   316,  -205,    40,  -205,  -205,   160,    75,    75,
      75,    75,  -205,  -205,  -205,  -205,  -205,  -205,   161,   161,
     161,   114,   114,   173,    19,   191,   205,  -205,   175,  -205,
     180,   174,   181,   182,   183,   245,  -205,  -205,   220,   221,
     222,   223,   225,   226,   229,   101,   230,  -205,  -205,    12,
     258,  -205,  -205,  -205,   276,   296,   251,   -28,  -205,   -31,
     204,   209,  -205,    73,  -205,  -205,  -205,   244,   216,   264,
     216,   265,   235,   234,   252,   253,   254,   255,   257,   259,
     266,   267,   269,   270,   237,     1,    19,    19,    74,    -3,
    -205,   268,    19,   289,  -205,  -205,   291,   272,   293,   278,
     274,   277,   279,   282,   283,  -205,  -205,  -205,  -205,   311,
     325,  -205,  -205,  -205,  -205,  -205,  -205,  -205,    -1,  -205,
     297,  -205,   298,   292,   294,   295,   319,  -205,   354,  -205,
    -205,  -205,   326,   299,   330,   327,   357,   332,   320,  -205,
     361,   344,   345,   161,   161,    12,    12,    12,    12,  -205,
     346,   362,   331,   339,   347,  -205,   368,   340,  -205,  -205,
    -205,  -205,   251,   251,   251,   341,   371,   342,   353,  -205,
     375,   348,   349,  -205,  -205,  -205,  -205,   350,   360,   379,
     351,   366,   181,   367,   161,   355,   370,   161,   278,   161,
    -205,   372,   161,  -205,   216,  -205,   161,  -205,   182,  -205,
     352,   359,  -205
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,   -13,  -205,  -152,     0,  -205,  -205,  -205,  -205,
     378,   356,   163,  -205,   380,   -30,    -2,  -205,  -205,  -205,
     -53,   -60,     4,   261,  -205,   285,   210,  -205,  -205,   207,
    -205,  -192,  -205,   115,    98,  -204,   113,  -205,  -205,  -205,
    -205,  -205,  -154,  -205,  -205,  -205,  -205,   -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -122
static const yytype_int16 yytable[] =
{
      15,    63,    42,    28,    20,    80,   241,   192,   193,    83,
     198,   200,   112,     5,    15,     1,   266,    55,    20,    49,
      64,     2,     3,     4,     5,    54,     6,     7,     3,     8,
      76,    26,     9,    10,   147,    81,    82,    77,    78,    56,
    -121,   231,    57,    58,   232,    98,    99,    27,    50,   104,
     101,    11,    85,    86,    20,    64,    47,    11,    11,    85,
      86,    48,    66,    67,   113,    64,    54,   176,   267,    52,
     115,   189,    64,   256,    87,    51,   142,    28,   269,   100,
      67,    31,    32,    33,    34,    73,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   167,    64,    11,    65,
      31,    32,    33,    34,    66,    67,    35,    36,    53,    15,
     313,   314,   315,    20,    83,   263,   264,    11,   265,    31,
      32,    33,    34,    69,    37,    35,    36,    38,   111,    70,
     338,   300,   301,    39,    92,    93,    94,    95,    96,    97,
     221,   222,    72,    37,   235,   236,    38,   146,   116,   117,
     118,   119,    39,    11,    71,    31,    32,    33,    34,   194,
     195,    35,    36,   105,    28,    28,   259,   259,   106,   107,
     108,   230,   330,   109,   110,   333,   224,   335,   114,    37,
     337,   121,    38,   144,   339,   145,   160,   161,    39,    15,
     162,    88,    89,    20,   164,   165,   171,   166,   172,   169,
     177,   261,   261,    90,    91,    92,    93,    94,    95,    96,
      97,   170,   178,   179,   173,   174,   180,   181,   120,   175,
     182,    88,    89,   183,   184,   185,   258,   258,   186,   188,
     199,   189,    28,    90,    91,    92,    93,    94,    95,    96,
      97,    88,    89,   196,   202,   143,   204,   205,    67,   207,
     209,   211,   213,    90,    91,    92,    93,    94,    95,    96,
      97,   214,   215,   216,   217,   158,   218,   219,   220,   228,
     223,   225,   302,   303,   304,   305,   233,   230,   230,   230,
     234,    88,    89,   237,   238,    15,    15,    15,    15,    20,
      20,    20,    20,    90,    91,    92,    93,    94,    95,    96,
      97,    88,    89,   240,   242,   159,   243,   244,   255,   245,
     246,   247,   248,    90,    91,    92,    93,    94,    95,    96,
      97,    88,    89,   251,   252,   163,   253,   254,   270,   249,
     271,   250,   273,    90,    91,    92,    93,    94,    95,    96,
      97,    88,    89,   226,   268,   272,   274,   276,   277,   279,
     281,   280,   278,    90,    91,    92,    93,    94,    95,    96,
      97,    88,    89,   227,   282,   290,   283,   284,   285,   292,
     286,   287,   291,    90,    91,    92,    93,    94,    95,    96,
      97,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   288,   294,   296,   293,   295,
     297,   298,   299,   307,   308,   306,   309,   311,   310,   312,
     317,   318,   316,   319,   320,   324,   322,   321,   325,   323,
     326,   327,   329,   341,   331,   332,   342,   336,   102,   187,
     103,   289,   206,   141,   262,   257,   340,   328,     0,     0,
       0,   334
};

static const yytype_int16 yycheck[] =
{
       0,    14,     4,     3,     0,    30,   210,   159,   160,    39,
     164,   165,    65,    12,    14,     3,    19,     0,    14,    39,
      66,     9,    10,    11,    12,    56,    14,    15,    10,    17,
      76,    39,    20,    21,    87,    37,    38,    72,    73,    22,
      71,    69,    25,    26,    72,    47,    48,    68,    68,    51,
      50,    39,    53,    54,    50,    66,    68,    39,    39,    53,
      54,    68,    73,    74,    66,    66,    56,   120,    71,    67,
      72,    70,    66,   225,    68,    68,    78,    77,   232,    16,
      74,    41,    42,    43,    44,     4,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   109,    66,    39,    68,
      41,    42,    43,    44,    73,    74,    47,    48,    67,   109,
     302,   303,   304,   109,   144,    41,    42,    39,    44,    41,
      42,    43,    44,    67,    65,    47,    48,    68,    69,    67,
     334,   283,   284,    74,    59,    60,    61,    62,    63,    64,
      39,    40,    73,    65,    71,    72,    68,    69,     5,     6,
       7,     8,    74,    39,    67,    41,    42,    43,    44,   161,
     162,    47,    48,    39,   164,   165,   226,   227,    39,    39,
      39,   196,   324,    70,    39,   327,   189,   329,    41,    65,
     332,    69,    68,    72,   336,    75,    39,    67,    74,   189,
      67,    45,    46,   189,    68,    70,    75,    70,    70,    67,
      67,   226,   227,    57,    58,    59,    60,    61,    62,    63,
      64,    69,    58,    58,    70,    70,    58,    58,    72,    70,
      58,    45,    46,    58,    58,    58,   226,   227,    58,    69,
      39,    70,   232,    57,    58,    59,    60,    61,    62,    63,
      64,    45,    46,    70,    39,    69,    71,    67,    74,    68,
      68,    68,     7,    57,    58,    59,    60,    61,    62,    63,
      64,    41,    41,    41,    41,    69,    41,    41,    39,    18,
      40,    13,   285,   286,   287,   288,    72,   302,   303,   304,
      71,    45,    46,    39,    68,   285,   286,   287,   288,   285,
     286,   287,   288,    57,    58,    59,    60,    61,    62,    63,
      64,    45,    46,    39,    39,    69,    71,    73,    71,    57,
      57,    57,    57,    57,    58,    59,    60,    61,    62,    63,
      64,    45,    46,    57,    57,    69,    57,    57,    39,    72,
      39,    72,    39,    57,    58,    59,    60,    61,    62,    63,
      64,    45,    46,    67,    76,    73,    68,    73,    71,    67,
      39,    68,    73,    57,    58,    59,    60,    61,    62,    63,
      64,    45,    46,    67,    39,    39,    69,    69,    76,    39,
      76,    76,    73,    57,    58,    59,    60,    61,    62,    63,
      64,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    76,    39,    77,    71,    67,
      39,    57,    57,    41,    73,    59,    67,    39,    61,    69,
      39,    69,    71,    60,    39,    55,    67,    69,    39,    69,
      69,    55,    55,    71,    69,    55,    67,    55,    50,   144,
      50,   268,   171,    77,   227,   225,   338,   322,    -1,    -1,
      -1,   328
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    14,    15,    17,    20,
      21,    39,    79,    80,    81,    83,    88,    92,    95,    96,
     100,   104,   106,   108,   110,   125,    39,    68,    83,    89,
     120,    41,    42,    43,    44,    47,    48,    65,    68,    74,
      83,    93,    94,    97,    99,   100,   102,    68,    68,    39,
      68,    68,    67,    67,    56,     0,    22,    25,    26,   116,
     117,   121,   123,    80,    66,    68,    73,    74,   101,    67,
      67,    67,    73,     4,    94,    98,    76,    72,    73,    91,
     125,    94,    94,    93,   103,    53,    54,    68,    45,    46,
      57,    58,    59,    60,    61,    62,    63,    64,    94,    94,
      16,    83,    88,    92,    94,    39,    39,    39,    39,    70,
      39,    69,    98,    94,    41,    94,     5,     6,     7,     8,
      72,    69,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    84,    85,    86,    87,
      90,    89,    94,    69,    72,    75,    69,    98,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    69,    69,
      39,    67,    67,    69,    68,    70,    70,    80,   118,    67,
      69,    75,    70,    70,    70,    70,    98,    67,    58,    58,
      58,    58,    58,    58,    58,    58,    58,   103,    69,    70,
      82,   105,    82,    82,    94,    94,    70,   119,   120,    39,
     120,   122,    39,   124,    71,    67,   101,    68,   111,    68,
     112,    68,   115,     7,    41,    41,    41,    41,    41,    41,
      39,    39,    40,    40,    80,    13,    67,    67,    18,   109,
     125,    69,    72,    72,    71,    71,    72,    39,    68,   113,
      39,   113,    39,    71,    73,    57,    57,    57,    57,    72,
      72,    57,    57,    57,    57,    71,    82,   104,    83,    99,
     107,   125,   107,    41,    42,    44,    19,    71,    76,   120,
      39,    39,    73,    39,    68,   114,    73,    71,    73,    67,
      68,    39,    39,    69,    69,    76,    76,    76,    76,    90,
      39,    73,    39,    71,    39,    67,    77,    39,    57,    57,
      82,    82,    80,    80,    80,    80,    59,    41,    73,    67,
      61,    39,    69,   109,   109,   109,    71,    39,    69,    60,
      39,    69,    67,    69,    55,    39,    69,    55,   111,    55,
      82,    69,    55,    82,   114,    82,    55,    82,   113,    82,
     112,    71,    67
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
        case 105:
#line 259 "code/yacc.y"
    {printf("Group claim rule\n");;}
    break;

  case 109:
#line 265 "code/yacc.y"
    {printf("Group_closure_rule\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1747 "code/y.tab.c"
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


#line 308 "code/yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

