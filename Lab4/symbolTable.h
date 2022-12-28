#ifndef SYMBOLTABLE_H

#define SYMBOLTABLE_H
#include "parser.tab.h"

struct symbol;

struct identifierProp {
    union {
        
    }
};

struct symbol {
    char *id;
    struct symbol *next;
    struct Stack *stack; 
};

struct symbolTable {
    int size;
    struct symbol **symbols;
};

struct Stack {
    int *array;
    int size;
    int top;
};

struct Stack *newStack();

void pushInStack(struct Stack *stack, int token);

int popInStack(struct Stack *stack);

struct symbolTable *createSymbolTable(int size);

void insertInSymTable(int idx, struct symbolTable *table, struct symbol *symbol);

int findInSymTable(char *id, struct symbolTable *table);

int isEmptyStack(struct Stack *stack);

#endif
