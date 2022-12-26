%{
#include <stdio.h>
#include <stdlib.h>
%}
digit [0-9]
%%
{digit}+ { return atoi(yytext); }
<<EOF>> { return -1; }
.|\n { /*The dot (.) accepts anything but a newline */ return 0; }
%%
int yywrap(){}
int main(int argc, char *argv[]) {
int val, sum = 0;
while ((val = yylex()) >= 0 ) {
sum += val;
}
printf("sum = %d\n", sum);
return 0;
}