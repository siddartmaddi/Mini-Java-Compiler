/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sem.y"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"header.c"
#include<string.h>
#define YYSTYPE YACC



extern int yylineno;
extern FILE *yyin;
int yylex();
void yyerror(char *s);

int index_a;
int* current_scope;
char* return_string();
int num_extract(char *s);


struct node
{
   char type[10];
   char value[20];
   char name[33];
   char scope[10];
   struct node *next;
};

struct hash
{
  struct node *head;
  int count;
};



struct hash *ht;
int size = 10;

void display(struct hash *);
void insert(struct hash *ht, int key, char* scope, char* name, char* type,char* val);
int search(struct hash *ht,int key, char* scope, char* name);
struct node* get_node(struct hash *ht,int key, char* scope, char* name);
FILE *t;

#line 119 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_NUM = 3,                      /* T_NUM  */
  YYSYMBOL_T_DIMS = 4,                     /* T_DIMS  */
  YYSYMBOL_T_REAL = 5,                     /* T_REAL  */
  YYSYMBOL_T_ID = 6,                       /* T_ID  */
  YYSYMBOL_T_FLOAT = 7,                    /* T_FLOAT  */
  YYSYMBOL_T_INT = 8,                      /* T_INT  */
  YYSYMBOL_T_IMPORT = 9,                   /* T_IMPORT  */
  YYSYMBOL_T_DOUBLE = 10,                  /* T_DOUBLE  */
  YYSYMBOL_T_BOOLEAN = 11,                 /* T_BOOLEAN  */
  YYSYMBOL_T_STRING = 12,                  /* T_STRING  */
  YYSYMBOL_T_CHAR = 13,                    /* T_CHAR  */
  YYSYMBOL_T_IF = 14,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 15,                    /* T_ELSE  */
  YYSYMBOL_T_DO = 16,                      /* T_DO  */
  YYSYMBOL_T_WHILE = 17,                   /* T_WHILE  */
  YYSYMBOL_T_RETURN = 18,                  /* T_RETURN  */
  YYSYMBOL_T_PACKAGE = 19,                 /* T_PACKAGE  */
  YYSYMBOL_T_CLASS = 20,                   /* T_CLASS  */
  YYSYMBOL_T_PUBLIC = 21,                  /* T_PUBLIC  */
  YYSYMBOL_T_PRIVATE = 22,                 /* T_PRIVATE  */
  YYSYMBOL_T_PROTECTED = 23,               /* T_PROTECTED  */
  YYSYMBOL_T_STATIC = 24,                  /* T_STATIC  */
  YYSYMBOL_T_VOID = 25,                    /* T_VOID  */
  YYSYMBOL_T_MAIN = 26,                    /* T_MAIN  */
  YYSYMBOL_T_CONST = 27,                   /* T_CONST  */
  YYSYMBOL_T_TRUE = 28,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 29,                   /* T_FALSE  */
  YYSYMBOL_T_NULL = 30,                    /* T_NULL  */
  YYSYMBOL_T_BREAK = 31,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 32,                /* T_CONTINUE  */
  YYSYMBOL_T_PRINTLN = 33,                 /* T_PRINTLN  */
  YYSYMBOL_T_PRINT = 34,                   /* T_PRINT  */
  YYSYMBOL_T_EXIT = 35,                    /* T_EXIT  */
  YYSYMBOL_T_PE = 36,                      /* T_PE  */
  YYSYMBOL_T_ME = 37,                      /* T_ME  */
  YYSYMBOL_T_DE = 38,                      /* T_DE  */
  YYSYMBOL_T_MULE = 39,                    /* T_MULE  */
  YYSYMBOL_T_PERCE = 40,                   /* T_PERCE  */
  YYSYMBOL_T_AND = 41,                     /* T_AND  */
  YYSYMBOL_T_OR = 42,                      /* T_OR  */
  YYSYMBOL_T_NE = 43,                      /* T_NE  */
  YYSYMBOL_T_GTE = 44,                     /* T_GTE  */
  YYSYMBOL_T_LTE = 45,                     /* T_LTE  */
  YYSYMBOL_T_EE = 46,                      /* T_EE  */
  YYSYMBOL_T_NEW = 47,                     /* T_NEW  */
  YYSYMBOL_T_PID = 48,                     /* T_PID  */
  YYSYMBOL_T_FINAL = 49,                   /* T_FINAL  */
  YYSYMBOL_T_STR = 50,                     /* T_STR  */
  YYSYMBOL_T_PLUS = 51,                    /* T_PLUS  */
  YYSYMBOL_T_LESS = 52,                    /* T_LESS  */
  YYSYMBOL_T_GREATER = 53,                 /* T_GREATER  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_60_ = 60,                       /* '+'  */
  YYSYMBOL_61_ = 61,                       /* '='  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_Prog = 67,                      /* Prog  */
  YYSYMBOL_Package = 68,                   /* Package  */
  YYSYMBOL_Import = 69,                    /* Import  */
  YYSYMBOL_Modifier = 70,                  /* Modifier  */
  YYSYMBOL_Modifier1 = 71,                 /* Modifier1  */
  YYSYMBOL_Modifier2 = 72,                 /* Modifier2  */
  YYSYMBOL_Classes = 73,                   /* Classes  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_ClassBody = 75,                 /* ClassBody  */
  YYSYMBOL_GlobalVar = 76,                 /* GlobalVar  */
  YYSYMBOL_MethodDec = 77,                 /* MethodDec  */
  YYSYMBOL_78_2 = 78,                      /* $@2  */
  YYSYMBOL_79_3 = 79,                      /* $@3  */
  YYSYMBOL_80_4 = 80,                      /* $@4  */
  YYSYMBOL_ParameterList = 81,             /* ParameterList  */
  YYSYMBOL_Statements = 82,                /* Statements  */
  YYSYMBOL_Statement = 83,                 /* Statement  */
  YYSYMBOL_PrintBlock = 84,                /* PrintBlock  */
  YYSYMBOL_Declr = 85,                     /* Declr  */
  YYSYMBOL_Type = 86,                      /* Type  */
  YYSYMBOL_ListVar = 87,                   /* ListVar  */
  YYSYMBOL_X = 88,                         /* X  */
  YYSYMBOL_Assign = 89,                    /* Assign  */
  YYSYMBOL_90_5 = 90,                      /* @5  */
  YYSYMBOL_OtherAssign = 91,               /* OtherAssign  */
  YYSYMBOL_String = 92,                    /* String  */
  YYSYMBOL_Cond = 93,                      /* Cond  */
  YYSYMBOL_Exp = 94,                       /* Exp  */
  YYSYMBOL_LogExp = 95,                    /* LogExp  */
  YYSYMBOL_Logop = 96,                     /* Logop  */
  YYSYMBOL_EqExp0 = 97,                    /* EqExp0  */
  YYSYMBOL_RelG = 98,                      /* RelG  */
  YYSYMBOL_Eqop = 99,                      /* Eqop  */
  YYSYMBOL_RelExp = 100,                   /* RelExp  */
  YYSYMBOL_Relop = 101,                    /* Relop  */
  YYSYMBOL_ArithExp = 102,                 /* ArithExp  */
  YYSYMBOL_T = 103,                        /* T  */
  YYSYMBOL_G = 104,                        /* G  */
  YYSYMBOL_print_pid = 105,                /* print_pid  */
  YYSYMBOL_print_id = 106,                 /* print_id  */
  YYSYMBOL_flower_paran_o = 107,           /* flower_paran_o  */
  YYSYMBOL_flower_paran_c = 108,           /* flower_paran_c  */
  YYSYMBOL_flower_paran_o_c = 109,         /* flower_paran_o_c  */
  YYSYMBOL_flower_paran_c_c = 110,         /* flower_paran_c_c  */
  YYSYMBOL_func_paran_o = 111,             /* func_paran_o  */
  YYSYMBOL_func_paran_c = 112              /* func_paran_c  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      56,    57,    63,    60,    55,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,    61,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    62,    63,    64,    68,    69,    70,    74,
      75,    76,    77,    81,    82,    86,    87,    92,    92,    93,
      97,    98,    99,   103,   107,   107,   108,   108,   109,   109,
     114,   115,   120,   121,   125,   126,   127,   128,   129,   130,
     131,   132,   137,   138,   139,   140,   144,   148,   149,   150,
     151,   152,   153,   156,   157,   158,   159,   160,   161,   162,
     163,   166,   168,   169,   175,   175,   222,   223,   228,   229,
     230,   231,   232,   240,   244,   247,   248,   251,   252,   255,
     256,   259,   260,   263,   264,   265,   266,   269,   270,   273,
     276,   277,   278,   279,   280,   281,   285,   313,   341,   344,
     372,   400,   401,   404,   405,   406,   422,   423,   426,   429,
     432,   435,   437,   440,   442,   444
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
  "\"end of file\"", "error", "\"invalid token\"", "T_NUM", "T_DIMS",
  "T_REAL", "T_ID", "T_FLOAT", "T_INT", "T_IMPORT", "T_DOUBLE",
  "T_BOOLEAN", "T_STRING", "T_CHAR", "T_IF", "T_ELSE", "T_DO", "T_WHILE",
  "T_RETURN", "T_PACKAGE", "T_CLASS", "T_PUBLIC", "T_PRIVATE",
  "T_PROTECTED", "T_STATIC", "T_VOID", "T_MAIN", "T_CONST", "T_TRUE",
  "T_FALSE", "T_NULL", "T_BREAK", "T_CONTINUE", "T_PRINTLN", "T_PRINT",
  "T_EXIT", "T_PE", "T_ME", "T_DE", "T_MULE", "T_PERCE", "T_AND", "T_OR",
  "T_NE", "T_GTE", "T_LTE", "T_EE", "T_NEW", "T_PID", "T_FINAL", "T_STR",
  "T_PLUS", "T_LESS", "T_GREATER", "';'", "','", "'('", "')'", "'{'",
  "'}'", "'+'", "'='", "'-'", "'*'", "'/'", "'%'", "$accept", "Prog",
  "Package", "Import", "Modifier", "Modifier1", "Modifier2", "Classes",
  "$@1", "ClassBody", "GlobalVar", "MethodDec", "$@2", "$@3", "$@4",
  "ParameterList", "Statements", "Statement", "PrintBlock", "Declr",
  "Type", "ListVar", "X", "Assign", "@5", "OtherAssign", "String", "Cond",
  "Exp", "LogExp", "Logop", "EqExp0", "RelG", "Eqop", "RelExp", "Relop",
  "ArithExp", "T", "G", "print_pid", "print_id", "flower_paran_o",
  "flower_paran_c", "flower_paran_o_c", "flower_paran_c_c", "func_paran_o",
  "func_paran_c", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    59,    44,    40,    41,   123,   125,
      43,    61,    45,    42,    47,    37
};
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -166,    62,    79,  -166,     9,    31,  -166,  -166,    48,    63,
      23,    -2,    -2,    -2,    71,  -166,   104,  -166,  -166,  -166,
    -166,  -166,    74,   107,  -166,  -166,  -166,  -166,   158,  -166,
    -166,  -166,   121,  -166,   132,   227,   115,   132,   132,  -166,
    -166,  -166,  -166,  -166,  -166,    59,   126,    82,  -166,   127,
    -166,  -166,  -166,  -166,  -166,   137,   131,  -166,  -166,     8,
    -166,   133,   133,   158,   136,   158,     5,    76,   133,  -166,
     176,   234,  -166,   145,  -166,  -166,    12,  -166,    86,  -166,
    -166,  -166,  -166,   234,  -166,   134,  -166,   143,   142,    65,
      57,  -166,  -166,   171,   -15,  -166,   201,   234,   158,   154,
     158,   234,    14,   234,  -166,   208,    42,   125,  -166,   134,
     163,  -166,  -166,   134,  -166,  -166,   134,  -166,  -166,  -166,
    -166,  -166,  -166,    22,    22,    22,    22,    22,    22,  -166,
     154,   214,  -166,   161,   170,   222,   134,   223,  -166,  -166,
    -166,  -166,  -166,    57,   171,  -166,    22,   -15,   -15,    69,
    -166,  -166,  -166,   161,   154,  -166,   188,   234,  -166,  -166,
      56,   188,   161,   172,   174,   134,   173,   180,   184,   188,
     194,    82,   195,   196,    -1,  -166,   184,   188,   134,   188,
     197,   116,   116,  -166,  -166,  -166,  -166,    16,  -166,  -166,
     169,    22,    22,    22,    22,    22,  -166,   184,   198,    65,
     199,  -166,   200,   202,    69,    69,    69,    69,    69,  -166,
     203,   236,   206,   209,   188,   210,  -166,  -166,   205,   134,
     239,   211,   204,   213,   188,  -166,   212,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     8,     1,     0,    16,   109,   108,     0,     0,
       0,    16,    16,    16,    16,    15,     0,    12,    14,     2,
       3,     4,     0,     0,     9,    10,    11,    13,     0,     6,
       7,    17,     0,   112,    16,     0,     0,    16,    16,    48,
      47,    49,    50,    52,    51,     0,     0,     0,   113,    16,
      20,    21,    28,    26,    23,     0,    46,    53,    54,    61,
      18,     0,     0,     0,    57,     0,    62,     0,     0,   114,
       0,     0,    58,     0,    56,    55,    61,    63,     0,   106,
     107,    85,    86,     0,    73,     0,    64,    45,    44,    75,
      78,    82,    83,    76,    98,   102,   105,     0,     0,     0,
       0,     0,    62,     0,    67,     0,     0,     0,    65,     0,
       0,    79,    80,     0,    88,    87,     0,    95,    93,    91,
      94,    90,    92,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   115,     0,    30,     0,     0,     0,    66,    84,
     103,    42,    43,    77,     0,    81,     0,    96,    97,    89,
      99,   100,   101,     0,     0,   110,     0,     0,    60,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,   111,    27,    32,    34,    61,    35,    36,
       0,     0,     0,     0,     0,     0,    25,     0,     0,    74,
       0,    39,     0,     0,    68,    69,    71,    70,    72,    29,
       0,     0,     0,     0,     0,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,    38,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,    41,   147,   242,   216,  -166,    97,
    -166,  -166,  -166,  -166,  -166,   -90,  -156,  -166,   -35,   235,
     -27,  -166,   207,   -46,  -166,  -166,   159,    54,   -64,   -81,
    -166,   162,   160,  -166,  -166,  -166,   -83,    60,    81,  -166,
      -4,  -136,  -165,  -166,  -166,    25,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,    35,    17,    18,    19,    32,    36,
      37,    38,    68,    62,    61,    99,   168,   169,    86,   170,
     171,    56,    57,   172,   108,   173,    87,   198,    88,    89,
     113,    90,    91,   116,    92,   125,    93,    94,    95,     8,
      96,   156,   184,    34,    49,    70,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    58,   107,   190,   106,   176,    23,   130,    47,    77,
     153,   196,    66,   185,   104,     6,   102,   161,    77,    75,
      66,   197,    14,   200,    31,    79,   177,    80,     6,     6,
     144,   -19,   209,   144,   162,   191,   192,   193,   194,   195,
      10,    53,   149,    59,   100,   141,    16,    15,   126,   127,
     128,    64,    11,    12,    13,    14,   105,     7,   218,    72,
      67,    76,     3,   160,   -24,     6,    78,   175,   226,    67,
     100,    22,   104,    67,   135,   136,   137,    67,   146,    79,
      15,    80,     6,   111,   112,    52,    55,    71,     6,    79,
      16,    80,     6,    97,   131,   144,   134,   199,     4,   139,
     114,   180,    20,   115,    81,    82,   111,   112,   204,   205,
     206,   207,   208,   140,    81,    82,   123,    21,   124,    79,
      15,    80,     6,    83,    28,    58,    84,   -19,    29,   123,
     100,   124,    85,   103,    50,    51,   144,    79,   199,    80,
       6,    63,    85,     6,    81,    82,   202,   203,    11,    12,
      13,    14,   174,    11,    12,    13,    14,   174,    24,    25,
      26,    30,    81,    82,     6,   174,    84,   187,   117,   118,
     119,   120,    85,   174,    48,   174,    15,   121,   122,    33,
      54,    15,   140,   147,   148,   123,    65,   124,    98,    69,
      85,   -22,   101,   110,     6,    39,    40,    73,    41,    42,
      43,    44,   163,   109,   164,   129,   165,   150,   151,   152,
     174,   132,   138,    84,   117,   118,   119,   120,   154,   155,
     174,   166,   167,   121,   122,   157,   158,   159,   178,   181,
     136,   123,   179,   124,    39,    40,   182,    41,    42,    43,
      44,    39,    40,   183,    41,    42,    43,    44,   186,   188,
     189,   201,    45,   215,   222,   210,    27,   212,   211,   213,
     216,   214,   224,   217,   220,    60,   219,   225,   223,   142,
      46,   227,    74,   221,     0,   143,   145
};

static const yytype_int16 yycheck[] =
{
       4,    47,    85,     4,    85,   161,    10,    97,    35,     4,
     130,   176,     4,   169,    78,     6,     4,   153,     4,    65,
       4,   177,    24,   179,    28,     3,   162,     5,     6,     6,
     113,     0,   197,   116,   154,    36,    37,    38,    39,    40,
       9,    45,   125,    47,    71,   109,     5,    49,    63,    64,
      65,    55,    21,    22,    23,    24,    83,    48,   214,    63,
      61,    65,     0,   146,    56,     6,    61,   157,   224,    61,
      97,    48,   136,    61,   101,    61,   103,    61,    56,     3,
      49,     5,     6,    41,    42,    26,     4,    62,     6,     3,
      49,     5,     6,    68,    98,   178,   100,   178,    19,    57,
      43,   165,    54,    46,    28,    29,    41,    42,   191,   192,
     193,   194,   195,    57,    28,    29,    60,    54,    62,     3,
      49,     5,     6,    47,    20,   171,    50,     0,    54,    60,
     157,    62,    56,    47,    37,    38,   219,     3,   219,     5,
       6,     4,    56,     6,    28,    29,   181,   182,    21,    22,
      23,    24,   156,    21,    22,    23,    24,   161,    11,    12,
      13,    54,    28,    29,     6,   169,    50,   171,    43,    44,
      45,    46,    56,   177,    59,   179,    49,    52,    53,    58,
      54,    49,    57,   123,   124,    60,    55,    62,    12,    56,
      56,    59,    47,    51,     6,     7,     8,    61,    10,    11,
      12,    13,    14,    60,    16,     4,    18,   126,   127,   128,
     214,    57,     4,    50,    43,    44,    45,    46,     4,    58,
     224,    33,    34,    52,    53,    55,     4,     4,    56,    56,
      61,    60,    58,    62,     7,     8,    56,    10,    11,    12,
      13,     7,     8,    59,    10,    11,    12,    13,    54,    54,
      54,    54,    25,    17,    15,    57,    14,    57,    59,    57,
      54,    58,    58,    54,    59,    49,    56,    54,    57,   110,
      35,    59,    65,   219,    -1,   113,   116
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,    68,     0,    19,    69,     6,    48,   105,   106,
       9,    21,    22,    23,    24,    49,    70,    71,    72,    73,
      54,    54,    48,   106,    71,    71,    71,    72,    20,    54,
      54,   106,    74,    58,   109,    70,    75,    76,    77,     7,
       8,    10,    11,    12,    13,    25,    85,    86,    59,   110,
      75,    75,    26,   106,    54,     4,    87,    88,    89,   106,
      73,    80,    79,     4,   106,    55,     4,    61,    78,    56,
     111,   111,   106,    61,    88,    89,   106,     4,    61,     3,
       5,    28,    29,    47,    50,    56,    84,    92,    94,    95,
      97,    98,   100,   102,   103,   104,   106,   111,    12,    81,
      86,    47,     4,    47,    94,    86,    95,   102,    90,    60,
      51,    41,    42,    96,    43,    46,    99,    43,    44,    45,
      46,    52,    53,    60,    62,   101,    63,    64,    65,     4,
      81,   106,    57,   112,   106,    86,    61,    86,     4,    57,
      57,    94,    92,    97,   102,    98,    56,   103,   103,   102,
     104,   104,   104,   112,     4,    58,   107,    55,     4,     4,
     102,   107,   112,    14,    16,    18,    33,    34,    82,    83,
      85,    86,    89,    91,   106,    81,    82,   107,    56,    58,
      94,    56,    56,    59,   108,    82,    54,   106,    54,    54,
       4,    36,    37,    38,    39,    40,   108,    82,    93,    95,
      82,    54,    84,    84,   102,   102,   102,   102,   102,   108,
      57,    59,    57,    57,    58,    17,    54,    54,    82,    56,
      59,    93,    15,    57,    58,    54,    82,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    74,    73,    73,
      75,    75,    75,    76,    78,    77,    79,    77,    80,    77,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    84,    84,    84,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    88,    90,    89,    89,    89,    91,    91,
      91,    91,    91,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    99,    99,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   106,
     107,   108,   109,   110,   111,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     4,     4,     0,     4,     4,     0,     2,
       2,     2,     1,     2,     1,     1,     0,     0,     8,     0,
       2,     2,     0,     3,     0,    10,     0,    10,     0,    12,
       2,     4,     2,     1,     2,     2,     2,    11,     9,     3,
       5,     5,     3,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     3,     6,
       6,     1,     2,     3,     0,     4,     5,     4,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* Prog: Package Import Classes  */
#line 57 "sem.y"
                                {fprintf(stderr,"EOF\n"); YYACCEPT;}
#line 1543 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 92 "sem.y"
                                   {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, yyvsp[0].string,"class","(null)");}
#line 1549 "y.tab.c"
    break;

  case 24: /* $@2: %empty  */
#line 107 "sem.y"
                                {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-1].string,"(null)");}
#line 1555 "y.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 108 "sem.y"
                                  {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-1].string,"(null)");}
#line 1561 "y.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 109 "sem.y"
                                {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-1].string,"(null)");}
#line 1567 "y.tab.c"
    break;

  case 30: /* ParameterList: Type print_id  */
#line 114 "sem.y"
                       {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-1].string,"(null)");}
#line 1573 "y.tab.c"
    break;

  case 31: /* ParameterList: Type print_id ',' ParameterList  */
#line 115 "sem.y"
                                         {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, yyvsp[-2].string,yyvsp[-3].string,"(null)");}
#line 1579 "y.tab.c"
    break;

  case 42: /* PrintBlock: String '+' Exp  */
#line 137 "sem.y"
                        {yyval.type = "String"; char result[10]; if(strcmp(yyvsp[0].type,"int") == 0){sprintf(result,"%d",yyvsp[0].number);} else{sprintf(result,"%f",yyvsp[0].real);}yyval.string = strcat(yyvsp[-2].string,result);}
#line 1585 "y.tab.c"
    break;

  case 43: /* PrintBlock: Exp T_PLUS String  */
#line 138 "sem.y"
                           {yyval.type = "String";}
#line 1591 "y.tab.c"
    break;

  case 44: /* PrintBlock: Exp  */
#line 139 "sem.y"
             {yyval = yyvsp[0];}
#line 1597 "y.tab.c"
    break;

  case 45: /* PrintBlock: String  */
#line 140 "sem.y"
                {yyval.type = "String"; yyval.string = yyvsp[0].string;}
#line 1603 "y.tab.c"
    break;

  case 53: /* ListVar: X  */
#line 156 "sem.y"
           {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[0].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-1].string,"(null)");}}
#line 1609 "y.tab.c"
    break;

  case 54: /* ListVar: Assign  */
#line 157 "sem.y"
                {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[0].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[0].type,yyvsp[0].val);}}
#line 1615 "y.tab.c"
    break;

  case 55: /* ListVar: ListVar ',' Assign  */
#line 158 "sem.y"
                      { char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[0].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-3].string,yyvsp[0].val);}}
#line 1621 "y.tab.c"
    break;

  case 56: /* ListVar: ListVar ',' X  */
#line 159 "sem.y"
                 { char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[0].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-3].string,"(null)");}}
#line 1627 "y.tab.c"
    break;

  case 57: /* ListVar: T_DIMS print_id  */
#line 160 "sem.y"
                         {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[0].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-2].string,"(null)");}}
#line 1633 "y.tab.c"
    break;

  case 58: /* ListVar: T_DIMS T_DIMS print_id  */
#line 161 "sem.y"
                                {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[0].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, yyvsp[0].string,yyvsp[-3].string,"(null)");}}
#line 1639 "y.tab.c"
    break;

  case 59: /* ListVar: print_id T_DIMS '=' T_NEW Type T_DIMS  */
#line 162 "sem.y"
                                               {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[-5].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {if(yyvsp[0].number==-1){yyerror("error");}insert(ht, num_extract(scope), scope, yyvsp[-5].string,yyvsp[-6].string,"(null)");}}
#line 1645 "y.tab.c"
    break;

  case 60: /* ListVar: T_DIMS print_id '=' T_NEW Type T_DIMS  */
#line 163 "sem.y"
                                               {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,yyvsp[-4].string)){yyerror("Declaring twice!\n");YYACCEPT;} else {if(yyvsp[0].number==-1){yyerror("error");}insert(ht, num_extract(scope), scope, yyvsp[-4].string,yyvsp[-6].string,"(null)");}}
#line 1651 "y.tab.c"
    break;

  case 62: /* X: print_id T_DIMS  */
#line 168 "sem.y"
                         {yyval=yyvsp[-1];}
#line 1657 "y.tab.c"
    break;

  case 63: /* X: print_id T_DIMS T_DIMS  */
#line 169 "sem.y"
                                {yyval=yyvsp[-2];}
#line 1663 "y.tab.c"
    break;

  case 64: /* @5: %empty  */
#line 175 "sem.y"
                                 {yyval.string=yyvsp[-2].string;}
#line 1669 "y.tab.c"
    break;

  case 65: /* Assign: print_id '=' PrintBlock @5  */
#line 176 "sem.y"
{ 
 char* scope = return_string(current_scope);
 if(search(ht,num_extract(scope),scope,yyvsp[-3].string))
 {
	struct node* node = get_node(ht,num_extract(scope),scope,yyvsp[-3].string); 


	if(strcmp(node->type,yyvsp[-1].type)!=0)
	{
		printf("INCOMPATIBLE type\n");
		YYACCEPT;
	}
  	else
  	{
	  	yyval.type = yyvsp[-1].type;
	  	char result[20];
	  	if(strcmp(yyvsp[-1].type,"int") == 0){sprintf(result,"%d",yyvsp[-1].number);} 
	    else if(strcmp(yyvsp[-1].type,"double") == 0){sprintf(result,"%f",yyvsp[-1].real);}
	    else{strcpy(result,yyvsp[-1].string);}
	    strcpy(node->value,result);
  	}
} 
else //int n = 2;
 {

	if(!(strcmp(yyvsp[-4].string,"int")==0 ||strcmp(yyvsp[-4].string,"double")==0 || strcmp(yyvsp[-4].string,"String")==0 ||strcmp(yyvsp[-4].string,"boolean")==0))
  	{
  		yyerror("Identifier undeclared!\n");YYACCEPT;
  	}
	if(strcmp(yyvsp[-4].string,yyvsp[-1].type)!=0)
	{
		printf("INCOMPATIBLE type\n");
		YYACCEPT;
	}
	else 
	  {
	  	yyval.type = yyvsp[-4].string;
	  	char result[20];
	  	if(strcmp(yyvsp[-1].type,"int") == 0){sprintf(result,"%d",yyvsp[-1].number);} 
	    else if(strcmp(yyvsp[-1].type,"double") == 0){sprintf(result,"%f",yyvsp[-1].real);}
	    else{strcpy(result,yyvsp[-1].string);}
	    yyval.val = result;
	  }
} 

}
#line 1720 "y.tab.c"
    break;

  case 66: /* Assign: print_id '=' T_NEW Type T_DIMS  */
#line 222 "sem.y"
                                        {if(yyvsp[0].number==-1){yyerror("error");}yyval=yyvsp[-4];}
#line 1726 "y.tab.c"
    break;

  case 67: /* Assign: print_id T_DIMS '=' Exp  */
#line 223 "sem.y"
                                 {if(yyvsp[-2].number==-1){yyerror("error");}yyval=yyvsp[-3];}
#line 1732 "y.tab.c"
    break;

  case 68: /* OtherAssign: print_id T_PE ArithExp  */
#line 228 "sem.y"
                                {yyval=yyvsp[-2];}
#line 1738 "y.tab.c"
    break;

  case 69: /* OtherAssign: print_id T_ME ArithExp  */
#line 229 "sem.y"
                                {yyval=yyvsp[-2];}
#line 1744 "y.tab.c"
    break;

  case 70: /* OtherAssign: print_id T_MULE ArithExp  */
#line 230 "sem.y"
                                  {yyval=yyvsp[-2];}
#line 1750 "y.tab.c"
    break;

  case 71: /* OtherAssign: print_id T_DE ArithExp  */
#line 231 "sem.y"
                                {yyval=yyvsp[-2];}
#line 1756 "y.tab.c"
    break;

  case 72: /* OtherAssign: print_id T_PERCE ArithExp  */
#line 232 "sem.y"
                               {yyval=yyvsp[-2];}
#line 1762 "y.tab.c"
    break;

  case 75: /* Exp: LogExp  */
#line 247 "sem.y"
               {yyval.type = yyvsp[0].type;}
#line 1768 "y.tab.c"
    break;

  case 76: /* Exp: ArithExp  */
#line 248 "sem.y"
                  { yyval = yyvsp[0];}
#line 1774 "y.tab.c"
    break;

  case 77: /* LogExp: LogExp Logop EqExp0  */
#line 251 "sem.y"
                            {yyval.type = "boolean";}
#line 1780 "y.tab.c"
    break;

  case 78: /* LogExp: EqExp0  */
#line 252 "sem.y"
                {yyval.type = "boolean";}
#line 1786 "y.tab.c"
    break;

  case 96: /* ArithExp: ArithExp '+' T  */
#line 286 "sem.y"
      {
     if(strcmp(yyvsp[-2].type,"double")==0)
     { 
     	yyval.type = "double";
     	if(strcmp(yyvsp[0].type,"double")==0)
     	{ 
     		yyval.real =  yyvsp[-2].real + yyvsp[0].real ;
     	} 
     	else 
     	{
     		yyval.real =  yyvsp[-2].real + yyvsp[0].number;
     	} 
     } 
     else
     {
     	if(strcmp(yyvsp[0].type,"double")==0){
        	yyval.real = yyvsp[-2].number + yyvsp[0].real;
            yyval.type = "double";
     	}
     	else{
        	yyval.number = yyvsp[-2].number + yyvsp[0].number;

		yyval.type = "int";
     	}
     }
     }
#line 1817 "y.tab.c"
    break;

  case 97: /* ArithExp: ArithExp '-' T  */
#line 314 "sem.y"
    {
     if(strcmp(yyvsp[-2].type,"double")==0)
     { 
     	yyval.type = "double";
     	if(strcmp(yyvsp[0].type,"double")==0)
     	{ 
     		yyval.real =  yyvsp[-2].real - yyvsp[0].real ;
     	} 
     	else 
     	{
     		yyval.real =  yyvsp[-2].real - yyvsp[0].number;
     	} 
     } 
     else
     {
     	if(strcmp(yyvsp[0].type,"double")==0){
        	yyval.real = yyvsp[-2].number - yyvsp[0].real;
            yyval.type = "double";
     	}
     	else{
        	yyval.number = yyvsp[-2].number - yyvsp[0].number;
            yyval.type = "int";
     	}
     }
     }
#line 1847 "y.tab.c"
    break;

  case 98: /* ArithExp: T  */
#line 341 "sem.y"
           {yyval = yyvsp[0];}
#line 1853 "y.tab.c"
    break;

  case 99: /* T: T '*' G  */
#line 345 "sem.y"
     {
     if(strcmp(yyvsp[-2].type,"double")==0)
     { 
     	yyval.type = "double";
     	if(strcmp(yyvsp[0].type,"double")==0)
     	{ 
     		yyval.real =  yyvsp[-2].real * yyvsp[0].real ;
     	} 
     	else 
     	{
     		yyval.real =  yyvsp[-2].real * yyvsp[0].number;
     	} 
     } 
     else
     {
     	if(strcmp(yyvsp[0].type,"double")==0){
        	yyval.real = yyvsp[-2].number * yyvsp[0].real;
            yyval.type = "double";
     	}
     	else{
        	yyval.number = yyvsp[-2].number * yyvsp[0].number;
            yyval.type = "int";
     	}
     }
     }
#line 1883 "y.tab.c"
    break;

  case 100: /* T: T '/' G  */
#line 373 "sem.y"
    {
     if(strcmp(yyvsp[-2].type,"double")==0)
     { 
     	yyval.type = "double";
     	if(strcmp(yyvsp[0].type,"double")==0)
     	{ 
     		yyval.real =  yyvsp[-2].real / yyvsp[0].real ;
     	} 
     	else 
     	{
     		yyval.real =  yyvsp[-2].real / yyvsp[0].number;
     	} 
     } 
     else
     {
     	if(strcmp(yyvsp[0].type,"double")==0){
        	yyval.real = yyvsp[-2].number / yyvsp[0].real;
            yyval.type = "double";
     	}
     	else{

        	yyval.number = yyvsp[-2].number / yyvsp[0].number;

            yyval.type = "int";
     	}
     }
    }
#line 1915 "y.tab.c"
    break;

  case 101: /* T: T '%' G  */
#line 400 "sem.y"
                 {yyval.type = yyvsp[0].type; yyval.number = yyvsp[-2].number % yyvsp[0].number;}
#line 1921 "y.tab.c"
    break;

  case 102: /* T: G  */
#line 401 "sem.y"
           {yyval = yyvsp[0];}
#line 1927 "y.tab.c"
    break;

  case 104: /* G: print_id T_DIMS  */
#line 405 "sem.y"
                         {char* scope = return_string(current_scope); if(!search(ht,num_extract(scope),scope,yyvsp[-1].string)){yyerror("Identifier undeclared!\n");YYACCEPT;}}
#line 1933 "y.tab.c"
    break;

  case 105: /* G: print_id  */
#line 407 "sem.y"
  {
  	char* scope = return_string(current_scope); 
  	if(!search(ht,num_extract(scope),scope,yyvsp[0].string))
  	{
  		yyerror("Identifier undeclared!\n");YYACCEPT;
  	}
  	else
  	{
  		struct node* node = get_node(ht,num_extract(scope),scope,yyvsp[0].string);
  		yyval.type = node->type;
		if(node->value[0]=='('){printf("Uninitialised\n");YYACCEPT;}
  		if(strcmp(node->type,"int")==0){  yyval.number = atoi(node->value);}
  		else yyval.real = atof(node->value);
  	}
  }
#line 1953 "y.tab.c"
    break;

  case 106: /* G: T_NUM  */
#line 422 "sem.y"
               {yyval.type = "int"; yyval.number = yyvsp[0].number;}
#line 1959 "y.tab.c"
    break;

  case 107: /* G: T_REAL  */
#line 423 "sem.y"
                {yyval.type = "double"; yyval.real = yyvsp[0].real;}
#line 1965 "y.tab.c"
    break;

  case 108: /* print_pid: T_PID  */
#line 426 "sem.y"
                {}
#line 1971 "y.tab.c"
    break;

  case 109: /* print_id: T_ID  */
#line 429 "sem.y"
                {}
#line 1977 "y.tab.c"
    break;

  case 110: /* flower_paran_o: '{'  */
#line 432 "sem.y"
                 {index_a++;current_scope[index_a]+=1;}
#line 1983 "y.tab.c"
    break;

  case 111: /* flower_paran_c: '}'  */
#line 435 "sem.y"
                {index_a--;}
#line 1989 "y.tab.c"
    break;

  case 112: /* flower_paran_o_c: '{'  */
#line 437 "sem.y"
                 {index_a++;current_scope[index_a]+=1;current_scope[2]=0;}
#line 1995 "y.tab.c"
    break;

  case 113: /* flower_paran_c_c: '}'  */
#line 440 "sem.y"
                {current_scope[2]=0;index_a--;}
#line 2001 "y.tab.c"
    break;

  case 114: /* func_paran_o: '('  */
#line 442 "sem.y"
                { index_a++;current_scope[index_a]+=1;}
#line 2007 "y.tab.c"
    break;

  case 115: /* func_paran_c: ')'  */
#line 444 "sem.y"
                {current_scope[index_a]-=1;index_a--;}
#line 2013 "y.tab.c"
    break;


#line 2017 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 447 "sem.y"

void insert(struct hash *ht, int key, char* scope, char* name, char* type,char* value)
 {
   if(search(ht,key,scope,name))
   {
    
   }
   else
   {
       int index;
       struct node *temp;

       temp=malloc(sizeof(struct node));
       strcpy(temp->name,name);
       strcpy(temp->type,type);
       strcpy(temp->scope,scope);
       strcpy(temp->value,value);
       temp->next=NULL;

       index=key%size;//hash function
       temp->next=ht[index].head;
       ht[index].head=temp;
       ht[index].count++;
    }
    
}


void display(struct hash* ht)
 {
    int i;
    struct node *temp;
    int s;

   fprintf(t,"NAME\tTYPE\tSCOPE\tVALUE\tSIZE\n");

   for(i=0;i<size;i++)
   {
     if(ht[i].head!=NULL)
     {
        temp=ht[i].head;
        while(temp!=NULL)
        {
          fprintf(t,"%s\t",temp->name);
          fprintf(t,"%s\t",temp->type);
          fprintf(t,"%s\t",temp->scope);
          fprintf(t,"%s\t",temp->value);
          if(strcmp(temp->type,"int")==0)
          {
          	s=4;
          	printf("\t");
          }
          else if(strcmp(temp->type,"double")==0)
          	s=8;
          else if(strcmp(temp->type,"boolean")==0)
          	s=1;
          else if(strcmp(temp->type,"short")==0)
          	s=1;
          else if(strcmp(temp->type,"long")==0)
          	s=8;
          else if(strcmp(temp->type,"float")==0)
          	s=4;
          else if(strcmp(temp->type,"char")==0)
          	s=2;
          fprintf(t,"%d\t",s);
          fprintf(t,"\n");

          temp=temp->next;
        }
      }
   }


  }


 int search(struct hash *ht,int key, char* scope, char* name)
 {
  int index;
   struct node *temp, *prev;

   index=key%size;

   temp=ht[index].head;


   while(temp!=NULL)
   {
   		if(strcmp(temp->name,name) == 0 &&strcmp(temp->scope,scope)==0)
        {
        	return 1;
        }
        temp=temp->next;
   }

   if(temp==NULL)
     return 0;
    return 0;
  }

 struct node* get_node(struct hash *ht,int key, char* scope, char* name)
 {
  int index;
   struct node *temp, *prev;

   index=key%size;

   temp=ht[index].head;


   while(temp!=NULL)
   {
   		if(strcmp(temp->name,name) == 0 &&strcmp(temp->scope,scope)==0)
        {
        	return temp;
        }
        temp=temp->next;
   }

   if(temp==NULL)
     return NULL;
  }

char* return_string()
{
	char* sco;
	sco=(char*)malloc(15*sizeof(char));
	char hi[10];
	for(int j=0;j<=index_a;j++)
	{
		sprintf(hi,"%d",current_scope[j]);
		if(j==index_a)
		{
			strcat(sco,hi);
		}
		else
		{
			strcat(sco,hi);
			strcat(sco,".");
		}	
	}
	return sco;
}
int num_extract(char *s)
{
const char del[2] = ".";
int len = strlen(s);
char str[len+1];
strcpy(str,s);
char *token;
char new[10] = "";
token = strtok(str, del);
while( token != NULL ) 
{
strcat(new, token);
token = strtok(NULL, del);
}
return atoi(new);
}


void yyerror(char *s)
{
fprintf(stderr,"%s in line %d\n",s,yylineno);


}
int yywrap()
{
    return 1;
}

void printing()
{
	for(int j=0;j<=index_a;j++)
	{
		if(j==index_a)
			fprintf(t,"%d",current_scope[j]);
		else
			fprintf(t,"%d.",current_scope[j]);		
	}
		
}

int main()
{
	t = fopen("Sem-symboltable.txt","w");
	ht=malloc(size* sizeof(struct hash));
  	for(int i=0;i<size;i++)
 	{
    		ht[i].head=NULL;
    		ht[i].count=0;
  	}	
	current_scope=(int*)malloc(3*sizeof(int));
	current_scope[0]=1;
	index_a=0;
	char fname[100];
	fprintf(stderr,"\nEnter the name of file\n");
	scanf("%s",fname);
	yyin=fopen(fname,"r+");

	yyparse();
	display(ht);
return 0;
}
  
