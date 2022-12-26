{ 
/**********************************************/
#include <stdio.h>
#include <stdlib.h>

extern char *yytext;
/**********************************************/
}

%start LLparser, Expression;
%token NUMBER, PLUS, MINUS, TIMES, DIVIDE, 
       LEFT_PARENTHESIS, RIGHT_PARENTHESIS;
%options "generate-lexer-wrapper";
%lexical yylex;


Expression{int sign = 0;}
            : Term [[PLUS | MINUS{sign = 1;}] Term{(sign ? printf("SUB\n") : printf("ADD\n"));}]*
            ;

Term{int isDivide = 0;}
            : Factor [[TIMES | DIVIDE{isDivide = 1;}] Factor{isDivide ? printf("DIV\n") : printf("MUL\n");}]*
            ;
    
Factor 
            : NUMBER{printf("PUSH %s\n", yytext);}
            | MINUS Factor{printf("PUSH -1\nMUL\n");}
            | LEFT_PARENTHESIS Expression RIGHT_PARENTHESIS  
            ;


{ 
/*****************************************************************/
/* the following code is copied verbatim in the generated C file */

void LLmessage(int token) {
  printf("Syntax error....abort\n");
  exit(0);
}

int main() {
  LLparser();
  return 0;
}

/*****************************************************************/
}
