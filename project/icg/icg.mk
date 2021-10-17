a.out: y.tab.c lex.yy.c
	gcc -o a.out y.tab.c lex.yy.c -ll
y.tab.c: icg.y
	yacc -d icg.y
lex.yy.c: prog.l
	lex prog.l
