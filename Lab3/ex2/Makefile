all: parser lexer
	gcc parser.o lexer.o -lfl -lm

parser: parser.y
	bison -d parser.y
	mv parser.tab.c parser.c
	gcc -c parser.c

lexer: lexer.fl
	flex lexer.fl
	mv lex.yy.c lexer.c
	gcc -c lexer.c
clean:
	rm -f *~
	rm -f *.o
	rm -f parser.c
	rm -f parser.tab.h
	rm -f lexer.c
	rm -f a.out
