/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ast.y"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
extern int yylineno;
extern FILE *yyin;
int yylex();
void yyerror(char *s);


typedef struct node
{
	char name[10];
    char id[10];
    int val;
    int is_leaf ;
  	struct node *left;
  	struct node *right;
}NODE;

int nodes =0;
NODE *newnode(char *name,NODE *left,NODE *right,int is_leaf,char* id, int val)
{
    nodes+=1;
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    strcpy(temp->name,name);
    if(!is_leaf)
    {
	temp->is_leaf = 0;
   	temp->left = left;
    	temp->right = right;
    }
    else
    {
    	temp->is_leaf = 1;
	if(id[0] == '\0')
    		temp->val = val;
    	else
    		strcpy(temp->id,id);
    }

    return temp;
}
void print_ast(NODE*,int);
void print(NODE*,int );
FILE *f;

#line 120 "y.tab.c"

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
union YYSTYPE
{
#line 53 "ast.y"

	int number;
	double real;
	char *string;
	NODE* node;

#line 285 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
  YYSYMBOL_55_ = 55,                       /* '{'  */
  YYSYMBOL_56_ = 56,                       /* '}'  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* ')'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
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
  YYSYMBOL_ClassBody = 74,                 /* ClassBody  */
  YYSYMBOL_GlobalVar = 75,                 /* GlobalVar  */
  YYSYMBOL_MethodDec = 76,                 /* MethodDec  */
  YYSYMBOL_MainParams = 77,                /* MainParams  */
  YYSYMBOL_ParameterList = 78,             /* ParameterList  */
  YYSYMBOL_List = 79,                      /* List  */
  YYSYMBOL_Statements = 80,                /* Statements  */
  YYSYMBOL_Statement = 81,                 /* Statement  */
  YYSYMBOL_IfStatement = 82,               /* IfStatement  */
  YYSYMBOL_PrintBlock = 83,                /* PrintBlock  */
  YYSYMBOL_Declr = 84,                     /* Declr  */
  YYSYMBOL_Type = 85,                      /* Type  */
  YYSYMBOL_ListVar = 86,                   /* ListVar  */
  YYSYMBOL_X = 87,                         /* X  */
  YYSYMBOL_Assign = 88,                    /* Assign  */
  YYSYMBOL_String = 89,                    /* String  */
  YYSYMBOL_Cond = 90,                      /* Cond  */
  YYSYMBOL_Exp = 91,                       /* Exp  */
  YYSYMBOL_LogExp = 92,                    /* LogExp  */
  YYSYMBOL_Logop = 93,                     /* Logop  */
  YYSYMBOL_EqExp0 = 94,                    /* EqExp0  */
  YYSYMBOL_RelG = 95,                      /* RelG  */
  YYSYMBOL_Eqop = 96,                      /* Eqop  */
  YYSYMBOL_RelExp = 97,                    /* RelExp  */
  YYSYMBOL_Relop = 98,                     /* Relop  */
  YYSYMBOL_ArithExp = 99,                  /* ArithExp  */
  YYSYMBOL_T = 100,                        /* T  */
  YYSYMBOL_G = 101                         /* G  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
      57,    58,    63,    60,    59,    62,     2,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,    61,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
       0,    74,    74,    79,    80,    81,    85,    86,    87,    91,
      92,    93,    94,    98,    99,   103,   104,   109,   110,   114,
     115,   116,   120,   124,   126,   127,   132,   136,   140,   141,
     145,   146,   150,   151,   152,   153,   154,   155,   156,   160,
     164,   165,   166,   167,   171,   175,   176,   177,   178,   179,
     180,   183,   184,   185,   186,   187,   188,   192,   193,   194,
     195,   199,   200,   202,   204,   205,   206,   208,   210,   215,
     219,   223,   224,   227,   228,   231,   232,   235,   236,   239,
     240,   241,   242,   245,   246,   249,   252,   253,   254,   255,
     256,   257,   260,   261,   262,   265,   266,   267,   268,   271,
     272,   274,   275,   276
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
  "T_PLUS", "T_LESS", "T_GREATER", "';'", "'{'", "'}'", "'('", "')'",
  "','", "'+'", "'='", "'-'", "'*'", "'/'", "'%'", "$accept", "Prog",
  "Package", "Import", "Modifier", "Modifier1", "Modifier2", "Classes",
  "ClassBody", "GlobalVar", "MethodDec", "MainParams", "ParameterList",
  "List", "Statements", "Statement", "IfStatement", "PrintBlock", "Declr",
  "Type", "ListVar", "X", "Assign", "String", "Cond", "Exp", "LogExp",
  "Logop", "EqExp0", "RelG", "Eqop", "RelExp", "Relop", "ArithExp", "T",
  "G", YY_NULLPTR
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
     305,   306,   307,   308,    59,   123,   125,    40,    41,    44,
      43,    61,    45,    42,    47,    37
};
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -130,    15,     2,  -130,     1,   137,    24,    26,     3,   -12,
     -12,   -12,    38,  -130,    70,  -130,  -130,  -130,  -130,  -130,
      56,    62,  -130,  -130,  -130,  -130,   112,  -130,  -130,    71,
     147,   226,    75,   147,   147,  -130,  -130,  -130,  -130,  -130,
    -130,    14,    76,    27,   133,  -130,  -130,    79,    83,  -130,
      32,    20,    88,  -130,  -130,  -130,   233,   126,   142,    91,
       7,    22,    22,    22,    22,    22,   233,    92,   156,   107,
     158,   167,   120,  -130,   134,  -130,   106,  -130,  -130,   176,
      22,   -19,    50,  -130,   -19,   -19,   -19,   -19,   127,  -130,
    -130,   233,  -130,   138,  -130,   128,   136,     6,   -20,  -130,
    -130,   170,    25,  -130,   135,   150,  -130,   188,   139,   233,
     233,  -130,  -130,   -16,    22,    22,    22,    22,    22,   162,
     207,   -24,   131,   138,   168,  -130,  -130,   138,  -130,  -130,
     138,  -130,  -130,  -130,  -130,  -130,  -130,    22,    12,   194,
     158,  -130,   194,   215,   216,  -130,    50,    50,  -130,  -130,
    -130,   194,  -130,  -130,  -130,  -130,   -20,   170,  -130,   -19,
     138,    63,   164,   169,   138,   172,   174,   179,   194,   171,
      48,   193,  -130,   186,  -130,  -130,   192,   165,   138,   194,
     195,   122,   122,  -130,  -130,  -130,    68,  -130,  -130,  -130,
     196,     6,   197,  -130,   198,   199,   200,   235,   204,   205,
     194,  -130,   203,  -130,  -130,   206,   138,   246,   208,   209,
     211,   194,  -130,   212,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     8,     1,     0,    16,     0,     0,     0,    16,
      16,    16,    16,    15,     0,    12,    14,     2,     4,     3,
       0,     0,     9,    10,    11,    13,     0,     7,     6,     0,
      16,     0,     0,    16,    16,    46,    45,    47,    48,    50,
      49,     0,     0,     0,    16,    19,    20,     0,     0,    22,
       0,    57,    44,    51,    58,    17,     0,     0,     0,    53,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,    60,     0,   102,   103,   101,
       0,    62,    94,    98,    63,    65,    64,    68,     0,    81,
      82,     0,    69,     0,    61,    43,    42,    71,    74,    78,
      79,    72,    57,    52,     0,    28,    27,     0,     0,     0,
       0,    67,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,    84,    83,
       0,    91,    89,    87,    90,    86,    88,     0,    59,     0,
       0,    26,     0,     0,     0,    99,    92,    93,    95,    96,
      97,     0,    66,    80,    40,    41,    73,     0,    77,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,    29,     0,    56,    55,     0,     0,     0,     0,
       0,     0,     0,    24,    30,    32,    57,    33,    25,    23,
       0,    70,     0,    36,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    37,    38,     0,     0,     0,     0,     0,
       0,     0,    35,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,     9,    74,   238,   219,    41,  -130,
    -130,  -130,   201,   129,  -129,  -130,  -130,   -88,   239,   -21,
    -130,   210,   -38,   148,    65,   -68,   -87,  -130,   146,   144,
    -130,  -130,  -130,   -61,     8,    81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    31,    15,    16,    17,    32,    33,
      34,    72,    69,   106,   167,   168,   201,    94,   169,   170,
      52,    53,   171,    95,   190,    96,    97,   127,    98,    99,
     130,   100,   137,   101,    82,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    84,    85,    86,    87,    54,   121,     6,   111,    20,
      43,    75,    12,   173,    14,     3,    75,   125,   126,   113,
      47,     4,   176,   128,    60,    77,   129,    78,    79,   138,
      54,    50,   122,    51,   153,    70,    58,    13,    59,   184,
      48,   114,   145,   115,   114,    70,   115,   125,   126,     7,
     192,    21,    50,    14,   186,   154,    61,    62,    63,    64,
      65,    61,    62,    63,    64,    65,   157,   177,    76,   157,
     120,   205,    60,   160,    45,    46,   159,    66,    18,    80,
      19,    67,   213,    22,    23,    24,    67,    13,   143,   144,
      26,   191,   111,   194,   195,    77,   180,    78,    79,    61,
      62,    63,    64,    65,    61,    62,    63,    64,    65,    77,
      27,    78,    79,   116,   117,   118,    28,   157,    29,   191,
      89,    90,   146,   147,    67,    77,    30,    78,    79,    67,
      49,    44,    54,   -18,    89,    90,    56,   -18,    71,    91,
      57,    77,    92,    78,    79,   157,     8,    68,    73,    93,
      89,    90,    74,   110,     9,    10,    11,    12,     9,    10,
      11,    12,   102,    93,   105,   104,    89,    90,     9,    10,
      11,    12,    92,   107,   131,   132,   133,   134,   108,    93,
     112,   109,    13,   135,   136,   119,    13,   124,   123,   145,
     139,   114,   141,   115,   142,    93,    13,   148,   149,   150,
     161,    35,    36,   -21,    37,    38,    39,    40,   162,   140,
     163,   152,   164,   131,   132,   133,   134,   151,    92,   174,
     175,   178,   135,   136,   179,   185,   160,   165,   166,   181,
     114,   182,   115,    35,    36,   183,    37,    38,    39,    40,
      35,    36,   188,    37,    38,    39,    40,   187,   189,   193,
      25,    41,   202,   197,   196,   200,   198,   199,   203,   204,
     206,   209,   207,    55,   211,   212,   210,    88,   214,   172,
      42,   208,   155,   156,   158,     0,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
      61,    62,    63,    64,    65,    43,    93,     6,    76,     6,
      31,     4,    24,   142,     5,     0,     4,    41,    42,    80,
       6,    19,   151,    43,     4,     3,    46,     5,     6,     4,
      68,     4,    93,     6,    58,    56,     4,    49,     6,   168,
      26,    60,    58,    62,    60,    66,    62,    41,    42,    48,
     179,    48,     4,    44,     6,   123,    36,    37,    38,    39,
      40,    36,    37,    38,    39,    40,   127,     4,    61,   130,
      91,   200,     4,    61,    33,    34,   137,    57,    54,    57,
      54,    61,   211,     9,    10,    11,    61,    49,   109,   110,
      20,   178,   160,   181,   182,     3,   164,     5,     6,    36,
      37,    38,    39,    40,    36,    37,    38,    39,    40,     3,
      54,     5,     6,    63,    64,    65,    54,   178,     6,   206,
      28,    29,   114,   115,    61,     3,    55,     5,     6,    61,
      54,    56,   170,     0,    28,    29,    57,     0,    12,    47,
      57,     3,    50,     5,     6,   206,     9,    59,     6,    57,
      28,    29,    61,    47,    21,    22,    23,    24,    21,    22,
      23,    24,     6,    57,     6,    58,    28,    29,    21,    22,
      23,    24,    50,     6,    43,    44,    45,    46,    58,    57,
       4,    47,    49,    52,    53,    58,    49,    51,    60,    58,
      55,    60,     4,    62,    55,    57,    49,   116,   117,   118,
       6,     7,     8,    56,    10,    11,    12,    13,    14,    59,
      16,     4,    18,    43,    44,    45,    46,    55,    50,     4,
       4,    57,    52,    53,    55,    54,    61,    33,    34,    57,
      60,    57,    62,     7,     8,    56,    10,    11,    12,    13,
       7,     8,    56,    10,    11,    12,    13,    54,    56,    54,
      12,    25,    17,    56,    58,    55,    58,    58,    54,    54,
      57,    15,    56,    44,    55,    54,    58,    66,    56,   140,
      31,   206,   124,   127,   130,    -1,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    67,    68,     0,    19,    69,     6,    48,     9,    21,
      22,    23,    24,    49,    70,    71,    72,    73,    54,    54,
       6,    48,    71,    71,    71,    72,    20,    54,    54,     6,
      55,    70,    74,    75,    76,     7,     8,    10,    11,    12,
      13,    25,    84,    85,    56,    74,    74,     6,    26,    54,
       4,     6,    86,    87,    88,    73,    57,    57,     4,     6,
       4,    36,    37,    38,    39,    40,    57,    61,    59,    78,
      85,    12,    77,     6,    61,     4,    61,     3,     5,     6,
      57,    99,   100,   101,    99,    99,    99,    99,    78,    28,
      29,    47,    50,    57,    83,    89,    91,    92,    94,    95,
      97,    99,     6,    87,    58,     6,    79,     6,    58,    47,
      47,    91,     4,    99,    60,    62,    63,    64,    65,    58,
      85,    92,    99,    60,    51,    41,    42,    93,    43,    46,
      96,    43,    44,    45,    46,    52,    53,    98,     4,    55,
      59,     4,    55,    85,    85,    58,   100,   100,   101,   101,
     101,    55,     4,    58,    91,    89,    94,    99,    95,    99,
      61,     6,    14,    16,    18,    33,    34,    80,    81,    84,
      85,    88,    79,    80,     4,     4,    80,     4,    57,    55,
      91,    57,    57,    56,    80,    54,     6,    54,    56,    56,
      90,    92,    80,    54,    83,    83,    58,    56,    58,    58,
      55,    82,    17,    54,    54,    80,    57,    56,    90,    15,
      58,    55,    54,    80,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    76,    76,    76,    77,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    82,
      83,    83,    83,    83,    84,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    96,    96,    97,    98,    98,    98,    98,
      98,    98,    99,    99,    99,   100,   100,   100,   100,   101,
     101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     4,     4,     0,     4,     4,     0,     2,
       2,     2,     1,     2,     1,     1,     0,     7,     0,     2,
       2,     0,     3,     9,     9,     9,     3,     2,     1,     3,
       2,     1,     2,     2,     5,     9,     3,     5,     5,     7,
       3,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     6,     6,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     5,     4,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       2,     1,     1,     1
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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
#line 74 "ast.y"
                               {printf("no of nodes : %d\n",nodes);print((yyvsp[0].node),0);YYACCEPT;}
#line 1522 "y.tab.c"
    break;

  case 17: /* Classes: Modifier T_CLASS T_ID '{' ClassBody '}' Classes  */
#line 109 "ast.y"
                                                         {(yyval.node)  = newnode("CLASSES", (yyvsp[-2].node) , (yyvsp[0].node) , 0, "", 0);}
#line 1528 "y.tab.c"
    break;

  case 18: /* Classes: %empty  */
#line 110 "ast.y"
         {(yyval.node)  = newnode("", NULL , NULL , 0, "", 0);}
#line 1534 "y.tab.c"
    break;

  case 19: /* ClassBody: GlobalVar ClassBody  */
#line 114 "ast.y"
                             {(yyval.node)  = newnode("GLOBALVAR",(yyvsp[-1].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1540 "y.tab.c"
    break;

  case 20: /* ClassBody: MethodDec ClassBody  */
#line 115 "ast.y"
                             {(yyval.node)  = newnode("METHODDEC",(yyvsp[-1].node) ,(yyvsp[0].node) , 0, "", 0);}
#line 1546 "y.tab.c"
    break;

  case 21: /* ClassBody: %empty  */
#line 116 "ast.y"
          {(yyval.node)  = newnode("",NULL ,NULL , 0, "", 0);}
#line 1552 "y.tab.c"
    break;

  case 22: /* GlobalVar: Modifier Declr ';'  */
#line 120 "ast.y"
                            {(yyval.node)  = (yyvsp[-1].node) ;}
#line 1558 "y.tab.c"
    break;

  case 23: /* MethodDec: Modifier Type T_ID '(' ParameterList ')' '{' Statements '}'  */
#line 124 "ast.y"
                                                                     {(yyval.node)  = newnode("FUNC",(yyvsp[-4].node) ,(yyvsp[-1].node) , 0, "", 0);}
#line 1564 "y.tab.c"
    break;

  case 24: /* MethodDec: Modifier T_VOID T_ID '(' ParameterList ')' '{' Statements '}'  */
#line 126 "ast.y"
                                                                          {(yyval.node)  = newnode("FUNC",(yyvsp[-4].node) ,(yyvsp[-1].node) , 0, "", 0);}
#line 1570 "y.tab.c"
    break;

  case 25: /* MethodDec: Modifier T_VOID T_MAIN '(' MainParams ')' '{' Statements '}'  */
#line 127 "ast.y"
                                                                          {(yyval.node)  = newnode("FUNC",(yyvsp[-4].node) ,(yyvsp[-1].node) , 0, "", 0);}
#line 1576 "y.tab.c"
    break;

  case 26: /* MainParams: T_STRING T_ID T_DIMS  */
#line 132 "ast.y"
                             {(yyval.node) = newnode("DECL",newnode("TYPE",NULL,NULL,1,(yyvsp[-2].string),0),newnode("ID",NULL,NULL,1,(yyvsp[-1].string),0),0,"",0);}
#line 1582 "y.tab.c"
    break;

  case 27: /* ParameterList: Type List  */
#line 136 "ast.y"
                  {(yyval.node)  = newnode("DECL",(yyvsp[-1].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1588 "y.tab.c"
    break;

  case 28: /* List: T_ID  */
#line 140 "ast.y"
             {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1594 "y.tab.c"
    break;

  case 29: /* List: T_ID ',' List  */
#line 141 "ast.y"
                   {(yyval.node)  = newnode(",",newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1600 "y.tab.c"
    break;

  case 30: /* Statements: Statement Statements  */
#line 145 "ast.y"
                              {(yyval.node)  = newnode("SEQ",(yyvsp[-1].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1606 "y.tab.c"
    break;

  case 31: /* Statements: Statement  */
#line 146 "ast.y"
                   {(yyval.node)  = (yyvsp[0].node) ;}
#line 1612 "y.tab.c"
    break;

  case 32: /* Statement: Declr ';'  */
#line 150 "ast.y"
                   {(yyval.node)  = (yyvsp[-1].node) ;}
#line 1618 "y.tab.c"
    break;

  case 33: /* Statement: Assign ';'  */
#line 151 "ast.y"
                    {(yyval.node)  = (yyvsp[-1].node) ;}
#line 1624 "y.tab.c"
    break;

  case 34: /* Statement: T_IF '(' Cond ')' IfStatement  */
#line 152 "ast.y"
                                       {(yyval.node)  = newnode("IF",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1630 "y.tab.c"
    break;

  case 35: /* Statement: T_DO '{' Statements '}' T_WHILE '(' Cond ')' ';'  */
#line 153 "ast.y"
                                                          {(yyval.node)  = newnode("DO-WHILE",(yyvsp[-6].node) ,(yyvsp[-2].node) ,0,"",0);}
#line 1636 "y.tab.c"
    break;

  case 36: /* Statement: T_RETURN Exp ';'  */
#line 154 "ast.y"
                          {(yyval.node)  = newnode("SEQ",newnode("KEY",NULL,NULL,1,"RETURN",0),(yyvsp[-1].node) ,0,"",0);}
#line 1642 "y.tab.c"
    break;

  case 39: /* IfStatement: '{' Statements '}' T_ELSE '{' Statements '}'  */
#line 160 "ast.y"
                                                      {(yyval.node)  = newnode("SEQ",(yyvsp[-5].node) ,(yyvsp[-1].node) ,0,"",0);}
#line 1648 "y.tab.c"
    break;

  case 40: /* PrintBlock: String '+' Exp  */
#line 164 "ast.y"
                        {(yyval.node)  = newnode("STR",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1654 "y.tab.c"
    break;

  case 41: /* PrintBlock: Exp T_PLUS String  */
#line 165 "ast.y"
                           {(yyval.node)  = newnode((yyvsp[-1].string),(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1660 "y.tab.c"
    break;

  case 42: /* PrintBlock: Exp  */
#line 166 "ast.y"
             {(yyval.node)  = (yyvsp[0].node) ;}
#line 1666 "y.tab.c"
    break;

  case 43: /* PrintBlock: String  */
#line 167 "ast.y"
                {(yyval.node)  = (yyvsp[0].node) ;}
#line 1672 "y.tab.c"
    break;

  case 44: /* Declr: Type ListVar  */
#line 171 "ast.y"
                       {(yyval.node)  = newnode("DECLARE",(yyvsp[-1].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1678 "y.tab.c"
    break;

  case 45: /* Type: T_INT  */
#line 175 "ast.y"
               {(yyval.node)  = newnode("INTEGER",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1684 "y.tab.c"
    break;

  case 46: /* Type: T_FLOAT  */
#line 176 "ast.y"
                 {(yyval.node)  = newnode("FLOAT",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1690 "y.tab.c"
    break;

  case 47: /* Type: T_DOUBLE  */
#line 177 "ast.y"
                  {(yyval.node)  = newnode("DOUBLE",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1696 "y.tab.c"
    break;

  case 48: /* Type: T_BOOLEAN  */
#line 178 "ast.y"
                   {(yyval.node)  = newnode("BOOLEAN",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1702 "y.tab.c"
    break;

  case 49: /* Type: T_CHAR  */
#line 179 "ast.y"
                {(yyval.node)  = newnode("CHAR",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1708 "y.tab.c"
    break;

  case 50: /* Type: T_STRING  */
#line 180 "ast.y"
                  {(yyval.node)  = newnode("STRING",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1714 "y.tab.c"
    break;

  case 51: /* ListVar: X  */
#line 183 "ast.y"
           {(yyval.node)  = (yyvsp[0].node) ;}
#line 1720 "y.tab.c"
    break;

  case 52: /* ListVar: ListVar ',' X  */
#line 184 "ast.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1726 "y.tab.c"
    break;

  case 53: /* ListVar: T_DIMS T_ID  */
#line 185 "ast.y"
                     {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1732 "y.tab.c"
    break;

  case 54: /* ListVar: T_DIMS T_DIMS T_ID  */
#line 186 "ast.y"
                            {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1738 "y.tab.c"
    break;

  case 55: /* ListVar: T_ID T_DIMS '=' T_NEW Type T_DIMS  */
#line 187 "ast.y"
                                           {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[-5].string),0);}
#line 1744 "y.tab.c"
    break;

  case 56: /* ListVar: T_DIMS T_ID '=' T_NEW Type T_DIMS  */
#line 188 "ast.y"
                                           {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[-4].string),0);}
#line 1750 "y.tab.c"
    break;

  case 57: /* X: T_ID  */
#line 192 "ast.y"
              {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[0].string),0);}
#line 1756 "y.tab.c"
    break;

  case 58: /* X: Assign  */
#line 193 "ast.y"
                {(yyval.node)  = (yyvsp[0].node) ;}
#line 1762 "y.tab.c"
    break;

  case 59: /* X: T_ID T_DIMS  */
#line 194 "ast.y"
                     {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[-1].string),0);}
#line 1768 "y.tab.c"
    break;

  case 60: /* X: T_ID T_DIMS T_DIMS  */
#line 195 "ast.y"
                            {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0);}
#line 1774 "y.tab.c"
    break;

  case 61: /* Assign: T_ID '=' PrintBlock  */
#line 199 "ast.y"
                             {(yyval.node)  = newnode("=",newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1780 "y.tab.c"
    break;

  case 62: /* Assign: T_ID T_PE ArithExp  */
#line 200 "ast.y"
                            {(yyval.node)  = newnode((yyvsp[-1].string),newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1786 "y.tab.c"
    break;

  case 63: /* Assign: T_ID T_ME ArithExp  */
#line 202 "ast.y"
                            {(yyval.node)  = newnode((yyvsp[-1].string),newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1792 "y.tab.c"
    break;

  case 64: /* Assign: T_ID T_MULE ArithExp  */
#line 204 "ast.y"
                              {(yyval.node)  = newnode((yyvsp[-1].string),newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1798 "y.tab.c"
    break;

  case 65: /* Assign: T_ID T_DE ArithExp  */
#line 205 "ast.y"
                            {(yyval.node)  = newnode((yyvsp[-1].string),newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1804 "y.tab.c"
    break;

  case 66: /* Assign: T_ID '=' T_NEW Type T_DIMS  */
#line 206 "ast.y"
                                    {(yyval.node)  = newnode("=",newnode("ID",NULL,NULL,1,(yyvsp[-4].string),0),newnode("NEW",NULL,NULL,1,"ARRAY",0),0,"",0);}
#line 1810 "y.tab.c"
    break;

  case 67: /* Assign: T_ID T_DIMS '=' Exp  */
#line 208 "ast.y"
                             {(yyval.node)  = newnode("=",newnode("ID",NULL,NULL,1,(yyvsp[-3].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1816 "y.tab.c"
    break;

  case 68: /* Assign: T_ID T_PERCE ArithExp  */
#line 210 "ast.y"
                               {(yyval.node)  = newnode((yyvsp[-1].string),newnode("ID",NULL,NULL,1,(yyvsp[-2].string),0),(yyvsp[0].node) ,0,"",0);}
#line 1822 "y.tab.c"
    break;

  case 69: /* String: T_STR  */
#line 215 "ast.y"
               {(yyval.node)  = newnode("STR",NULL,NULL ,1 ,(yyvsp[0].string),0);}
#line 1828 "y.tab.c"
    break;

  case 70: /* Cond: LogExp  */
#line 219 "ast.y"
                {(yyval.node)  = (yyvsp[0].node) ;}
#line 1834 "y.tab.c"
    break;

  case 71: /* Exp: LogExp  */
#line 223 "ast.y"
               {(yyval.node)  = (yyvsp[0].node) ;}
#line 1840 "y.tab.c"
    break;

  case 72: /* Exp: ArithExp  */
#line 224 "ast.y"
                  {(yyval.node)  = (yyvsp[0].node) ;}
#line 1846 "y.tab.c"
    break;

  case 73: /* LogExp: LogExp Logop EqExp0  */
#line 227 "ast.y"
                            {(yyval.node)  = newnode((yyvsp[-1].string),(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1852 "y.tab.c"
    break;

  case 74: /* LogExp: EqExp0  */
#line 228 "ast.y"
                {(yyval.node)  = (yyvsp[0].node) ;}
#line 1858 "y.tab.c"
    break;

  case 75: /* Logop: T_AND  */
#line 231 "ast.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 1864 "y.tab.c"
    break;

  case 76: /* Logop: T_OR  */
#line 232 "ast.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 1870 "y.tab.c"
    break;

  case 77: /* EqExp0: EqExp0 Eqop RelG  */
#line 235 "ast.y"
                          {(yyval.node)  = newnode((yyvsp[-1].string),(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1876 "y.tab.c"
    break;

  case 78: /* EqExp0: RelG  */
#line 236 "ast.y"
              {(yyval.node)  = (yyvsp[0].node) ;}
#line 1882 "y.tab.c"
    break;

  case 79: /* RelG: RelExp  */
#line 239 "ast.y"
               {(yyval.node)  = (yyvsp[0].node) ;}
#line 1888 "y.tab.c"
    break;

  case 80: /* RelG: '(' LogExp ')'  */
#line 240 "ast.y"
                        {(yyval.node)  = (yyvsp[-1].node) ;}
#line 1894 "y.tab.c"
    break;

  case 81: /* RelG: T_TRUE  */
#line 241 "ast.y"
                {(yyval.node)  = newnode("BOOL",NULL,NULL,1,"TRUE",0);}
#line 1900 "y.tab.c"
    break;

  case 82: /* RelG: T_FALSE  */
#line 242 "ast.y"
                 {(yyval.node)  = newnode("BOOL",NULL,NULL,1,"FALSE",0);}
#line 1906 "y.tab.c"
    break;

  case 83: /* Eqop: T_EE  */
#line 245 "ast.y"
             {(yyval.string) = (yyvsp[0].string);}
#line 1912 "y.tab.c"
    break;

  case 84: /* Eqop: T_NE  */
#line 246 "ast.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 1918 "y.tab.c"
    break;

  case 85: /* RelExp: ArithExp Relop ArithExp  */
#line 249 "ast.y"
                                {(yyval.node)  = newnode((yyvsp[-1].string),(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1924 "y.tab.c"
    break;

  case 86: /* Relop: T_LESS  */
#line 252 "ast.y"
               {(yyval.string) = (yyvsp[0].string);}
#line 1930 "y.tab.c"
    break;

  case 87: /* Relop: T_LTE  */
#line 253 "ast.y"
               {(yyval.string) = (yyvsp[0].string);}
#line 1936 "y.tab.c"
    break;

  case 88: /* Relop: T_GREATER  */
#line 254 "ast.y"
                   {(yyval.string) = (yyvsp[0].string);}
#line 1942 "y.tab.c"
    break;

  case 89: /* Relop: T_GTE  */
#line 255 "ast.y"
               {(yyval.string) = (yyvsp[0].string);}
#line 1948 "y.tab.c"
    break;

  case 90: /* Relop: T_EE  */
#line 256 "ast.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 1954 "y.tab.c"
    break;

  case 91: /* Relop: T_NE  */
#line 257 "ast.y"
              {(yyval.string) = (yyvsp[0].string);}
#line 1960 "y.tab.c"
    break;

  case 92: /* ArithExp: ArithExp '+' T  */
#line 260 "ast.y"
                        {(yyval.node)  = newnode("+",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1966 "y.tab.c"
    break;

  case 93: /* ArithExp: ArithExp '-' T  */
#line 261 "ast.y"
                        {(yyval.node)  = newnode("-",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1972 "y.tab.c"
    break;

  case 94: /* ArithExp: T  */
#line 262 "ast.y"
           {(yyval.node)  = (yyvsp[0].node) ;}
#line 1978 "y.tab.c"
    break;

  case 95: /* T: T '*' G  */
#line 265 "ast.y"
                 {(yyval.node)  = newnode("*",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1984 "y.tab.c"
    break;

  case 96: /* T: T '/' G  */
#line 266 "ast.y"
                 {(yyval.node)  = newnode("/",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1990 "y.tab.c"
    break;

  case 97: /* T: T '%' G  */
#line 267 "ast.y"
                 {(yyval.node)  = newnode("%",(yyvsp[-2].node) ,(yyvsp[0].node) ,0,"",0);}
#line 1996 "y.tab.c"
    break;

  case 98: /* T: G  */
#line 268 "ast.y"
           {(yyval.node)  = (yyvsp[0].node) ;}
#line 2002 "y.tab.c"
    break;

  case 99: /* G: '(' ArithExp ')'  */
#line 271 "ast.y"
                          {(yyval.node)  = (yyvsp[-1].node) ;}
#line 2008 "y.tab.c"
    break;

  case 100: /* G: T_ID T_DIMS  */
#line 272 "ast.y"
                      {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[-1].string),0);}
#line 2014 "y.tab.c"
    break;

  case 101: /* G: T_ID  */
#line 274 "ast.y"
              {(yyval.node)  = newnode("ID",NULL,NULL,1,(yyvsp[0].string),0);}
#line 2020 "y.tab.c"
    break;

  case 102: /* G: T_NUM  */
#line 275 "ast.y"
               {(yyval.node)  = newnode("NUM",NULL,NULL,1,"",1);}
#line 2026 "y.tab.c"
    break;

  case 103: /* G: T_REAL  */
#line 276 "ast.y"
                {(yyval.node) = newnode("REAL",NULL,NULL,1,"",1);}
#line 2032 "y.tab.c"
    break;


#line 2036 "y.tab.c"

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

#line 282 "ast.y"



void print(NODE* root,int sp)
{
	if(root!=NULL)
	{
		sp+=1;
		print(root->right,sp);
		for (int i=1;i<sp;i++)
		{
			fprintf(f,"-----");
		}
		fprintf(f,"├──%s \n",root->name);
		print(root->left,sp);
		
	}
}
		
		

void yyerror(char *s)
{
fprintf(stderr,"%s in line %d\n",s,yylineno);
}
int yywrap()
{
    return 1;
}


int main()
{
	f = fopen("ast.txt","w");
	char fname[100];
	fprintf(stderr,"\nEnter the name of file\n");
	scanf("%s",fname);
	yyin=fopen(fname,"r+");

	yyparse();
	
return 0;
}
