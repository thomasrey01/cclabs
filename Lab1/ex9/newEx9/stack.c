#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

struct Stack *newStack() 
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->size = 0;
    stack->top = 0;
    return stack;
}

void push(struct Stack *stack, double val)
{
    stack->array[stack->top] = val;
    stack->size++;
    stack->top++;
}

double pop(struct Stack *stack)
{
    if (stack->top == 0) {
        printf("Stack empty!\n");
        exit(-1);
    }
    double val = stack->array[--(stack->top)];
    return val;
}

void calculateNpush(struct Stack *stack, char op)
{
    double num1 = pop(stack);
    double num2 = pop(stack);
    double res;
    switch (op) {
        case '+':
            res = num1 + num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '-':
            res = num2 - num1;
            break;
        case '/':
            res = num2 / num1;
            break;
    }
    push(stack, res);
}
