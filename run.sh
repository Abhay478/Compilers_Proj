# /opt/homebrew/opt/bison/bin/bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.cpp
bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.cpp
flex++ -o code/lex.yy.cpp code/lex.l
g++ code/lex.yy.cpp code/y.tab.cpp code/yylval.cpp code/symbol_table.cpp code/structs.cpp -ll
