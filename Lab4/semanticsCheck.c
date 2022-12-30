#include <stdio.h>
#include <stdlib.h>
#include "semanticsCheck.h"

struct symbolTable *localvars;
struct symbolTable *globalvars;
struct symbolTable *functions;

void initTables()
{
    localvars = createSymbolTable(100);
    globalvars = createSymbolTable(100);
    functions = createSymbolTable(100);
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

void checkAssign(int idx)
{
    struct symbol *sym = findInSymTable(idx, globalvars);
    if (sym == NULL) {
        sym = findInSymTable(idx, localvars);
        if (sym == NULL) {
            printf("undefined symbol\n");
            return;
        }
    }
    if (sym->isConst) {
        printf("Cannot assign to constant variable\n");
    }
}

void addConst(int idx, int isGlobal)
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
    sym->isConst = 1;
    if (isGlobal) {
        insertInSymTable(idx, globalvars, sym);
    } else {
        insertInSymTable(idx, localvars, sym);
    }
}
