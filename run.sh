bison -d -v code/yacc.y -o code/y.tab.c
flex -o code/lex.yy.c code/lex.l
gcc code/lex.yy.c code/y.tab.c -ll