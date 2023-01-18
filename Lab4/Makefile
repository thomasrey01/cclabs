all: strtab stack linkedList semanticsCheck parser lexer symbolTable
	gcc -g -O2 strtab.o stack.o linkedList.o semanticsCheck.o parser.o lexer.o symbolTable.o -lfl -lm

stack: stack.c stack.h
	gcc -g -O2 -c stack.c

semanticsCheck:semanticsCheck.c semanticsCheck.h
	gcc -g -O2 -c semanticsCheck.c

strtab: strtab.c strtab.h
	gcc -g -O2 -c strtab.c

parser: parser.y
	bison -d parser.y
	mv parser.tab.c parser.c
	gcc -g -O2 -c parser.c

lexer: lexer.fl
	flex lexer.fl
	mv lex.yy.c lexer.c
	gcc -g -O2 -c lexer.c

symbolTable: symbolTable.c symbolTable.h
	gcc -g -O2 -c symbolTable.c

linkedList: linkedList.c linkedList.h
	gcc -g -O2 -c linkedList.c

clean:
	rm -f *~
	rm -f *.o
	rm -f parser.c
	rm -f parser.tab.h
	rm -f lexer.c
	rm -f a.out
