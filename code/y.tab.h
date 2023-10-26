/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CLAIM = 258,
     KW_IS = 259,
     KW_GROUP = 260,
     KW_RING = 261,
     KW_FIELD = 262,
     KW_SPACE = 263,
     KW_PRINT = 264,
     KW_LET = 265,
     KW_RETURN = 266,
     KW_IF = 267,
     KW_ELSE = 268,
     KW_WHILE = 269,
     KW_FOR = 270,
     KW_IN = 271,
     KW_SWITCH = 272,
     KW_CASE = 273,
     KW_DEFAULT = 274,
     KW_BREAK = 275,
     KW_CONTINUE = 276,
     KW_FN = 277,
     KW_MORPH = 278,
     KW_FORGE = 279,
     KW_STRUCT = 280,
     KW_ENUM = 281,
     KW_CYCLIC = 282,
     KW_BIG_RATIONAL = 283,
     KW_COMPLEX = 284,
     KW_SYMMETRIC = 285,
     KW_ALTERNATING = 286,
     KW_DIHEDRAL = 287,
     KW_INV_MAT = 288,
     KW_BIGINT = 289,
     KW_MATRIX = 290,
     KW_POLYNOMIAL = 291,
     KW_VEC = 292,
     KW_BUF = 293,
     IDENT = 294,
     PRIMITIVE_DTYPE = 295,
     LIT_INT = 296,
     LIT_FLOAT = 297,
     LIT_STR = 298,
     LIT_CHAR = 299,
     log_op = 300,
     rel_op = 301,
     KW_TRUE = 302,
     KW_FALSE = 303,
     GROUP = 304,
     RING = 305,
     FIELD = 306,
     SPACE = 307,
     INCR = 308,
     DECR = 309,
     ARROW = 310,
     VARIANT = 311
   };
#endif
/* Tokens.  */
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
#define KW_FN 277
#define KW_MORPH 278
#define KW_FORGE 279
#define KW_STRUCT 280
#define KW_ENUM 281
#define KW_CYCLIC 282
#define KW_BIG_RATIONAL 283
#define KW_COMPLEX 284
#define KW_SYMMETRIC 285
#define KW_ALTERNATING 286
#define KW_DIHEDRAL 287
#define KW_INV_MAT 288
#define KW_BIGINT 289
#define KW_MATRIX 290
#define KW_POLYNOMIAL 291
#define KW_VEC 292
#define KW_BUF 293
#define IDENT 294
#define PRIMITIVE_DTYPE 295
#define LIT_INT 296
#define LIT_FLOAT 297
#define LIT_STR 298
#define LIT_CHAR 299
#define log_op 300
#define rel_op 301
#define KW_TRUE 302
#define KW_FALSE 303
#define GROUP 304
#define RING 305
#define FIELD 306
#define SPACE 307
#define INCR 308
#define DECR 309
#define ARROW 310
#define VARIANT 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

