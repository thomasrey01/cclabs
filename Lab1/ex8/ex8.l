%{
    #include <stdio.h>
%}
%option noyywrap
%%
a   {return 'a';}
b   {return 'b';}
\n  {return -1;}
%%
int main()
{
    int state = 1;
    int val;
    while ((val = yylex()) != -1) {
        switch (state) {
            case 1:
                switch (val) {
                    case 'a':
                        break;
                    case 'b':
                        state = 2;
                        break;
                }
                break;
            case 2:
                switch (val) {
                    case 'a':
                        state = 3;
                        break;
                    case 'b':
                        break;
                }
                break;
            case 3:
                switch (val) {
                    case 'a':
                        state = 1;
                        break;
                    case 'b':
                        state = 2;
                        break;
                }
                break;
        }
    }
    if (state == 1) {
        printf("accepted\n");
    } else {
        printf("rejected\n");
    }
}
