CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=-ll

all: a.out

a.out: code/*.cpp code/lex.l code/yacc.y code/semantic.hpp
	bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.cpp
	flex -o code/lex.yy.cpp code/lex.l
	$(CC) code/*.cpp

debug: code/*.cpp code/lex.l code/yacc.y code/semantic.hpp
	bison -d -v -Wcounterexamples code/yacc.y -o code/y.tab.cpp
	flex -o code/lex.yy.cpp code/lex.l
	$(CC) -g code/*.cpp

clean:
	rm -rf code/lex.yy.cpp code/y.tab.cpp code/y.tab.hpp code/y.output a.out
