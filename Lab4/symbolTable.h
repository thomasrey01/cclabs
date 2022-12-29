#ifndef SYMBOLTABLE_H

#define SYMBOLTABLE_H
#include "parser.tab.h"

struct symbol;

struct identifierProp {
    enum yytokentype type;
    int scope;
    union {
        int ival;
        double dval;
    } value;
};

struct symbol {
    int id;
    struct symbol *next;
    struct Stack *stack; 
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

int findInSymTable(int idx, struct symbolTable *table);

int isEmptyStack(struct Stack *stack);

#endif
