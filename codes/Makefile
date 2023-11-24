CC=g++
CFLAGS=-std=c++17 -g -O3
LDFLAGS=-ll

SOURCES := $(wildcard code/*.cpp)

OBJ := $(patsubst code/%.cpp,obj/%.o,$(SOURCES))

all: obj/y.tab.cpp obj/lex.yy.cpp $(OBJ) code/semantic.hpp
	$(CC) $(CFLAGS) $(OBJ) obj/lex.yy.o obj/y.tab.o -o a.out

obj/%.o: code/%.cpp code/semantic.hpp ## compiles all source files without linking
	$(CC) $(CFLAGS) -c $< -o $@

obj/lex.yy.cpp: code/lex.l obj/y.tab.cpp
	flex -o obj/lex.yy.cpp code/lex.l
	$(CC) $(CFLAGS) -c obj/lex.yy.cpp -o obj/lex.yy.o

obj/y.tab.cpp: code/yacc.y
	bison -d -v -Wcounterexamples code/yacc.y -o obj/y.tab.cpp --report-file=obj/y.output
	$(CC) $(CFLAGS) -c obj/y.tab.cpp -o obj/y.tab.o

clean:
	rm obj/*.o obj/*.cpp obj/*.hpp obj/*.output a.out
