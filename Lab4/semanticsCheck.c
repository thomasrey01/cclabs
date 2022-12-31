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

void addFunction(int idx, int numArgs, int funcType)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if(sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
    }
    sym->isConst = 0;
    sym->isFunc = funcType;
    sym->numArguments = numArgs;
    insertInSymTable(idx, functions, sym);
}

void checkAssign(int idx)
{
    struct symbol *sym = findInSymTable(idx, globalvars);
    if (sym == NULL) {
        sym = findInSymTable(idx, localvars);
        if (sym == NULL) {
            printf("undefined symbol\n");
            exit(EXIT_SUCCESS);
            return;
        }
    }
    if (sym->isConst) {
        printf("Cannot assign to constant variable\n");
        exit(EXIT_SUCCESS);
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
        printf("Undefined function call\n");
        exit(EXIT_SUCCESS);
    }
    if (sym->numArguments != args) {
        printf("Invalid number of arguments\n");
        exit(EXIT_SUCCESS);
    }
    if (sym->isFunc == 2) {
        printf("Cannot return value from procedure\n");
        exit(EXIT_SUCCESS);
    }
}

void addToLocal(int idx, int type)
{
    struct symbol *sym = findInSymTable(idx, localvars);
    if (sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
    }
    sym->isFunc = 0;
    sym->isConst = 0;
    insertInSymTable(idx, localvars, sym);
}

void addGlobal(int idx, int type)
{
    struct symbol *sym = findInSymTable(idx, globalvars);
    if (sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
    }
    sym->isFunc = 0;
    sym->isConst = 0;
    insertInSymTable(idx, globalvars, sym);
}

void freeListRec(struct symbol *sym)
{
    if (sym == NULL) return;
    freeListRec(sym->next);
    free(sym);
}

void purgeLocalTable()
{
    for (int i = 0; i < tableSize; i++) {
        freeListRec(localvars->symbols[i]);
        localvars->symbols[i] = NULL;
    }
}


void checkTable(int idx)
{
    struct symbol *sym = findInSymTable(idx, localvars);
    if (sym == NULL) {
        sym = findInSymTable(idx, globalvars);
        if (sym == NULL) {
            printf("Undefined symbol %d \n", idx);
            exit(1);
        }
    }
}

void checkSyms(struct symbol *sym)
{
    struct symbol *temp = sym;
    while (temp != NULL) {
        checkTable(temp->id);
        temp = temp->next;
    }
}

void addFromList(struct symbol* sym, int table)
{
    struct symbol *temp = sym;
    int type = sym->varType;
    while (temp != NULL) {
        if (table == 0) {
            addToLocal(temp->id, temp->varType);
        } else if (table == 1) {
            addGlobal(temp->id, temp->varType);
        }
        temp = temp->next;
    }
}
