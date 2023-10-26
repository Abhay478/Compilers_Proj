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
    KW_SWITCH = 264,               /* KW_SWITCH  */
    KW_CASE = 265,                 /* KW_CASE  */
    KW_DEFAULT = 266,              /* KW_DEFAULT  */
    KW_BREAK = 267,                /* KW_BREAK  */
    KW_CONTINUE = 268,             /* KW_CONTINUE  */
    KW_CYCLIC = 269,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 270,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 271,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 272,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 273,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 274,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 275,              /* KW_INV_MAT  */
    KW_BIGINT = 276,               /* KW_BIGINT  */
    KW_MATRIX = 277,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 278,           /* KW_POLYNOMIAL  */
    KW_VEC = 279,                  /* KW_VEC  */
    KW_BUF = 280,                  /* KW_BUF  */
    IDENT = 281,                   /* IDENT  */
    PRIMITIVE_DTYPE = 282,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 283,                 /* LIT_INT  */
    LIT_FLOAT = 284,               /* LIT_FLOAT  */
    LIT_STR = 285,                 /* LIT_STR  */
    LIT_CHAR = 286,                /* LIT_CHAR  */
    LOGICAL_AND = 287,             /* LOGICAL_AND  */
    LOGICAL_OR = 288,              /* LOGICAL_OR  */
    LOGICAL_NOT = 289,             /* LOGICAL_NOT  */
    EQ = 290,                      /* EQ  */
    NEQ = 291,                     /* NEQ  */
    GT = 292,                      /* GT  */
    LT = 293,                      /* LT  */
    GTEQ = 294,                    /* GTEQ  */
    LTEQ = 295,                    /* LTEQ  */
    KW_TRUE = 296,                 /* KW_TRUE  */
    KW_FALSE = 297                 /* KW_FALSE  */
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
#define KW_SWITCH 264
#define KW_CASE 265
#define KW_DEFAULT 266
#define KW_BREAK 267
#define KW_CONTINUE 268
#define KW_CYCLIC 269
#define KW_BIG_RATIONAL 270
#define KW_COMPLEX 271
#define KW_SYMMETRIC 272
#define KW_ALTERNATING 273
#define KW_DIHEDRAL 274
#define KW_INV_MAT 275
#define KW_BIGINT 276
#define KW_MATRIX 277
#define KW_POLYNOMIAL 278
#define KW_VEC 279
#define KW_BUF 280
#define IDENT 281
#define PRIMITIVE_DTYPE 282
#define LIT_INT 283
#define LIT_FLOAT 284
#define LIT_STR 285
#define LIT_CHAR 286
#define LOGICAL_AND 287
#define LOGICAL_OR 288
#define LOGICAL_NOT 289
#define EQ 290
#define NEQ 291
#define GT 292
#define LT 293
#define GTEQ 294
#define LTEQ 295
#define KW_TRUE 296
#define KW_FALSE 297

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
  YYSYMBOL_KW_SWITCH = 9,                  /* KW_SWITCH  */
  YYSYMBOL_KW_CASE = 10,                   /* KW_CASE  */
  YYSYMBOL_KW_DEFAULT = 11,                /* KW_DEFAULT  */
  YYSYMBOL_KW_BREAK = 12,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 13,               /* KW_CONTINUE  */
  YYSYMBOL_KW_CYCLIC = 14,                 /* KW_CYCLIC  */
  YYSYMBOL_KW_BIG_RATIONAL = 15,           /* KW_BIG_RATIONAL  */
  YYSYMBOL_KW_COMPLEX = 16,                /* KW_COMPLEX  */
  YYSYMBOL_KW_SYMMETRIC = 17,              /* KW_SYMMETRIC  */
  YYSYMBOL_KW_ALTERNATING = 18,            /* KW_ALTERNATING  */
  YYSYMBOL_KW_DIHEDRAL = 19,               /* KW_DIHEDRAL  */
  YYSYMBOL_KW_INV_MAT = 20,                /* KW_INV_MAT  */
  YYSYMBOL_KW_BIGINT = 21,                 /* KW_BIGINT  */
  YYSYMBOL_KW_MATRIX = 22,                 /* KW_MATRIX  */
  YYSYMBOL_KW_POLYNOMIAL = 23,             /* KW_POLYNOMIAL  */
  YYSYMBOL_KW_VEC = 24,                    /* KW_VEC  */
  YYSYMBOL_KW_BUF = 25,                    /* KW_BUF  */
  YYSYMBOL_IDENT = 26,                     /* IDENT  */
  YYSYMBOL_PRIMITIVE_DTYPE = 27,           /* PRIMITIVE_DTYPE  */
  YYSYMBOL_LIT_INT = 28,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 29,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_STR = 30,                   /* LIT_STR  */
  YYSYMBOL_LIT_CHAR = 31,                  /* LIT_CHAR  */
  YYSYMBOL_LOGICAL_AND = 32,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 33,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 34,               /* LOGICAL_NOT  */
  YYSYMBOL_EQ = 35,                        /* EQ  */
  YYSYMBOL_NEQ = 36,                       /* NEQ  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_LT = 38,                        /* LT  */
  YYSYMBOL_GTEQ = 39,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 40,                      /* LTEQ  */
  YYSYMBOL_KW_TRUE = 41,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 42,                  /* KW_FALSE  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '@'  */
  YYSYMBOL_51_ = 51,                       /* '+'  */
  YYSYMBOL_52_ = 52,                       /* '-'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_54_ = 54,                       /* '/'  */
  YYSYMBOL_55_ = 55,                       /* '%'  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_60_ = 60,                       /* '{'  */
  YYSYMBOL_61_ = 61,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_statements = 63,                /* statements  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_var = 65,                       /* var  */
  YYSYMBOL_field_data_type = 66,           /* field_data_type  */
  YYSYMBOL_group_data_type = 67,           /* group_data_type  */
  YYSYMBOL_ring_data_type = 68,            /* ring_data_type  */
  YYSYMBOL_space_data_type = 69,           /* space_data_type  */
  YYSYMBOL_declaration = 70,               /* declaration  */
  YYSYMBOL_A = 71,                         /* A  */
  YYSYMBOL_assignment = 72,                /* assignment  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_arithmetic_expr = 74,           /* arithmetic_expr  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_factor = 76,                    /* factor  */
  YYSYMBOL_constant = 77,                  /* constant  */
  YYSYMBOL_logical_expr = 78,              /* logical_expr  */
  YYSYMBOL_B = 79,                         /* B  */
  YYSYMBOL_logical_op = 80,                /* logical_op  */
  YYSYMBOL_return_stmt = 81,               /* return_stmt  */
  YYSYMBOL_call_stmt_standalone = 82,      /* call_stmt_standalone  */
  YYSYMBOL_call_stmt = 83,                 /* call_stmt  */
  YYSYMBOL_pass_param_list = 84,           /* pass_param_list  */
  YYSYMBOL_unary_operation = 85,           /* unary_operation  */
  YYSYMBOL_array_access = 86,              /* array_access  */
  YYSYMBOL_C = 87,                         /* C  */
  YYSYMBOL_array_decl = 88,                /* array_decl  */
  YYSYMBOL_array_list = 89,                /* array_list  */
  YYSYMBOL_if_else_conditional = 90,       /* if_else_conditional  */
  YYSYMBOL_D = 91,                         /* D  */
  YYSYMBOL_loop_stmt = 92,                 /* loop_stmt  */
  YYSYMBOL_V = 93,                         /* V  */
  YYSYMBOL_switch_case = 94,               /* switch_case  */
  YYSYMBOL_switch_case_blocks = 95,        /* switch_case_blocks  */
  YYSYMBOL_epsilon = 96                    /* epsilon  */
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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,     2,     2,     2,     2,    55,     2,     2,
      56,    57,    53,    51,    47,    52,    44,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    43,
      45,    49,    46,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
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
     105,   106,   107,   108,   111,   112,   113,   114,   117,   118,
     119,   122,   125,   126,   127,   130,   131,   132,   133,   134,
     135,   136,   137,   140,   143,   144,   147,   148,   151,   152,
     155,   156,   159,   162,   163,   166,   169,   170,   173,   176,
     177,   178,   185,   186,   187,   190,   191,   194,   195,   198,
     199,   200,   201,   204
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
  "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_SWITCH", "KW_CASE",
  "KW_DEFAULT", "KW_BREAK", "KW_CONTINUE", "KW_CYCLIC", "KW_BIG_RATIONAL",
  "KW_COMPLEX", "KW_SYMMETRIC", "KW_ALTERNATING", "KW_DIHEDRAL",
  "KW_INV_MAT", "KW_BIGINT", "KW_MATRIX", "KW_POLYNOMIAL", "KW_VEC",
  "KW_BUF", "IDENT", "PRIMITIVE_DTYPE", "LIT_INT", "LIT_FLOAT", "LIT_STR",
  "LIT_CHAR", "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "EQ", "NEQ",
  "GT", "LT", "GTEQ", "LTEQ", "KW_TRUE", "KW_FALSE", "';'", "'.'", "'<'",
  "'>'", "','", "':'", "'='", "'@'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "$accept", "statements",
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

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      37,    -2,   118,    -8,     8,    14,    17,    57,    70,    36,
     122,    37,   -21,    83,    87,    89,  -115,    80,  -115,  -115,
    -115,  -115,    94,  -115,  -115,  -115,  -115,   173,  -115,  -115,
     105,   173,    28,    65,  -115,   165,    30,  -115,  -115,  -115,
     247,  -115,  -115,  -115,  -115,   173,   173,    26,   118,  -115,
    -115,   125,  -115,  -115,   118,    62,   126,  -115,  -115,  -115,
    -115,   118,   280,    43,   -25,  -115,   105,  -115,    86,    96,
     109,    99,    -2,   113,   115,   153,   105,   105,   105,   105,
     105,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   173,
     108,   112,   -26,   129,   134,   121,  -115,  -115,   137,   138,
     131,   127,  -115,   147,  -115,  -115,   161,   168,   174,   175,
    -115,   176,   178,   179,   181,   -27,   -27,   -27,   -27,   -27,
     -27,    86,  -115,  -115,    28,  -115,  -115,  -115,  -115,  -115,
     170,    30,    30,  -115,  -115,  -115,  -115,   158,   182,   173,
     173,   184,  -115,   118,   185,   177,   206,   208,   213,   223,
     226,   231,   234,    12,   239,    -2,   118,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,    37,  -115,    37,   218,
     224,   259,  -115,  -115,  -115,   227,   228,   230,   235,   225,
     237,   242,   243,   244,   245,   274,  -115,   262,   263,    -2,
      -2,    47,    10,  -115,  -115,  -115,  -115,  -115,   299,   300,
    -115,  -115,  -115,   -27,   294,   279,  -115,    35,  -115,   270,
    -115,   271,   281,   282,   283,   284,  -115,   287,   288,  -115,
     290,   -27,   -27,   -27,   -27,   -27,   -27,     9,   276,   277,
      37,    37,    37,    37,  -115,  -115,   311,  -115,  -115,  -115,
    -115,  -115,  -115,    37,  -115,    37,    37,   259,   259,   259,
     278,   295,   285,   286,   289,  -115,  -115,  -115,  -115,   -27,
    -115,  -115,  -115,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
     113,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,   113,     0,     0,     0,     0,     6,     0,     8,    10,
       9,     3,     0,    66,    65,    67,    64,     0,    73,    74,
       0,     0,     0,    57,    83,    71,    52,    56,    60,    47,
      69,    61,    63,    62,    48,     0,     0,     0,     0,    11,
      12,     0,     1,     2,     0,     0,     0,    92,     4,     5,
       7,     0,    15,    57,    71,    70,     0,    59,    71,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,    79,    80,    77,    78,    76,    75,     0,
       0,     0,     0,     0,     0,     0,    14,    44,     0,    89,
       0,     0,    45,     0,    16,    17,     0,     0,     0,     0,
      23,     0,     0,     0,     0,   113,   113,   113,   113,   113,
     113,     0,    58,    72,     0,    95,    49,    90,    91,    87,
       0,    50,    51,    53,    54,    55,    68,     0,     0,     0,
       0,     0,    85,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    36,    28,
      33,    31,    32,    34,    96,    86,   113,    98,   113,     0,
       0,   113,    88,    84,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,   113,
     113,     0,     0,   112,    18,    19,    20,    21,     0,     0,
      25,    26,    27,   113,    15,    99,   102,     0,   105,     0,
     106,     0,     0,     0,     0,     0,   108,     0,     0,    29,
       0,   113,   113,   113,   113,   113,   113,     0,     0,     0,
     113,   113,   113,   113,    22,    24,     0,    39,    38,    42,
      40,    41,    43,   113,   100,   113,   113,   113,   113,   113,
       0,     0,     0,     0,     0,   110,   111,   109,   107,   113,
     101,   104,   103,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,    32,  -115,     7,   136,   139,   140,   141,   301,  -114,
     302,    -1,   -15,    21,   -13,   -22,   -12,  -115,  -115,  -115,
    -115,  -115,   -62,   -84,    25,   197,  -115,   229,   124,  -115,
    -115,   162,  -115,  -108,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    63,   117,   118,   119,   120,    13,   157,
      14,    99,    35,    36,    37,    38,    39,    40,    89,    15,
      16,    41,   100,    42,    43,    57,    44,    71,    18,   167,
      19,   209,    20,   192,   158
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    34,   159,   160,   161,   162,   163,    12,    22,    33,
      70,    21,    64,   130,     3,    65,    68,    67,    12,    69,
     155,   215,   156,    54,     9,    17,    76,    77,    54,     1,
      64,    64,    56,    90,    91,    55,    17,    56,   182,   183,
       1,     2,     3,    53,     4,     5,     6,    95,    45,     7,
       8,   121,     9,    97,    92,    33,    23,    24,    25,    26,
     102,    33,    33,     9,    46,   133,   134,   135,    33,   243,
      47,   216,    17,    48,    64,   212,   213,   136,   214,   126,
      51,   172,    33,    78,    79,    80,    73,    74,     9,   219,
      23,    24,    25,    26,    73,    74,    27,   131,   132,    75,
      49,    56,    70,    28,    29,   208,   208,   237,   238,   239,
     240,   241,   242,    50,    30,    72,    73,    74,    31,    98,
      32,    75,    52,    56,    64,    64,    58,   169,   170,    61,
      59,     9,    60,    23,    24,    25,    26,    76,    77,   255,
     256,   257,    62,   122,     9,   263,    23,    24,    25,    26,
      33,    96,    27,   123,   101,   186,   124,    30,   125,    28,
      29,    66,   185,    33,   127,   137,    21,   128,    21,   138,
      30,   193,   139,    12,    31,    12,    32,   140,   141,     9,
     142,    23,    24,    25,    26,   143,   145,    27,   144,   210,
     210,    17,   146,    17,    28,    29,   207,   207,   187,     9,
     188,    23,    24,    25,    26,    30,   147,    27,   -46,    31,
     129,    32,   -46,   148,    28,    29,    76,    77,   166,   149,
     150,   151,   -46,   152,   153,    30,   154,   165,   173,    31,
      21,    21,    21,    21,   175,    56,   176,    12,    12,    12,
      12,   177,   168,    21,   171,    21,    21,   193,   193,   193,
      12,   178,    12,    12,   179,    17,    17,    17,    17,   180,
     181,   189,   247,   248,   249,   250,   184,   190,    17,   191,
      17,    17,   198,   194,   195,   252,   196,   253,   254,    81,
      82,   197,    83,    84,   199,   227,    85,    86,   200,   201,
     202,   203,    87,    88,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   220,
     221,   222,   204,   205,   206,   217,   218,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   245,   246,   251,   258,
     223,   259,   174,   224,   225,   226,   260,   261,    93,    94,
     262,   244,   211,   164
};

static const yytype_int16 yycheck[] =
{
       0,     2,   116,   117,   118,   119,   120,     0,     1,     2,
      32,    11,    27,    75,     5,    27,    31,    30,    11,    31,
      47,    11,    49,    49,    26,     0,    51,    52,    49,     3,
      45,    46,    58,    45,    46,    56,    11,    58,    26,    27,
       3,     4,     5,    11,     7,     8,     9,    48,    56,    12,
      13,    66,    26,    54,    47,    48,    28,    29,    30,    31,
      61,    54,    55,    26,    56,    78,    79,    80,    61,    60,
      56,    61,    47,    56,    89,    28,    29,    89,    31,    72,
      44,   143,    75,    53,    54,    55,    51,    52,    26,   203,
      28,    29,    30,    31,    51,    52,    34,    76,    77,    56,
      43,    58,   124,    41,    42,   189,   190,   221,   222,   223,
     224,   225,   226,    43,    52,    50,    51,    52,    56,    57,
      58,    56,     0,    58,   139,   140,    43,   139,   140,    49,
      43,    26,    43,    28,    29,    30,    31,    51,    52,   247,
     248,   249,    48,    57,    26,   259,    28,    29,    30,    31,
     143,    26,    34,    57,    28,   156,    47,    52,    59,    41,
      42,    56,   155,   156,    51,    57,   166,    52,   168,    57,
      52,   171,    43,   166,    56,   168,    58,    43,    57,    26,
      43,    28,    29,    30,    31,    47,    59,    34,    57,   189,
     190,   166,    45,   168,    41,    42,   189,   190,   166,    26,
     168,    28,    29,    30,    31,    52,    45,    34,    43,    56,
      57,    58,    47,    45,    41,    42,    51,    52,    60,    45,
      45,    45,    57,    45,    45,    52,    45,    57,    43,    56,
     230,   231,   232,   233,    28,    58,    28,   230,   231,   232,
     233,    28,    60,   243,    60,   245,   246,   247,   248,   249,
     243,    28,   245,   246,    28,   230,   231,   232,   233,    28,
      26,    43,   230,   231,   232,   233,    27,    43,   243,    10,
     245,   246,    47,    46,    46,   243,    46,   245,   246,    32,
      33,    46,    35,    36,    47,     6,    39,    40,    46,    46,
      46,    46,    45,    46,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    48,    61,    61,    26,    26,    57,    57,    48,
      48,    48,    48,    46,    46,    45,    60,    60,    27,    61,
     204,    46,   145,   204,   204,   204,    61,    61,    47,    47,
      61,   227,   190,   124
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    12,    13,    26,
      63,    64,    65,    70,    72,    81,    82,    86,    90,    92,
      94,    96,    65,    28,    29,    30,    31,    34,    41,    42,
      52,    56,    58,    65,    73,    74,    75,    76,    77,    78,
      79,    83,    85,    86,    88,    56,    56,    56,    56,    43,
      43,    44,     0,    63,    49,    56,    58,    87,    43,    43,
      43,    49,    48,    65,    74,    78,    56,    76,    74,    78,
      77,    89,    50,    51,    52,    56,    51,    52,    53,    54,
      55,    32,    33,    35,    36,    39,    40,    45,    46,    80,
      78,    78,    65,    70,    72,    73,    26,    73,    57,    73,
      84,    28,    73,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    66,    67,    68,
      69,    74,    57,    57,    47,    59,    65,    51,    52,    57,
      84,    75,    75,    76,    76,    76,    78,    57,    57,    43,
      43,    57,    43,    47,    57,    59,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    47,    49,    71,    96,    71,
      71,    71,    71,    71,    89,    57,    60,    91,    60,    78,
      78,    60,    84,    43,    87,    28,    28,    28,    28,    28,
      28,    26,    26,    27,    27,    65,    73,    63,    63,    43,
      43,    10,    95,    96,    46,    46,    46,    46,    47,    47,
      46,    46,    46,    46,    48,    61,    61,    65,    85,    93,
      96,    93,    28,    29,    31,    11,    61,    26,    26,    71,
      25,    26,    27,    66,    67,    68,    69,     6,    57,    57,
      48,    48,    48,    48,    46,    46,    45,    71,    71,    71,
      71,    71,    71,    60,    90,    60,    60,    63,    63,    63,
      63,    27,    63,    63,    63,    95,    95,    95,    61,    46,
      61,    61,    61,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    89,    89,    90,    91,
      91,    91,    92,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     2,     2,     1,     3,     0,     1,     1,     4,     4,
       4,     4,     6,     1,     6,     4,     4,     4,     5,     8,
       5,     5,     5,     5,     5,     2,     1,     8,     5,     5,
       5,     5,     5,     5,     3,     3,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     4,     4,     3,     3,     1,
       3,     3,     2,     4,     3,     3,     3,     1,     5,     3,
       5,     7,     7,    11,    11,     1,     1,    10,     7,     5,
       5,     5,     1,     0
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
#line 1478 "y.tab.c"
    break;

  case 51: /* arithmetic_expr: arithmetic_expr '-' term  */
#line 91 "temp_yacc.y"
                                           {printf("Rule: arithmetic_expr : arithmetic_expr \'-\' term\n");}
#line 1484 "y.tab.c"
    break;

  case 52: /* arithmetic_expr: term  */
#line 92 "temp_yacc.y"
                       {printf("Rule: arithmetic_expr : term\n");}
#line 1490 "y.tab.c"
    break;

  case 53: /* term: term '*' factor  */
#line 96 "temp_yacc.y"
                                  {printf("Rule: term : term \'*\' factor\n");}
#line 1496 "y.tab.c"
    break;

  case 54: /* term: term '/' factor  */
#line 97 "temp_yacc.y"
                                  {printf("Rule: term : term \'/\' factor\n");}
#line 1502 "y.tab.c"
    break;

  case 55: /* term: term '%' factor  */
#line 98 "temp_yacc.y"
                                  {printf("Rule: term : term \'\%\' factor\n");}
#line 1508 "y.tab.c"
    break;

  case 56: /* term: factor  */
#line 99 "temp_yacc.y"
                         {printf("Rule: term : factor\n");}
#line 1514 "y.tab.c"
    break;

  case 57: /* factor: var  */
#line 102 "temp_yacc.y"
                      {printf("Rule: factor : var\n");}
#line 1520 "y.tab.c"
    break;

  case 58: /* factor: '(' arithmetic_expr ')'  */
#line 103 "temp_yacc.y"
                                          {printf("Rule: factor : \'(\' arithmetic_expr \')\'\n");}
#line 1526 "y.tab.c"
    break;

  case 60: /* factor: constant  */
#line 105 "temp_yacc.y"
                           {printf("Rule: factor : constant\n");}
#line 1532 "y.tab.c"
    break;

  case 61: /* factor: call_stmt  */
#line 106 "temp_yacc.y"
                            {printf("Rule: factor : call_stmt\n");}
#line 1538 "y.tab.c"
    break;

  case 62: /* factor: array_access  */
#line 107 "temp_yacc.y"
                               {printf("Rule: factor : array_access\n");}
#line 1544 "y.tab.c"
    break;

  case 63: /* factor: unary_operation  */
#line 108 "temp_yacc.y"
                                  {printf("Rule: factor : unary_operation\n");}
#line 1550 "y.tab.c"
    break;


#line 1554 "y.tab.c"

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

#line 206 "temp_yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
