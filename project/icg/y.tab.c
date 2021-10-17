/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "icg.y" /* yacc.c:339  */

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
void const_fold_prop();
char* evaluate(char* op, char* arg1, char* arg2, char* type);
int is_number(char* s);

typedef struct quad
{
	char op[10];
    char arg1[10];
    char arg2[10];
    char res[10];
    int flag;
    struct quad* next;
}quad;

quad* get_quad(quad* curr, char* res);
int check_assign(quad* curr,char* res);
void qdelete(quad* curr);
int check_usage(quad* curr, char* arg);
int block_usage(int block, char* res);
void eliminate();

quad *head;
int temp = 0;
int label = 0;
char* l1, *l2;
char* newTemp();
char* newLabel();
int flag = 1;
char scope[6] = "1.1.1";

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

void display(struct hash *,FILE* t);
void insert(struct hash *ht, int key, char* scope, char* name, char* type,char* val);
int search(struct hash *ht,int key, char* scope, char* name);
struct node* get_node(struct hash *ht,int key, char* scope, char* name);
void qinsert(char* op,char* arg1,char *arg2,char* res,int flag);
void qdisplay();
void delete_block(char* label);
char* extract_op(char* s);
void update_st();
void filter_st();

FILE *t;
FILE *q;
FILE *o;
FILE *e;
FILE *u;

#line 151 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_NUM = 258,
    T_DIMS = 259,
    T_REAL = 260,
    T_ID = 261,
    T_FLOAT = 262,
    T_INT = 263,
    T_IMPORT = 264,
    T_DOUBLE = 265,
    T_BOOLEAN = 266,
    T_STRING = 267,
    T_CHAR = 268,
    T_IF = 269,
    T_ELSE = 270,
    T_DO = 271,
    T_WHILE = 272,
    T_RETURN = 273,
    T_PACKAGE = 274,
    T_CLASS = 275,
    T_PUBLIC = 276,
    T_PRIVATE = 277,
    T_PROTECTED = 278,
    T_STATIC = 279,
    T_VOID = 280,
    T_MAIN = 281,
    T_CONST = 282,
    T_TRUE = 283,
    T_FALSE = 284,
    T_NULL = 285,
    T_BREAK = 286,
    T_CONTINUE = 287,
    T_PRINTLN = 288,
    T_PRINT = 289,
    T_EXIT = 290,
    T_PE = 291,
    T_ME = 292,
    T_DE = 293,
    T_MULE = 294,
    T_PERCE = 295,
    T_AND = 296,
    T_OR = 297,
    T_NE = 298,
    T_GTE = 299,
    T_LTE = 300,
    T_EE = 301,
    T_NEW = 302,
    T_PID = 303,
    T_FINAL = 304,
    T_STR = 305,
    T_PLUS = 306,
    T_LESS = 307,
    T_GREATER = 308
  };
#endif
/* Tokens.  */
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

/* Copy the second part of user declarations.  */

#line 308 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    99,   100,   101,   105,   106,   107,   111,
     112,   113,   114,   118,   119,   123,   124,   129,   130,   134,
     135,   136,   140,   144,   145,   146,   150,   151,   155,   156,
     159,   160,   161,   162,   162,   162,   162,   163,   163,   163,
     164,   165,   166,   170,   171,   172,   173,   177,   185,   186,
     187,   188,   189,   190,   194,   195,   196,   197,   198,   199,
     200,   201,   204,   206,   207,   211,   212,   213,   217,   218,
     219,   220,   221,   226,   230,   233,   234,   237,   239,   242,
     243,   246,   248,   251,   252,   253,   254,   257,   258,   261,
     265,   266,   267,   268,   269,   270,   274,   277,   280,   284,
     287,   290,   292,   296,   297,   298,   300,   301,   305,   308,
     311,   314,   316,   319,   321,   323
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUM", "T_DIMS", "T_REAL", "T_ID",
  "T_FLOAT", "T_INT", "T_IMPORT", "T_DOUBLE", "T_BOOLEAN", "T_STRING",
  "T_CHAR", "T_IF", "T_ELSE", "T_DO", "T_WHILE", "T_RETURN", "T_PACKAGE",
  "T_CLASS", "T_PUBLIC", "T_PRIVATE", "T_PROTECTED", "T_STATIC", "T_VOID",
  "T_MAIN", "T_CONST", "T_TRUE", "T_FALSE", "T_NULL", "T_BREAK",
  "T_CONTINUE", "T_PRINTLN", "T_PRINT", "T_EXIT", "T_PE", "T_ME", "T_DE",
  "T_MULE", "T_PERCE", "T_AND", "T_OR", "T_NE", "T_GTE", "T_LTE", "T_EE",
  "T_NEW", "T_PID", "T_FINAL", "T_STR", "T_PLUS", "T_LESS", "T_GREATER",
  "';'", "','", "'('", "')'", "'{'", "'}'", "'+'", "'='", "'-'", "'*'",
  "'/'", "'%'", "$accept", "Prog", "Package", "Import", "Modifier",
  "Modifier1", "Modifier2", "Classes", "ClassBody", "GlobalVar",
  "MethodDec", "ParameterList", "Statements", "Statement", "$@1", "$@2",
  "$@3", "$@4", "$@5", "PrintBlock", "Declr", "Type", "ListVar", "X",
  "Assign", "OtherAssign", "String", "Cond", "Exp", "LogExp", "Logop",
  "EqExp0", "RelG", "Eqop", "RelExp", "Relop", "ArithExp", "T", "G",
  "print_pid", "print_id", "flower_paran_o", "flower_paran_c",
  "flower_paran_o_c", "flower_paran_c_c", "func_paran_o", "func_paran_c", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    59,    44,    40,    41,   123,   125,
      43,    61,    45,    42,    47,    37
};
# endif

#define YYPACT_NINF -150

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -150,    16,     1,  -150,     4,   139,  -150,  -150,   -27,   -20,
      12,    -5,    -5,    -5,   -11,  -150,    60,  -150,  -150,  -150,
    -150,  -150,    34,    38,  -150,  -150,  -150,  -150,    90,  -150,
    -150,    43,  -150,   155,   244,    49,   155,   155,  -150,  -150,
    -150,  -150,  -150,  -150,    69,    61,   115,  -150,   151,  -150,
    -150,    62,    62,  -150,   136,    72,  -150,  -150,    10,  -150,
    -150,   122,   200,    90,    82,    90,     7,    88,   200,    90,
      95,    90,  -150,   119,  -150,  -150,     9,  -150,    94,  -150,
    -150,  -150,  -150,   200,  -150,   125,  -150,   111,   129,   114,
       2,  -150,  -150,   188,    22,  -150,   191,    95,   192,  -150,
     134,   142,   200,    11,   200,  -150,   195,    41,   141,   125,
     152,  -150,  -150,   125,  -150,  -150,   125,  -150,  -150,  -150,
    -150,  -150,  -150,    25,    25,    25,    25,    25,    25,  -150,
     134,    95,  -150,   212,   200,   201,   125,   202,  -150,  -150,
    -150,  -150,  -150,     2,   188,  -150,    25,    22,    22,   105,
    -150,  -150,  -150,   212,   134,   159,   158,   125,   161,   171,
     170,   212,   181,   115,   182,   183,    17,  -150,  -150,  -150,
      50,   170,   212,   125,  -150,   184,   108,   108,  -150,  -150,
    -150,  -150,    13,  -150,  -150,   178,    25,    25,    25,    25,
      25,  -150,   170,   185,   114,   212,  -150,   186,   187,   105,
     105,   105,   105,   105,  -150,   189,   190,   199,   204,  -150,
     242,  -150,  -150,   212,   205,  -150,   125,   203,   206,   245,
    -150,   207,   210,  -150,  -150,   212,   208,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     8,     1,     0,    16,   109,   108,     0,     0,
       0,    16,    16,    16,    16,    15,     0,    12,    14,     2,
       3,     4,     0,     0,     9,    10,    11,    13,     0,     6,
       7,     0,   112,    16,     0,     0,    16,    16,    49,    48,
      50,    51,    53,    52,     0,     0,     0,   113,    16,    19,
      20,     0,     0,    22,     0,    47,    54,    55,    62,    17,
     114,     0,     0,     0,    58,     0,    63,     0,     0,     0,
       0,     0,    59,     0,    57,    56,    62,    64,     0,   106,
     107,    85,    86,     0,    73,     0,    65,    46,    45,    75,
      78,    82,    83,    76,    98,   102,   105,     0,     0,   115,
       0,    26,     0,    63,     0,    67,     0,     0,     0,     0,
       0,    79,    80,     0,    88,    87,     0,    95,    93,    91,
      94,    90,    92,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   110,     0,     0,     0,     0,     0,    66,    84,
     103,    43,    44,    77,     0,    81,     0,    96,    97,    89,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,    27,    61,    60,
       0,     0,     0,     0,    37,     0,     0,     0,   111,    24,
      28,    30,    62,    31,    32,     0,     0,     0,     0,     0,
       0,    23,     0,     0,    74,     0,    40,     0,     0,    68,
      69,    71,    70,    72,    25,     0,     0,     0,     0,    33,
       0,    41,    42,     0,     0,    34,     0,     0,     0,     0,
      38,     0,     0,    35,    39,     0,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,  -150,     3,   113,   252,   220,   133,  -150,
    -150,   -61,  -149,  -150,  -150,  -150,  -150,  -150,  -150,     6,
     236,   -25,  -150,   209,   -43,  -150,   162,    55,   -73,   -83,
    -150,   160,   163,  -150,  -150,  -150,   -84,    66,    19,  -150,
      -4,  -105,  -145,  -150,  -150,   -19,   -62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    34,    17,    18,    19,    35,    36,
      37,    70,   160,   161,   213,   217,   225,   195,   222,    86,
     162,   163,    55,    56,   164,   165,    87,   193,    88,    89,
     113,    90,    91,   116,    92,   125,    93,    94,    95,     8,
      96,   133,   179,    33,    48,    61,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,   108,   107,    57,   171,   105,    23,    97,    16,    46,
       6,    77,   180,   103,    66,    77,     3,    66,     6,    14,
       4,   185,    75,   192,    31,   153,   191,    20,    79,   144,
      80,     6,   144,    62,    21,   130,   141,    71,    15,    68,
      52,   149,    58,    71,    15,   114,   206,   204,   115,   172,
      64,    16,     7,   186,   187,   188,   189,   190,   106,    72,
      22,    76,   170,   105,   215,    98,    60,   101,    78,   154,
      67,    67,   136,   167,    67,     6,   226,   135,    67,   137,
      28,   146,   111,   112,   175,   126,   127,   128,    29,   144,
     194,    79,    30,    80,     6,    51,     6,    79,   139,    80,
       6,    32,   199,   200,   201,   202,   203,   140,    47,    71,
     123,    79,   124,    80,     6,    53,    81,    82,    60,    54,
      57,     6,    81,    82,    24,    25,    26,    65,    79,   166,
      80,     6,   144,   194,    69,    83,    81,    82,    84,   -18,
      63,   104,     6,    73,    85,   150,   151,   152,    10,   166,
      85,   -18,    99,    81,    82,   111,   112,   166,    84,   182,
      11,    12,    13,    14,    85,   123,   102,   124,   166,    49,
      50,   109,    11,    12,    13,    14,    11,    12,    13,    14,
     110,    85,   197,   198,   117,   118,   119,   120,    15,   147,
     148,   166,   132,   121,   122,   129,   131,   134,   140,   138,
      15,   123,    84,   124,    15,   168,   169,    38,    39,   166,
      40,    41,    42,    43,   -21,   173,   174,   176,     6,    38,
      39,   166,    40,    41,    42,    43,   155,   177,   156,   178,
     157,   117,   118,   119,   120,   181,   183,   184,   196,   136,
     121,   122,   205,   207,   208,   158,   159,   209,   123,   210,
     124,    38,    39,   211,    40,    41,    42,    43,   212,   214,
     221,   216,   219,   220,   224,   223,    27,   227,    59,    44,
      45,   218,   142,   143,    74,     0,     0,     0,     0,   145
};

static const yytype_int16 yycheck[] =
{
       4,    85,    85,    46,   153,    78,    10,    68,     5,    34,
       6,     4,   161,     4,     4,     4,     0,     4,     6,    24,
      19,     4,    65,   172,    28,   130,   171,    54,     3,   113,
       5,     6,   116,    52,    54,    97,   109,    62,    49,    58,
      44,   125,    46,    68,    49,    43,   195,   192,    46,   154,
      54,    48,    48,    36,    37,    38,    39,    40,    83,    63,
      48,    65,   146,   136,   213,    69,    56,    71,    61,   131,
      61,    61,    61,   134,    61,     6,   225,   102,    61,   104,
      20,    56,    41,    42,   157,    63,    64,    65,    54,   173,
     173,     3,    54,     5,     6,    26,     6,     3,    57,     5,
       6,    58,   186,   187,   188,   189,   190,    57,    59,   134,
      60,     3,    62,     5,     6,    54,    28,    29,    56,     4,
     163,     6,    28,    29,    11,    12,    13,    55,     3,   133,
       5,     6,   216,   216,    12,    47,    28,    29,    50,     0,
       4,    47,     6,    61,    56,   126,   127,   128,     9,   153,
      56,     0,    57,    28,    29,    41,    42,   161,    50,   163,
      21,    22,    23,    24,    56,    60,    47,    62,   172,    36,
      37,    60,    21,    22,    23,    24,    21,    22,    23,    24,
      51,    56,   176,   177,    43,    44,    45,    46,    49,   123,
     124,   195,    58,    52,    53,     4,     4,    55,    57,     4,
      49,    60,    50,    62,    49,     4,     4,     7,     8,   213,
      10,    11,    12,    13,    59,    56,    58,    56,     6,     7,
       8,   225,    10,    11,    12,    13,    14,    56,    16,    59,
      18,    43,    44,    45,    46,    54,    54,    54,    54,    61,
      52,    53,    57,    57,    57,    33,    34,    58,    60,    59,
      62,     7,     8,    54,    10,    11,    12,    13,    54,    17,
      15,    56,    59,    57,    54,    58,    14,    59,    48,    25,
      34,   216,   110,   113,    65,    -1,    -1,    -1,    -1,   116
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    67,    68,     0,    19,    69,     6,    48,   105,   106,
       9,    21,    22,    23,    24,    49,    70,    71,    72,    73,
      54,    54,    48,   106,    71,    71,    71,    72,    20,    54,
      54,   106,    58,   109,    70,    74,    75,    76,     7,     8,
      10,    11,    12,    13,    25,    86,    87,    59,   110,    74,
      74,    26,   106,    54,     4,    88,    89,    90,   106,    73,
      56,   111,   111,     4,   106,    55,     4,    61,   111,    12,
      77,    87,   106,    61,    89,    90,   106,     4,    61,     3,
       5,    28,    29,    47,    50,    56,    85,    92,    94,    95,
      97,    98,   100,   102,   103,   104,   106,    77,   106,    57,
     112,   106,    47,     4,    47,    94,    87,    95,   102,    60,
      51,    41,    42,    96,    43,    46,    99,    43,    44,    45,
      46,    52,    53,    60,    62,   101,    63,    64,    65,     4,
     112,     4,    58,   107,    55,    87,    61,    87,     4,    57,
      57,    94,    92,    97,   102,    98,    56,   103,   103,   102,
     104,   104,   104,   107,   112,    14,    16,    18,    33,    34,
      78,    79,    86,    87,    90,    91,   106,    77,     4,     4,
     102,    78,   107,    56,    58,    94,    56,    56,    59,   108,
      78,    54,   106,    54,    54,     4,    36,    37,    38,    39,
      40,   108,    78,    93,    95,    83,    54,    85,    85,   102,
     102,   102,   102,   102,   108,    57,    78,    57,    57,    58,
      59,    54,    54,    80,    17,    78,    56,    81,    93,    59,
      57,    15,    84,    58,    54,    82,    78,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    75,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    80,    81,    82,    79,    83,    84,    79,
      79,    79,    79,    85,    85,    85,    85,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    89,    90,    90,    90,    91,    91,
      91,    91,    91,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    99,    99,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   106,
     107,   108,   109,   110,   111,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     4,     0,     4,     4,     0,     2,
       2,     2,     1,     2,     1,     1,     0,     7,     0,     2,
       2,     0,     3,     9,     9,    11,     2,     4,     2,     1,
       2,     2,     2,     0,     0,     0,    14,     0,     0,    11,
       3,     5,     5,     3,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       6,     6,     1,     2,     3,     3,     5,     4,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 94 "icg.y" /* yacc.c:1646  */
    {fprintf(stderr,"EOF\n"); YYACCEPT;}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 162 "icg.y" /* yacc.c:1646  */
    {l1 = newLabel(); qinsert("ifFalse",(yyvsp[-2]).string,"",l1,flag);flag++;}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "icg.y" /* yacc.c:1646  */
    {l2 = newLabel(); qinsert("goto","","",l2,flag);flag++;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "icg.y" /* yacc.c:1646  */
    {qinsert("Label","","",l1,++flag);  }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 162 "icg.y" /* yacc.c:1646  */
    {qinsert("Label","","",l2,++flag);  }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "icg.y" /* yacc.c:1646  */
    {l1 = newLabel();qinsert("Label","","",l1,++flag);  }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 163 "icg.y" /* yacc.c:1646  */
    {l2 = newLabel(); qinsert("ifFalse",(yyvsp[-1]).string,"",l2,flag);flag++;qinsert("goto","","",l1,flag);qinsert("Label","","",l2,++flag);  }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 194 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[0]).string,(yyvsp[-1]).string,"(null)");}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 195 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[0]).string,(yyvsp[0]).type,"(null)");}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 196 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[0]).string,(yyvsp[-3]).string,"(null)");}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 197 "icg.y" /* yacc.c:1646  */
    { insert(ht, num_extract(scope), scope, (yyvsp[0]).string,(yyvsp[-3]).string,"(null)");}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[0]).string,(yyvsp[-2]).string,"(null)");}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 199 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[0]).string,(yyvsp[-3]).string,"(null)");}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 200 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[-5]).string,(yyvsp[-6]).string,"(null)");}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 201 "icg.y" /* yacc.c:1646  */
    {insert(ht, num_extract(scope), scope, (yyvsp[-4]).string,(yyvsp[-6]).string,"(null)");}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 211 "icg.y" /* yacc.c:1646  */
    {qinsert("", (yyvsp[0]).string, "", (yyvsp[-2]).string,flag);  (yyval).string=(yyvsp[-2]).string;(yyval).type = (yyvsp[-3]).string;}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 217 "icg.y" /* yacc.c:1646  */
    {qinsert(extract_op((yyvsp[-1]).string), (yyvsp[-2]).string, (yyvsp[0]).string, (yyvsp[-2]).string,flag);  (yyval).string = (yyvsp[-2]).string;}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 218 "icg.y" /* yacc.c:1646  */
    {qinsert(extract_op((yyvsp[-1]).string), (yyvsp[-2]).string, (yyvsp[0]).string, (yyvsp[-2]).string,flag);  (yyval).string = (yyvsp[-2]).string;}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 219 "icg.y" /* yacc.c:1646  */
    {qinsert(extract_op((yyvsp[-1]).string), (yyvsp[-2]).string, (yyvsp[0]).string, (yyvsp[-2]).string,flag);  (yyval).string = (yyvsp[-2]).string;}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 220 "icg.y" /* yacc.c:1646  */
    {qinsert(extract_op((yyvsp[-1]).string), (yyvsp[-2]).string, (yyvsp[0]).string, (yyvsp[-2]).string,flag);  (yyval).string = (yyvsp[-2]).string;}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 221 "icg.y" /* yacc.c:1646  */
    {qinsert(extract_op((yyvsp[-1]).string), (yyvsp[-2]).string, (yyvsp[0]).string, (yyvsp[-2]).string,flag);  (yyval).string = (yyvsp[-2]).string;}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 237 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert((yyvsp[-1]).string, (yyvsp[-2]).string, (yyvsp[0]).string, s, flag);  (yyval).string = s;
    insert(ht, num_extract(scope), scope,s,"boolean","(null)");}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 246 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert((yyvsp[-1]).string, (yyvsp[-2]).string, (yyvsp[0]).string, s, flag);  (yyval).string = s;
    insert(ht, num_extract(scope), scope,s,"boolean","(null)");}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 252 "icg.y" /* yacc.c:1646  */
    {(yyval).string = (yyvsp[-1]).string;}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 261 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert((yyvsp[-1]).string, (yyvsp[-2]).string, (yyvsp[0]).string, s, flag);  (yyval).string = s;
     insert(ht, num_extract(scope), scope,s,"boolean","(null)");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 274 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert("+", (yyvsp[-2]).string, (yyvsp[0]).string, s,flag);  (yyval).string = s;
     if(strcmp((yyvsp[-2]).type,"double")==0)(yyval).type = "double"; else if(strcmp((yyvsp[0]).type,"double")==0)(yyval).type = "double";else (yyval).type = "int";
     insert(ht, num_extract(scope), scope,s,(yyval).type,"(null)");}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 277 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert("-", (yyvsp[-2]).string, (yyvsp[0]).string, s,flag);  (yyval).string = s;
     if(strcmp((yyvsp[-2]).type,"double")==0)(yyval).type = "double"; else if(strcmp((yyvsp[0]).type,"double")==0)(yyval).type = "double";else (yyval).type = "int";
     insert(ht, num_extract(scope), scope,s,(yyval).type,"(null)");}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 280 "icg.y" /* yacc.c:1646  */
    {(yyval).type = (yyvsp[0]).type;(yyval).string = (yyvsp[0]).string;}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 284 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert("*", (yyvsp[-2]).string, (yyvsp[0]).string, s, flag); (yyval).string = s;
     if(strcmp((yyvsp[-2]).type,"double")==0)(yyval).type = "double"; else if(strcmp((yyvsp[0]).type,"double")==0)(yyval).type = "double";else (yyval).type = "int";
     insert(ht, num_extract(scope), scope,s,(yyval).type,"(null)");}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 287 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert("/", (yyvsp[-2]).string, (yyvsp[0]).string, s, flag); (yyval).string = s;
     if(strcmp((yyvsp[-2]).type,"double")==0)(yyval).type = "double"; else if(strcmp((yyvsp[0]).type,"double")==0)(yyval).type = "double";else (yyval).type = "int";
     insert(ht, num_extract(scope), scope,s,(yyval).type,"(null)");}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 290 "icg.y" /* yacc.c:1646  */
    {char *s = newTemp();qinsert("%", (yyvsp[-2]).string, (yyvsp[0]).string, s, flag); (yyval).string = s;(yyval).type = (yyvsp[-2]).type;
    insert(ht, num_extract(scope), scope,s,(yyval).type,"(null)");}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 292 "icg.y" /* yacc.c:1646  */
    {(yyval).type = (yyvsp[0]).type;(yyval).string = (yyvsp[0]).string;}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 296 "icg.y" /* yacc.c:1646  */
    {(yyval).type = (yyvsp[-1]).type;(yyval).string = (yyvsp[-1]).string;}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 298 "icg.y" /* yacc.c:1646  */
    {struct node* node = get_node(ht,num_extract(scope),scope,(yyvsp[0]).string);
  		(yyval).type = node->type;}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 300 "icg.y" /* yacc.c:1646  */
    {char *c = malloc(sizeof(char)*10);sprintf(c,"%d",(yyvsp[0]).number);(yyval).string = c;(yyval).type = "int";}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 301 "icg.y" /* yacc.c:1646  */
    {char *c = malloc(sizeof(char)*10);sprintf(c,"%f",(yyvsp[0]).real);(yyval).string = c;(yyval).type = "double";}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1787 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 326 "icg.y" /* yacc.c:1906  */


quad* get_quad(quad* curr, char* res)
{
    quad *temp = head;
    quad *new_quad = curr;
    while(temp!=curr)
    {
        if(strcmp(temp->res,res) == 0 && is_number(temp->arg1) && strcmp(temp->arg2,"") == 0)
            new_quad = temp;
        else if(strcmp(temp->res,res) == 0)
            new_quad = curr;
        temp = temp->next;
    }
    return new_quad;
}

int check_assign(quad* curr,char* res)
{
    quad *temp = curr;
    int count = 1;
    if(strcmp(temp->res,res) == 0 && (strcmp(temp->arg1,res) == 0 || strcmp(temp->arg2,res) == 0))
        return count;
    temp = temp->next;
    while(temp!=NULL)
    {
        if(strcmp(temp->res,res) == 0)
            return count;
        temp = temp->next;
        count++;
    }
    return 0;
}

void qdelete(quad* curr)
{
    if(head == curr)
	head = curr->next;
    else
    {
    quad* temp = head;
    while(temp->next!=curr)
        temp = temp->next;
    temp->next = curr->next;
    
    }
free(curr);
}

int check_usage(quad* curr, char* arg)
{
    quad* temp = curr;
    if(strcmp(temp->arg1,arg) == 0 || strcmp(temp->arg2,arg) == 0)
        return 1;
    temp = temp->next;
    int count = 1;
    while(temp!=NULL)
    {
        if(strcmp(temp->arg1,arg) == 0 || strcmp(temp->arg2,arg) == 0)
            return count;
        temp = temp->next;
        count++;
    }
    return 0;
}

void delete_block(char* label)
{
    quad* temp = head,*temp_quad;
    int block;
    while(!(strcmp(temp->res,label)==0 && strcmp(temp->op,"Label")==0))
        temp = temp->next;
    block = temp->flag;
    while(temp!=NULL && temp->flag == block)
    {
        temp_quad = temp;
        temp = temp->next;
        qdelete(temp_quad);
    }
}

int block_usage(int block, char* res)
{
    quad* temp = head;
    while(temp!=NULL && temp->flag!=block)
        temp = temp->next;
    while(temp!=NULL && temp->flag==block)
    {
        if(strcmp(temp->arg1,res) == 0 || strcmp(temp->arg2,res) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void eliminate()
{
    quad* temp = head,*temp_quad;
    char t[10];
    int u,a,block,b;
    while(temp!=NULL)
    {
        if(strcmp(temp->op,"ifFalse") == 0)
        {
		//printf("In iffalse\n");
            if(strcmp(temp->arg1,"false") == 0)
            {
		//printf("In iffalse false\n");
                temp_quad = temp;
                temp = temp->next;
                qdelete(temp_quad);
                block = temp->flag; 
                while(temp!=NULL && temp->flag==block)
                {
			//printf("In iffalse false while\n");
                    temp_quad = temp;
                    temp = temp->next;
                    qdelete(temp_quad);
                }
            }
            else if(strcmp(temp->arg1,"true") == 0)
            {
		//printf("In iffalse true\n");
                strcpy(t,temp->res);
                temp_quad = temp;
                temp = temp->next;
                qdelete(temp_quad);
                delete_block(t);
            }
	    else
		temp = temp->next;
        }
        else if(strcmp(temp->op,"Label") == 0 || strcmp(temp->op,"goto") == 0){printf("In label and goto\n");temp = temp->next;}
        else
        {
		//printf("In other parts\n");
            u = check_usage(temp,temp->res);
            //printf("Check usage for %s count: %d\n",temp->res,u);
            a = check_assign(temp,temp->res);
            b = block_usage(temp->flag,temp->res);
            //printf("Check assign for %s count: %d\n",temp->res,a);
            if(b){temp = temp->next;}
            else if(a)
            {
                if(u == 0 || a<u)
                {
                    temp_quad = temp;
                    temp = temp->next;
                    qdelete(temp_quad);
                }
                else
                    temp = temp->next;
            }
            else if(u)
            {
                temp = temp->next;
            }
            else
            {
                temp_quad = temp;
                temp = temp->next;
                qdelete(temp_quad);
            }
        }
    }
}

char* evaluate(char* op, char* arg1, char* arg2, char* type)
{
    char* s = malloc(sizeof(char)*10);
    if(strcmp(type,"int") == 0)
    {
        int a,b,res;
        a = atoi(arg1);
        b = atoi(arg2);
        if(strcmp(op,"+") == 0)res = a+b;
        if(strcmp(op,"-") == 0)res = a-b;
        if(strcmp(op,"*") == 0)res = a*b;
        if(strcmp(op,"/") == 0)res = a/b;
        sprintf(s,"%d",res);
        return s;
    }
    if(strcmp(type,"double") == 0)
    {
        double a,b,res;
        a = atof(arg1);
        b = atof(arg2);
        if(strcmp(op,"+") == 0)res = a+b;
        if(strcmp(op,"-") == 0)res = a-b;
        if(strcmp(op,"*") == 0)res = a*b;
        if(strcmp(op,"/") == 0)res = a/b;
        sprintf(s,"%f",res);
        return s;
    }
    if(strcmp(type,"boolean") == 0)
    {
        if(is_number(arg1))
        {
            int a,b,res;
            a = atoi(arg1);
            b = atoi(arg2);
            if(strcmp(op,"<") == 0)if(a<b)res = 1;else res = 0;
            if(strcmp(op,">") == 0)if(a>b)res = 1;else res = 0;
            if(strcmp(op,"<=") == 0)if(a<=b)res = 1;else res = 0;
            if(strcmp(op,">=") == 0)if(a>=b)res = 1;else res = 0;
            if(strcmp(op,"==") == 0)if(a==b)res = 1;else res = 0;
            if(strcmp(op,"!=") == 0)if(a!=b)res = 1;else res = 0;
            if(res == 1)
            strcpy(s,"true");
            else
            strcpy(s,"false");
            return s;
        }
        else
        {
        int a,b,res;
        if(strcmp(arg1,"true") == 0)a = 1;else a = 0;
        if(strcmp(arg2,"true") == 0)b = 1;else b = 0;
        if(strcmp(op,"&&") == 0)if(a == 1 && b == 1)res = 1;else res = 0;
        if(strcmp(op,"||") == 0)if(a == 1 || b == 1)res = 1;else res = 0;
        if(strcmp(op,"==") == 0)if(a == b)res = 1;else res = 0;
        if(strcmp(op,"!=") == 0)if(a!=b)res = 1;else res = 0;
        if(res == 1)
        strcpy(s,"true");
        else
        strcpy(s,"false");
        return s;
        }
    }
}

void const_fold_prop()
{
    quad *temp = head, *temp_quad;
    struct node* node;
    int curr_block = -1;
    while(temp!=NULL)
    {
        if(curr_block!=temp->flag)curr_block = temp->flag;
        if(is_number(temp->arg1))
        {
            if(is_number(temp->arg2))
            {
                node = get_node(ht,num_extract(scope),scope,temp->res);
                strcpy(temp->arg1,evaluate(temp->op,temp->arg1,temp->arg2,node->type));
                strcpy(temp->op,"");
                strcpy(temp->arg2,"");
            }
            else if(strcmp(temp->arg2,"") == 0){}
            else
            {
                if(!check_assign(temp,temp->arg2))
                {    temp_quad = get_quad(temp,temp->arg2);
                    if(temp_quad!=temp)
                    {
                        node = get_node(ht,num_extract(scope),scope,temp->res);
                        strcpy(temp->arg1,evaluate(temp->op,temp->arg1,temp_quad->arg1,node->type));
                        strcpy(temp->op,"");
                        strcpy(temp->arg2,"");
                    }
                }
            }
        }
        else
        {
            if(!is_number(temp->arg2) && strcmp(temp->arg2,"") != 0)
            {
                if(!check_assign(temp,temp->arg2))
                {    temp_quad = get_quad(temp,temp->arg2);
                    if(temp_quad!=temp)
                        strcpy(temp->arg2,temp_quad->arg1);
                }
            }
            if(!check_assign(temp,temp->arg1))
            {    temp_quad = get_quad(temp,temp->arg1);
                if(temp_quad!=temp)
                {
                    strcpy(temp->arg1,temp_quad->arg1);  
                    if(is_number(temp->arg2))
                    {
                        node = get_node(ht,num_extract(scope),scope,temp->res);
                        strcpy(temp->arg1,evaluate(temp->op,temp->arg1,temp->arg2,node->type));
                        strcpy(temp->op,"");
                        strcpy(temp->arg2,"");
                    }
                }
            }
        }
        temp = temp->next;
    }
}

int is_number(char* s)
{
if((s[0]>=48 && s[0]<=57)|| s[0]==45)
	return 1;
else if(strcmp(s,"true") == 0 || strcmp(s,"false") == 0)
	return 1;
return 0;
}



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


void display(struct hash* ht,FILE* t)
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
          if(strcmp(temp->type,"int")==0)s=4;
          else if(strcmp(temp->type,"double")==0)s=8;
          else if(strcmp(temp->type,"boolean")==0)s=1;
          else if(strcmp(temp->type,"short")==0)s=1;
          else if(strcmp(temp->type,"long")==0)s=8;
          else if(strcmp(temp->type,"float")==0)s=4;
          else if(strcmp(temp->type,"char")==0)s=2;
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
  
char* newTemp()
{
	char *t = malloc(sizeof(char)*5);
	t[0]= 't';
	t[1]='\0';
	char c[10];
 	sprintf(c,"%d",++temp);
    strcat(t,c);
    return t;
}

char* newLabel()
{
	char *t = malloc(sizeof(char)*5);
	t[0]= 'L';
	t[1]='\0';
	char c[10];
 	sprintf(c,"%d",++label);
    strcat(t,c);
    return t;
}


void qinsert(char* op,char* arg1,char* arg2,char* res,int flag)
{
	quad *temp,*q;
	temp = malloc(sizeof(quad));
    strcpy(temp->op,op);
    strcpy(temp->arg1,arg1);
    strcpy(temp->arg2,arg2);
    strcpy(temp->res,res);
    temp->flag = flag;

	if(head==NULL)
    {
    	head = temp;
    }
    else
    {
    	q = head;
        while(q->next!=NULL)
        {
        	q = q->next;
        }
        q->next = temp;
    }
    	
}

void qdisplay(FILE *q)
{
	quad *temp = head;
    	while(temp!=NULL)
        {
        	if(strcmp(temp->op,"ifFalse") == 0)
            {
            	fprintf(q,"%s %s %s %s",temp->op,temp->arg1,"goto",temp->res);
            	fprintf(q,"\n");
            }
            else if(strcmp(temp->op,"goto") == 0)
            {	
            	fprintf(q,"%s %s",temp->op,temp->res);
            	fprintf(q,"\n");
            }
            else if(strcmp(temp->op,"Label")==0)
            {
            	fprintf(q,"%s :",temp->res);
            	fprintf(q,"\n");
            }
            else
            {
              fprintf(q,"%s = %s %s %s",temp->res,temp->arg1,temp->op,temp->arg2);
              fprintf(q,"\n");
            }
            temp = temp->next;
        }
}

char* extract_op(char* s)
{
    char* s1 = malloc(sizeof(char)*2);
    s1[0] = s[0];
    s1[1] = '\0';
    return s1;
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

void filter_st()
{
    int i;
    struct node* temp, *node_temp, *prev;
    for(i = 0;i<size;i++)
    {
        temp = ht[i].head;
        prev = NULL;
        while(temp!=NULL)
        {
            if(temp->value[0] == '(')
            {
                if(temp == ht[i].head)
                {
                    node_temp = temp;
                    ht[i].head = temp->next;
                    temp = temp->next;
                    free(node_temp);
                }
                else
                {
                    prev->next = temp->next;
                    free(temp);
                    temp = prev->next;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

void update_st()
{
    quad* temp = head;
    struct node* node;
    while(temp!=NULL)
    {
	printf("Quad : %s Op: %s arg1 :%s arg2:%s \n",temp->res,temp->op,temp->arg1,temp->arg2);
        if(!(strcmp(temp->op,"ifFalse") == 0 || strcmp(temp->op,"goto") == 0 || strcmp(temp->op,"Label") == 0))
        {
		printf("Update in symbol table: %s\n",temp->res);
            node = get_node(ht,num_extract(scope),scope,temp->res);
            if(is_number(temp->arg1) && strcmp(temp->arg2,"") == 0)
                strcpy(node->value,temp->arg1);
            else if(!is_number(node->value))
                strcpy(node->value,"NA");
        }
        temp = temp->next;
    }
    filter_st();
}

int main()
{
	
	t = fopen("symboltable.txt","w");
    	q = fopen("icgtable.txt","w");
	o = fopen("constant.txt","w");
	e = fopen("dead_code.txt","w");
	u = fopen("updated_st.txt","w");
	ht = malloc(size* sizeof(struct hash));
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
	display(ht,t);
	qdisplay(q);
	const_fold_prop();
	qdisplay(o);
	eliminate();
	qdisplay(e);
	update_st();
	display(ht,u);
return 0;
}
  

