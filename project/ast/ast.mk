a.out: y.tab.c lex.yy.c
	gcc -o a.out y.tab.c lex.yy.c -ll
y.tab.c: ast.y
	yacc -d ast.y
lex.yy.c: syn.l
	lex syn.l
