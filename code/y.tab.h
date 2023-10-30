/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CODE_Y_TAB_H_INCLUDED
# define YY_YY_CODE_Y_TAB_H_INCLUDED
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
    KW_FN = 277,                   /* KW_FN  */
    KW_MORPH = 278,                /* KW_MORPH  */
    KW_FORGE = 279,                /* KW_FORGE  */
    KW_AS = 280,                   /* KW_AS  */
    KW_STRUCT = 281,               /* KW_STRUCT  */
    KW_ENUM = 282,                 /* KW_ENUM  */
    KW_CYCLIC = 283,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 284,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 285,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 286,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 287,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 288,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 289,              /* KW_INV_MAT  */
    KW_BIGINT = 290,               /* KW_BIGINT  */
    KW_MATRIX = 291,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 292,           /* KW_POLYNOMIAL  */
    KW_VEC = 293,                  /* KW_VEC  */
    KW_BUF = 294,                  /* KW_BUF  */
    IDENT = 295,                   /* IDENT  */
    PRIMITIVE_DTYPE = 296,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 297,                 /* LIT_INT  */
    LIT_FLOAT = 298,               /* LIT_FLOAT  */
    LIT_STR = 299,                 /* LIT_STR  */
    LIT_CHAR = 300,                /* LIT_CHAR  */
    rel_op = 301,                  /* rel_op  */
    KW_TRUE = 302,                 /* KW_TRUE  */
    KW_FALSE = 303,                /* KW_FALSE  */
    INCR = 304,                    /* INCR  */
    DECR = 305,                    /* DECR  */
    ARROW = 306,                   /* ARROW  */
    VARIANT = 307,                 /* VARIANT  */
    SLICE = 308,                   /* SLICE  */
    AND = 309,                     /* AND  */
    OR = 310                       /* OR  */
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


#endif /* !YY_YY_CODE_Y_TAB_H_INCLUDED  */
