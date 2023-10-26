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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  340

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
     257,   259,   262,   265,   268,   272,   276,   278,   284,   286,
     290,   294,   300,   310,   320,   326,   328,   330,   341,   349,
     355,   361,   367,   369,   380,   390,   399,   417,   427,   437,
     445,   454,   463,   468,   476,   478,   480,   484,   488,   494,
     496,   500,   506,   508,   512
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      79,     0,    -1,    80,    -1,    79,   115,    -1,    79,   120,
      -1,    79,   122,    -1,    81,    80,    -1,   124,    -1,    88,
      67,    -1,    92,    67,    -1,    96,    -1,    95,    67,    -1,
     103,    -1,   107,    -1,   105,    -1,     9,    68,    98,    69,
      67,    -1,    20,    67,    -1,    21,    67,    -1,   109,    -1,
      70,    80,    71,    -1,    39,    -1,    83,    66,    39,    -1,
      39,    56,    39,    -1,    -1,    28,    -1,    29,    -1,    27,
      58,    41,    57,    -1,    30,    58,    41,    57,    -1,    31,
      58,    41,    57,    -1,    32,    58,    41,    57,    -1,    33,
      58,    41,    72,    39,    57,    -1,    34,    -1,    35,    58,
      41,    72,    39,    57,    -1,    36,    58,    39,    57,    -1,
      37,    58,    39,    57,    -1,    37,    58,    40,    57,    -1,
      10,    89,    -1,   119,    91,    -1,    40,    -1,    38,    58,
      40,    57,    -1,    39,    -1,    85,    -1,    86,    -1,    84,
      -1,    87,    -1,    73,    94,    -1,    72,    89,    -1,   124,
      -1,    83,    73,    94,    -1,   100,    73,    94,    -1,    44,
      -1,    42,    -1,    41,    -1,    43,    -1,    94,    59,    94,
      -1,    94,    60,    94,    -1,    94,    61,    94,    -1,    94,
      62,    94,    -1,    94,    63,    94,    -1,    68,    94,    69,
      -1,    94,    45,    94,    -1,    65,    94,    -1,    94,    46,
      94,    -1,    94,    57,    94,    -1,    94,    58,    94,    -1,
      83,    -1,    93,    -1,    99,    -1,   100,    -1,    97,    -1,
      47,    -1,    48,    -1,    94,    64,    94,    -1,   101,    -1,
      11,    94,    -1,    39,    68,    98,    69,    67,    -1,    39,
      68,    69,    67,    -1,    39,    68,    98,    69,    -1,    39,
      68,    69,    -1,    94,    72,    98,    -1,    94,    -1,    83,
      53,    -1,    83,    54,    -1,    83,   101,    -1,    74,   102,
      75,    -1,    93,    72,   102,    -1,    93,    -1,    12,    68,
      94,    69,   104,    -1,    82,    -1,    82,    13,   103,    -1,
      82,    13,    82,    -1,    14,    68,    94,    69,    82,    -1,
      15,    68,    92,    67,    94,    67,   106,    69,    82,    -1,
      15,    68,    88,    67,    94,    67,   106,    69,    82,    -1,
      15,    39,    16,    39,    82,    -1,    99,    -1,   124,    -1,
      17,    68,    94,    69,    70,   108,    19,    76,    80,    71,
      -1,    17,    68,    94,    69,    70,   108,    71,    -1,    18,
      44,    76,    80,   108,    -1,    18,    41,    76,    80,   108,
      -1,    18,    42,    76,    80,   108,    -1,   124,    -1,     3,
      39,     4,     5,    70,   110,   112,   113,    71,    67,    -1,
       3,    39,     4,     6,    70,   111,   112,    71,    67,    -1,
       3,    39,     4,     7,    70,   114,    71,    67,    -1,     3,
      39,     4,     8,    70,     7,    73,    68,    39,    69,    67,
     110,   113,   112,   111,    71,    67,    -1,    68,    39,    73,
      39,    59,    39,    69,    55,    82,    -1,    68,    39,    73,
      39,    61,    39,    69,    55,    82,    -1,    68,    39,    73,
      41,    69,    55,    82,    -1,    68,    39,    73,    60,    39,
      69,    55,    82,    -1,    68,    39,    73,    77,    39,    69,
      55,    82,    -1,   116,    70,   117,    71,    -1,    22,    39,
      68,   118,    69,    76,    90,    -1,    80,    -1,   119,    -1,
     118,    72,   119,    -1,    83,    76,    90,    -1,    25,    39,
      70,   121,    71,    -1,    39,    -1,   119,    72,    39,    -1,
      26,    39,    70,   123,    71,    -1,    39,    -1,   123,    72,
      39,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    20,    20,    21,    22,    23,    25,    26,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      45,    46,    47,    50,    51,    52,    55,    56,    57,    58,
      59,    62,    63,    64,    67,    68,    71,    74,    76,    77,
      78,    79,    80,    81,    82,    85,    86,    87,    90,    91,
      94,    95,    96,    97,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   111,   111,   111,   111,
     112,   112,   113,   114,   117,   120,   121,   124,   125,   128,
     129,   132,   133,   136,   143,   146,   147,   150,   153,   154,
     155,   162,   163,   164,   165,   168,   169,   172,   173,   176,
     177,   178,   179,   182,   183,   184,   185,   188,   191,   194,
     197,   200,   203,   206,   209,   212,   213,   216,   219,   221,
     222,   224,   226,   227,   229
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
  "unary_operation", "array_access", "array_decl", "array_list",
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
      98,    99,    99,   100,   101,   102,   102,   103,   104,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   108,
     108,   108,   108,   109,   109,   109,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   118,   119,   120,   121,
     121,   122,   123,   123,   124
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
       1,     2,     2,     2,     3,     3,     1,     5,     1,     3,
       3,     5,     9,     9,     5,     1,     1,    10,     7,     5,
       5,     5,     1,    10,     9,     8,    17,     9,     9,     7,
       8,     8,     4,     7,     1,     1,     3,     3,     5,     1,
       3,     5,     1,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     2,   124,     0,     0,     0,     0,    10,
       0,    12,    14,    13,    18,     7,     0,     0,    20,     0,
      36,   124,    20,    52,    51,    53,    50,    70,    71,     0,
       0,     0,    65,    66,    74,    69,    67,    68,    73,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     1,     0,
       0,     0,     3,     0,     4,     5,     6,     0,     0,    83,
       8,     9,    11,     0,     0,    80,     0,    23,     0,     0,
      37,    47,     0,    61,     0,    86,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,   124,    21,    48,    49,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,     0,    31,     0,
       0,     0,     0,    40,    38,    43,    41,    42,    44,   117,
      46,    45,    78,     0,    59,     0,    84,    60,    62,    63,
      64,    54,    55,    56,    57,    58,    72,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,    79,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    85,   124,    88,    87,
      91,    94,     0,     0,   124,    75,     0,   115,    20,     0,
       0,   122,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   124,     0,     0,   102,     0,     0,
       0,   118,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,    27,    28,    29,     0,     0,    33,    34,
      35,    39,    19,    90,    89,     0,    95,     0,    96,     0,
       0,     0,     0,     0,    98,    23,   116,   120,   123,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,   124,   124,   124,   124,   113,     0,     0,     0,
       0,     0,   104,     0,     0,    30,    32,    93,    92,   124,
     124,   124,     0,     0,     0,     0,   103,     0,     0,     0,
     100,   101,    99,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
     111,     0,   107,     0,   108,     0,   110,     0,     0,   106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,   188,    42,   135,   136,   137,   138,
      16,    30,   139,    80,    17,    43,    75,    18,    19,    45,
      76,    46,    47,    48,    86,    21,   189,    22,   257,    23,
     226,    24,   205,   207,   236,   272,   209,    62,    63,   169,
     196,    31,    64,   200,    65,   202,    25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -219
static const yytype_int16 yypact[] =
{
      14,    -3,   -22,    10,   160,     2,    23,   -23,    31,   -34,
      -5,   -29,    32,  -219,    14,    19,    57,    58,    60,  -219,
      55,  -219,  -219,  -219,  -219,  -219,    68,   160,    21,   -36,
    -219,   -51,    12,  -219,  -219,  -219,  -219,  -219,  -219,   160,
     160,    53,   -11,  -219,   333,  -219,  -219,  -219,  -219,   160,
     160,   121,     9,   160,  -219,  -219,    99,    75,  -219,   100,
     102,   103,  -219,    81,  -219,  -219,  -219,   117,   160,  -219,
    -219,  -219,  -219,   160,   140,   181,    88,   182,    10,   160,
    -219,  -219,   111,  -219,   233,    89,    85,  -219,  -219,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   253,
     273,   123,    96,    97,   293,  -219,   110,    98,   101,   113,
     114,    14,  -219,   333,   333,   116,   118,   119,   120,   160,
     125,   135,  -219,  -219,   136,   137,   138,   142,  -219,   147,
     148,   172,   173,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,   333,  -219,   112,  -219,    53,  -219,    72,    72,    72,
      72,  -219,  -219,  -219,  -219,  -219,  -219,   162,   162,   162,
     160,   160,   163,  -219,   168,    10,   197,   198,  -219,   177,
     183,   184,   186,   242,  -219,  -219,   209,   214,   215,   216,
     225,   226,   237,    27,   240,  -219,  -219,    14,   264,  -219,
    -219,  -219,   201,   313,   263,  -219,   -31,  -219,   -12,   228,
     230,  -219,    41,  -219,   265,   235,   266,   235,   267,   236,
     247,   251,   252,   268,   269,   249,   255,   271,   272,   283,
     284,   274,    -1,    10,    10,    45,    -6,  -219,   248,    10,
     304,  -219,  -219,   305,   250,   307,   279,   275,   278,   287,
     294,   295,  -219,  -219,  -219,  -219,   325,   326,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,    22,  -219,   297,  -219,   298,
     292,   306,   308,   309,  -219,   182,  -219,  -219,  -219,   330,
     310,   342,   315,   348,   321,   312,  -219,   359,   343,   344,
     162,   162,    14,    14,    14,    14,  -219,   340,   361,   331,
     336,   345,  -219,   366,   338,  -219,  -219,  -219,  -219,   263,
     263,   263,   337,   370,   341,   351,  -219,   373,   346,   347,
    -219,  -219,  -219,  -219,   349,   358,   377,   350,   362,   183,
     365,   162,   352,   367,   162,   279,   162,  -219,   368,   162,
    -219,   235,  -219,   162,  -219,   184,  -219,   353,   360,  -219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,   -13,  -219,  -151,     0,  -219,  -219,  -219,  -219,
     374,   354,   164,  -219,   376,   -35,    11,  -219,  -219,  -219,
     -45,  -103,     4,     5,   280,   208,  -219,  -219,   207,  -219,
    -218,  -219,   115,   104,  -205,   108,  -219,  -219,  -219,  -219,
    -219,  -156,  -219,  -219,  -219,  -219,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -120
static const yytype_int16 yytable[] =
{
      15,    66,   238,    29,    20,    81,    85,   190,   191,   197,
     199,     5,   107,   263,    15,    44,    51,     1,    20,     3,
      69,    78,    79,     2,     3,     4,     5,    56,     6,     7,
      67,     8,    58,    54,     9,    10,    26,   143,   228,    57,
      77,   229,    87,    88,    56,    52,    27,    69,    28,    28,
      83,    84,    15,    11,    59,    67,    20,    60,    61,  -119,
      99,   100,    55,    41,   104,   264,   218,   219,    56,   187,
      49,   253,    74,   266,   174,    87,    88,    56,    29,   113,
      82,   310,   311,   312,   114,    67,   260,   261,    67,   262,
     141,    50,    68,    41,    33,    34,    35,    36,   168,    53,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      85,    15,   232,   233,    32,    20,    33,    34,    35,    36,
     256,   256,    37,    38,    70,    71,   335,    72,    73,   297,
     298,    93,    94,    95,    96,    97,    98,   101,   105,   108,
      39,   109,   110,    40,   106,   115,   116,   117,   118,    41,
      32,   111,    33,    34,    35,    36,   112,   120,    37,    38,
     146,   145,   159,   160,   161,    29,    29,   164,   227,   165,
     327,   192,   193,   330,   221,   332,    39,   163,   334,    40,
     142,   185,   336,   166,   167,    41,   170,    15,   171,   172,
     173,    20,   175,   176,   177,   178,   179,   258,   258,    32,
     180,    33,    34,    35,    36,   181,   182,    37,    38,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   255,   255,    39,    89,    90,    40,    29,
     183,   184,   187,   194,    41,   195,   198,   201,    91,    92,
      93,    94,    95,    96,    97,    98,    89,    90,   203,   210,
     211,   204,   206,   119,   208,   212,   213,   214,    91,    92,
      93,    94,    95,    96,    97,    98,   215,   216,   223,   299,
     300,   301,   302,   227,   227,   227,   217,   222,    89,    90,
     220,   225,    15,    15,    15,    15,    20,    20,    20,    20,
      91,    92,    93,    94,    95,    96,    97,    98,    89,    90,
     230,   231,   144,   235,   234,   237,   239,   240,   242,   243,
      91,    92,    93,    94,    95,    96,    97,    98,    89,    90,
     241,   246,   157,   269,   265,   244,   245,   247,   248,   249,
      91,    92,    93,    94,    95,    96,    97,    98,    89,    90,
     250,   251,   158,   267,   268,   252,   270,   271,   273,   274,
      91,    92,    93,    94,    95,    96,    97,    98,    89,    90,
     275,   276,   162,   277,   278,   279,   280,   281,   282,   287,
      91,    92,    93,    94,    95,    96,    97,    98,    89,    90,
     224,   289,   283,   288,   284,   285,   290,   291,   292,   293,
      91,    92,    93,    94,    95,    96,    97,    98,   294,   303,
     295,   296,   304,   306,   305,   308,   307,   309,   313,   314,
     315,   316,   317,   321,   319,   318,   322,   324,   320,   323,
     326,   328,   329,   333,   338,   186,   102,   339,   103,   286,
     254,   259,   140,   331,   325,     0,     0,     0,     0,   337
};

static const yytype_int16 yycheck[] =
{
       0,    14,   207,     3,     0,    31,    41,   158,   159,   165,
     166,    12,    57,    19,    14,     4,    39,     3,    14,    10,
      15,    72,    73,     9,    10,    11,    12,    56,    14,    15,
      66,    17,     0,    67,    20,    21,    39,    82,    69,    68,
      76,    72,    53,    54,    56,    68,    68,    42,    39,    39,
      39,    40,    52,    39,    22,    66,    52,    25,    26,    71,
      49,    50,    67,    74,    53,    71,    39,    40,    56,    70,
      68,   222,     4,   229,   119,    53,    54,    56,    78,    68,
      68,   299,   300,   301,    73,    66,    41,    42,    66,    44,
      79,    68,    73,    74,    41,    42,    43,    44,   111,    68,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     145,   111,    71,    72,    39,   111,    41,    42,    43,    44,
     223,   224,    47,    48,    67,    67,   331,    67,    73,   280,
     281,    59,    60,    61,    62,    63,    64,    16,    39,    39,
      65,    39,    39,    68,    69,     5,     6,     7,     8,    74,
      39,    70,    41,    42,    43,    44,    39,    69,    47,    48,
      75,    72,    39,    67,    67,   165,   166,    69,   194,    68,
     321,   160,   161,   324,   187,   326,    65,    67,   329,    68,
      69,    69,   333,    70,    70,    74,    70,   187,    70,    70,
      70,   187,    67,    58,    58,    58,    58,   223,   224,    39,
      58,    41,    42,    43,    44,    58,    58,    47,    48,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,   223,   224,    65,    45,    46,    68,   229,
      58,    58,    70,    70,    74,    67,    39,    39,    57,    58,
      59,    60,    61,    62,    63,    64,    45,    46,    71,     7,
      41,    68,    68,    72,    68,    41,    41,    41,    57,    58,
      59,    60,    61,    62,    63,    64,    41,    41,    67,   282,
     283,   284,   285,   299,   300,   301,    39,    13,    45,    46,
      40,    18,   282,   283,   284,   285,   282,   283,   284,   285,
      57,    58,    59,    60,    61,    62,    63,    64,    45,    46,
      72,    71,    69,    68,    39,    39,    39,    71,    57,    57,
      57,    58,    59,    60,    61,    62,    63,    64,    45,    46,
      73,    72,    69,    73,    76,    57,    57,    72,    57,    57,
      57,    58,    59,    60,    61,    62,    63,    64,    45,    46,
      57,    57,    69,    39,    39,    71,    39,    68,    73,    71,
      57,    58,    59,    60,    61,    62,    63,    64,    45,    46,
      73,    67,    69,    68,    39,    39,    69,    69,    76,    39,
      57,    58,    59,    60,    61,    62,    63,    64,    45,    46,
      67,    39,    76,    73,    76,    76,    71,    39,    67,    77,
      57,    58,    59,    60,    61,    62,    63,    64,    39,    59,
      57,    57,    41,    67,    73,    39,    61,    69,    71,    39,
      69,    60,    39,    55,    67,    69,    39,    55,    69,    69,
      55,    69,    55,    55,    71,   145,    52,    67,    52,   265,
     222,   224,    78,   325,   319,    -1,    -1,    -1,    -1,   335
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    14,    15,    17,    20,
      21,    39,    79,    80,    81,    83,    88,    92,    95,    96,
     100,   103,   105,   107,   109,   124,    39,    68,    39,    83,
      89,   119,    39,    41,    42,    43,    44,    47,    48,    65,
      68,    74,    83,    93,    94,    97,    99,   100,   101,    68,
      68,    39,    68,    68,    67,    67,    56,    68,     0,    22,
      25,    26,   115,   116,   120,   122,    80,    66,    73,   101,
      67,    67,    67,    73,     4,    94,    98,    76,    72,    73,
      91,   124,    68,    94,    94,    93,   102,    53,    54,    45,
      46,    57,    58,    59,    60,    61,    62,    63,    64,    94,
      94,    16,    88,    92,    94,    39,    69,    98,    39,    39,
      39,    70,    39,    94,    94,     5,     6,     7,     8,    72,
      69,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    84,    85,    86,    87,    90,
      89,    94,    69,    98,    69,    72,    75,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    69,    69,    39,
      67,    67,    69,    67,    69,    68,    70,    70,    80,   117,
      70,    70,    70,    70,    98,    67,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    69,   102,    70,    82,   104,
      82,    82,    94,    94,    70,    67,   118,   119,    39,   119,
     121,    39,   123,    71,    68,   110,    68,   111,    68,   114,
       7,    41,    41,    41,    41,    41,    41,    39,    39,    40,
      40,    80,    13,    67,    67,    18,   108,   124,    69,    72,
      72,    71,    71,    72,    39,    68,   112,    39,   112,    39,
      71,    73,    57,    57,    57,    57,    72,    72,    57,    57,
      57,    57,    71,    82,   103,    83,    99,   106,   124,   106,
      41,    42,    44,    19,    71,    76,   119,    39,    39,    73,
      39,    68,   113,    73,    71,    73,    67,    68,    39,    39,
      69,    69,    76,    76,    76,    76,    90,    39,    73,    39,
      71,    39,    67,    77,    39,    57,    57,    82,    82,    80,
      80,    80,    80,    59,    41,    73,    67,    61,    39,    69,
     108,   108,   108,    71,    39,    69,    60,    39,    69,    67,
      69,    55,    39,    69,    55,   110,    55,    82,    69,    55,
      82,   113,    82,    55,    82,   112,    82,   111,    71,    67
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
        case 103:
#line 182 "code/yacc.y"
    {printf("Group claim rule\n");;}
    break;

  case 107:
#line 188 "code/yacc.y"
    {printf("Group_closure_rule\n");;}
    break;


/* Line 1267 of yacc.c.  */
#line 1741 "code/y.tab.c"
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


#line 231 "code/yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

