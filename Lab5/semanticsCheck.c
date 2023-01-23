#include <stdio.h>
#include <stdlib.h>
#include "semanticsCheck.h"

int tableSize = 100;

extern int linenr;

struct symbolTable *localvars;
struct symbolTable *globalvars;
struct symbolTable *functions;

void raiseError(char *msg) {
    printf("Line %d: ", linenr);
    printf("%s\n", msg);
    freeTable(localvars);
    freeTable(globalvars);
    freeTable(functions);
    exit(EXIT_SUCCESS);
}

void initTables()
{
    localvars = createSymbolTable(tableSize);
    globalvars = createSymbolTable(tableSize);
    functions = createSymbolTable(tableSize);
}

void addFunction(int idx, struct node *args, int funcType)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if(sym == NULL) {
        sym = malloc(sizeof(struct symbol));
        sym->id = idx;
        sym->next = NULL;
    }
    sym->isConst = 0;
    sym->isFunc = funcType;
    sym->args = args;
    insertInSymTable(idx, functions, sym);
}

void checkAssign(int idx)
{
    struct symbol *sym = findInSymTable(idx, globalvars);
    if (sym == NULL) {
        sym = findInSymTable(idx, localvars);
        if (sym == NULL) {
            raiseError("Undefined symbol.");
        }
    }
    if (sym->isConst) {
        raiseError("Cannot assign to constant variable");
    }
}

void addConsts(struct node *l, int tab)
{
    struct node *ptr = l;
    struct symbolTable *table;
    if (tab == 0) table = globalvars;
    else table = localvars;
    while (ptr != NULL) {
        struct symbol *sym = (struct symbol*)malloc(sizeof(struct symbol));
        sym->isConst = 1;
        sym->id = ptr->idx;
        sym->isFunc = 0;
        sym->varType = ptr->type;
        sym->next = NULL;
        sym->args = NULL;
        insertInSymTable(sym->id, table, sym); 
        ptr = ptr->next;
    }
}

void addVars(struct node *l, int tab)
{
    struct node *ptr = l;
    struct symbolTable *table;
    if (tab == 0) table = globalvars;
    else table = localvars;
    while (ptr != NULL) {
        struct symbol *sym = (struct symbol*)malloc(sizeof(struct symbol));
        sym->isConst = 0;
        sym->isFunc = 0;
        sym->varType = ptr->type;
        sym->next = NULL;
        sym->id = ptr->idx;
        sym->args = NULL;
        insertInSymTable(sym->id, table, sym);
        ptr = ptr->next;
    }
}

void checkFunction(int idx, struct node *args)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if (sym == NULL) {
        raiseError("Undefined function call.");
    }
    if (sym->isFunc != 1) {
        raiseError("Call is not a function.");
    }
    struct node *funcArgs = sym->args;

    if (!isSameList(args, funcArgs)) {
        raiseError("Wrong argument(s) in function call");
    }
}   

void checkProcedure(int idx, struct node *args)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if (sym == NULL) {
        raiseError("Undefined procedure call.");
    } if (sym->isFunc != 2) {
        raiseError("Call is not a procedure.");
    }
    struct node *funcArgs = sym->args;
    if (!isSameList(args, funcArgs)) {
        raiseError("Wrong argument(s) in procedure call.");
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
            raiseError("Undefined symbol\n"); 
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


int getType(int idx)
{
    struct symbol *sym = findInSymTable(idx, localvars);
    if (sym != NULL) {
        return sym->varType;
    }
    sym = findInSymTable(idx, globalvars);
    if (sym != NULL) {
        return sym->varType;
    }
    raiseError("Uninitialised value.");
    return -1;
}

int getFuncType(int idx)
{
    struct symbol *sym = findInSymTable(idx, functions);
    if (sym == NULL) {
        raiseError("Unintialised function.");
        return -1;
    }
    return sym->varType;
}

void noReal(int val1, int val2)
{
    if (val1 == 1 || val2 == 1) {
        raiseError("Cannot parse real value to integer operation.");
    }
}

