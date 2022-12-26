%{
    #include <stdio.h>
    #include <stdlib.h>

    extern char *yytext;
    extern int position;
    char* input;
    
    void setScannerInput(char *input);
    void finalizeScanner();
    int yylex(void);
    
    void yyerror(const char *s);
%}

%start Start;
%token TOKX TOKY TOKZ;

%%
Start       : S
            ;

S           : A
            | B TOKY
            | C C
            ;

A           : C TOKX A
            | TOKX A
            | TOKZ
            | { /* epsilob */ }
            ;

B           : TOKX C TOKY
            | TOKZ C
            ;

C           : C TOKZ
            | TOKX TOKZ TOKY
            | TOKX TOKY
            ;

%%

void printToken()
{
    switch(yychar) {
        case TOKX: printf("'x'"); break;
        case TOKY: printf("'y'"); break;
        case TOKZ: printf("'z'"); break;
        default: printf("'%c'", yychar);
    }
}

void yyerror(const char *msg)
{
    printf("Syntax error: %s", input);
    printf("-------------");
    for (int i = 0; i < position; i++) {
        putchar('-');
    }
    printf("^ unexpected symbol ");
    printToken();
    printf("\n");
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
    input = recReadStdin(0);
    setScannerInput(input);

    yyparse();

    finalizeScanner();
    free(input);

    printf("SUCCESS\n");
    return 0;
}

