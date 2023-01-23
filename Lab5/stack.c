#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stackSize = 10000;

void pushStack(int val, struct stack *s)
{
    if (s->top == stackSize) {
        printf("Stack Overflow!\n");
        exit(EXIT_SUCCESS);
    }
    s->array[s->top] = val;
    s->top++;
}

struct stack *newStack()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = 0;
    return s;
}

int popStack(struct stack *s)
{
    if (s->top == 0) {
        printf("Stack Underflow!\n");
        exit(EXIT_SUCCESS);
    }
    s->top--;
    return (s->array[s->top]);
}

int peekStack(struct stack *s)
{
    if (s->top == 0) {
        printf("Empty stack!\n");
        exit(EXIT_SUCCESS);
    }
    return (s->array[s->top - 1]);
}
