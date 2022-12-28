#include <stdio.h>
#include <stdlib.h>
#include "semanticsCheck.h"
#include "symbolTable.h"
#include "parser_tab.h"

extern struct symbolTable *symtab;

void checkType(char *s)
{
    if (!findInTable(symtab, s)) {
        yyerror("Undefined variable: %s", s);
    }
}

void checkExistance(int idx)
{
    char *s = getFromIndex(idx);
    if (!findInTable(symtab, s)) {
        yyerror("Undefined variable: %s", s);
    }
}

void addToTable(int idx, enum yytokentype type)
{
    
}
