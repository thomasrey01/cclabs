#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

int getHash(char *id, int size)
{
    unsigned int res = 0;
    char *idPtr = id;
    int i = 1;
    while ((*idPtr) != '\0') {
        res += (int)*idPtr * i;
        i++;
        idPtr++;
    }
    return (int)(res % size);
}

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

void insertInSymTable(struct symbolTable *table, struct symbol *symbol)
{
    int pos = getHash(symbol->id, table->size);
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

void insertFromIndex(struct symbolTable *table, int idx)
{
    char *s = getFromIndex(idx);
    
}

int findInSymTable(char *id, struct symbolTable *table)
{
    int pos = getHash(id, table->size);
    if (table->symbols[pos] != NULL) {
        struct symbol *symbolPtr = table->symbols[pos];
        while (symbolPtr != NULL) {
            if (!strcmp(symbolPtr->id, id)) {
                return 1;
            }
            symbolPtr = symbolPtr->next;
        }
    }
    return 0;
}

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->array = malloc(size * sizeof(int));
    stack->top = 0;
    return stack;
}

void pushInStack(struct Stack *stack, int token)
{
    if (stack->top == stack->size) {
        printf("Stack Overflow!\n");
        exit(EXIT_SUCCESS);
    }
    stack->array[stack->top] = token;
    stack->top++;
}

int popInStack(struct Stack *stack)
{
    if (isEmptyStack(stack)) {
        printf("Stack Underflow!\n");
        exit(EXIT_SUCCESS);
    }
    stack->top -= 1;
    int res = stack->array[stack->top];
    return res;
} 

int isEmptyStack(struct Stack *stack)
{
    return (stack->top == 0);
}
