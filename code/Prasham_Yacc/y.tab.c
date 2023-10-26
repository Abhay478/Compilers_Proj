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
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '*'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_54_ = 54,                       /* '%'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* '{'  */
  YYSYMBOL_60_ = 60,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_statements = 62,                /* statements  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_var = 64,                       /* var  */
  YYSYMBOL_field_data_type = 65,           /* field_data_type  */
  YYSYMBOL_group_data_type = 66,           /* group_data_type  */
  YYSYMBOL_ring_data_type = 67,            /* ring_data_type  */
  YYSYMBOL_space_data_type = 68,           /* space_data_type  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_A = 70,                         /* A  */
  YYSYMBOL_assignment = 71,                /* assignment  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_arithmetic_expr = 73,           /* arithmetic_expr  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_factor = 75,                    /* factor  */
  YYSYMBOL_constant = 76,                  /* constant  */
  YYSYMBOL_logical_expr = 77,              /* logical_expr  */
  YYSYMBOL_B = 78,                         /* B  */
  YYSYMBOL_logical_op = 79,                /* logical_op  */
  YYSYMBOL_return_stmt = 80,               /* return_stmt  */
  YYSYMBOL_call_stmt_standalone = 81,      /* call_stmt_standalone  */
  YYSYMBOL_call_stmt = 82,                 /* call_stmt  */
  YYSYMBOL_pass_param_list = 83,           /* pass_param_list  */
  YYSYMBOL_unary_operation = 84,           /* unary_operation  */
  YYSYMBOL_array_access = 85,              /* array_access  */
  YYSYMBOL_C = 86,                         /* C  */
  YYSYMBOL_array_decl = 87,                /* array_decl  */
  YYSYMBOL_array_list = 88,                /* array_list  */
  YYSYMBOL_if_else_conditional = 89,       /* if_else_conditional  */
  YYSYMBOL_D = 90,                         /* D  */
  YYSYMBOL_loop_stmt = 91,                 /* loop_stmt  */
  YYSYMBOL_V = 92,                         /* V  */
  YYSYMBOL_switch_case = 93,               /* switch_case  */
  YYSYMBOL_switch_case_blocks = 94,        /* switch_case_blocks  */
  YYSYMBOL_epsilon = 95                    /* epsilon  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

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
       2,     2,     2,     2,     2,     2,     2,    54,     2,     2,
      55,    56,    52,    50,    47,    51,    44,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    43,
      45,    49,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      56,    57,    58,    59,    60,    63,    64,    67,    68,    71,
      72,    78,    81,    82,    83,    87,    88,    89,    90,    93,
      94,    95,    96,    97,    98,    99,   102,   103,   104,   105,
     108,   109,   110,   113,   116,   117,   118,   121,   122,   123,
     124,   125,   126,   127,   128,   131,   134,   135,   138,   139,
     142,   143,   146,   147,   150,   153,   154,   157,   160,   161,
     164,   167,   168,   169,   176,   177,   178,   181,   182,   185,
     186,   189,   190,   191,   192,   195
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
  "'>'", "','", "':'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "$accept", "statements", "statement",
  "var", "field_data_type", "group_data_type", "ring_data_type",
  "space_data_type", "declaration", "A", "assignment", "expression",
  "arithmetic_expr", "term", "factor", "constant", "logical_expr", "B",
  "logical_op", "return_stmt", "call_stmt_standalone", "call_stmt",
  "pass_param_list", "unary_operation", "array_access", "C", "array_decl",
  "array_list", "if_else_conditional", "D", "loop_stmt", "V",
  "switch_case", "switch_case_blocks", "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     248,    19,   118,    -4,    18,    33,    38,    47,    57,    58,
     105,   248,    -9,    64,    74,    88,  -160,    77,  -160,  -160,
    -160,  -160,    84,  -160,  -160,  -160,  -160,   161,  -160,  -160,
       8,   161,    83,    46,  -160,   120,   -25,  -160,  -160,  -160,
     165,  -160,  -160,  -160,  -160,   161,   161,    17,   118,  -160,
    -160,   108,  -160,  -160,   118,    53,   107,  -160,  -160,  -160,
    -160,   118,   261,    27,  -160,     8,  -160,    35,    80,    90,
      81,    92,    87,    99,     8,     8,     8,     8,     8,  -160,
    -160,  -160,  -160,  -160,  -160,  -160,  -160,   161,    89,    95,
      -5,   100,   114,   102,  -160,  -160,   122,   119,   112,   103,
    -160,   132,  -160,  -160,   133,   134,   135,   136,  -160,   137,
     138,   148,   149,   147,   147,   147,   147,   147,   147,    35,
    -160,  -160,    83,  -160,  -160,  -160,  -160,   143,   -25,   -25,
    -160,  -160,  -160,  -160,   150,   154,   161,   161,   155,  -160,
     118,   163,   151,   179,   187,   193,   194,   196,   203,   206,
      15,   207,   118,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,  -160,   248,  -160,   248,   195,   197,   227,  -160,  -160,
    -160,   199,   200,   202,   208,   192,   211,   213,   216,   217,
     218,  -160,   205,   209,    19,    19,    25,     4,  -160,  -160,
    -160,  -160,  -160,   240,   241,  -160,  -160,  -160,   147,   262,
    -160,    48,  -160,   214,  -160,   215,   224,   225,   242,   243,
    -160,   246,   247,  -160,    12,   230,   235,   248,   248,   248,
     248,  -160,  -160,   248,  -160,   248,   248,   227,   227,   227,
     236,   237,   238,   239,  -160,  -160,  -160,  -160,  -160,  -160,
    -160
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
     105,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,   105,     0,     0,     0,     0,     6,     0,     8,    10,
       9,     3,     0,    58,    57,    59,    56,     0,    65,    66,
       0,     0,     0,    49,    75,    63,    44,    48,    52,    40,
      61,    53,    55,    54,    41,     0,     0,     0,     0,    11,
      12,     0,     1,     2,     0,     0,     0,    84,     4,     5,
       7,     0,    15,    63,    62,     0,    51,    63,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    71,    72,    69,    70,    68,    67,     0,     0,     0,
       0,     0,     0,     0,    14,    37,     0,    81,     0,     0,
      38,     0,    16,    17,     0,     0,     0,     0,    23,     0,
       0,     0,     0,   105,   105,   105,   105,   105,   105,     0,
      50,    64,     0,    87,    82,    83,    79,     0,    42,    43,
      45,    46,    47,    60,     0,     0,     0,     0,     0,    77,
       0,     0,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    36,    28,    33,    31,    32,    34,
      88,    78,   105,    90,   105,     0,     0,   105,    80,    76,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,   105,   105,     0,     0,   104,    18,
      19,    20,    21,     0,     0,    25,    26,    27,   105,    91,
      94,     0,    97,     0,    98,     0,     0,     0,     0,     0,
     100,     0,     0,    29,     0,     0,     0,   105,   105,   105,
     105,    22,    24,   105,    92,   105,   105,   105,   105,   105,
       0,     0,     0,     0,   102,   103,   101,    99,    93,    96,
      95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,    24,  -160,     0,  -160,  -160,  -160,  -160,   253,   -92,
     254,     1,   -15,   -14,   -11,   -30,   -13,  -160,  -160,  -160,
    -160,  -160,   -60,   -69,    10,   153,  -160,   180,    91,  -160,
    -160,   121,  -160,  -159,  -109
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    33,   115,   116,   117,   118,    13,   153,
      14,    97,    35,    36,    37,    38,    39,    40,    87,    15,
      16,    41,    98,    42,    43,    57,    44,    70,    18,   163,
      19,   203,    20,   187,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    22,    69,    34,   154,   154,   154,   154,   154,   154,
      17,    12,    63,   127,    64,   209,    67,     3,    68,    66,
       1,    17,   155,   156,   157,   158,   159,    76,    77,    78,
      63,    63,    88,    89,     9,    53,    23,    24,    25,    26,
      54,   178,   179,     9,    54,     9,    55,    90,    56,    93,
     119,    45,    56,   206,   207,    95,   208,    17,   188,    30,
     128,   129,   100,    65,   210,   130,   131,   132,   234,   235,
     236,   223,    63,    46,   133,   204,   204,    74,    75,     9,
     168,    23,    24,    25,    26,    74,    75,    27,    47,   154,
      49,   120,    69,    48,    28,    29,    71,    72,    71,    72,
      50,    73,    51,    56,    30,    52,   213,    58,    31,    96,
      32,    23,    24,    25,    26,   202,   202,    59,   188,   188,
     188,    63,    63,   165,   166,     9,    61,    23,    24,    25,
      26,    60,    62,    27,    94,    99,   121,   122,   125,   123,
      28,    29,   124,   136,     9,   134,    23,    24,    25,    26,
      30,   135,    27,   181,    31,   126,    32,   137,   138,    28,
      29,   142,    12,   -39,    12,   139,   140,   -39,   141,    30,
      74,    75,    17,    31,    17,    32,   -39,   143,   144,   145,
     146,   147,   148,   149,   201,   201,   182,     9,   183,    23,
      24,    25,    26,   150,   151,    27,   152,    79,    80,   161,
      81,    82,    28,    29,    83,    84,   169,   171,    56,   162,
      85,    86,    30,   164,   167,   172,    31,    12,    12,    12,
      12,   173,   174,    12,   175,    12,    12,    17,    17,    17,
      17,   176,   177,    17,   180,    17,    17,   186,   184,   193,
     185,   227,   228,   229,   230,   189,   190,   231,   191,   232,
     233,     1,     2,     3,   192,     4,     5,     6,   194,   195,
       7,     8,   196,   197,   198,   199,   211,   212,   214,   200,
     215,   216,   217,   218,     9,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   225,
     219,   220,   221,   222,   226,   170,   237,   238,   239,   240,
      91,    92,   160,     0,     0,   224,   205
};

static const yytype_int16 yycheck[] =
{
       0,     1,    32,     2,   113,   114,   115,   116,   117,   118,
       0,    11,    27,    73,    27,    11,    31,     5,    31,    30,
       3,    11,   114,   115,   116,   117,   118,    52,    53,    54,
      45,    46,    45,    46,    26,    11,    28,    29,    30,    31,
      49,    26,    27,    26,    49,    26,    55,    47,    57,    48,
      65,    55,    57,    28,    29,    54,    31,    47,   167,    51,
      74,    75,    61,    55,    60,    76,    77,    78,   227,   228,
     229,    59,    87,    55,    87,   184,   185,    50,    51,    26,
     140,    28,    29,    30,    31,    50,    51,    34,    55,   198,
      43,    56,   122,    55,    41,    42,    50,    51,    50,    51,
      43,    55,    44,    57,    51,     0,   198,    43,    55,    56,
      57,    28,    29,    30,    31,   184,   185,    43,   227,   228,
     229,   136,   137,   136,   137,    26,    49,    28,    29,    30,
      31,    43,    48,    34,    26,    28,    56,    47,    51,    58,
      41,    42,    50,    43,    26,    56,    28,    29,    30,    31,
      51,    56,    34,   152,    55,    56,    57,    43,    56,    41,
      42,    58,   162,    43,   164,    43,    47,    47,    56,    51,
      50,    51,   162,    55,   164,    57,    56,    45,    45,    45,
      45,    45,    45,    45,   184,   185,   162,    26,   164,    28,
      29,    30,    31,    45,    45,    34,    49,    32,    33,    56,
      35,    36,    41,    42,    39,    40,    43,    28,    57,    59,
      45,    46,    51,    59,    59,    28,    55,   217,   218,   219,
     220,    28,    28,   223,    28,   225,   226,   217,   218,   219,
     220,    28,    26,   223,    27,   225,   226,    10,    43,    47,
      43,   217,   218,   219,   220,    46,    46,   223,    46,   225,
     226,     3,     4,     5,    46,     7,     8,     9,    47,    46,
      12,    13,    46,    46,    46,    60,    26,    26,     6,    60,
      56,    56,    48,    48,    26,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    59,
      48,    48,    46,    46,    59,   142,    60,    60,    60,    60,
      47,    47,   122,    -1,    -1,   214,   185
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    12,    13,    26,
      62,    63,    64,    69,    71,    80,    81,    85,    89,    91,
      93,    95,    64,    28,    29,    30,    31,    34,    41,    42,
      51,    55,    57,    64,    72,    73,    74,    75,    76,    77,
      78,    82,    84,    85,    87,    55,    55,    55,    55,    43,
      43,    44,     0,    62,    49,    55,    57,    86,    43,    43,
      43,    49,    48,    73,    77,    55,    75,    73,    77,    76,
      88,    50,    51,    55,    50,    51,    52,    53,    54,    32,
      33,    35,    36,    39,    40,    45,    46,    79,    77,    77,
      64,    69,    71,    72,    26,    72,    56,    72,    83,    28,
      72,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    65,    66,    67,    68,    73,
      56,    56,    47,    58,    50,    51,    56,    83,    74,    74,
      75,    75,    75,    77,    56,    56,    43,    43,    56,    43,
      47,    56,    58,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    49,    70,    95,    70,    70,    70,    70,    70,
      88,    56,    59,    90,    59,    77,    77,    59,    83,    43,
      86,    28,    28,    28,    28,    28,    28,    26,    26,    27,
      27,    72,    62,    62,    43,    43,    10,    94,    95,    46,
      46,    46,    46,    47,    47,    46,    46,    46,    46,    60,
      60,    64,    84,    92,    95,    92,    28,    29,    31,    11,
      60,    26,    26,    70,     6,    56,    56,    48,    48,    48,
      48,    46,    46,    59,    89,    59,    59,    62,    62,    62,
      62,    62,    62,    62,    94,    94,    94,    60,    60,    60,
      60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    86,    86,    87,    88,    88,
      89,    90,    90,    90,    91,    91,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     2,     2,     1,     3,     0,     1,     1,     4,     4,
       4,     4,     6,     1,     6,     4,     4,     4,     5,     8,
       5,     5,     5,     5,     5,     2,     1,     3,     3,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     4,     4,     3,
       3,     1,     3,     3,     2,     4,     3,     3,     3,     1,
       5,     3,     5,     7,     7,    11,    11,     1,     1,    10,
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

#line 1456 "y.tab.c"

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

#line 197 "temp_yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
