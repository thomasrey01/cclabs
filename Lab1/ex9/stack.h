#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    double array[50];
    int size;
    int top;
} Stack;

Stack newStack();

void push(Stack *stack, double val);

double pop(Stack *stack);

void calculateNpush(Stack stack, char op);

#endif
