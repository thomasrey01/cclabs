all: lexer compile clean

lexer:
	lex ex8.l

compile:
	gcc lex.yy.c -g -o a.out
clean:
	rm lex.yy.c
