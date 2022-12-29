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

int findInSymTable(int idx, struct symbolTable *table)
{
    int pos = idx % table->size;
    if (table->symbols[pos] != NULL) {
        struct symbol *symbolPtr = table->symbols[pos];
        while (symbolPtr != NULL) {
            if (symbolPtr->id == idx) {
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
    stack->prop = (struct identifierProp **)malloc(size * sizeof(struct identifierProp*));
    stack->top = 0;
    return stack;
}

void pushInStack(struct Stack *stack, struct identifierProp *token)
{
    if (stack->top == stack->size) {
        printf("Stack Overflow!\n");
        exit(EXIT_SUCCESS);
    }
    stack->prop[stack->top] = token;
    stack->top++;
}

struct identifierProp *popInStack(struct Stack *stack)
{
    if (isEmptyStack(stack)) {
        printf("Stack Underflow!\n");
        exit(EXIT_SUCCESS);
    }
    stack->top -= 1;
    struct identifierProp *res = stack->prop[stack->top];
    return res;
} 

int isEmptyStack(struct Stack *stack)
{
    return (stack->top == 0);
}
