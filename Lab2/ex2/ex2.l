%{
    #include <stdlib.h>
    #include "parser.h"

    #define Return(token) {position ++; return token;}

    int position = 0;
%}

%%

[ \t\n]     { position++;       }
"a"         { Return(TOKA);     }
"+"         { Return(PLUS);     }
"*"         { Return(MULT);     }
"("         { Return(LPAR);     }
")"         { Return(RPAR);     }

.           { Return(yytext[0]);}
