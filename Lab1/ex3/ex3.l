%{
    #include <stdio.h>
    #include <stdlib.h>
    int num = 0;
%}

%%
<<EOF>> {return 0;}
I {printf("I"); return 1;}
V {printf("V"); return 5;}
X {printf("X"); return 10;}
L {printf("L"); return 50;}
C {printf("C"); return 100;}
D {printf("D"); return 500;}
M {printf("M"); return 1000;}
.|\n {return -1;}
%%

int yywrap(){}
int main ()
{
	int val;
    int prev = 0;
	while ((val = yylex())) {
		if (val < 0) {
			printf("=%d\n", num);
            num = 0;
            prev = 0;
		} else {
            num += val;
            if (prev > 0 && prev < val) {
                num -= 2 * prev;
            } 
            prev = val;
        }
    }
}
