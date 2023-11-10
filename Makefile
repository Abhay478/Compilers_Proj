CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=-ll

debug: code/*.cpp code/lex.l code/yacc.y code/semantic.hpp
	bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.cpp
	flex -o code/lex.yy.cpp code/lex.l
	$(CC) -g code/*.cpp -o debug.out

release: code/*.cpp code/lex.l code/yacc.y code/semantic.hpp
	bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.cpp
	flex -o code/lex.yy.cpp code/lex.l
	$(CC) -O3 code/*.cpp -o release.out

clean:
	rm -rf code/lex.yy.cpp code/y.tab.cpp code/y.tab.hpp code/y.output debug.out release.out
