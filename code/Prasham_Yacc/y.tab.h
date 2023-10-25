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
    KW_CYCLIC = 260,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 261,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 262,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 263,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 264,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 265,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 266,              /* KW_INV_MAT  */
    KW_BIGINT = 267,               /* KW_BIGINT  */
    KW_MATRIX = 268,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 269,           /* KW_POLYNOMIAL  */
    KW_VEC = 270,                  /* KW_VEC  */
    KW_BUF = 271,                  /* KW_BUF  */
    IDENT = 272,                   /* IDENT  */
    PRIMITIVE_DTYPE = 273,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 274,                 /* LIT_INT  */
    LIT_FLOAT = 275,               /* LIT_FLOAT  */
    LIT_STR = 276,                 /* LIT_STR  */
    LIT_CHAR = 277,                /* LIT_CHAR  */
    LOGICAL_AND = 278,             /* LOGICAL_AND  */
    LOGICAL_OR = 279,              /* LOGICAL_OR  */
    LOGICAL_NOT = 280,             /* LOGICAL_NOT  */
    EQ = 281,                      /* EQ  */
    NEQ = 282,                     /* NEQ  */
    GT = 283,                      /* GT  */
    LT = 284,                      /* LT  */
    GTEQ = 285,                    /* GTEQ  */
    LTEQ = 286,                    /* LTEQ  */
    KW_TRUE = 287,                 /* KW_TRUE  */
    KW_FALSE = 288                 /* KW_FALSE  */
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
#define KW_CYCLIC 260
#define KW_BIG_RATIONAL 261
#define KW_COMPLEX 262
#define KW_SYMMETRIC 263
#define KW_ALTERNATING 264
#define KW_DIHEDRAL 265
#define KW_INV_MAT 266
#define KW_BIGINT 267
#define KW_MATRIX 268
#define KW_POLYNOMIAL 269
#define KW_VEC 270
#define KW_BUF 271
#define IDENT 272
#define PRIMITIVE_DTYPE 273
#define LIT_INT 274
#define LIT_FLOAT 275
#define LIT_STR 276
#define LIT_CHAR 277
#define LOGICAL_AND 278
#define LOGICAL_OR 279
#define LOGICAL_NOT 280
#define EQ 281
#define NEQ 282
#define GT 283
#define LT 284
#define GTEQ 285
#define LTEQ 286
#define KW_TRUE 287
#define KW_FALSE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
