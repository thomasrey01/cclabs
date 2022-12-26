#include <stdio.h>
#include "stack.h"

Stack newStack() 
{
    Stack stack;
    stack->size = 0;
    stack->top = 0;
    return stack;
}

void push(Stack *stack, double val)
{
    stack->array[stack->top] = val;
    stack->size++;
    stack->top++;
}

double pop(Stack *stack)
{
    if (stack->top == 0) {
        printf("Stack empty!\n");
        exit(-1)
    }
    double val = stack->array[--stack->top];
    return val;
}

void calculateNpush(Stack *stack, char op)
{
    double num1 = stack.pop()
    double num2 = stack.pop()
    double res;
    switch (op) {
        case "+":
            res = num1 + num2;
        case "*":
            res = num1 * num2;
        case "-":
            res = num2 - num1;
        case "/":
            res = num2 / num1;
    }
    stack.push(res);
}
