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
    KW_CLAIM = 258,                /* KW_CLAIM  */
    KW_IS = 259,                   /* KW_IS  */
    KW_GROUP = 260,                /* KW_GROUP  */
    KW_RING = 261,                 /* KW_RING  */
    KW_FIELD = 262,                /* KW_FIELD  */
    KW_SPACE = 263,                /* KW_SPACE  */
    KW_PRINT = 264,                /* KW_PRINT  */
    KW_LET = 265,                  /* KW_LET  */
    KW_RETURN = 266,               /* KW_RETURN  */
    KW_IF = 267,                   /* KW_IF  */
    KW_ELSE = 268,                 /* KW_ELSE  */
    KW_WHILE = 269,                /* KW_WHILE  */
    KW_FOR = 270,                  /* KW_FOR  */
    KW_IN = 271,                   /* KW_IN  */
    KW_SWITCH = 272,               /* KW_SWITCH  */
    KW_CASE = 273,                 /* KW_CASE  */
    KW_DEFAULT = 274,              /* KW_DEFAULT  */
    KW_BREAK = 275,                /* KW_BREAK  */
    KW_CONTINUE = 276,             /* KW_CONTINUE  */
    KW_CYCLIC = 277,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 278,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 279,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 280,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 281,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 282,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 283,              /* KW_INV_MAT  */
    KW_BIGINT = 284,               /* KW_BIGINT  */
    KW_MATRIX = 285,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 286,           /* KW_POLYNOMIAL  */
    KW_VEC = 287,                  /* KW_VEC  */
    KW_BUF = 288,                  /* KW_BUF  */
    IDENT = 289,                   /* IDENT  */
    PRIMITIVE_DTYPE = 290,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 291,                 /* LIT_INT  */
    LIT_FLOAT = 292,               /* LIT_FLOAT  */
    LIT_STR = 293,                 /* LIT_STR  */
    LIT_CHAR = 294,                /* LIT_CHAR  */
    LOGICAL_AND = 295,             /* LOGICAL_AND  */
    LOGICAL_OR = 296,              /* LOGICAL_OR  */
    LOGICAL_NOT = 297,             /* LOGICAL_NOT  */
    EQ = 298,                      /* EQ  */
    NEQ = 299,                     /* NEQ  */
    GT = 300,                      /* GT  */
    LT = 301,                      /* LT  */
    GTEQ = 302,                    /* GTEQ  */
    LTEQ = 303,                    /* LTEQ  */
    KW_TRUE = 304,                 /* KW_TRUE  */
    KW_FALSE = 305                 /* KW_FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
  YYSYMBOL_KW_CLAIM = 3,                   /* KW_CLAIM  */
  YYSYMBOL_KW_IS = 4,                      /* KW_IS  */
  YYSYMBOL_KW_GROUP = 5,                   /* KW_GROUP  */
  YYSYMBOL_KW_RING = 6,                    /* KW_RING  */
  YYSYMBOL_KW_FIELD = 7,                   /* KW_FIELD  */
  YYSYMBOL_KW_SPACE = 8,                   /* KW_SPACE  */
  YYSYMBOL_KW_PRINT = 9,                   /* KW_PRINT  */
  YYSYMBOL_KW_LET = 10,                    /* KW_LET  */
  YYSYMBOL_KW_RETURN = 11,                 /* KW_RETURN  */
  YYSYMBOL_KW_IF = 12,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 13,                   /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 14,                  /* KW_WHILE  */
  YYSYMBOL_KW_FOR = 15,                    /* KW_FOR  */
  YYSYMBOL_KW_IN = 16,                     /* KW_IN  */
  YYSYMBOL_KW_SWITCH = 17,                 /* KW_SWITCH  */
  YYSYMBOL_KW_CASE = 18,                   /* KW_CASE  */
  YYSYMBOL_KW_DEFAULT = 19,                /* KW_DEFAULT  */
  YYSYMBOL_KW_BREAK = 20,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 21,               /* KW_CONTINUE  */
  YYSYMBOL_KW_CYCLIC = 22,                 /* KW_CYCLIC  */
  YYSYMBOL_KW_BIG_RATIONAL = 23,           /* KW_BIG_RATIONAL  */
  YYSYMBOL_KW_COMPLEX = 24,                /* KW_COMPLEX  */
  YYSYMBOL_KW_SYMMETRIC = 25,              /* KW_SYMMETRIC  */
  YYSYMBOL_KW_ALTERNATING = 26,            /* KW_ALTERNATING  */
  YYSYMBOL_KW_DIHEDRAL = 27,               /* KW_DIHEDRAL  */
  YYSYMBOL_KW_INV_MAT = 28,                /* KW_INV_MAT  */
  YYSYMBOL_KW_BIGINT = 29,                 /* KW_BIGINT  */
  YYSYMBOL_KW_MATRIX = 30,                 /* KW_MATRIX  */
  YYSYMBOL_KW_POLYNOMIAL = 31,             /* KW_POLYNOMIAL  */
  YYSYMBOL_KW_VEC = 32,                    /* KW_VEC  */
  YYSYMBOL_KW_BUF = 33,                    /* KW_BUF  */
  YYSYMBOL_IDENT = 34,                     /* IDENT  */
  YYSYMBOL_PRIMITIVE_DTYPE = 35,           /* PRIMITIVE_DTYPE  */
  YYSYMBOL_LIT_INT = 36,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 37,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_STR = 38,                   /* LIT_STR  */
  YYSYMBOL_LIT_CHAR = 39,                  /* LIT_CHAR  */
  YYSYMBOL_LOGICAL_AND = 40,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 41,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 42,               /* LOGICAL_NOT  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_NEQ = 44,                       /* NEQ  */
  YYSYMBOL_GT = 45,                        /* GT  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GTEQ = 47,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 48,                      /* LTEQ  */
  YYSYMBOL_KW_TRUE = 49,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 50,                  /* KW_FALSE  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_56_ = 56,                       /* '<'  */
  YYSYMBOL_57_ = 57,                       /* '>'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_59_ = 59,                       /* '='  */
  YYSYMBOL_60_ = 60,                       /* '@'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_66_ = 66,                       /* '['  */
  YYSYMBOL_67_ = 67,                       /* ']'  */
  YYSYMBOL_68_ = 68,                       /* '{'  */
  YYSYMBOL_69_ = 69,                       /* '}'  */
  YYSYMBOL_70_ = 70,                       /* '~'  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_statements = 72,                /* statements  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_print_param_list = 74,          /* print_param_list  */
  YYSYMBOL_var = 75,                       /* var  */
  YYSYMBOL_field_data_type = 76,           /* field_data_type  */
  YYSYMBOL_group_data_type = 77,           /* group_data_type  */
  YYSYMBOL_ring_data_type = 78,            /* ring_data_type  */
  YYSYMBOL_space_data_type = 79,           /* space_data_type  */
  YYSYMBOL_declaration = 80,               /* declaration  */
  YYSYMBOL_A = 81,                         /* A  */
  YYSYMBOL_assignment = 82,                /* assignment  */
  YYSYMBOL_expression = 83,                /* expression  */
  YYSYMBOL_arithmetic_expr = 84,           /* arithmetic_expr  */
  YYSYMBOL_term = 85,                      /* term  */
  YYSYMBOL_factor = 86,                    /* factor  */
  YYSYMBOL_constant = 87,                  /* constant  */
  YYSYMBOL_logical_expr = 88,              /* logical_expr  */
  YYSYMBOL_B = 89,                         /* B  */
  YYSYMBOL_logical_op = 90,                /* logical_op  */
  YYSYMBOL_return_stmt = 91,               /* return_stmt  */
  YYSYMBOL_call_stmt_standalone = 92,      /* call_stmt_standalone  */
  YYSYMBOL_call_stmt = 93,                 /* call_stmt  */
  YYSYMBOL_pass_param_list = 94,           /* pass_param_list  */
  YYSYMBOL_unary_operation = 95,           /* unary_operation  */
  YYSYMBOL_array_access = 96,              /* array_access  */
  YYSYMBOL_C = 97,                         /* C  */
  YYSYMBOL_array_decl = 98,                /* array_decl  */
  YYSYMBOL_array_list = 99,                /* array_list  */
  YYSYMBOL_if_else_conditional = 100,      /* if_else_conditional  */
  YYSYMBOL_D = 101,                        /* D  */
  YYSYMBOL_loop_stmt = 102,                /* loop_stmt  */
  YYSYMBOL_V = 103,                        /* V  */
  YYSYMBOL_switch_case = 104,              /* switch_case  */
  YYSYMBOL_switch_case_blocks = 105,       /* switch_case_blocks  */
  YYSYMBOL_archetype_claim = 106,          /* archetype_claim  */
  YYSYMBOL_group_closure_rule = 107,       /* group_closure_rule  */
  YYSYMBOL_ring_closure_rule = 108,        /* ring_closure_rule  */
  YYSYMBOL_identity_rule = 109,            /* identity_rule  */
  YYSYMBOL_group_inverse_rule = 110,       /* group_inverse_rule  */
  YYSYMBOL_field_inverse_rule = 111,       /* field_inverse_rule  */
  YYSYMBOL_epsilon = 112                   /* epsilon  */
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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_CLAIM", "KW_IS",
  "KW_GROUP", "KW_RING", "KW_FIELD", "KW_SPACE", "KW_PRINT", "KW_LET",
  "KW_RETURN", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_IN",
  "KW_SWITCH", "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_CONTINUE",
  "KW_CYCLIC", "KW_BIG_RATIONAL", "KW_COMPLEX", "KW_SYMMETRIC",
  "KW_ALTERNATING", "KW_DIHEDRAL", "KW_INV_MAT", "KW_BIGINT", "KW_MATRIX",
  "KW_POLYNOMIAL", "KW_VEC", "KW_BUF", "IDENT", "PRIMITIVE_DTYPE",
  "LIT_INT", "LIT_FLOAT", "LIT_STR", "LIT_CHAR", "LOGICAL_AND",
  "LOGICAL_OR", "LOGICAL_NOT", "EQ", "NEQ", "GT", "LT", "GTEQ", "LTEQ",
  "KW_TRUE", "KW_FALSE", "';'", "'('", "')'", "','", "'.'", "'<'", "'>'",
  "':'", "'='", "'@'", "'+'", "'-'", "'*'", "'/'", "'%'", "'['", "']'",
  "'{'", "'}'", "'~'", "$accept", "statements", "statement",
  "print_param_list", "var", "field_data_type", "group_data_type",
  "ring_data_type", "space_data_type", "declaration", "A", "assignment",
  "expression", "arithmetic_expr", "term", "factor", "constant",
  "logical_expr", "B", "logical_op", "return_stmt", "call_stmt_standalone",
  "call_stmt", "pass_param_list", "unary_operation", "array_access", "C",
  "array_decl", "array_list", "if_else_conditional", "D", "loop_stmt", "V",
  "switch_case", "switch_case_blocks", "archetype_claim",
  "group_closure_rule", "ring_closure_rule", "identity_rule",
  "group_inverse_rule", "field_inverse_rule", "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-197)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,   -12,  -197,   -68,     4,   218,   221,   222,   223,   419,
    -132,   420,     6,    11,   119,    23,   -26,    49,  -197,  -197,
    -197,  -197,  -197,   -61,   -15,     0,   294,  -197,   318,   174,
    -197,  -197,   236,  -197,  -189,  -197,   130,   122,  -196,   132,
    -197,  -119
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    12,    13,    70,    14,   135,   136,   137,   138,    15,
     183,    16,    71,    40,    41,    42,    43,    44,    45,    99,
      17,    18,    46,   110,    47,    48,    63,    49,    81,    20,
     193,    21,   253,    22,   227,    23,   203,   205,   231,   264,
     207,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
  case 56: /* arithmetic_expr: arithmetic_expr '+' term  */
#line 98 "temp_yacc.y"
                                           {printf("Rule: arithmetic_expr : arithmetic_expr \'+\' term\n");}
#line 1579 "y.tab.c"
    break;

  case 57: /* arithmetic_expr: arithmetic_expr '-' term  */
#line 99 "temp_yacc.y"
                                           {printf("Rule: arithmetic_expr : arithmetic_expr \'-\' term\n");}
#line 1585 "y.tab.c"
    break;

  case 58: /* arithmetic_expr: term  */
#line 100 "temp_yacc.y"
                       {printf("Rule: arithmetic_expr : term\n");}
#line 1591 "y.tab.c"
    break;

  case 59: /* term: term '*' factor  */
#line 104 "temp_yacc.y"
                                  {printf("Rule: term : term \'*\' factor\n");}
#line 1597 "y.tab.c"
    break;

  case 60: /* term: term '/' factor  */
#line 105 "temp_yacc.y"
                                  {printf("Rule: term : term \'/\' factor\n");}
#line 1603 "y.tab.c"
    break;

  case 61: /* term: term '%' factor  */
#line 106 "temp_yacc.y"
                                  {printf("Rule: term : term \'\%\' factor\n");}
#line 1609 "y.tab.c"
    break;

  case 62: /* term: factor  */
#line 107 "temp_yacc.y"
                         {printf("Rule: term : factor\n");}
#line 1615 "y.tab.c"
    break;

  case 63: /* factor: var  */
#line 110 "temp_yacc.y"
                      {printf("Rule: factor : var\n");}
#line 1621 "y.tab.c"
    break;

  case 64: /* factor: '(' arithmetic_expr ')'  */
#line 111 "temp_yacc.y"
                                          {printf("Rule: factor : \'(\' arithmetic_expr \')\'\n");}
#line 1627 "y.tab.c"
    break;

  case 66: /* factor: constant  */
#line 113 "temp_yacc.y"
                           {printf("Rule: factor : constant\n");}
#line 1633 "y.tab.c"
    break;

  case 67: /* factor: call_stmt  */
#line 114 "temp_yacc.y"
                            {printf("Rule: factor : call_stmt\n");}
#line 1639 "y.tab.c"
    break;

  case 68: /* factor: array_access  */
#line 115 "temp_yacc.y"
                               {printf("Rule: factor : array_access\n");}
#line 1645 "y.tab.c"
    break;

  case 69: /* factor: unary_operation  */
#line 116 "temp_yacc.y"
                                  {printf("Rule: factor : unary_operation\n");}
#line 1651 "y.tab.c"
    break;

  case 120: /* archetype_claim: KW_CLAIM IDENT KW_IS KW_GROUP '{' group_closure_rule identity_rule group_inverse_rule '}' ';'  */
#line 213 "temp_yacc.y"
                                                                                                                    {printf("Group claim rule\n");}
#line 1657 "y.tab.c"
    break;

  case 124: /* group_closure_rule: '(' IDENT '=' IDENT '+' IDENT ')' '=' '>' '{' statements '}'  */
#line 219 "temp_yacc.y"
                                                                                   {printf("Group_closure_rule\n");}
#line 1663 "y.tab.c"
    break;


#line 1667 "y.tab.c"

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

#line 236 "temp_yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
