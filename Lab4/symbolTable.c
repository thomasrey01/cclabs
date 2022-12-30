#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

struct symbolTable *createSymbolTable(int size)
{
    struct symbolTable *table;
    table = (struct symbolTable*)malloc(sizeof(struct symbolTable));
    table->size = size;
    table->symbols = (struct symbol**)malloc(size * sizeof(struct symbol));
    for (int i = 0; i < table->size; i++) {
        table->symbols[i] = NULL;
    }
    return table;
}

void insertInSymTable(int idx, struct symbolTable *table, struct symbol *symbol)
{
    int pos = idx % table->size; 
    if (table->symbols[pos] == NULL) {
        table->symbols[pos] = symbol;
    } else {
        struct symbol *symbolPtr = table->symbols[pos];
        while (symbolPtr != NULL) {
            symbolPtr = symbolPtr->next;
        }
        symbolPtr = symbol;
    }
}

struct symbol *findInSymTable(int idx, struct symbolTable *table)
{
    int pos = idx % table->size;
    if (table->symbols[pos] != NULL) {
        struct symbol *symbolPtr = table->symbols[pos];
        while (symbolPtr != NULL) {
            if (symbolPtr->id == idx) {
                return symbolPtr;
            }
            symbolPtr = symbolPtr->next;
        }
    }
    return NULL;
}


int isEmptyStack(struct Stack *stack)
{
    return (stack->top == 0);
}
