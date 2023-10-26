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
    KW_CYCLIC = 268,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 269,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 270,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 271,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 272,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 273,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 274,              /* KW_INV_MAT  */
    KW_BIGINT = 275,               /* KW_BIGINT  */
    KW_MATRIX = 276,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 277,           /* KW_POLYNOMIAL  */
    KW_VEC = 278,                  /* KW_VEC  */
    KW_BUF = 279,                  /* KW_BUF  */
    IDENT = 280,                   /* IDENT  */
    PRIMITIVE_DTYPE = 281,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 282,                 /* LIT_INT  */
    LIT_FLOAT = 283,               /* LIT_FLOAT  */
    LIT_STR = 284,                 /* LIT_STR  */
    LIT_CHAR = 285,                /* LIT_CHAR  */
    LOGICAL_AND = 286,             /* LOGICAL_AND  */
    LOGICAL_OR = 287,              /* LOGICAL_OR  */
    LOGICAL_NOT = 288,             /* LOGICAL_NOT  */
    EQ = 289,                      /* EQ  */
    NEQ = 290,                     /* NEQ  */
    GT = 291,                      /* GT  */
    LT = 292,                      /* LT  */
    GTEQ = 293,                    /* GTEQ  */
    LTEQ = 294,                    /* LTEQ  */
    KW_TRUE = 295,                 /* KW_TRUE  */
    KW_FALSE = 296                 /* KW_FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

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
  YYSYMBOL_KW_CYCLIC = 13,                 /* KW_CYCLIC  */
  YYSYMBOL_KW_BIG_RATIONAL = 14,           /* KW_BIG_RATIONAL  */
  YYSYMBOL_KW_COMPLEX = 15,                /* KW_COMPLEX  */
  YYSYMBOL_KW_SYMMETRIC = 16,              /* KW_SYMMETRIC  */
  YYSYMBOL_KW_ALTERNATING = 17,            /* KW_ALTERNATING  */
  YYSYMBOL_KW_DIHEDRAL = 18,               /* KW_DIHEDRAL  */
  YYSYMBOL_KW_INV_MAT = 19,                /* KW_INV_MAT  */
  YYSYMBOL_KW_BIGINT = 20,                 /* KW_BIGINT  */
  YYSYMBOL_KW_MATRIX = 21,                 /* KW_MATRIX  */
  YYSYMBOL_KW_POLYNOMIAL = 22,             /* KW_POLYNOMIAL  */
  YYSYMBOL_KW_VEC = 23,                    /* KW_VEC  */
  YYSYMBOL_KW_BUF = 24,                    /* KW_BUF  */
  YYSYMBOL_IDENT = 25,                     /* IDENT  */
  YYSYMBOL_PRIMITIVE_DTYPE = 26,           /* PRIMITIVE_DTYPE  */
  YYSYMBOL_LIT_INT = 27,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 28,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_STR = 29,                   /* LIT_STR  */
  YYSYMBOL_LIT_CHAR = 30,                  /* LIT_CHAR  */
  YYSYMBOL_LOGICAL_AND = 31,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 32,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 33,               /* LOGICAL_NOT  */
  YYSYMBOL_EQ = 34,                        /* EQ  */
  YYSYMBOL_NEQ = 35,                       /* NEQ  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_LT = 37,                        /* LT  */
  YYSYMBOL_GTEQ = 38,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 39,                      /* LTEQ  */
  YYSYMBOL_KW_TRUE = 40,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 41,                  /* KW_FALSE  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '.'  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '*'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '%'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_statements = 61,                /* statements  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_var = 63,                       /* var  */
  YYSYMBOL_field_data_type = 64,           /* field_data_type  */
  YYSYMBOL_group_data_type = 65,           /* group_data_type  */
  YYSYMBOL_ring_data_type = 66,            /* ring_data_type  */
  YYSYMBOL_space_data_type = 67,           /* space_data_type  */
  YYSYMBOL_declaration = 68,               /* declaration  */
  YYSYMBOL_A = 69,                         /* A  */
  YYSYMBOL_assignment = 70,                /* assignment  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_arithmetic_expr = 72,           /* arithmetic_expr  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_constant = 75,                  /* constant  */
  YYSYMBOL_logical_expr = 76,              /* logical_expr  */
  YYSYMBOL_B = 77,                         /* B  */
  YYSYMBOL_logical_op = 78,                /* logical_op  */
  YYSYMBOL_return_stmt = 79,               /* return_stmt  */
  YYSYMBOL_call_stmt_standalone = 80,      /* call_stmt_standalone  */
  YYSYMBOL_call_stmt = 81,                 /* call_stmt  */
  YYSYMBOL_pass_param_list = 82,           /* pass_param_list  */
  YYSYMBOL_unary_operation = 83,           /* unary_operation  */
  YYSYMBOL_array_access = 84,              /* array_access  */
  YYSYMBOL_C = 85,                         /* C  */
  YYSYMBOL_array_decl = 86,                /* array_decl  */
  YYSYMBOL_array_list = 87,                /* array_list  */
  YYSYMBOL_if_else_conditional = 88,       /* if_else_conditional  */
  YYSYMBOL_D = 89,                         /* D  */
  YYSYMBOL_loop_stmt = 90,                 /* loop_stmt  */
  YYSYMBOL_V = 91,                         /* V  */
  YYSYMBOL_epsilon = 92                    /* epsilon  */
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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      54,    55,    51,    49,    46,    50,    43,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    42,
      44,    48,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    14,    14,    15,    18,    19,    20,    21,    22,    23,
      27,    28,    31,    32,    33,    36,    37,    38,    39,    40,
      43,    44,    45,    48,    49,    52,    53,    54,    55,    56,
      57,    58,    61,    62,    65,    68,    69,    74,    75,    78,
      79,    80,    84,    85,    86,    87,    90,    91,    92,    93,
      94,    95,    96,    99,   100,   101,   102,   105,   106,   107,
     110,   113,   114,   115,   118,   119,   120,   121,   122,   123,
     124,   125,   128,   131,   132,   135,   136,   139,   140,   143,
     144,   147,   150,   151,   154,   157,   158,   161,   164,   165,
     166,   173,   174,   175,   178,   179,   191
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
  "KW_DEFAULT", "KW_BREAK", "KW_CYCLIC", "KW_BIG_RATIONAL", "KW_COMPLEX",
  "KW_SYMMETRIC", "KW_ALTERNATING", "KW_DIHEDRAL", "KW_INV_MAT",
  "KW_BIGINT", "KW_MATRIX", "KW_POLYNOMIAL", "KW_VEC", "KW_BUF", "IDENT",
  "PRIMITIVE_DTYPE", "LIT_INT", "LIT_FLOAT", "LIT_STR", "LIT_CHAR",
  "LOGICAL_AND", "LOGICAL_OR", "LOGICAL_NOT", "EQ", "NEQ", "GT", "LT",
  "GTEQ", "LTEQ", "KW_TRUE", "KW_FALSE", "';'", "'.'", "'<'", "'>'", "','",
  "':'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'['",
  "']'", "'{'", "'}'", "$accept", "statements", "statement", "var",
  "field_data_type", "group_data_type", "ring_data_type",
  "space_data_type", "declaration", "A", "assignment", "expression",
  "arithmetic_expr", "term", "factor", "constant", "logical_expr", "B",
  "logical_op", "return_stmt", "call_stmt_standalone", "call_stmt",
  "pass_param_list", "unary_operation", "array_access", "C", "array_decl",
  "array_list", "if_else_conditional", "D", "loop_stmt", "V", "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,    -5,    75,   -31,   -10,    -3,    -9,    68,    33,     5,
      15,    32,    45,   -89,   -89,   -89,   -89,    54,   -89,   -89,
     -89,   -89,   127,   -89,   -89,   134,   127,    49,    -4,   -89,
      44,     9,   -89,   -89,   -89,   172,   -89,   -89,   -20,   -89,
     127,   127,    18,    64,   -89,   -89,    75,    42,   -89,   -89,
     -89,   205,    31,   -89,   -89,   134,   -89,    57,    36,    74,
      69,    79,    90,    94,   115,   -89,   134,   134,   134,   134,
     134,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   127,
      91,   103,   117,   124,   128,   -89,   -89,   129,   123,   119,
     131,   -89,   -89,   132,   135,   136,   138,   -89,   139,   141,
     142,   143,   130,   130,   130,   130,   130,   130,    57,   -89,
     -89,    49,   -89,   -89,   -89,   -89,   137,   133,     9,     9,
     -89,   -89,   -89,   -89,   140,   147,   127,   127,   -89,    75,
     149,   162,   167,   170,   173,   181,   182,   187,    92,   188,
      75,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     157,    33,   -89,    33,   190,   191,   -89,   -89,   189,   192,
     193,   194,   169,   195,   197,   198,   199,   200,   -89,   -89,
     176,   177,    -5,    -5,   -89,   -89,   -89,   -89,   215,   221,
     -89,   -89,   -89,   130,   241,   -89,    83,   -89,   196,   -89,
     201,   203,   204,   -89,     7,   202,   206,   -89,   -89,    33,
     -89,    33,    33,   207,   208,   209,   -89,   -89,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      96,     0,     0,     0,     0,     0,    10,     0,    96,     0,
       0,     0,     0,     6,     8,     9,     3,     0,    55,    54,
      56,    53,     0,    62,    63,     0,     0,     0,    46,    72,
      60,    41,    45,    49,    36,    58,    50,    52,    51,    38,
       0,     0,     0,     0,     1,     2,     0,     0,     4,     5,
       7,    12,    60,    59,    51,     0,    48,    60,     0,    86,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    70,    71,    68,    69,    66,    67,    65,    64,     0,
       0,     0,     0,     0,     0,    11,    34,     0,    78,     0,
       0,    13,    14,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    96,    96,    96,    96,    96,    96,     0,    47,
      61,     0,    84,    79,    80,    76,     0,     0,    39,    40,
      42,    43,    44,    57,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    33,    25,    30,    28,    29,    31,    85,    75,
      83,    96,    87,    96,     0,     0,    77,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    82,
       0,     0,    96,    96,    15,    16,    17,    18,     0,     0,
      22,    23,    24,    96,    88,    91,     0,    94,     0,    95,
       0,     0,     0,    26,     0,     0,     0,    19,    21,    96,
      89,    96,    96,     0,     0,     0,    90,    93,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,    -6,   -89,     0,   -89,   -89,   -89,   -89,   210,   -74,
     211,     3,   -16,    70,   -14,   -23,   -13,   -89,   -89,   -89,
     -89,   -89,   -56,   -34,     1,   100,   -89,   144,    60,   -89,
     -89,    84,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,    28,   104,   105,   106,   107,    10,   141,
      11,    88,    30,    31,    32,    33,    34,    35,    79,    12,
      13,    36,    89,    37,    54,    65,    39,    60,    14,   152,
      15,   188,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    17,    45,    38,    59,    29,    52,   116,     9,    53,
      57,    56,     3,    58,   142,   142,   142,   142,   142,   142,
       6,     1,   -37,    40,    52,    52,   -37,    80,    81,   143,
     144,   145,   146,   147,    43,   -37,     1,     2,     3,   108,
       4,     5,    82,     6,    41,    61,    62,    38,    38,    86,
      63,    42,    64,    46,   120,   121,   122,    48,     6,    47,
      68,    69,    70,    52,    38,   199,   123,     6,    44,    18,
      19,    20,    21,   156,    49,    22,    18,    19,    20,    21,
      66,    67,    23,    24,   189,   189,   -35,    50,    59,    85,
     -35,   110,    25,    66,    67,   142,    26,    87,    27,   -35,
       6,    51,    18,    19,    20,    21,    66,    67,    22,   193,
      52,    52,   109,   154,   155,    23,    24,   165,   166,     6,
     111,    18,    19,    20,    21,    25,   112,    22,   113,    26,
      38,    27,    61,    62,    23,    24,   118,   119,   187,   187,
     114,    38,   117,   168,    25,   170,   124,   171,    26,   115,
      27,     9,     6,     9,    18,    19,    20,    21,   125,     6,
      22,    18,    19,    20,    21,    46,   126,    23,    24,   129,
     127,   128,   186,   186,   130,   131,   132,    25,   140,   133,
     134,    26,   135,   136,    25,   137,   138,   139,    55,   158,
     150,   157,   149,   203,   159,   204,   205,   160,   151,     9,
     161,     9,     9,    71,    72,   153,    73,    74,   162,   163,
      75,    76,   164,    64,   167,   178,    77,    78,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   172,   173,   174,   184,   185,   175,   176,   177,
     191,   179,   180,   181,   182,   183,   192,   194,   197,   198,
     169,   195,    83,    84,   200,   148,   196,   190,     0,     0,
     201,     0,     0,     0,   202,     0,   206,   207,   208
};

static const yytype_int16 yycheck[] =
{
       0,     1,     8,     2,    27,     2,    22,    63,     8,    22,
      26,    25,     5,    26,   102,   103,   104,   105,   106,   107,
      25,     3,    42,    54,    40,    41,    46,    40,    41,   103,
     104,   105,   106,   107,    43,    55,     3,     4,     5,    55,
       7,     8,    42,    25,    54,    49,    50,    46,    47,    46,
      54,    54,    56,    48,    68,    69,    70,    42,    25,    54,
      51,    52,    53,    79,    63,    58,    79,    25,     0,    27,
      28,    29,    30,   129,    42,    33,    27,    28,    29,    30,
      49,    50,    40,    41,   172,   173,    42,    42,   111,    25,
      46,    55,    50,    49,    50,   183,    54,    55,    56,    55,
      25,    47,    27,    28,    29,    30,    49,    50,    33,   183,
     126,   127,    55,   126,   127,    40,    41,    25,    26,    25,
      46,    27,    28,    29,    30,    50,    57,    33,    49,    54,
     129,    56,    49,    50,    40,    41,    66,    67,   172,   173,
      50,   140,    27,   140,    50,   151,    55,   153,    54,    55,
      56,   151,    25,   153,    27,    28,    29,    30,    55,    25,
      33,    27,    28,    29,    30,    48,    42,    40,    41,    46,
      42,    42,   172,   173,    55,    44,    44,    50,    48,    44,
      44,    54,    44,    44,    50,    44,    44,    44,    54,    27,
      57,    42,    55,   199,    27,   201,   202,    27,    58,   199,
      27,   201,   202,    31,    32,    58,    34,    35,    27,    27,
      38,    39,    25,    56,    26,    46,    44,    45,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    42,    42,    45,    59,    59,    45,    45,    45,
      25,    46,    45,    45,    45,    45,    25,     6,    45,    45,
     150,    55,    42,    42,   194,   111,    55,   173,    -1,    -1,
      58,    -1,    -1,    -1,    58,    -1,    59,    59,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,    25,    61,    62,    63,
      68,    70,    79,    80,    88,    90,    92,    63,    27,    28,
      29,    30,    33,    40,    41,    50,    54,    56,    63,    71,
      72,    73,    74,    75,    76,    77,    81,    83,    84,    86,
      54,    54,    54,    43,     0,    61,    48,    54,    42,    42,
      42,    47,    72,    76,    84,    54,    74,    72,    76,    75,
      87,    49,    50,    54,    56,    85,    49,    50,    51,    52,
      53,    31,    32,    34,    35,    38,    39,    44,    45,    78,
      76,    76,    63,    68,    70,    25,    71,    55,    71,    82,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    64,    65,    66,    67,    72,    55,
      55,    46,    57,    49,    50,    55,    82,    27,    73,    73,
      74,    74,    74,    76,    55,    55,    42,    42,    42,    46,
      55,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      48,    69,    92,    69,    69,    69,    69,    69,    87,    55,
      57,    58,    89,    58,    76,    76,    82,    42,    27,    27,
      27,    27,    27,    27,    25,    25,    26,    26,    71,    85,
      61,    61,    42,    42,    45,    45,    45,    45,    46,    46,
      45,    45,    45,    45,    59,    59,    63,    83,    91,    92,
      91,    25,    25,    69,     6,    55,    55,    45,    45,    58,
      88,    58,    58,    61,    61,    61,    59,    59,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    71,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    86,    87,    87,    88,    89,    89,
      89,    90,    90,    90,    91,    91,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     2,     1,     1,
       1,     3,     0,     1,     1,     4,     4,     4,     4,     6,
       1,     6,     4,     4,     4,     5,     8,     5,     5,     5,
       5,     5,     2,     1,     3,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     4,     4,     3,     3,     1,     3,
       3,     2,     4,     3,     3,     3,     1,     5,     3,     5,
       7,     7,    11,    11,     1,     1,     0
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

#line 1383 "y.tab.c"

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

#line 193 "temp_yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
