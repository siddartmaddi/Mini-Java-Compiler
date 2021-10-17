%{
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
%}



%union
{
	int number;
	double real;
	char *string;
	NODE* node;
}

%token <number> T_NUM T_DIMS
%token <real> T_REAL
%token <string> T_ID T_FLOAT T_INT T_IMPORT T_DOUBLE T_BOOLEAN T_STRING T_CHAR T_IF T_ELSE T_DO T_WHILE T_RETURN T_PACKAGE T_CLASS T_PUBLIC T_PRIVATE T_PROTECTED T_STATIC T_VOID T_MAIN T_CONST T_TRUE T_FALSE T_NULL T_BREAK T_CONTINUE T_PRINTLN T_PRINT T_EXIT T_PE T_ME T_DE T_MULE T_PERCE T_AND T_OR T_NE T_GTE T_LTE T_EE T_NEW T_PID T_FINAL T_STR T_PLUS T_LESS T_GREATER
//%type <string> Type T_ID ListVar Assign X

%type <node> Classes ClassBody GlobalVar MethodDec MainParams ParameterList List Statements Statement IfStatement PrintBlock Declr Type ListVar X Assign String Cond Exp LogExp EqExp0 RelG RelExp ArithExp T G

%type <string> Logop Eqop Relop



%%

Prog:
	 Package Import Classes{printf("no of nodes : %d\n",nodes);print($3,0);YYACCEPT;}
	;


Package:
	 Package T_PACKAGE T_PID ';'
	|Package T_PACKAGE T_ID ';'
	|
	;
	
Import:
	 Import T_IMPORT T_PID ';'
	|Import T_IMPORT T_ID ';'
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

	 Modifier T_CLASS T_ID '{' ClassBody '}' Classes {$$  = newnode("CLASSES", $5 , $7 , 0, "", 0);}
	|{$$  = newnode("", NULL , NULL , 0, "", 0);} //fprintf(stderr,"EOF\n");
	; 	

ClassBody:
	 GlobalVar ClassBody {$$  = newnode("GLOBALVAR",$1 ,$2 ,0,"",0);}
	|MethodDec ClassBody {$$  = newnode("METHODDEC",$1 ,$2 , 0, "", 0);}
	| {$$  = newnode("",NULL ,NULL , 0, "", 0);}
	;

GlobalVar:
	 Modifier Declr ';' {$$  = $2 ;}
	;

MethodDec:
	 Modifier Type T_ID '(' ParameterList ')' '{' Statements '}' {$$  = newnode("FUNC",$5 ,$8 , 0, "", 0);}
	
	|Modifier T_VOID  T_ID  '(' ParameterList ')' '{' Statements '}'  {$$  = newnode("FUNC",$5 ,$8 , 0, "", 0);}
	|Modifier T_VOID  T_MAIN  '(' MainParams ')' '{' Statements '}'   {$$  = newnode("FUNC",$5 ,$8 , 0, "", 0);}
	

	;
MainParams:
	T_STRING T_ID T_DIMS {$$ = newnode("DECL",newnode("TYPE",NULL,NULL,1,$1,0),newnode("ID",NULL,NULL,1,$2,0),0,"",0);}
    ;

ParameterList:
	Type List {$$  = newnode("DECL",$1 ,$2 ,0,"",0);}
	;

List:
	T_ID {$$  = newnode("ID",NULL,NULL,1,$1,0);}
    |T_ID ',' List {$$  = newnode(",",newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}
	
	;
Statements:
	 Statement Statements {$$  = newnode("SEQ",$1 ,$2 ,0,"",0);}
	|Statement {$$  = $1 ;}

	;
Statement:
	 Declr ';' {$$  = $1 ;}
	|Assign ';' {$$  = $1 ;}
	|T_IF '(' Cond ')' IfStatement {$$  = newnode("IF",$3 ,$5 ,0,"",0);}
	|T_DO '{' Statements '}' T_WHILE '(' Cond ')' ';' {$$  = newnode("DO-WHILE",$3 ,$7 ,0,"",0);}
	|T_RETURN Exp ';' {$$  = newnode("SEQ",newnode("KEY",NULL,NULL,1,"RETURN",0),$2 ,0,"",0);}
	|T_PRINTLN '(' PrintBlock ')' ';'
	|T_PRINT '(' PrintBlock ')' ';'
    ;
	
IfStatement:
	 '{' Statements '}' T_ELSE '{' Statements '}' {$$  = newnode("SEQ",$2 ,$6 ,0,"",0);}
	;

PrintBlock:
	 String '+' Exp {$$  = newnode("STR",$1 ,$3 ,0,"",0);}
	|Exp T_PLUS String {$$  = newnode($2,$1 ,$3 ,0,"",0);}
	|Exp {$$  = $1 ;}
	|String {$$  = $1 ;}
	;

Declr:
	 Type ListVar  {$$  = newnode("DECLARE",$1 ,$2 ,0,"",0);}
	;

Type:
	 T_INT {$$  = newnode("INTEGER",NULL,NULL,1,$1,0);}
	|T_FLOAT {$$  = newnode("FLOAT",NULL,NULL,1,$1,0);}
	|T_DOUBLE {$$  = newnode("DOUBLE",NULL,NULL,1,$1,0);}
	|T_BOOLEAN {$$  = newnode("BOOLEAN",NULL,NULL,1,$1,0);}
	|T_CHAR {$$  = newnode("CHAR",NULL,NULL,1,$1,0);}
	|T_STRING {$$  = newnode("STRING",NULL,NULL,1,$1,0);}
	;
ListVar:
	 X {$$  = $1 ;}
	|ListVar ',' X {$$ = $3;}
	|T_DIMS T_ID {$$  = newnode("ID",NULL,NULL,1,$2,0);}
	|T_DIMS T_DIMS T_ID {$$  = newnode("ID",NULL,NULL,1,$3,0);}
	|T_ID T_DIMS '=' T_NEW Type T_DIMS {$$  = newnode("ID",NULL,NULL,1,$1,0);}
	|T_DIMS T_ID '=' T_NEW Type T_DIMS {$$  = newnode("ID",NULL,NULL,1,$2,0);}
	;
    
X:
	 T_ID {$$  = newnode("ID",NULL,NULL,1,$1,0);}
	|Assign {$$  = $1 ;}
	|T_ID T_DIMS {$$  = newnode("ID",NULL,NULL,1,$1,0);}
	|T_ID T_DIMS T_DIMS {$$  = newnode("ID",NULL,NULL,1,$1,0);}
	;
    
Assign:
	 T_ID '=' PrintBlock {$$  = newnode("=",newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}
	|T_ID T_PE ArithExp {$$  = newnode($2,newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}

	|T_ID T_ME ArithExp {$$  = newnode($2,newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}

	|T_ID T_MULE ArithExp {$$  = newnode($2,newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}
	|T_ID T_DE ArithExp {$$  = newnode($2,newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}
	|T_ID '=' T_NEW Type T_DIMS {$$  = newnode("=",newnode("ID",NULL,NULL,1,$1,0),newnode("NEW",NULL,NULL,1,"ARRAY",0),0,"",0);}

	|T_ID T_DIMS '=' Exp {$$  = newnode("=",newnode("ID",NULL,NULL,1,$1,0),$4 ,0,"",0);}

	|T_ID T_PERCE ArithExp {$$  = newnode($2,newnode("ID",NULL,NULL,1,$1,0),$3 ,0,"",0);}
	
	;

String:
	 T_STR {$$  = newnode("STR",NULL,NULL ,1 ,$1,0);}
	;
	
Cond:
	 LogExp {$$  = $1 ;}

	;
Exp: 
	LogExp {$$  = $1 ;}
	|ArithExp {$$  = $1 ;}
	;
LogExp:
	LogExp Logop EqExp0 {$$  = newnode($2,$1 ,$3 ,0,"",0);}
	|EqExp0 {$$  = $1 ;}
	;
Logop:
	T_AND {$$ = $1;}
	|T_OR {$$ = $1;}
	;
EqExp0: 
	EqExp0 Eqop RelG  {$$  = newnode($2,$1 ,$3 ,0,"",0);}
	|RelG {$$  = $1 ;}
	;
RelG:
	RelExp {$$  = $1 ;}
	|'(' LogExp ')' {$$  = $2 ;}
	|T_TRUE {$$  = newnode("BOOL",NULL,NULL,1,"TRUE",0);}
	|T_FALSE {$$  = newnode("BOOL",NULL,NULL,1,"FALSE",0);}
	;
Eqop:
	T_EE {$$ = $1;}
	|T_NE {$$ = $1;}
	;
RelExp:
	ArithExp Relop ArithExp {$$  = newnode($2,$1 ,$3 ,0,"",0);}
	;
Relop:
	T_LESS {$$ = $1;}
	|T_LTE {$$ = $1;}
	|T_GREATER {$$ = $1;}
	|T_GTE {$$ = $1;}
	|T_EE {$$ = $1;}
	|T_NE {$$ = $1;}
	;
ArithExp:
	 ArithExp '+' T {$$  = newnode("+",$1 ,$3 ,0,"",0);}
	|ArithExp '-' T {$$  = newnode("-",$1 ,$3 ,0,"",0);}
	|T {$$  = $1 ;}
	;
T:
	 T '*' G {$$  = newnode("*",$1 ,$3 ,0,"",0);}
	|T '/' G {$$  = newnode("/",$1 ,$3 ,0,"",0);}
	|T '%' G {$$  = newnode("%",$1 ,$3 ,0,"",0);}
	|G {$$  = $1 ;}
	;
G:
	 '(' ArithExp ')' {$$  = $2 ;}
	|T_ID T_DIMS  {$$  = newnode("ID",NULL,NULL,1,$1,0);}
	//|T_ID '.' T_ID {}
	|T_ID {$$  = newnode("ID",NULL,NULL,1,$1,0);}
	|T_NUM {$$  = newnode("NUM",NULL,NULL,1,"",1);}
	|T_REAL {$$ = newnode("REAL",NULL,NULL,1,"",1);}
	;




%%


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
