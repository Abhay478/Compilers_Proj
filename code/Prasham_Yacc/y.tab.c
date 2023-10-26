/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "temp_yacc.y"

#include <stdio.h>

int yylex();
void yyerror(const char* s);


#line 79 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_LET = 258,                  /* KW_LET  */
    KW_RETURN = 259,               /* KW_RETURN  */
    KW_IF = 260,                   /* KW_IF  */
    KW_ELSE = 261,                 /* KW_ELSE  */
    KW_WHILE = 262,                /* KW_WHILE  */
    KW_FOR = 263,                  /* KW_FOR  */
    KW_IN = 264,                   /* KW_IN  */
    KW_SWITCH = 265,               /* KW_SWITCH  */
    KW_CASE = 266,                 /* KW_CASE  */
    KW_DEFAULT = 267,              /* KW_DEFAULT  */
    KW_BREAK = 268,                /* KW_BREAK  */
    KW_CONTINUE = 269,             /* KW_CONTINUE  */
    KW_CYCLIC = 270,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 271,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 272,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 273,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 274,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 275,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 276,              /* KW_INV_MAT  */
    KW_BIGINT = 277,               /* KW_BIGINT  */
    KW_MATRIX = 278,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 279,           /* KW_POLYNOMIAL  */
    KW_VEC = 280,                  /* KW_VEC  */
    KW_BUF = 281,                  /* KW_BUF  */
    IDENT = 282,                   /* IDENT  */
    PRIMITIVE_DTYPE = 283,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 284,                 /* LIT_INT  */
    LIT_FLOAT = 285,               /* LIT_FLOAT  */
    LIT_STR = 286,                 /* LIT_STR  */
    LIT_CHAR = 287,                /* LIT_CHAR  */
    LOGICAL_AND = 288,             /* LOGICAL_AND  */
    LOGICAL_OR = 289,              /* LOGICAL_OR  */
    LOGICAL_NOT = 290,             /* LOGICAL_NOT  */
    EQ = 291,                      /* EQ  */
    NEQ = 292,                     /* NEQ  */
    GT = 293,                      /* GT  */
    LT = 294,                      /* LT  */
    GTEQ = 295,                    /* GTEQ  */
    LTEQ = 296,                    /* LTEQ  */
    KW_TRUE = 297,                 /* KW_TRUE  */
    KW_FALSE = 298                 /* KW_FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_LET 258
#define KW_RETURN 259
#define KW_IF 260
#define KW_ELSE 261
#define KW_WHILE 262
#define KW_FOR 263
#define KW_IN 264
#define KW_SWITCH 265
#define KW_CASE 266
#define KW_DEFAULT 267
#define KW_BREAK 268
#define KW_CONTINUE 269
#define KW_CYCLIC 270
#define KW_BIG_RATIONAL 271
#define KW_COMPLEX 272
#define KW_SYMMETRIC 273
#define KW_ALTERNATING 274
#define KW_DIHEDRAL 275
#define KW_INV_MAT 276
#define KW_BIGINT 277
#define KW_MATRIX 278
#define KW_POLYNOMIAL 279
#define KW_VEC 280
#define KW_BUF 281
#define IDENT 282
#define PRIMITIVE_DTYPE 283
#define LIT_INT 284
#define LIT_FLOAT 285
#define LIT_STR 286
#define LIT_CHAR 287
#define LOGICAL_AND 288
#define LOGICAL_OR 289
#define LOGICAL_NOT 290
#define EQ 291
#define NEQ 292
#define GT 293
#define LT 294
#define GTEQ 295
#define LTEQ 296
#define KW_TRUE 297
#define KW_FALSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_LET = 3,                     /* KW_LET  */
  YYSYMBOL_KW_RETURN = 4,                  /* KW_RETURN  */
  YYSYMBOL_KW_IF = 5,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 6,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 7,                   /* KW_WHILE  */
  YYSYMBOL_KW_FOR = 8,                     /* KW_FOR  */
  YYSYMBOL_KW_IN = 9,                      /* KW_IN  */
  YYSYMBOL_KW_SWITCH = 10,                 /* KW_SWITCH  */
  YYSYMBOL_KW_CASE = 11,                   /* KW_CASE  */
  YYSYMBOL_KW_DEFAULT = 12,                /* KW_DEFAULT  */
  YYSYMBOL_KW_BREAK = 13,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 14,               /* KW_CONTINUE  */
  YYSYMBOL_KW_CYCLIC = 15,                 /* KW_CYCLIC  */
  YYSYMBOL_KW_BIG_RATIONAL = 16,           /* KW_BIG_RATIONAL  */
  YYSYMBOL_KW_COMPLEX = 17,                /* KW_COMPLEX  */
  YYSYMBOL_KW_SYMMETRIC = 18,              /* KW_SYMMETRIC  */
  YYSYMBOL_KW_ALTERNATING = 19,            /* KW_ALTERNATING  */
  YYSYMBOL_KW_DIHEDRAL = 20,               /* KW_DIHEDRAL  */
  YYSYMBOL_KW_INV_MAT = 21,                /* KW_INV_MAT  */
  YYSYMBOL_KW_BIGINT = 22,                 /* KW_BIGINT  */
  YYSYMBOL_KW_MATRIX = 23,                 /* KW_MATRIX  */
  YYSYMBOL_KW_POLYNOMIAL = 24,             /* KW_POLYNOMIAL  */
  YYSYMBOL_KW_VEC = 25,                    /* KW_VEC  */
  YYSYMBOL_KW_BUF = 26,                    /* KW_BUF  */
  YYSYMBOL_IDENT = 27,                     /* IDENT  */
  YYSYMBOL_PRIMITIVE_DTYPE = 28,           /* PRIMITIVE_DTYPE  */
  YYSYMBOL_LIT_INT = 29,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 30,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_STR = 31,                   /* LIT_STR  */
  YYSYMBOL_LIT_CHAR = 32,                  /* LIT_CHAR  */
  YYSYMBOL_LOGICAL_AND = 33,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 34,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 35,               /* LOGICAL_NOT  */
  YYSYMBOL_EQ = 36,                        /* EQ  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_GT = 38,                        /* GT  */
  YYSYMBOL_LT = 39,                        /* LT  */
  YYSYMBOL_GTEQ = 40,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 41,                      /* LTEQ  */
  YYSYMBOL_KW_TRUE = 42,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 43,                  /* KW_FALSE  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_51_ = 51,                       /* '@'  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '*'  */
  YYSYMBOL_55_ = 55,                       /* '/'  */
  YYSYMBOL_56_ = 56,                       /* '%'  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* ')'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* '{'  */
  YYSYMBOL_62_ = 62,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_statements = 64,                /* statements  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_var = 66,                       /* var  */
  YYSYMBOL_field_data_type = 67,           /* field_data_type  */
  YYSYMBOL_group_data_type = 68,           /* group_data_type  */
  YYSYMBOL_ring_data_type = 69,            /* ring_data_type  */
  YYSYMBOL_space_data_type = 70,           /* space_data_type  */
  YYSYMBOL_declaration = 71,               /* declaration  */
  YYSYMBOL_A = 72,                         /* A  */
  YYSYMBOL_assignment = 73,                /* assignment  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_arithmetic_expr = 75,           /* arithmetic_expr  */
  YYSYMBOL_term = 76,                      /* term  */
  YYSYMBOL_factor = 77,                    /* factor  */
  YYSYMBOL_constant = 78,                  /* constant  */
  YYSYMBOL_logical_expr = 79,              /* logical_expr  */
  YYSYMBOL_B = 80,                         /* B  */
  YYSYMBOL_logical_op = 81,                /* logical_op  */
  YYSYMBOL_return_stmt = 82,               /* return_stmt  */
  YYSYMBOL_call_stmt_standalone = 83,      /* call_stmt_standalone  */
  YYSYMBOL_call_stmt = 84,                 /* call_stmt  */
  YYSYMBOL_pass_param_list = 85,           /* pass_param_list  */
  YYSYMBOL_unary_operation = 86,           /* unary_operation  */
  YYSYMBOL_array_access = 87,              /* array_access  */
  YYSYMBOL_C = 88,                         /* C  */
  YYSYMBOL_array_decl = 89,                /* array_decl  */
  YYSYMBOL_array_list = 90,                /* array_list  */
  YYSYMBOL_if_else_conditional = 91,       /* if_else_conditional  */
  YYSYMBOL_D = 92,                         /* D  */
  YYSYMBOL_loop_stmt = 93,                 /* loop_stmt  */
  YYSYMBOL_V = 94,                         /* V  */
  YYSYMBOL_switch_case = 95,               /* switch_case  */
  YYSYMBOL_switch_case_blocks = 96,        /* switch_case_blocks  */
  YYSYMBOL_epsilon = 97                    /* epsilon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
      57,    58,    54,    52,    48,    53,    45,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    44,
      46,    50,    47,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    14,    14,    15,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    29,    30,    33,    34,    35,    38,    39,
      40,    41,    42,    45,    46,    47,    50,    51,    54,    55,
      56,    57,    58,    59,    60,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    75,    76,    79,    80,    86,    87,
      90,    91,    92,    96,    97,    98,    99,   102,   103,   104,
     105,   106,   107,   108,   109,   112,   113,   114,   115,   118,
     119,   120,   123,   126,   127,   128,   131,   132,   133,   134,
     135,   136,   137,   138,   141,   144,   145,   148,   149,   152,
     153,   156,   157,   160,   163,   164,   167,   170,   171,   174,
     177,   178,   179,   186,   187,   188,   189,   192,   193,   196,
     197,   200,   201,   202,   203,   208
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_LET", "KW_RETURN",
  "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_IN", "KW_SWITCH",
  "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_CONTINUE", "KW_CYCLIC",
  "KW_BIG_RATIONAL", "KW_COMPLEX", "KW_SYMMETRIC", "KW_ALTERNATING",
  "KW_DIHEDRAL", "KW_INV_MAT", "KW_BIGINT", "KW_MATRIX", "KW_POLYNOMIAL",
  "KW_VEC", "KW_BUF", "IDENT", "PRIMITIVE_DTYPE", "LIT_INT", "LIT_FLOAT",
  "LIT_STR", "LIT_CHAR", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "EQ",
  "NEQ", "GT", "LT", "GTEQ", "LTEQ", "KW_TRUE", "KW_FALSE", "';'", "'.'",
  "'<'", "'>'", "','", "':'", "'='", "'@'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'('", "')'", "'['", "']'", "'{'", "'}'", "$accept", "statements",
  "statement", "var", "field_data_type", "group_data_type",
  "ring_data_type", "space_data_type", "declaration", "A", "assignment",
  "expression", "arithmetic_expr", "term", "factor", "constant",
  "logical_expr", "B", "logical_op", "return_stmt", "call_stmt_standalone",
  "call_stmt", "pass_param_list", "unary_operation", "array_access", "C",
  "array_decl", "array_list", "if_else_conditional", "D", "loop_stmt", "V",
  "switch_case", "switch_case_blocks", "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     180,    13,   263,   -10,    -5,     3,     4,    14,    25,    28,
      75,   180,   -24,    37,    51,    62,  -167,    61,  -167,  -167,
    -167,  -167,    74,   100,  -167,  -167,  -167,  -167,   272,  -167,
    -167,    -7,   272,    36,   114,  -167,   168,    24,  -167,  -167,
    -167,   177,  -167,  -167,  -167,  -167,   272,   272,   120,    16,
     263,  -167,  -167,   106,  -167,  -167,   263,    67,   112,  -167,
    -167,  -167,  -167,   263,   315,   115,    48,    31,  -167,    -7,
    -167,     1,    85,    96,    86,    13,    97,   101,   105,    -7,
      -7,    -7,    -7,    -7,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   272,   102,   118,   128,   -11,   126,   133,   122,
    -167,  -167,   142,   141,   134,   131,  -167,   149,  -167,  -167,
     150,   154,   157,   169,  -167,   173,   179,   184,   185,   -14,
     -14,   -14,   -14,   -14,   -14,   176,     1,  -167,  -167,    36,
    -167,  -167,  -167,  -167,  -167,   164,    24,    24,  -167,  -167,
    -167,  -167,   171,   175,   182,   272,   272,   183,  -167,   263,
     190,   178,   209,   216,   221,   222,   224,   231,   236,    76,
     237,    13,   263,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   180,  -167,   180,   180,   220,   226,   260,  -167,
    -167,  -167,   225,   230,   233,   238,   235,   239,   244,   249,
     250,   253,   229,  -167,   246,   247,   248,    13,    13,    12,
       9,  -167,  -167,  -167,  -167,  -167,   257,   284,  -167,  -167,
    -167,   -14,   329,   306,  -167,  -167,    66,  -167,   255,  -167,
     259,   269,   270,   274,   275,  -167,   279,   280,  -167,   282,
     -14,   -14,   -14,   -14,   -14,   -14,    11,   297,   298,   180,
     180,   180,   180,  -167,  -167,   293,  -167,  -167,  -167,  -167,
    -167,  -167,   180,  -167,   180,   180,   260,   260,   260,   299,
     313,   300,   301,   302,  -167,  -167,  -167,  -167,   -14,  -167,
    -167,  -167,  -167
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
     115,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,   115,     0,     0,     0,     0,     6,     0,     8,    10,
       9,     3,     0,    57,    67,    66,    68,    65,     0,    74,
      75,     0,     0,     0,     0,    84,    72,    52,    56,    61,
      47,    70,    62,    64,    63,    48,     0,     0,     0,     0,
       0,    11,    12,     0,     1,     2,     0,     0,     0,    93,
       4,     5,     7,     0,    15,     0,     0,    72,    71,     0,
      60,    72,     0,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    80,    81,    78,    79,
      77,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    44,     0,    90,     0,     0,    45,     0,    16,    17,
       0,     0,     0,     0,    23,     0,     0,     0,     0,   115,
     115,   115,   115,   115,   115,    58,     0,    59,    73,     0,
      96,    49,    91,    92,    88,     0,    50,    51,    53,    54,
      55,    69,     0,     0,     0,     0,     0,     0,    86,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    36,    28,    33,    31,    32,    34,
      97,    87,   115,    99,   115,   115,     0,     0,   115,    89,
      85,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,   115,   115,     0,
       0,   114,    18,    19,    20,    21,     0,     0,    25,    26,
      27,   115,    15,   100,   103,   106,     0,   107,     0,   108,
       0,     0,     0,     0,     0,   110,     0,     0,    29,     0,
     115,   115,   115,   115,   115,   115,     0,     0,     0,   115,
     115,   115,   115,    22,    24,     0,    39,    38,    42,    40,
      41,    43,   115,   101,   115,   115,   115,   115,   115,     0,
       0,     0,     0,     0,   112,   113,   111,   109,   115,   102,
     105,   104,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,    34,  -167,     7,   153,   155,   156,   158,   317,  -118,
     320,    -1,   -18,    42,     6,   -21,   -15,  -167,  -167,  -167,
    -167,  -167,   -63,   -59,    27,   223,  -167,   242,   136,  -167,
    -167,   181,  -167,  -166,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    66,   121,   122,   123,   124,    13,   163,
      14,   103,    36,    37,    38,    39,    40,    41,    92,    15,
      16,    42,   104,    43,    44,    59,    45,    74,    18,   173,
      19,   218,    20,   200,   164
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    35,   165,   166,   167,   168,   169,    12,    22,    34,
      67,    21,    73,    68,    71,   135,     3,    72,    12,     1,
      23,   224,    24,    25,    26,    27,    56,    17,    67,    67,
      48,    93,    94,    57,   161,    58,   162,    70,    17,    56,
       9,   221,   222,     9,   223,    55,    31,    46,    58,    99,
      69,   126,    47,    79,    80,   101,    96,    34,    51,   127,
      49,    50,   106,    34,    34,    24,    25,    26,    27,    52,
      34,   225,   252,    53,    67,    54,    17,   141,    81,    82,
      83,    60,   131,    79,    80,    34,   179,   138,   139,   140,
     264,   265,   266,   228,    23,    61,    24,    25,    26,    27,
      76,    77,    28,   189,   190,    78,    62,    58,    73,    29,
      30,    63,   246,   247,   248,   249,   250,   251,    76,    77,
      31,   136,   137,    64,    32,   102,    33,    67,    67,    95,
     176,   177,    23,   100,    24,    25,    26,    27,   217,   217,
      28,   105,   125,   128,   129,    65,   130,    29,    30,   132,
     272,   -13,   -13,   -13,   133,   144,    34,   -13,    31,   -13,
     142,   193,    32,   134,    33,    75,    76,    77,   192,    34,
     145,    78,    21,    58,    21,    21,   143,   146,   201,    12,
     147,    12,    12,     1,     2,     3,   148,     4,     5,   149,
       6,   151,   150,     7,     8,   152,   153,   219,   219,    17,
     154,    17,    17,   155,   216,   216,   194,     9,   195,   196,
      84,    85,   -46,    86,    87,   156,   -46,    88,    89,   157,
      79,    80,   171,    90,    91,   158,   -46,   -14,   -14,   -14,
     159,   160,   172,   -14,   180,   -14,   174,    58,   182,    21,
      21,    21,    21,   175,   178,   183,    12,    12,    12,    12,
     184,   185,    21,   186,    21,    21,   201,   201,   201,    12,
     187,    12,    12,   188,   197,   191,    17,    17,    17,    17,
     198,   199,   202,   256,   257,   258,   259,   203,   212,    17,
     204,    17,    17,   206,   226,   205,   261,   207,   262,   263,
      23,   208,    24,    25,    26,    27,   209,   210,    28,    23,
     211,    24,    25,    26,    27,    29,    30,    28,   213,   214,
     215,   227,   236,   237,    29,    30,    31,   238,   239,   240,
      32,   260,    33,   241,   242,    31,   243,   244,   245,    32,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   229,   230,   231,   254,   255,
     268,   267,   269,   270,   271,   232,    97,   233,   234,    98,
     235,   170,   253,     0,   181,     0,     0,     0,     0,   220
};

static const yytype_int16 yycheck[] =
{
       0,     2,   120,   121,   122,   123,   124,     0,     1,     2,
      28,    11,    33,    28,    32,    78,     5,    32,    11,     3,
      27,    12,    29,    30,    31,    32,    50,     0,    46,    47,
      27,    46,    47,    57,    48,    59,    50,    31,    11,    50,
      27,    29,    30,    27,    32,    11,    53,    57,    59,    50,
      57,    69,    57,    52,    53,    56,    49,    50,    44,    58,
      57,    57,    63,    56,    57,    29,    30,    31,    32,    44,
      63,    62,    61,    45,    92,     0,    49,    92,    54,    55,
      56,    44,    75,    52,    53,    78,   149,    81,    82,    83,
     256,   257,   258,   211,    27,    44,    29,    30,    31,    32,
      52,    53,    35,    27,    28,    57,    44,    59,   129,    42,
      43,    50,   230,   231,   232,   233,   234,   235,    52,    53,
      53,    79,    80,    49,    57,    58,    59,   145,   146,     9,
     145,   146,    27,    27,    29,    30,    31,    32,   197,   198,
      35,    29,    27,    58,    48,    45,    60,    42,    43,    52,
     268,    51,    52,    53,    53,    27,   149,    57,    53,    59,
      58,   162,    57,    58,    59,    51,    52,    53,   161,   162,
      44,    57,   172,    59,   174,   175,    58,    44,   178,   172,
      58,   174,   175,     3,     4,     5,    44,     7,     8,    48,
      10,    60,    58,    13,    14,    46,    46,   197,   198,   172,
      46,   174,   175,    46,   197,   198,   172,    27,   174,   175,
      33,    34,    44,    36,    37,    46,    48,    40,    41,    46,
      52,    53,    58,    46,    47,    46,    58,    51,    52,    53,
      46,    46,    61,    57,    44,    59,    61,    59,    29,   239,
     240,   241,   242,    61,    61,    29,   239,   240,   241,   242,
      29,    29,   252,    29,   254,   255,   256,   257,   258,   252,
      29,   254,   255,    27,    44,    28,   239,   240,   241,   242,
      44,    11,    47,   239,   240,   241,   242,    47,    49,   252,
      47,   254,   255,    48,    27,    47,   252,    48,   254,   255,
      27,    47,    29,    30,    31,    32,    47,    47,    35,    27,
      47,    29,    30,    31,    32,    42,    43,    35,    62,    62,
      62,    27,     6,    58,    42,    43,    53,    58,    49,    49,
      57,    28,    59,    49,    49,    53,    47,    47,    46,    57,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    61,    61,
      47,    62,    62,    62,    62,   212,    49,   212,   212,    49,
     212,   129,   236,    -1,   151,    -1,    -1,    -1,    -1,   198
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    10,    13,    14,    27,
      64,    65,    66,    71,    73,    82,    83,    87,    91,    93,
      95,    97,    66,    27,    29,    30,    31,    32,    35,    42,
      43,    53,    57,    59,    66,    74,    75,    76,    77,    78,
      79,    80,    84,    86,    87,    89,    57,    57,    27,    57,
      57,    44,    44,    45,     0,    64,    50,    57,    59,    88,
      44,    44,    44,    50,    49,    45,    66,    75,    79,    57,
      77,    75,    79,    78,    90,    51,    52,    53,    57,    52,
      53,    54,    55,    56,    33,    34,    36,    37,    40,    41,
      46,    47,    81,    79,    79,     9,    66,    71,    73,    74,
      27,    74,    58,    74,    85,    29,    74,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    67,    68,    69,    70,    27,    75,    58,    58,    48,
      60,    66,    52,    53,    58,    85,    76,    76,    77,    77,
      77,    79,    58,    58,    27,    44,    44,    58,    44,    48,
      58,    60,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    48,    50,    72,    97,    72,    72,    72,    72,    72,
      90,    58,    61,    92,    61,    61,    79,    79,    61,    85,
      44,    88,    29,    29,    29,    29,    29,    29,    27,    27,
      28,    28,    66,    74,    64,    64,    64,    44,    44,    11,
      96,    97,    47,    47,    47,    47,    48,    48,    47,    47,
      47,    47,    49,    62,    62,    62,    66,    86,    94,    97,
      94,    29,    30,    32,    12,    62,    27,    27,    72,    26,
      27,    28,    67,    68,    69,    70,     6,    58,    58,    49,
      49,    49,    49,    47,    47,    46,    72,    72,    72,    72,
      72,    72,    61,    91,    61,    61,    64,    64,    64,    64,
      28,    64,    64,    64,    96,    96,    96,    62,    47,    62,
      62,    62,    72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      68,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    88,    88,    89,    90,    90,    91,
      92,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    96,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     2,     2,     1,     3,     0,     1,     1,     4,     4,
       4,     4,     6,     1,     6,     4,     4,     4,     5,     8,
       5,     5,     5,     5,     5,     2,     1,     8,     5,     5,
       5,     5,     5,     5,     3,     3,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     1,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     4,     4,     3,     3,
       1,     3,     3,     2,     4,     3,     3,     3,     1,     5,
       3,     5,     7,     7,    11,    11,     7,     1,     1,    10,
       7,     5,     5,     5,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 50: /* arithmetic_expr: arithmetic_expr '+' term  */
#line 90 "temp_yacc.y"
                                           {printf("Rule: arithmetic_expr : arithmetic_expr \'+\' term\n");}
#line 1488 "y.tab.c"
    break;

  case 51: /* arithmetic_expr: arithmetic_expr '-' term  */
#line 91 "temp_yacc.y"
                                           {printf("Rule: arithmetic_expr : arithmetic_expr \'-\' term\n");}
#line 1494 "y.tab.c"
    break;

  case 52: /* arithmetic_expr: term  */
#line 92 "temp_yacc.y"
                       {printf("Rule: arithmetic_expr : term\n");}
#line 1500 "y.tab.c"
    break;

  case 53: /* term: term '*' factor  */
#line 96 "temp_yacc.y"
                                  {printf("Rule: term : term \'*\' factor\n");}
#line 1506 "y.tab.c"
    break;

  case 54: /* term: term '/' factor  */
#line 97 "temp_yacc.y"
                                  {printf("Rule: term : term \'/\' factor\n");}
#line 1512 "y.tab.c"
    break;

  case 55: /* term: term '%' factor  */
#line 98 "temp_yacc.y"
                                  {printf("Rule: term : term \'\%\' factor\n");}
#line 1518 "y.tab.c"
    break;

  case 56: /* term: factor  */
#line 99 "temp_yacc.y"
                         {printf("Rule: term : factor\n");}
#line 1524 "y.tab.c"
    break;

  case 57: /* factor: IDENT  */
#line 102 "temp_yacc.y"
                        {printf("Rule: factor : IDENT\n");}
#line 1530 "y.tab.c"
    break;

  case 58: /* factor: IDENT '.' IDENT  */
#line 103 "temp_yacc.y"
                                  {printf("Rule: factor : IDENT \'.\' IDENT\n");}
#line 1536 "y.tab.c"
    break;

  case 59: /* factor: '(' arithmetic_expr ')'  */
#line 104 "temp_yacc.y"
                                          {printf("Rule: factor : \'(\' arithmetic_expr \')\'\n");}
#line 1542 "y.tab.c"
    break;

  case 61: /* factor: constant  */
#line 106 "temp_yacc.y"
                           {printf("Rule: factor : constant\n");}
#line 1548 "y.tab.c"
    break;

  case 62: /* factor: call_stmt  */
#line 107 "temp_yacc.y"
                            {printf("Rule: factor : call_stmt\n");}
#line 1554 "y.tab.c"
    break;

  case 63: /* factor: array_access  */
#line 108 "temp_yacc.y"
                               {printf("Rule: factor : array_access\n");}
#line 1560 "y.tab.c"
    break;

  case 64: /* factor: unary_operation  */
#line 109 "temp_yacc.y"
                                  {printf("Rule: factor : unary_operation\n");}
#line 1566 "y.tab.c"
    break;


#line 1570 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 210 "temp_yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
