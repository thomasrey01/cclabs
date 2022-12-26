%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%
[A-Z]   {printf("%c", (*yytext - 'A' + 1) % 26 + 'A');}
[a-z]   {printf("%c", (*yytext - 'a' + 1) % 26 + 'a');}
[0-9]   {printf("%c", (*yytext - '0' + 1) % 10 + '0');}
.|\n    {printf("%c", *yytext);}
%%
int yywrap(){}
int main() {
    yylex();
    return 0;
}