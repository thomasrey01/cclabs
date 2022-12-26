all: lexer compile clean

lexer:
	lex ex7.l

compile:
	gcc lex.yy.c -g -o a.out
clean:
	rm -r lex.yy.c
