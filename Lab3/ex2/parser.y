%{
    #include <stdio.h>
    #include <stdlib.h>

    extern char *yytext;
    extern int position;
    extern int nested;
    extern int sCount;
    extern int cCount;
    extern int nCount;
    char* input;
    
    void setScannerInput(char *input);
    void finalizeScanner();
    int yylex(void);
    
    void yyerror(const char *s);
%}

%start Start;
%token LNPAR RNPAR LCPAR RCPAR LSPAR RSPAR;

%%
Start       : S
            ;

S           : LNPAR N RNPAR S   { nCount++; }
            | LSPAR N RSPAR S   { sCount++; }
            | LCPAR N RCPAR S   { cCount++; }
            | S S
            | { /* epsilon */ }
            ;

N           : LNPAR N RNPAR N     { nested++; nCount++; }
            | LSPAR N RSPAR N     { nested++; sCount++; }
            | LCPAR N RCPAR N     { nested++; cCount++; }
            | N N
            | {}
            ;

%%

void printToken()
{
    switch(yychar) {
        case LNPAR: printf("'('"); break;
        case RNPAR: printf("')'"); break;
        case LCPAR: printf("'{'"); break;
        case RCPAR: printf("'}'"); break;
        case LSPAR: printf("'['"); break;
        case RSPAR: printf("']'"); break;
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
    printf("(): %d\n", nCount);
    printf("[]: %d\n", sCount);
    printf("{}: %d\n", cCount);
    printf("nested: %d\n", nested);
    return 0;
}

