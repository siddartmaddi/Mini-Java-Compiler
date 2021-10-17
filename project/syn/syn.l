%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void yyerror(char *s);
int extract(char *s);
char* strextract(char *s);

typedef struct node
{
	char *name;
    char *id;
    int val;
    int is_leaf ;
  	struct node *left;
  	struct node *right;
}NODE;
    
#include "y.tab.h"






%}

digit	[0-9]
letter	[a-zA-Z_]
id	{letter}({letter}|{digit})*
pack_id	[a-z]+(\.[a-z]+)+
digits	{digit}+
opFraction	(\.{digits})?
opExponent	([Ee][+-]?{digits})?
real	{digits}{opFraction}{opExponent}

%option yylineno
%%

"/*"([^*]|\*+[^*/])*\*+"/" ;
"//"[^\n]*	;
"+="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_PE",yytext);return T_PE;}
"-="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_ME",yytext);return T_ME;}
"/="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_DE",yytext);return T_DE;}
"*="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_MULE",yytext);return T_MULE;}
"%="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_PERCE",yytext);return T_PERCE;}
"&&"    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_AND",yytext);return T_AND;}
"||"    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_OR",yytext);return T_OR;}
"!="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_NE",yytext);return T_NE;}
"<="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_LTE",yytext);return T_LTE;}
">="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_GTE",yytext);return T_GTE;}
"=="    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_EE",yytext);return T_EE;}
"<"	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_LESS",yytext);return T_LESS;}
">"	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_GREATER",yytext);return T_GREATER;}
"new"	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_NEW",yytext);return T_NEW;}
import	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_IMPORT",yytext);return T_IMPORT;}
package	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PACKAGE",yytext);return T_PACKAGE;}
class	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_CLASS",yytext);return T_CLASS;}
public	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PUBLIC",yytext);return T_PUBLIC;}
private	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PRIVATE",yytext);return T_PRIVATE;}
protected	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PROTECTED",yytext);return T_PROTECTED;}
static	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_STATIC",yytext);return T_STATIC;}
void	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_VOID",yytext);return T_VOID;}
final	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_FINAL",yytext);return T_FINAL;}
main	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_MAIN",yytext);return T_MAIN;}
const	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_CONST",yytext);return T_CONST;}
int	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_INT",yytext);return T_INT;}
float	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_FLOAT",yytext);return T_FLOAT;}
double	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_DOUBLE",yytext);return T_DOUBLE;}
boolean	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_BOOLEAN",yytext);return T_BOOLEAN;}
String	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_STRING",yytext);return T_STRING;}
char	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_CHAR",yytext);return T_CHAR;}
true	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_TRUE",yytext);return T_TRUE;}
false	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_FALSE",yytext);return T_FALSE;}
null	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_NULL",yytext);return T_NULL;}
break	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_BREAK",yytext);return T_BREAK;}
continue	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_CONTINUE",yytext);return T_CONTINUE;}
return	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_RETURN",yytext);return T_RETURN;}
System\.out\.println	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PRINTLN",yytext);return T_PRINTLN;}
System\.out\.print	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PRINT",yytext);return T_PRINT;}
if/[' '\t]*"(".*")"	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_IF",yytext);return T_IF;}
else	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_ELSE",yytext);return T_ELSE;}
do	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_DO",yytext);return T_DO;}
while	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_WHILE",yytext);return T_WHILE;}
exit	{return T_EXIT;}
{pack_id}	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_PID",yytext);return T_PID;}
{id}	{yylval.string=strdup(yytext);printf("%s\t%s\n","T_ID",yytext);return T_ID;}
\"[^\n]*\"	{yylval.string=strextract(yytext);printf("%s\t%s\n","T_STR",strextract(yytext));return T_STR;}
\[{digits}?\]	{yylval.number=extract(yytext);printf("%s\t%s\n","T_DIMS",yytext);return T_DIMS;}
{digits}	{yylval.number=atoi(yytext);printf("%s\t%s\n","T_NUM",yytext);return T_NUM;}
{real}	{yylval.real=atof(yytext);printf("%s\t%s\n","T_REAL",yytext);return T_REAL;}
\+/[' '\t]*\"    {yylval.string=strdup(yytext);printf("%s\t%s\n","T_PLUS",yytext);return T_PLUS;}
[\n|\t|' ']	;

.	{printf("%s\t%s\n",yytext,yytext);return *yytext;}
%%



char* strextract(char *s)
{
int len = strlen(s);
char* new = malloc(sizeof(char)*len+1);
strcpy(new,s+1);
new[len-2]='\0';
return new;

}
int extract(char *s)
{
int len = strlen(s),i;
char *new;
if(len == 2)
	return -1;
else
{
	s[len-1] = '\0';
	new = s+1;
	
	i = atoi(new);
	return i;
}
}
