%{
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
%}

%token T_NUM T_DIMS
%token T_REAL
%token T_ID T_FLOAT T_INT T_IMPORT T_DOUBLE T_BOOLEAN T_STRING T_CHAR T_IF T_ELSE T_DO T_WHILE T_RETURN T_PACKAGE T_CLASS T_PUBLIC T_PRIVATE T_PROTECTED T_STATIC T_VOID T_MAIN T_CONST T_TRUE T_FALSE T_NULL T_BREAK T_CONTINUE T_PRINTLN T_PRINT T_EXIT T_PE T_ME T_DE T_MULE T_PERCE T_AND T_OR T_NE T_GTE T_LTE T_EE T_NEW T_PID T_FINAL T_STR T_PLUS T_LESS T_GREATER
//%type <string> Type print_id  ListVar Assign X 

%%

Prog:
	 Package Import Classes {fprintf(stderr,"EOF\n"); YYACCEPT;}
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

	 Modifier T_CLASS print_id {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, $3.string,"class","(null)");} flower_paran_o_c ClassBody flower_paran_c_c Classes
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
	 Modifier Type print_id {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, $3.string,$2.string,"(null)");} func_paran_o ParameterList func_paran_c flower_paran_o Statements flower_paran_c
	|Modifier T_VOID print_id {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, $3.string,$2.string,"(null)");} func_paran_o ParameterList func_paran_c flower_paran_o Statements flower_paran_c
	|Modifier T_VOID T_MAIN {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, $3.string,$2.string,"(null)");} func_paran_o T_STRING print_id T_DIMS func_paran_c flower_paran_o Statements flower_paran_c
	;


ParameterList:
	 Type print_id {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, $2.string,$1.string,"(null)");}
	|Type print_id ',' ParameterList {char* scope = return_string(current_scope);insert(ht, num_extract(scope), scope, $2.string,$1.string,"(null)");}
	;
	
	
Statements:
	 Statement Statements
	|Statement

	;
Statement:
	 Declr ';' 
	|Assign ';'
    |OtherAssign ';'
	|T_IF '(' Cond ')' '{' Statements '}' T_ELSE '{' Statements '}'
	|T_DO '{' Statements '}' T_WHILE '(' Cond ')' ';'
	|T_RETURN Exp ';'
	|T_PRINTLN '(' PrintBlock ')' ';'
	|T_PRINT '(' PrintBlock ')' ';'

	;

PrintBlock:
	 String '+' Exp {$$.type = "String"; char result[10]; if(strcmp($3.type,"int") == 0){sprintf(result,"%d",$3.number);} else{sprintf(result,"%f",$3.real);}$$.string = strcat($1.string,result);} //;
	|Exp T_PLUS String {$$.type = "String";}
	|Exp {$$ = $1;}//$$.type = $1.type;}
	|String {$$.type = "String"; $$.string = $1.string;}
	;

Declr:
	 Type ListVar
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
	 X {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$1.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, $1.string,$0.string,"(null)");}}
	|Assign {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$1.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, $1.string,$1.type,$1.val);}}
  |ListVar ',' Assign { char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$3.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, $3.string,$0.string,$3.val);}}
  |ListVar ',' X { char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$3.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, $3.string,$0.string,"(null)");}}
	|T_DIMS print_id {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$2.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, $2.string,$0.string,"(null)");}}
	|T_DIMS T_DIMS print_id {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$3.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {insert(ht, num_extract(scope), scope, $3.string,$0.string,"(null)");}}
	|print_id T_DIMS '=' T_NEW Type T_DIMS {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$1.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {if($6.number==-1){yyerror("error");}insert(ht, num_extract(scope), scope, $1.string,$0.string,"(null)");}}
	|T_DIMS print_id '=' T_NEW Type T_DIMS {char* scope = return_string(current_scope); if(search(ht,num_extract(scope),scope,$2.string)){yyerror("Declaring twice!\n");YYACCEPT;} else {if($6.number==-1){yyerror("error");}insert(ht, num_extract(scope), scope, $2.string,$0.string,"(null)");}}
	;
X:
	 print_id
	//|Assign
	|print_id T_DIMS {$$=$1;}
	|print_id T_DIMS T_DIMS {$$=$1;}
	;
    


Assign:
	 print_id '=' PrintBlock {$$.string=$1.string;}
{ 
 char* scope = return_string(current_scope);
 if(search(ht,num_extract(scope),scope,$1.string))
 {
	struct node* node = get_node(ht,num_extract(scope),scope,$1.string); 


	if(strcmp(node->type,$3.type)!=0)
	{
		printf("INCOMPATIBLE type\n");
		YYACCEPT;
	}
  	else
  	{
	  	$$.type = $3.type;
	  	char result[20];
	  	if(strcmp($3.type,"int") == 0){sprintf(result,"%d",$3.number);} 
	    else if(strcmp($3.type,"double") == 0){sprintf(result,"%f",$3.real);}
	    else{strcpy(result,$3.string);}
	    strcpy(node->value,result);
  	}
} 
else //int n = 2;
 {

	if(!(strcmp($0.string,"int")==0 ||strcmp($0.string,"double")==0 || strcmp($0.string,"String")==0 ||strcmp($0.string,"boolean")==0))
  	{
  		yyerror("Identifier undeclared!\n");YYACCEPT;
  	}
	if(strcmp($0.string,$3.type)!=0)
	{
		printf("INCOMPATIBLE type\n");
		YYACCEPT;
	}
	else 
	  {
	  	$$.type = $0.string;
	  	char result[20];
	  	if(strcmp($3.type,"int") == 0){sprintf(result,"%d",$3.number);} 
	    else if(strcmp($3.type,"double") == 0){sprintf(result,"%f",$3.real);}
	    else{strcpy(result,$3.string);}
	    $$.val = result;
	  }
} 

}
	|print_id '=' T_NEW Type T_DIMS {if($5.number==-1){yyerror("error");}$$=$1;}
	|print_id T_DIMS '=' Exp {if($2.number==-1){yyerror("error");}$$=$1;}
	//|print_id '=' String
	;
    
OtherAssign:
	 print_id T_PE ArithExp {$$=$1;}
	|print_id T_ME ArithExp {$$=$1;}
	|print_id T_MULE ArithExp {$$=$1;}
	|print_id T_DE ArithExp {$$=$1;}
    |print_id T_PERCE ArithExp {$$=$1;}
    ;

/*Strings:
	Strings '+' String
	|String 
	;*/
String:
	 T_STR
	;
	
Cond:
	 LogExp
	;
Exp: 
	LogExp {$$.type = $1.type;}
	|ArithExp { $$ = $1;}//$$.type = $1.type; }
	;
LogExp:
	LogExp Logop EqExp0 {$$.type = "boolean";}
	|EqExp0 {$$.type = "boolean";}
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
      {
     if(strcmp($1.type,"double")==0)
     { 
     	$$.type = "double";
     	if(strcmp($3.type,"double")==0)
     	{ 
     		$$.real =  $1.real + $3.real ;
     	} 
     	else 
     	{
     		$$.real =  $1.real + $3.number;
     	} 
     } 
     else
     {
     	if(strcmp($3.type,"double")==0){
        	$$.real = $1.number + $3.real;
            $$.type = "double";
     	}
     	else{
        	$$.number = $1.number + $3.number;

		$$.type = "int";
     	}
     }
     }
     
	|ArithExp '-' T 
    {
     if(strcmp($1.type,"double")==0)
     { 
     	$$.type = "double";
     	if(strcmp($3.type,"double")==0)
     	{ 
     		$$.real =  $1.real - $3.real ;
     	} 
     	else 
     	{
     		$$.real =  $1.real - $3.number;
     	} 
     } 
     else
     {
     	if(strcmp($3.type,"double")==0){
        	$$.real = $1.number - $3.real;
            $$.type = "double";
     	}
     	else{
        	$$.number = $1.number - $3.number;
            $$.type = "int";
     	}
     }
     }
    
    
	|T {$$ = $1;}
	;
T:
	 T '*' G 
     {
     if(strcmp($1.type,"double")==0)
     { 
     	$$.type = "double";
     	if(strcmp($3.type,"double")==0)
     	{ 
     		$$.real =  $1.real * $3.real ;
     	} 
     	else 
     	{
     		$$.real =  $1.real * $3.number;
     	} 
     } 
     else
     {
     	if(strcmp($3.type,"double")==0){
        	$$.real = $1.number * $3.real;
            $$.type = "double";
     	}
     	else{
        	$$.number = $1.number * $3.number;
            $$.type = "int";
     	}
     }
     }
     
     
	|T '/' G  
    {
     if(strcmp($1.type,"double")==0)
     { 
     	$$.type = "double";
     	if(strcmp($3.type,"double")==0)
     	{ 
     		$$.real =  $1.real / $3.real ;
     	} 
     	else 
     	{
     		$$.real =  $1.real / $3.number;
     	} 
     } 
     else
     {
     	if(strcmp($3.type,"double")==0){
        	$$.real = $1.number / $3.real;
            $$.type = "double";
     	}
     	else{

        	$$.number = $1.number / $3.number;

            $$.type = "int";
     	}
     }
    }
	|T '%' G {$$.type = $3.type; $$.number = $1.number % $3.number;}
	|G {$$ = $1;}
	;
G:
	 '(' ArithExp ')'
	|print_id T_DIMS {char* scope = return_string(current_scope); if(!search(ht,num_extract(scope),scope,$1.string)){yyerror("Identifier undeclared!\n");YYACCEPT;}} 
	|print_id 
  {
  	char* scope = return_string(current_scope); 
  	if(!search(ht,num_extract(scope),scope,$1.string))
  	{
  		yyerror("Identifier undeclared!\n");YYACCEPT;
  	}
  	else
  	{
  		struct node* node = get_node(ht,num_extract(scope),scope,$1.string);
  		$$.type = node->type;
		if(node->value[0]=='('){printf("Uninitialised\n");YYACCEPT;}
  		if(strcmp(node->type,"int")==0){  $$.number = atoi(node->value);}
  		else $$.real = atof(node->value);
  	}
  }
	|T_NUM {$$.type = "int"; $$.number = $1.number;}
	|T_REAL {$$.type = "double"; $$.real = $1.real;}
	;
print_pid:
	T_PID	{}; 

print_id:
	T_ID	{};

flower_paran_o:
	'{'	 {index_a++;current_scope[index_a]+=1;};

flower_paran_c:
	'}'	{index_a--;};
flower_paran_o_c:
	'{'	 {index_a++;current_scope[index_a]+=1;current_scope[2]=0;};

flower_paran_c_c:
	'}'	{current_scope[2]=0;index_a--;};
func_paran_o:
	'('	{ index_a++;current_scope[index_a]+=1;};
func_paran_c:
	')'	{current_scope[index_a]-=1;index_a--;}; 


%%
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
  
