# /opt/homebrew/opt/bison/bin/bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.c
bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.c
flex -o code/lex.yy.c code/lex.l
gcc code/lex.yy.c code/y.tab.c code/yylval.c code/symbol_table.c -ll
