#include <stdio.h>
#include <stdlib.h>
#include "semanticsCheck.h"

int tableSize = 100;

struct symbolTable *localvars;
struct symbolTable *globalvars;
struct symbolTable *functions;

void initTables()
{
    localvars = createSymbolTable(tableSize);
    globalvars = createSymbolTable(tableSize);
    functions = createSymbolTable(tableSize);
}

void addFunction(int idx, int numArgs)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if(sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
    }
    sym->isConst = 0;
    sym->isFunc = 1;
    sym->numArguments = numArgs;
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

void checkFunction(int idx, int args)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if (sym == NULL) {
        printf("Undefined function call");
        return;
    }
    if (sym->numArguments != args) {
        printf("Invalid number of arguments");
        return;
    }
}
