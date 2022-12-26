#ifndef STACK_H
#define STACK_H

struct Stack {
    double array[50];
    int size;
    int top;
};

struct Stack *newStack();

void push(struct Stack *stack, double val);

double pop(struct Stack *stack);

void calculateNpush(struct Stack *stack, char op);

#endif
