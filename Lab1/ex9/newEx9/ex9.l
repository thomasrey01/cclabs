%{
    #include <stdio.h>
    #include "stack.h"
    struct Stack *stack;
%}
%option noyywrap

operator    \+|-|\*|\/
digit       [0-9]
integer     {digit}+
real        -?{integer}("."{integer})?("E+"-?{integer})?

%%
{real}      { push(stack, atof(yytext)); }
{operator}  { calculateNpush(stack, *yytext); }
\n          {return 0;}
" "         {}
%%

int main()
{
    stack = newStack();
    yylex();
    printf("%f\n", pop(stack));
}
