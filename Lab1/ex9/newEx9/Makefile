all: lexer compile clean

lexer:
	flex ex9.l

compile:
	gcc lex.yy.c stack.c -g -o a.out

clean:
	rm lex.yy.c
