a.out: y.tab.c lex.yy.c
	gcc -o a.out y.tab.c lex.yy.c -ll
y.tab.c: sem.y
	yacc -d sem.y
lex.yy.c: prog.l
	lex prog.l
