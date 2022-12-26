{
    #include <stdio.h>
    #include <stdlib.h>
    extern char *yytext;
    extern int position;
    char *str;
    void yy_scan_string(const char * str);
}

%start LLparser, Input;
%token TOKA, PLUS, MULT, LPAR, RPAR, NL;
%options "generate-lexer-wrapper";
%lexical yylex;

Input   : S
        ;

S       : A B
        ;

A       : TOKA
        | LPAR S RPAR
        ;

B       : S
        | PLUS S
        | MULT B
        |
        ;
{

void LLmessage(int token)
{
    printf("Syntax error: %s", str);
    printf("-------------");
    for (int i = 0; i < position; i++) {
        putchar('-');
    }
    printf("^ unexpected symbol ");
    printf("'%c'", str[position-1]);
    printf("\n");
    free(str);
    exit(EXIT_SUCCESS);
}

static char *recReadStdin(int length)
{
    char current = getchar();
    char *str;
    if (current == EOF) {
        str = malloc((1 + length) * sizeof(char));
        current = '\0';
    } else {
        str = recReadStdin(1 + length);
    }
    str[length] = current;
    return str;
}

int main()
{
    str = recReadStdin(0);
    yy_scan_string(str);

    LLparser();
    printf("SUCCESS\n");
    free(str);
}
}
