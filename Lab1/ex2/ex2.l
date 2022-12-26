%{
    #include <stdio.h>
    #include <stdio.h>
%}

%%
A|a	{ printf(".-"); }
B|b	{ printf("-..."); }
C|c	{ printf("-.-."); }
D|d	{ printf("-.."); }
E|e	{ printf("."); }
F|f	{ printf("..-."); }
G|g	{ printf("--."); }
H|h	{ printf("...."); }
I|i	{ printf(".."); }
J|j	{ printf(".---"); }
K|k	{ printf("-.-"); }
L|l	{ printf(".-.."); }
M|m	{ printf("--"); }
N|n	{ printf("-."); }
O|o	{ printf("---"); }
P|p	{ printf(".--."); }
Q|q	{ printf("--.-"); }
R|r	{ printf(".-."); }
S|s	{ printf("..."); }
T|t	{ printf("-"); }
U|u	{ printf("..-"); }
V|v	{ printf("...-"); }
W|w	{ printf(".--"); }
X|x	{ printf("-..-"); }
Y|y	{ printf("-.--"); }
Z|z	{ printf("--.."); }
"0"	{ printf("-----"); }
"1"	{ printf(".----"); }
"2"	{ printf("..---"); }
"3"	{ printf("...--"); }
"4"	{ printf("....-"); }
"5"	{ printf("....."); }
"6"	{ printf("-...."); }
"7"	{ printf("--..."); }
"8"	{ printf("---.."); }
"9"	{ printf("----."); }
","	{ printf("--..--"); }
":" { printf("---..."); }
"?"	{ printf("..--.."); }
"/"	{ printf("-..-."); }
"\\" { printf(".-..-."); }
"="	{ printf("-...-"); }
.|\n { printf("%c", *yytext); }
%%

int yywrap(){}
int main()
{
    yylex();
    return 0;
}
