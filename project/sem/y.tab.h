/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
    T_NUM = 258,                   /* T_NUM  */
    T_DIMS = 259,                  /* T_DIMS  */
    T_REAL = 260,                  /* T_REAL  */
    T_ID = 261,                    /* T_ID  */
    T_FLOAT = 262,                 /* T_FLOAT  */
    T_INT = 263,                   /* T_INT  */
    T_IMPORT = 264,                /* T_IMPORT  */
    T_DOUBLE = 265,                /* T_DOUBLE  */
    T_BOOLEAN = 266,               /* T_BOOLEAN  */
    T_STRING = 267,                /* T_STRING  */
    T_CHAR = 268,                  /* T_CHAR  */
    T_IF = 269,                    /* T_IF  */
    T_ELSE = 270,                  /* T_ELSE  */
    T_DO = 271,                    /* T_DO  */
    T_WHILE = 272,                 /* T_WHILE  */
    T_RETURN = 273,                /* T_RETURN  */
    T_PACKAGE = 274,               /* T_PACKAGE  */
    T_CLASS = 275,                 /* T_CLASS  */
    T_PUBLIC = 276,                /* T_PUBLIC  */
    T_PRIVATE = 277,               /* T_PRIVATE  */
    T_PROTECTED = 278,             /* T_PROTECTED  */
    T_STATIC = 279,                /* T_STATIC  */
    T_VOID = 280,                  /* T_VOID  */
    T_MAIN = 281,                  /* T_MAIN  */
    T_CONST = 282,                 /* T_CONST  */
    T_TRUE = 283,                  /* T_TRUE  */
    T_FALSE = 284,                 /* T_FALSE  */
    T_NULL = 285,                  /* T_NULL  */
    T_BREAK = 286,                 /* T_BREAK  */
    T_CONTINUE = 287,              /* T_CONTINUE  */
    T_PRINTLN = 288,               /* T_PRINTLN  */
    T_PRINT = 289,                 /* T_PRINT  */
    T_EXIT = 290,                  /* T_EXIT  */
    T_PE = 291,                    /* T_PE  */
    T_ME = 292,                    /* T_ME  */
    T_DE = 293,                    /* T_DE  */
    T_MULE = 294,                  /* T_MULE  */
    T_PERCE = 295,                 /* T_PERCE  */
    T_AND = 296,                   /* T_AND  */
    T_OR = 297,                    /* T_OR  */
    T_NE = 298,                    /* T_NE  */
    T_GTE = 299,                   /* T_GTE  */
    T_LTE = 300,                   /* T_LTE  */
    T_EE = 301,                    /* T_EE  */
    T_NEW = 302,                   /* T_NEW  */
    T_PID = 303,                   /* T_PID  */
    T_FINAL = 304,                 /* T_FINAL  */
    T_STR = 305,                   /* T_STR  */
    T_PLUS = 306,                  /* T_PLUS  */
    T_LESS = 307,                  /* T_LESS  */
    T_GREATER = 308                /* T_GREATER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_NUM 258
#define T_DIMS 259
#define T_REAL 260
#define T_ID 261
#define T_FLOAT 262
#define T_INT 263
#define T_IMPORT 264
#define T_DOUBLE 265
#define T_BOOLEAN 266
#define T_STRING 267
#define T_CHAR 268
#define T_IF 269
#define T_ELSE 270
#define T_DO 271
#define T_WHILE 272
#define T_RETURN 273
#define T_PACKAGE 274
#define T_CLASS 275
#define T_PUBLIC 276
#define T_PRIVATE 277
#define T_PROTECTED 278
#define T_STATIC 279
#define T_VOID 280
#define T_MAIN 281
#define T_CONST 282
#define T_TRUE 283
#define T_FALSE 284
#define T_NULL 285
#define T_BREAK 286
#define T_CONTINUE 287
#define T_PRINTLN 288
#define T_PRINT 289
#define T_EXIT 290
#define T_PE 291
#define T_ME 292
#define T_DE 293
#define T_MULE 294
#define T_PERCE 295
#define T_AND 296
#define T_OR 297
#define T_NE 298
#define T_GTE 299
#define T_LTE 300
#define T_EE 301
#define T_NEW 302
#define T_PID 303
#define T_FINAL 304
#define T_STR 305
#define T_PLUS 306
#define T_LESS 307
#define T_GREATER 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
