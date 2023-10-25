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
    KW_CYCLIC = 259,               /* KW_CYCLIC  */
    KW_BIG_RATIONAL = 260,         /* KW_BIG_RATIONAL  */
    KW_COMPLEX = 261,              /* KW_COMPLEX  */
    KW_SYMMETRIC = 262,            /* KW_SYMMETRIC  */
    KW_ALTERNATING = 263,          /* KW_ALTERNATING  */
    KW_DIHEDRAL = 264,             /* KW_DIHEDRAL  */
    KW_INV_MAT = 265,              /* KW_INV_MAT  */
    KW_BIGINT = 266,               /* KW_BIGINT  */
    KW_MATRIX = 267,               /* KW_MATRIX  */
    KW_POLYNOMIAL = 268,           /* KW_POLYNOMIAL  */
    KW_VEC = 269,                  /* KW_VEC  */
    KW_BUF = 270,                  /* KW_BUF  */
    IDENT = 271,                   /* IDENT  */
    PRIMITIVE_DTYPE = 272,         /* PRIMITIVE_DTYPE  */
    LIT_INT = 273,                 /* LIT_INT  */
    LIT_FLOAT = 274,               /* LIT_FLOAT  */
    LIT_STR = 275,                 /* LIT_STR  */
    LIT_CHAR = 276                 /* LIT_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_LET 258
#define KW_CYCLIC 259
#define KW_BIG_RATIONAL 260
#define KW_COMPLEX 261
#define KW_SYMMETRIC 262
#define KW_ALTERNATING 263
#define KW_DIHEDRAL 264
#define KW_INV_MAT 265
#define KW_BIGINT 266
#define KW_MATRIX 267
#define KW_POLYNOMIAL 268
#define KW_VEC 269
#define KW_BUF 270
#define IDENT 271
#define PRIMITIVE_DTYPE 272
#define LIT_INT 273
#define LIT_FLOAT 274
#define LIT_STR 275
#define LIT_CHAR 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
