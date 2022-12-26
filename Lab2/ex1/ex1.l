%{
    #include <stdio.h>
    int nextToken;
%}
%option noyywrap
%%
a {return 0;}
\( {return 1;}
\) {return 2;}
\+ {return 3;}
\* {return 4;}
\n  {return 5;}
<<eof>> {return 5;}
" " {}
.   {}
%%
enum Token
{
    A,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    PLUS,
    MULT,
    EPSILON,
};

int match(int token)
{
    if (nextToken != token) {
        return 0;
    }
    nextToken = yylex();
    return 1;
}

int parseA();
int parseB();

int parseS()
{
    if (parseA()) return parseB();
    return 0;
}

int parseA()
{
    if (match(LEFT_PARENTHESIS)) {
        return parseS() && match(RIGHT_PARENTHESIS); 
    }
    return match(A);
}

int parseB()
{
    if (match(PLUS)) return parseS();
    if (match(MULT)) return parseB();
    if (match(EPSILON)) return 1;
    parseS();
    return 1;
}

int main()
{
    nextToken = yylex();
    if (parseS() && nextToken == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAILURE\n");
    }
}



