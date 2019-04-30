//
// Created by Phill Janowski on 2019-04-18.
// CS2750 
// Header and declaration for stack struct
#ifndef CS2750_STACK_H
#define CS2750_STACK_H

typedef struct Stack {
    int top;
    char *stack[100];
} Stack;

char* pop(struct Stack* stack);

void popAll(struct Stack* stack);

void push(struct Stack* stack, char *pushee);

int isInStack(struct Stack* stack, char *pushee);
#endif //CS2750_STACK_H
