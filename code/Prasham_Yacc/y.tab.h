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
