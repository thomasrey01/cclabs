%{
    #include <stdio.h>
%}

%option noyywrap
%%
^(0*(10+)*)$      {return 1;}
^.*$             {return 0;}
<<eof>>         {return -1;}
%%

int main()
{
    int val;
    while ((val = yylex()) != -1) {
        if (val == 1) {
            printf("accepted: %s", yytext);
        } else {
            printf("rejected: %s", yytext);
        }
    }
}
