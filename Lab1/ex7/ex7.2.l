%{
    #include <stdio.h>
%}
%option noyywrap
%%
<<eof>> {return -1;}
0*(1(01*0)*1)*  {return 1;}
.    {return 0;}
\n   {return -1;}
%%

int main()
{
    int val;
    while ((val = yylex()) > 0) {
        
    }    
}

