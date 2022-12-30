#include <stdio.h>
#include <stdlib.h>
#include "semanticsCheck.h"
#include "symbolTable.h"
#include "parser_tab.h"

extern struct symbolTable *symtab;

extern struct symbolTable *localvars;
extern struct symbolTable *globalvars;
extern struct symbolTable *functions;

extern int scope;

void checkExistance(int idx)
{
    char *s = getFromIndex(idx);
    if (!findInTable(symtab, s)) {
        yyerror("Undefined variable: %s", s);
    }
}

void addToTable(int idx, enum type varType)
{
    if (!findInSymTable(idx, symtab)) {
        struct symbol *sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
    }
}

void addFunction(int idx)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if(sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
        insertInSymTable(idx, functions, sym);
    }
}

void addConst(int idx, int isGlobal, enum type type)
{
    struct symbol *sym;
    if (isGlobal) {
        sym = findInSymTable(idx, globalvars);
        
    } else {
        sym = findInSymTable(idx, localvars);
    }
    if (sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
    }
    sym->varType = type; 
    sym->isConst = 1;
}
