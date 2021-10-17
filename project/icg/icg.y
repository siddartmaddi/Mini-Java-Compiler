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
%}

%token T_NUM T_DIMS
%token T_REAL
%token T_ID T_FLOAT T_INT T_IMPORT T_DOUBLE T_BOOLEAN T_STRING T_CHAR T_IF T_ELSE T_DO T_WHILE T_RETURN T_PACKAGE T_CLASS T_PUBLIC T_PRIVATE T_PROTECTED T_STATIC T_VOID T_MAIN T_CONST T_TRUE T_FALSE T_NULL T_BREAK T_CONTINUE T_PRINTLN T_PRINT T_EXIT T_PE T_ME T_DE T_MULE T_PERCE T_AND T_OR T_NE T_GTE T_LTE T_EE T_NEW T_PID T_FINAL T_STR T_PLUS T_LESS T_GREATER


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

	 Modifier T_CLASS print_id flower_paran_o_c ClassBody flower_paran_c_c Classes
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
	|Modifier T_VOID print_id  func_paran_o ParameterList func_paran_c flower_paran_o Statements flower_paran_c
	|Modifier T_VOID T_MAIN  func_paran_o T_STRING print_id T_DIMS func_paran_c flower_paran_o Statements flower_paran_c
	;

ParameterList:
	 Type print_id
	|Type print_id ',' ParameterList 
	;
	
Statements:
	 Statement Statements
	|Statement
	;
Statement:
	 Declr ';' 
	|Assign ';'
    |OtherAssign ';'
	|T_IF '(' Cond ')' '{' {l1 = newLabel(); qinsert("ifFalse",$3.string,"",l1,flag);flag++;} Statements {l2 = newLabel(); qinsert("goto","","",l2,flag);flag++;} '}' T_ELSE '{' {qinsert("Label","","",l1,++flag);  } Statements '}' {qinsert("Label","","",l2,++flag);  }
	|T_DO '{' {l1 = newLabel();qinsert("Label","","",l1,++flag);  } Statements '}' T_WHILE '(' Cond ')' {l2 = newLabel(); qinsert("ifFalse",$8.string,"",l2,flag);flag++;qinsert("goto","","",l1,flag);qinsert("Label","","",l2,++flag);  } ';'
	|T_RETURN Exp ';'
	|T_PRINTLN '(' PrintBlock ')' ';'
	|T_PRINT '(' PrintBlock ')' ';'
	;

PrintBlock:
	 String '+' Exp 
	|Exp T_PLUS String
	|Exp 
	|String 
	;

Declr:
	 Type ListVar
	;

/*
Type

*/
Type:
	 T_INT
	|T_FLOAT
	|T_DOUBLE
	|T_BOOLEAN
	|T_CHAR
	|T_STRING 	
	;
    
ListVar:
	 X {insert(ht, num_extract(scope), scope, $1.string,$0.string,"(null)");}
	|Assign {insert(ht, num_extract(scope), scope, $1.string,$1.type,"(null)");}
  	|ListVar ',' Assign  {insert(ht, num_extract(scope), scope, $3.string,$0.string,"(null)");}
  	|ListVar ',' X  { insert(ht, num_extract(scope), scope, $3.string,$0.string,"(null)");}
	|T_DIMS print_id  {insert(ht, num_extract(scope), scope, $2.string,$0.string,"(null)");}
	|T_DIMS T_DIMS print_id {insert(ht, num_extract(scope), scope, $3.string,$0.string,"(null)");}
	|print_id T_DIMS '=' T_NEW Type T_DIMS {insert(ht, num_extract(scope), scope, $1.string,$0.string,"(null)");}
	|T_DIMS print_id '=' T_NEW Type T_DIMS {insert(ht, num_extract(scope), scope, $2.string,$0.string,"(null)");}
	;
X:
	 print_id
	//|Assign
	|print_id T_DIMS
	|print_id T_DIMS T_DIMS 
	;
    
Assign:
	 print_id '=' PrintBlock {qinsert("", $3.string, "", $1.string,flag);  $$.string=$1.string;$$.type = $0.string;}
	|print_id '=' T_NEW Type T_DIMS 
	|print_id T_DIMS '=' Exp 
	;
    
OtherAssign:
	 print_id T_PE ArithExp {qinsert(extract_op($2.string), $1.string, $3.string, $1.string,flag);  $$.string = $1.string;}
	|print_id T_ME ArithExp {qinsert(extract_op($2.string), $1.string, $3.string, $1.string,flag);  $$.string = $1.string;}
	|print_id T_MULE ArithExp {qinsert(extract_op($2.string), $1.string, $3.string, $1.string,flag);  $$.string = $1.string;}
	|print_id T_DE ArithExp {qinsert(extract_op($2.string), $1.string, $3.string, $1.string,flag);  $$.string = $1.string;}
    |print_id T_PERCE ArithExp {qinsert(extract_op($2.string), $1.string, $3.string, $1.string,flag);  $$.string = $1.string;}
    ;


String:
	 T_STR
	;
	
Cond:
	 LogExp
	;
Exp: 
	LogExp 
	|ArithExp
	;
LogExp:
	LogExp Logop EqExp0 {char *s = newTemp();qinsert($2.string, $1.string, $3.string, s, flag);  $$.string = s;
    insert(ht, num_extract(scope), scope,s,"boolean","(null)");}
	|EqExp0 
	;
Logop:
	T_AND
	|T_OR
	;
EqExp0: 
	EqExp0 Eqop RelG {char *s = newTemp();qinsert($2.string, $1.string, $3.string, s, flag);  $$.string = s;
    insert(ht, num_extract(scope), scope,s,"boolean","(null)");}
	|RelG
	;
RelG:
	RelExp
	|'(' LogExp ')'{$$.string = $2.string;}
	|T_TRUE 
	|T_FALSE
	;
Eqop:
	T_EE
	|T_NE
	;
RelExp:
	ArithExp Relop ArithExp {char *s = newTemp();qinsert($2.string, $1.string, $3.string, s, flag);  $$.string = s;
     insert(ht, num_extract(scope), scope,s,"boolean","(null)");}
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
	 ArithExp '+' T {char *s = newTemp();qinsert("+", $1.string, $3.string, s,flag);  $$.string = s;
     if(strcmp($1.type,"double")==0)$$.type = "double"; else if(strcmp($3.type,"double")==0)$$.type = "double";else $$.type = "int";
     insert(ht, num_extract(scope), scope,s,$$.type,"(null)");}
	|ArithExp '-' T {char *s = newTemp();qinsert("-", $1.string, $3.string, s,flag);  $$.string = s;
     if(strcmp($1.type,"double")==0)$$.type = "double"; else if(strcmp($3.type,"double")==0)$$.type = "double";else $$.type = "int";
     insert(ht, num_extract(scope), scope,s,$$.type,"(null)");}
	|T{$$.type = $1.type;$$.string = $1.string;}
	;
    //op arg1 arg2 res
T:
	 T '*' G {char *s = newTemp();qinsert("*", $1.string, $3.string, s, flag); $$.string = s;
     if(strcmp($1.type,"double")==0)$$.type = "double"; else if(strcmp($3.type,"double")==0)$$.type = "double";else $$.type = "int";
     insert(ht, num_extract(scope), scope,s,$$.type,"(null)");}
	|T '/' G {char *s = newTemp();qinsert("/", $1.string, $3.string, s, flag); $$.string = s;
     if(strcmp($1.type,"double")==0)$$.type = "double"; else if(strcmp($3.type,"double")==0)$$.type = "double";else $$.type = "int";
     insert(ht, num_extract(scope), scope,s,$$.type,"(null)");}
	|T '%' G {char *s = newTemp();qinsert("%", $1.string, $3.string, s, flag); $$.string = s;$$.type = $1.type;
    insert(ht, num_extract(scope), scope,s,$$.type,"(null)");}
	|G{$$.type = $1.type;$$.string = $1.string;}
	;
    //a = b * c + b * c
G:
	 '(' ArithExp ')' {$$.type = $2.type;$$.string = $2.string;}
	|print_id T_DIMS 
	|print_id {struct node* node = get_node(ht,num_extract(scope),scope,$1.string);
  		$$.type = node->type;}
	|T_NUM {char *c = malloc(sizeof(char)*10);sprintf(c,"%d",$1.number);$$.string = c;$$.type = "int";}
	|T_REAL {char *c = malloc(sizeof(char)*10);sprintf(c,"%f",$1.real);$$.string = c;$$.type = "double";}
	;

print_pid:
	T_PID	; 

print_id:
	T_ID	;

flower_paran_o:
	'{'	;

flower_paran_c:
	'}'	;
flower_paran_o_c:
	'{'	;

flower_paran_c_c:
	'}'	;
func_paran_o:
	'('	;
func_paran_c:
	')'	; 


%%

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
  

