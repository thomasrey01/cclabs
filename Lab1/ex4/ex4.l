%{
    #include <stdio.h>
%}

%%
(a*|bb)*ba(a|b)*    {return 1;}
ab?(b(bb)*|ba)      {return 2;}
a+(ba+)*c(db)*(daa+(ba+)*c(db)*)*    {return 3;}
.|\n   {return 0;}
<<eof>> {return -1;}
%%
int yywrap(){}
int main() 
{
    int val;
    while ((val = yylex()) != -1) {
    if (val == 0) continue;
        printf("DFA%d accepted: %s\n", val, yytext);
    }

}
