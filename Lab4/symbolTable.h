#ifndef SYMBOLTABLE_H

#define SYMBOLTABLE_H
#include "parser.tab.h"

enum type {
    INT,
    REAL
};

struct symbol;

struct symbol {
    int id;
    struct symbol *next;
    enum type varType;
    int isConst;
};

struct symbolTable {
    int size;
    struct symbol **symbols;
};

struct Stack {
    struct identifierProp **prop;
    int size;
    int top;
};

struct Stack *newStack();

void pushInStack(struct Stack *stack, struct identifierProp *token);

struct identifierProp *popInStack(struct Stack *stack);

struct symbolTable *createSymbolTable(int size);

void insertInSymTable(int idx, struct symbolTable *table, struct symbol *symbol);

struct symbol *findInSymTable(int idx, struct symbolTable *table);

int isEmptyStack(struct Stack *stack);

#endif
