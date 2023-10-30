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
#line 1 "code/yacc.y"

#include <stdio.h>

int yylex();
void yyerror(const char* s);


#line 79 "code/y.tab.c"

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

#include "y.tab.h"
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
  YYSYMBOL_KW_FN = 22,                     /* KW_FN  */
  YYSYMBOL_KW_MORPH = 23,                  /* KW_MORPH  */
  YYSYMBOL_KW_FORGE = 24,                  /* KW_FORGE  */
  YYSYMBOL_KW_AS = 25,                     /* KW_AS  */
  YYSYMBOL_KW_STRUCT = 26,                 /* KW_STRUCT  */
  YYSYMBOL_KW_ENUM = 27,                   /* KW_ENUM  */
  YYSYMBOL_KW_CYCLIC = 28,                 /* KW_CYCLIC  */
  YYSYMBOL_KW_BIG_RATIONAL = 29,           /* KW_BIG_RATIONAL  */
  YYSYMBOL_KW_COMPLEX = 30,                /* KW_COMPLEX  */
  YYSYMBOL_KW_SYMMETRIC = 31,              /* KW_SYMMETRIC  */
  YYSYMBOL_KW_ALTERNATING = 32,            /* KW_ALTERNATING  */
  YYSYMBOL_KW_DIHEDRAL = 33,               /* KW_DIHEDRAL  */
  YYSYMBOL_KW_INV_MAT = 34,                /* KW_INV_MAT  */
  YYSYMBOL_KW_BIGINT = 35,                 /* KW_BIGINT  */
  YYSYMBOL_KW_MATRIX = 36,                 /* KW_MATRIX  */
  YYSYMBOL_KW_POLYNOMIAL = 37,             /* KW_POLYNOMIAL  */
  YYSYMBOL_KW_VEC = 38,                    /* KW_VEC  */
  YYSYMBOL_KW_BUF = 39,                    /* KW_BUF  */
  YYSYMBOL_IDENT = 40,                     /* IDENT  */
  YYSYMBOL_PRIMITIVE_DTYPE = 41,           /* PRIMITIVE_DTYPE  */
  YYSYMBOL_LIT_INT = 42,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 43,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_STR = 44,                   /* LIT_STR  */
  YYSYMBOL_LIT_CHAR = 45,                  /* LIT_CHAR  */
  YYSYMBOL_rel_op = 46,                    /* rel_op  */
  YYSYMBOL_KW_TRUE = 47,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 48,                  /* KW_FALSE  */
  YYSYMBOL_INCR = 49,                      /* INCR  */
  YYSYMBOL_DECR = 50,                      /* DECR  */
  YYSYMBOL_ARROW = 51,                     /* ARROW  */
  YYSYMBOL_VARIANT = 52,                   /* VARIANT  */
  YYSYMBOL_SLICE = 53,                     /* SLICE  */
  YYSYMBOL_AND = 54,                       /* AND  */
  YYSYMBOL_OR = 55,                        /* OR  */
  YYSYMBOL_56_ = 56,                       /* '!'  */
  YYSYMBOL_57_ = 57,                       /* '@'  */
  YYSYMBOL_58_ = 58,                       /* '*'  */
  YYSYMBOL_59_ = 59,                       /* '/'  */
  YYSYMBOL_60_ = 60,                       /* '%'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '>'  */
  YYSYMBOL_64_ = 64,                       /* '<'  */
  YYSYMBOL_65_ = 65,                       /* '.'  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* '{'  */
  YYSYMBOL_68_ = 68,                       /* '}'  */
  YYSYMBOL_69_ = 69,                       /* '('  */
  YYSYMBOL_70_ = 70,                       /* ')'  */
  YYSYMBOL_71_ = 71,                       /* ','  */
  YYSYMBOL_72_ = 72,                       /* '='  */
  YYSYMBOL_73_ = 73,                       /* '&'  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_75_ = 75,                       /* ']'  */
  YYSYMBOL_76_ = 76,                       /* ':'  */
  YYSYMBOL_77_ = 77,                       /* '~'  */
  YYSYMBOL_YYACCEPT = 78,                  /* $accept  */
  YYSYMBOL_P = 79,                         /* P  */
  YYSYMBOL_declarations = 80,              /* declarations  */
  YYSYMBOL_body = 81,                      /* body  */
  YYSYMBOL_statements = 82,                /* statements  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_field_data_type = 84,           /* field_data_type  */
  YYSYMBOL_group_data_type = 85,           /* group_data_type  */
  YYSYMBOL_ring_data_type = 86,            /* ring_data_type  */
  YYSYMBOL_space_data_type = 87,           /* space_data_type  */
  YYSYMBOL_declaration = 88,               /* declaration  */
  YYSYMBOL_decl_list = 89,                 /* decl_list  */
  YYSYMBOL_decl_item = 90,                 /* decl_item  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_var = 92,                       /* var  */
  YYSYMBOL_assignment = 93,                /* assignment  */
  YYSYMBOL_constant = 94,                  /* constant  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_return_stmt = 96,               /* return_stmt  */
  YYSYMBOL_call = 97,                      /* call  */
  YYSYMBOL_pass_param_list = 98,           /* pass_param_list  */
  YYSYMBOL_unary_operation = 99,           /* unary_operation  */
  YYSYMBOL_array_access = 100,             /* array_access  */
  YYSYMBOL_array_decl = 101,               /* array_decl  */
  YYSYMBOL_array_list = 102,               /* array_list  */
  YYSYMBOL_conditional = 103,              /* conditional  */
  YYSYMBOL_if_body = 104,                  /* if_body  */
  YYSYMBOL_loop_stmt = 105,                /* loop_stmt  */
  YYSYMBOL_loop_mut = 106,                 /* loop_mut  */
  YYSYMBOL_switch_case = 107,              /* switch_case  */
  YYSYMBOL_sc_blocks = 108,                /* sc_blocks  */
  YYSYMBOL_archetype_claim = 109,          /* archetype_claim  */
  YYSYMBOL_additive_rule = 110,            /* additive_rule  */
  YYSYMBOL_mult_rule = 111,                /* mult_rule  */
  YYSYMBOL_identity_rule = 112,            /* identity_rule  */
  YYSYMBOL_negation_rule = 113,            /* negation_rule  */
  YYSYMBOL_inverse_rule = 114,             /* inverse_rule  */
  YYSYMBOL_function = 115,                 /* function  */
  YYSYMBOL_function_header = 116,          /* function_header  */
  YYSYMBOL_function_body = 117,            /* function_body  */
  YYSYMBOL_parameter_list = 118,           /* parameter_list  */
  YYSYMBOL_typ_var = 119,                  /* typ_var  */
  YYSYMBOL_struct = 120,                   /* struct  */
  YYSYMBOL_attr_list = 121,                /* attr_list  */
  YYSYMBOL_enum = 122,                     /* enum  */
  YYSYMBOL_variant_list = 123,             /* variant_list  */
  YYSYMBOL_forge = 124,                    /* forge  */
  YYSYMBOL_cart = 125,                     /* cart  */
  YYSYMBOL_typ_list = 126,                 /* typ_list  */
  YYSYMBOL_epsilon = 127                   /* epsilon  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  368

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
       2,     2,     2,    56,     2,     2,     2,    60,    73,     2,
      69,    70,    58,    61,    71,    62,    65,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    66,
      64,    72,    63,     2,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    68,    77,     2,     2,     2,
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
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    32,    32,    33,    34,    35,    36,    39,    40,    43,
      46,    47,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    63,    64,    67,    68,    69,    70,    71,
      74,    75,    76,    79,    82,    85,    86,    89,    90,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   104,   105,
     106,   107,   108,   111,   112,   115,   116,   117,   118,   119,
     120,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   138,   138,   138,
     138,   139,   142,   145,   148,   149,   152,   153,   156,   159,
     160,   163,   164,   167,   170,   171,   172,   175,   176,   177,
     178,   181,   182,   185,   186,   189,   190,   191,   192,   195,
     196,   197,   198,   201,   204,   207,   210,   213,   216,   219,
     222,   225,   226,   229,   232,   234,   235,   237,   239,   240,
     242,   244,   246,   247,   249
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
  "KW_SWITCH", "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_CONTINUE", "KW_FN",
  "KW_MORPH", "KW_FORGE", "KW_AS", "KW_STRUCT", "KW_ENUM", "KW_CYCLIC",
  "KW_BIG_RATIONAL", "KW_COMPLEX", "KW_SYMMETRIC", "KW_ALTERNATING",
  "KW_DIHEDRAL", "KW_INV_MAT", "KW_BIGINT", "KW_MATRIX", "KW_POLYNOMIAL",
  "KW_VEC", "KW_BUF", "IDENT", "PRIMITIVE_DTYPE", "LIT_INT", "LIT_FLOAT",
  "LIT_STR", "LIT_CHAR", "rel_op", "KW_TRUE", "KW_FALSE", "INCR", "DECR",
  "ARROW", "VARIANT", "SLICE", "AND", "OR", "'!'", "'@'", "'*'", "'/'",
  "'%'", "'+'", "'-'", "'>'", "'<'", "'.'", "';'", "'{'", "'}'", "'('",
  "')'", "','", "'='", "'&'", "'['", "']'", "':'", "'~'", "$accept", "P",
  "declarations", "body", "statements", "statement", "field_data_type",
  "group_data_type", "ring_data_type", "space_data_type", "declaration",
  "decl_list", "decl_item", "type", "var", "assignment", "constant",
  "expression", "return_stmt", "call", "pass_param_list",
  "unary_operation", "array_access", "array_decl", "array_list",
  "conditional", "if_body", "loop_stmt", "loop_mut", "switch_case",
  "sc_blocks", "archetype_claim", "additive_rule", "mult_rule",
  "identity_rule", "negation_rule", "inverse_rule", "function",
  "function_header", "function_body", "parameter_list", "typ_var",
  "struct", "attr_list", "enum", "variant_list", "forge", "cart",
  "typ_list", "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-270)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -26,   129,  -270,   -39,  -270,   -57,  -270,   -25,    21,
    -270,    19,   265,    55,    69,  -270,    48,  -270,  -270,  -270,
      -3,   265,   -26,   435,    56,    53,  -270,  -270,    66,    86,
      88,    95,  -270,    97,   101,   103,   115,  -270,  -270,   265,
     265,  -270,  -270,  -270,  -270,    58,  -270,    90,   113,    30,
    -270,  -270,  -270,   -17,  -270,  -270,  -270,  -270,  -270,  -270,
     435,   -15,   435,   435,   435,    17,  -270,   410,  -270,  -270,
    -270,  -270,   -26,   141,   142,   145,   146,   162,   167,   265,
     265,   170,  -270,    50,  -270,   -26,   173,   175,   176,   148,
     435,   150,   158,   -11,   159,   163,   164,  -270,    30,   179,
      22,   181,   182,   183,   161,  -270,  -270,  -270,  -270,   168,
    -270,   206,   435,   410,   199,   435,   187,   410,   180,   -47,
     390,   178,  -270,  -270,   216,  -270,   265,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,    63,  -270,
     194,   196,   197,   198,   191,   192,   201,   202,   204,  -270,
     265,   -33,   -57,   207,   190,  -270,    -8,   279,   435,   410,
     435,   435,   268,    16,   435,  -270,  -270,  -270,  -270,   435,
    -270,  -270,  -270,   435,  -270,  -270,    43,   215,  -270,   261,
    -270,    36,   435,  -270,  -270,  -270,    93,   232,  -270,   452,
     471,   471,   471,   108,   108,    93,    93,   212,   -26,  -270,
    -270,  -270,  -270,   265,   265,  -270,  -270,  -270,  -270,    30,
     249,  -270,  -270,   250,   195,   221,   286,   305,   269,   242,
     244,   327,   410,   410,   435,  -270,  -270,   241,  -270,   135,
     265,  -270,   251,   254,   245,  -270,  -270,   259,   266,   270,
     272,   276,   287,   287,   287,   435,   435,   288,  -270,  -270,
    -270,  -270,  -270,  -270,   267,   284,   289,   328,  -270,    30,
     344,  -270,  -270,  -270,   346,   368,   343,   330,   303,   334,
     303,   336,   309,   306,   311,    -2,   -28,   -28,    68,   -13,
    -270,   308,   354,   314,   323,   331,   324,   332,   333,  -270,
    -270,  -270,    27,  -270,   341,  -270,   347,   337,   340,   342,
     345,  -270,   379,   348,   384,   365,   397,   372,   362,  -270,
     265,   287,   287,    30,    30,    30,    30,   380,   398,   370,
     389,   388,  -270,   417,   391,  -270,  -270,   343,   343,   343,
     392,   418,   393,   400,  -270,   419,   396,   415,  -270,  -270,
    -270,  -270,   406,   433,   445,   416,   436,   267,   437,   287,
     420,   438,   287,   314,   287,  -270,   441,   287,  -270,   303,
    -270,   287,  -270,   284,  -270,   426,   429,  -270
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     134,     0,     0,     2,     0,     8,     0,    34,    35,    37,
       1,     0,     0,     0,     0,     3,     0,     4,     6,     5,
     134,     0,     0,     0,     0,     0,    23,    24,     0,     0,
       0,     0,    30,     0,     0,     0,     0,    41,    39,     0,
       0,    44,    42,    43,    45,     0,    47,     0,     0,   134,
       7,   123,    36,    48,    57,    56,    58,    55,    59,    60,
       0,     0,     0,     0,     0,    76,    77,    38,    80,    78,
      79,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   134,     0,
       0,     0,     0,     0,     0,    16,    18,    17,    22,     0,
      11,     0,   134,    62,    48,     0,    50,    63,     0,    77,
       0,     0,    86,    87,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,   125,     0,     0,   128,     0,     0,   134,    82,
       0,     0,     0,     0,     0,    20,    21,    10,    12,     0,
      13,    15,    14,     0,   118,    52,     0,     0,    85,     0,
      61,     0,     0,    89,    49,    64,    73,    74,    75,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    25,
      26,    27,    28,     0,     0,    32,    33,    40,   132,   134,
       0,   124,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,   134,    83,    51,    92,    91,     0,
       0,   122,     0,     0,     0,   126,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    90,
     119,    29,    31,   130,     0,     0,     0,     0,    19,   134,
      94,    93,    97,   100,     0,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   134,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      96,    95,     0,   101,     0,   102,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,   111,
       0,     0,     0,   134,   134,   134,   134,     0,     0,     0,
       0,     0,   110,     0,     0,    99,    98,   134,   134,   134,
       0,     0,     0,     0,   109,     0,     0,     0,   106,   107,
     105,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,     0,   117,     0,
     113,     0,   114,     0,   116,     0,     0,   112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,   476,  -226,   -93,  -270,  -270,  -270,  -270,  -270,
      11,   477,  -270,   -18,   -45,   338,   -62,     9,  -270,   -34,
    -149,  -100,   -41,   -52,   319,   227,  -270,  -270,   226,  -270,
    -121,  -270,   171,   156,  -269,   152,  -270,  -270,  -270,  -270,
     423,   -49,  -270,  -270,  -270,  -270,  -270,  -270,  -270,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   260,    97,    98,    41,    42,    43,    44,
      99,     7,     8,    45,    65,   101,    66,   176,   102,    68,
     177,    69,    70,    71,   121,   105,   261,   106,   294,   107,
     279,   108,   268,   270,   283,   305,   272,    15,    16,   109,
     138,     9,    17,   154,    18,   156,    19,    46,    83,   110
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   285,   119,    51,   100,   167,   300,     1,   104,   215,
      91,     4,   114,   125,     6,   103,   116,   262,   263,    21,
       5,    82,    84,   139,   181,   114,     1,    20,   -92,   162,
      61,     4,    67,    88,   209,   111,   139,   153,   198,    89,
       1,    90,    91,    61,    92,    93,    22,    94,   125,   290,
      95,    96,   112,   100,   115,   301,   114,   104,   163,    24,
     212,   146,   147,   213,   103,   259,   122,   123,   126,   113,
      53,   117,   118,   120,    61,   248,   122,   123,    54,    55,
      56,    57,   124,    58,    59,   325,   326,   124,    61,   127,
     363,    64,   124,    23,   169,    47,    64,   128,   129,   159,
     130,   131,   132,   133,   134,   135,   136,   137,   185,    48,
     297,   298,   178,   299,   224,    49,   234,    73,   100,   227,
     149,   150,   104,   355,   179,    72,   358,    85,   360,    10,
      74,   362,   208,   197,   198,   364,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   128,   129,   231,
      75,    11,    76,    12,   127,    13,    14,    86,   178,    77,
     126,    78,   128,   129,   100,    79,   274,    80,   104,   216,
     217,   136,   137,   221,   219,   103,   293,   293,   222,    81,
      87,   127,   223,   140,   141,   232,   233,   142,   143,   128,
     129,   229,   130,   131,   132,   133,   134,   135,   136,   137,
     237,   238,   239,   240,   144,   126,   338,   339,   340,   145,
     249,   148,   250,   152,   100,   155,   157,   158,   104,   160,
     327,   328,   329,   330,   178,   103,   127,   161,   164,   165,
     166,   292,   292,   173,   128,   129,   174,   130,   131,   132,
     133,   134,   135,   136,   137,   168,   175,   170,   171,   172,
     180,   111,   124,   183,   264,   265,   184,   199,   211,   200,
     201,   202,   203,   204,   205,   206,   280,   207,   100,   100,
     100,   100,   104,   104,   104,   104,   295,   295,   210,   103,
     103,   103,   103,   214,   218,   225,   126,   129,   230,   235,
     236,   241,   324,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   127,   245,   244,
     246,   126,   181,   253,   251,   128,   129,   252,   130,   131,
     132,   133,   134,   135,   136,   137,   254,   280,   280,   280,
     126,   226,   127,   255,    39,   273,   267,   256,    40,   257,
     128,   129,   258,   130,   131,   132,   133,   134,   135,   136,
     137,   127,   126,   269,   259,   266,   242,   275,   271,   128,
     129,   278,   130,   131,   132,   133,   134,   135,   136,   137,
     281,   126,   282,   127,   284,   243,   286,   287,   288,   289,
     302,   128,   129,   304,   130,   131,   132,   133,   134,   135,
     136,   137,   127,   126,   303,   306,   308,   247,   309,   307,
     128,   129,   310,   130,   131,   132,   133,   134,   135,   136,
     137,   311,   276,   313,   127,   126,   314,   312,   315,   317,
     318,   316,   128,   129,   319,   130,   131,   132,   133,   134,
     135,   136,   137,   320,   277,   126,   127,   321,   322,   323,
     332,   331,   333,   182,   128,   129,   335,   130,   131,   132,
     133,   134,   135,   136,   137,   334,   127,   336,   342,   345,
     341,   337,   344,   343,   128,   129,   346,   130,   131,   132,
     133,   134,   135,   136,   137,    53,   348,    54,    55,    56,
      57,   347,    58,    59,   349,   350,   351,   352,   354,   357,
     356,    60,   361,    61,   366,   367,    50,    62,   127,    52,
     228,   220,   291,   296,    63,   359,   128,   129,   151,    64,
     131,   132,   133,   134,   135,   136,   137,   127,   353,   365,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,     0,   134,   135,   136,   137
};

static const yytype_int16 yycheck[] =
{
       0,   270,    64,    21,    49,    98,    19,    10,    49,   158,
      12,     0,    40,    65,    40,    49,    61,   243,   244,    76,
      20,    39,    40,    72,    71,    40,    10,    66,    75,    40,
      58,    20,    23,     3,    67,    52,    85,    86,    71,     9,
      10,    11,    12,    58,    14,    15,    71,    17,   100,   275,
      20,    21,    69,    98,    69,    68,    40,    98,    69,    40,
      68,    79,    80,    71,    98,    67,    49,    50,    25,    60,
      40,    62,    63,    64,    58,   224,    49,    50,    42,    43,
      44,    45,    65,    47,    48,   311,   312,    65,    58,    46,
     359,    74,    65,    72,    72,    40,    74,    54,    55,    90,
      57,    58,    59,    60,    61,    62,    63,    64,   126,    40,
      42,    43,   112,    45,    71,    67,   209,    64,   163,   181,
      70,    71,   163,   349,   115,    69,   352,    69,   354,     0,
      64,   357,   150,    70,    71,   361,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,    54,    55,   198,
      64,    22,    64,    24,    46,    26,    27,    67,   158,    64,
      25,    64,    54,    55,   209,    64,   259,    64,   209,   160,
     161,    63,    64,   164,   163,   209,   276,   277,   169,    64,
      67,    46,   173,    42,    42,   203,   204,    42,    42,    54,
      55,   182,    57,    58,    59,    60,    61,    62,    63,    64,
       5,     6,     7,     8,    42,    25,   327,   328,   329,    42,
      75,    41,   230,    40,   259,    40,    40,    69,   259,    69,
     313,   314,   315,   316,   224,   259,    46,    69,    69,    66,
      66,   276,   277,    72,    54,    55,    68,    57,    58,    59,
      60,    61,    62,    63,    64,    66,    40,    66,    66,    66,
      70,    52,    65,    75,   245,   246,    40,    63,    68,    63,
      63,    63,    71,    71,    63,    63,   266,    63,   313,   314,
     315,   316,   313,   314,   315,   316,   276,   277,    71,   313,
     314,   315,   316,     4,    16,    70,    25,    55,    76,    40,
      40,    70,   310,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    46,    66,    40,
      66,    25,    71,    68,    63,    54,    55,    63,    57,    58,
      59,    60,    61,    62,    63,    64,    67,   327,   328,   329,
      25,    70,    46,    67,    69,     7,    69,    67,    73,    67,
      54,    55,    66,    57,    58,    59,    60,    61,    62,    63,
      64,    46,    25,    69,    67,    67,    70,    13,    69,    54,
      55,    18,    57,    58,    59,    60,    61,    62,    63,    64,
      40,    25,    69,    46,    40,    70,    40,    68,    72,    68,
      72,    54,    55,    69,    57,    58,    59,    60,    61,    62,
      63,    64,    46,    25,    40,    72,    72,    70,    66,    68,
      54,    55,    69,    57,    58,    59,    60,    61,    62,    63,
      64,    70,    66,    76,    46,    25,    76,    70,    76,    40,
      72,    76,    54,    55,    40,    57,    58,    59,    60,    61,
      62,    63,    64,    68,    66,    25,    46,    40,    66,    77,
      42,    61,    72,    53,    54,    55,    58,    57,    58,    59,
      60,    61,    62,    63,    64,    66,    46,    40,    40,    40,
      68,    70,    62,    70,    54,    55,    70,    57,    58,    59,
      60,    61,    62,    63,    64,    40,    70,    42,    43,    44,
      45,    66,    47,    48,    51,    40,    70,    51,    51,    51,
      70,    56,    51,    58,    68,    66,    20,    62,    46,    22,
     181,   163,   275,   277,    69,   353,    54,    55,    85,    74,
      58,    59,    60,    61,    62,    63,    64,    46,   347,   363,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    79,    80,    88,   127,    40,    89,    90,   119,
       0,    22,    24,    26,    27,   115,   116,   120,   122,   124,
      66,    76,    71,    72,    40,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    69,
      73,    84,    85,    86,    87,    91,   125,    40,    40,    67,
      80,    91,    89,    40,    42,    43,    44,    45,    47,    48,
      56,    58,    62,    69,    74,    92,    94,    95,    97,    99,
     100,   101,    69,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    91,   126,    91,    69,    67,    67,     3,     9,
      11,    12,    14,    15,    17,    20,    21,    82,    83,    88,
      92,    93,    96,    97,   100,   103,   105,   107,   109,   117,
     127,    52,    69,    95,    40,    69,    92,    95,    95,    94,
      95,   102,    49,    50,    65,   101,    25,    46,    54,    55,
      57,    58,    59,    60,    61,    62,    63,    64,   118,   119,
      42,    42,    42,    42,    42,    42,    91,    91,    41,    70,
      71,   118,    40,   119,   121,    40,   123,    40,    69,    95,
      69,    69,    40,    69,    69,    66,    66,    82,    66,    72,
      66,    66,    66,    72,    68,    40,    95,    98,   127,    95,
      70,    71,    53,    75,    40,    91,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    70,    71,    63,
      63,    63,    63,    71,    71,    63,    63,    63,    91,    67,
      71,    68,    68,    71,     4,    98,    95,    95,    16,    88,
      93,    95,    95,    95,    71,    70,    70,    94,   102,    95,
      76,   119,    91,    91,    82,    40,    40,     5,     6,     7,
       8,    70,    70,    70,    40,    66,    66,    70,    98,    75,
      91,    63,    63,    68,    67,    67,    67,    67,    66,    67,
      81,   104,    81,    81,    95,    95,    67,    69,   110,    69,
     111,    69,   114,     7,    82,    13,    66,    66,    18,   108,
     127,    40,    69,   112,    40,   112,    40,    68,    72,    68,
      81,   103,    92,    99,   106,   127,   106,    42,    43,    45,
      19,    68,    72,    40,    69,   113,    72,    68,    72,    66,
      69,    70,    70,    76,    76,    76,    76,    40,    72,    40,
      68,    40,    66,    77,    91,    81,    81,    82,    82,    82,
      82,    61,    42,    72,    66,    58,    40,    70,   108,   108,
     108,    68,    40,    70,    62,    40,    70,    66,    70,    51,
      40,    70,    51,   110,    51,    81,    70,    51,    81,   113,
      81,    51,    81,   112,    81,   111,    68,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    78,    79,    79,    79,    79,    79,    80,    80,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      86,    86,    86,    87,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    97,    98,    98,    99,    99,   100,   101,
     101,   102,   102,   103,   104,   104,   104,   105,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   108,   108,   109,
     109,   109,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   118,   119,   120,   121,   121,   122,   123,   123,
     124,   125,   126,   126,   127
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     3,     1,     3,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     5,
       2,     2,     1,     1,     1,     4,     4,     4,     4,     6,
       1,     6,     4,     4,     2,     1,     3,     1,     3,     1,
       4,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       2,     4,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     2,     4,     3,     1,     2,     2,     2,     3,
       5,     3,     1,     5,     1,     3,     3,     5,     9,     9,
       5,     1,     1,    10,     7,     5,     5,     5,     1,    10,
       9,     8,    17,     9,     9,     7,     8,     8,     4,     7,
       1,     1,     3,     3,     5,     1,     3,     5,     1,     3,
       7,     3,     3,     1,     0
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
  case 109: /* archetype_claim: KW_CLAIM IDENT KW_IS KW_GROUP '{' additive_rule identity_rule negation_rule '}' ';'  */
#line 195 "code/yacc.y"
                                                                                                      {printf("Group claim rule\n");}
#line 1467 "code/y.tab.c"
    break;

  case 113: /* additive_rule: '(' IDENT '=' IDENT '+' IDENT ')' ARROW body  */
#line 201 "code/yacc.y"
                                                               {printf("Group_closure_rule\n");}
#line 1473 "code/y.tab.c"
    break;


#line 1477 "code/y.tab.c"

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

#line 251 "code/yacc.y"


int main() {
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
