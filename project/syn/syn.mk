a.out: y.tab.c lex.yy.c
	gcc -o a.out y.tab.c lex.yy.c -ll
y.tab.c: syn.y
	yacc -d syn.y
lex.yy.c: syn.l
	lex syn.l
