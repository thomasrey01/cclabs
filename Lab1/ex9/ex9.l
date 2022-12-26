%{
    #include <stdio.h>
    #include "stack.h"
    Stack *stack = newStack();
%}
%option noyywrap

operator    "+" | "-" | "*" | "/"
digit       [0-9]
exponent    "E"
integer     {digit}+
real        {integer}("."{integer})?({exponent}{integer})?

%%
{real}      {stack.push(atof(yytext));}
{operator}  {calculateNpush(*stack, yytext);}
%%

int main()
{
    yylex();
    printf("%f\n", stack.pop());
}
