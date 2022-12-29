#include <stdio.h>
#include <stdlib.h>
#include "semanticsCheck.h"
#include "symbolTable.h"
#include "parser_tab.h"

extern struct symbolTable *symtab;
extern int scope;
const int stackSize = 50;

void checkExistance(int idx)
{
    char *s = getFromIndex(idx);
    if (!findInTable(symtab, s)) {
        yyerror("Undefined variable: %s", s);
    }
}

void addToTable(int idx, enum yytokentype type)
{
    if (!findInSymTable(idx, symtab)) {
        struct symbol *sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
        sym->stack = createStack(stackSize);
    }
}
