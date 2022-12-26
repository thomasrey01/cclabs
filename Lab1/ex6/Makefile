all: lexer compile clean

lexer:
	lex ex6.l

compile:
	gcc lex.yy.c -g -o a.out
clean:
	rm *.c
