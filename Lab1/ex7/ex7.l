%{
    #include <stdio.h>
%}
%option noyywrap
%%
<<eof>> {return -1;}
\n  {return -1;}
1   {return 1;}
0   {return 0;}
%%

int main() 
{
    int state = 0;
    int val;
    while ((val = yylex()) >= 0) {
        switch (state) {
            case 0:
                switch (val) {
                    case 0: state = 0; break;
                    case 1: state = 1; break; 
                }
                break;
            case 1:
                switch (val) {
                    case 0: state = 2; break;
                    case 1: state = 0; break;
                }
                break;
            case 2:
                switch (val) {
                    case 0: state = 1; break;
                    case 1: state = 2; break;
                }
                break;
        }
    }
    if (state == 0) {
        printf("accepted\n");
    } else {
        printf("rejected\n");
    }
}
