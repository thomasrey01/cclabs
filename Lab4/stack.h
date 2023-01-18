#ifndef STACK_H
#define STACK_H

struct stack {
    int top;
    int array[10000];
};

void pushStack(int val, struct stack *s);

int popStack(struct stack *s);

struct stack *newStack();

#endif
