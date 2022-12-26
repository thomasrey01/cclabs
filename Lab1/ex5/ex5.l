%{
    #include <stdio.h>
    int val = 0;
    int countA = 0;
    int countB = 0;
    char buffer[100];
    int i = 0;
%}
%option noyywrap
%%
a   {return 1;}
b   {return 2;}
\n  {return 3;}
<<eof>> {return 0;}
%%

int main()
{
    while ((val = yylex())) {
        if (val == 3) {
            buffer[i] = '\0';
            i = 0;
            if (countA == 2 && countB > 2) {
                printf("accepted: %s\n", buffer);
            } else {
                printf("rejected: %s\n", buffer);
            }
            countA = 0;
            countB = 0;
        } else if (val == 1) {
            countA++;
            buffer[i] = 'a';
            i++;
        } else if (val == 2) {
            countB++;
            buffer[i] = 'b';
            i++;
        }
    } 
}
