%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
extern int yylineno;
extern FILE *yyin;
int yylex();
void yyerror(char *s);
%}

%union
{
	int number;
	double real;
	char *string;
}

%token <number> T_NUM T_DIMS
%token <real> T_REAL
%token <string> T_ID T_FLOAT T_INT T_IMPORT T_DOUBLE T_BOOLEAN T_STRING T_CHAR T_IF T_ELSE T_DO T_WHILE T_RETURN T_PACKAGE T_CLASS T_PUBLIC T_PRIVATE T_PROTECTED T_STATIC T_VOID T_MAIN T_CONST T_TRUE T_FALSE T_NULL T_BREAK T_CONTINUE T_PRINTLN T_PRINT T_EXIT T_PE T_ME T_DE T_MULE T_PERCE T_AND T_OR T_NE T_GTE T_LTE T_EE T_NEW T_PID T_FINAL T_STR T_PLUS T_LESS T_GREATER
%type <string> Type print_id  ListVar Assign X  



%%

Prog:
	 Package Import Classes{fprintf(stderr,"EOF\n"); YYACCEPT;} 
	;


Package:
	 Package T_PACKAGE print_pid ';'
	|Package T_PACKAGE print_id ';'
	|
	;
	
Import:
	 Import T_IMPORT T_PID ';'
	|Import T_IMPORT print_id ';'
	|
	; 

Modifier:
	 T_PUBLIC Modifier1
	|T_PRIVATE Modifier1
	|T_PROTECTED Modifier1
	|Modifier1
	;

Modifier1:
	 T_STATIC Modifier2
	|Modifier2
	;

Modifier2:
	 T_FINAL
	|
	;

Classes:

	 Modifier T_CLASS print_id flower_paran_o_c ClassBody flower_paran_c_c Classes
	|Modifier T_CLASS error {yyclearin;} flower_paran_o_c {yyerrok;yyclearin;} ClassBody flower_paran_c_c Classes
	|Modifier error {yyclearin;} print_id {yyerrok;}flower_paran_o_c ClassBody flower_paran_c_c Classes
	|
	; 	

ClassBody:
	 GlobalVar ClassBody
	|MethodDec ClassBody
	|
	;

GlobalVar:
	 Modifier Declr ';' 
	;

MethodDec:
	 Modifier Type print_id  func_paran_o ParameterList func_paran_c flower_paran_o Statements flower_paran_c
	|Modifier T_VOID  print_id  func_paran_o ParameterList func_paran_c flower_paran_o Statements flower_paran_c
	|Modifier T_VOID  T_MAIN  func_paran_o T_STRING print_id T_DIMS func_paran_c flower_paran_o Statements flower_paran_c

	;


ParameterList:
	 Type print_id
	|Type error
	|Type print_id ',' ParameterList
	|Type error ',' {yyerrok;} ParameterList
	|
	;
	
	
Statements:
	 Statement Statements
	|Statement


	;
Statement:
	 Declr ';' {yyerrok;}
	|Assign ';'
  |OtherAssign ';'
	|T_IF '(' Cond ')' '{' Statements '}' T_ELSE '{' Statements '}'
	|T_IF '(' Cond ')' '{' Statements '}' error  '{' {yyerrok;} Statements '}' 
	//|error '(' Cond ')' '{' Statements '}' T_ELSE '{' Statements '}' 
	|T_DO '{' Statements '}' T_WHILE '(' Cond ')' ';'
	|T_DO '{'  Statements '}' error '(' {yyerrok;} Cond ')' ';'
	|T_RETURN Exp ';'
	|T_PRINTLN '(' PrintBlock ')' ';'
	|T_PRINT '(' PrintBlock ')' ';'
	|error 

	;

PrintBlock:
	 String '+' Exp
	|Exp T_PLUS String
	|Exp
	|String
	;


Declr:
	 Type ListVar
	|error 
	;

Type:
	 T_INT
	|T_FLOAT
	|T_DOUBLE
	|T_BOOLEAN
	|T_CHAR
	|T_STRING 	
	;
ListVar:
	 X 
	|Assign 
  	|ListVar ',' Assign  
  	|ListVar ',' X  
	|T_DIMS print_id {$$ = $2;}
	|T_DIMS T_DIMS print_id {$$ = $3;}
	|print_id T_DIMS '=' T_NEW Type T_DIMS {$$ = $1;}
	|T_DIMS print_id '=' T_NEW Type T_DIMS{$$ = $2;}
	;
X:
	 print_id
	|print_id T_DIMS
	|print_id T_DIMS T_DIMS 
	;
    
Assign:
	 print_id '=' PrintBlock{$$ = $1;}
  	|error {yyclearin;} '=' {yyerrok;} PrintBlock
	|print_id '=' T_NEW Type T_DIMS {$$ = $1;}
	|print_id T_DIMS '=' Exp {$$ = $1;}
	;
    
OtherAssign:
	 print_id T_PE ArithExp 
	|print_id T_ME ArithExp
	|print_id T_MULE ArithExp 
	|print_id T_DE ArithExp 
  |print_id T_PERCE ArithExp 
  ;

String:
	 T_STR
	;
	
Cond:
	 LogExp
	|error

	;
Exp: 
	LogExp
	|ArithExp
	;
LogExp:
	LogExp Logop EqExp0
	|EqExp0
	;
Logop:
	T_AND
	|T_OR
	;
EqExp0: 
	EqExp0 Eqop RelG
	|RelG
	;
RelG:
	RelExp
	|'(' LogExp ')'
	|T_TRUE
	|T_FALSE
	;
Eqop:
	T_EE
	|T_NE
	;
RelExp:
	ArithExp Relop ArithExp
	;
Relop:
	 T_LESS
	|T_LTE
	|T_GREATER
	|T_GTE
	|T_EE
	|T_NE
	;
ArithExp:
	 ArithExp '+' T
	|ArithExp '-' T
	|T
	;
T:
	 T '*' G
	|T '/' G
	|T '%' G
	|G
	;
G:
	 '(' ArithExp ')'
	|print_id T_DIMS 
	|print_id '.' print_id 
	|print_id 
	|T_NUM
	|T_REAL
	;
print_pid:
	T_PID; 

print_id:
	T_ID;

flower_paran_o:
	'{'	 ;

flower_paran_c:
	'}'	;
flower_paran_o_c:
	'{'	 ;

flower_paran_c_c:
	'}'	;
func_paran_o:
	'('	;
func_paran_c:
	')'	; 

%%


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
	char fname[100];
	fprintf(stderr,"\nEnter the name of file\n");
	scanf("%s",fname);
	yyin=fopen(fname,"r+");
	yyparse();
	return 0;
}
