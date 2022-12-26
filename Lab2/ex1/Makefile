all: lexer compile clean

lexer:
	lex ex1.l

compile:
	gcc lex.yy.c -g -o a.out

clean:
	rm lex.yy.c
