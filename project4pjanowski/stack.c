//
// Created by Phill Janowski on 2019-04-18->
//
#include "stack.h"
#include <stdio.h>
#include <string.h>
char* pop(struct Stack* stack)  {
    char *ret = stack->stack[stack->top];
    stack->top = stack->top - 1;
    return ret;
}

void popAll(struct Stack* stack) {
    for (int i = stack->top - 1; i >= 0; i--) {
        printf("%s in stack[%d]\n", stack->stack[i], i);
    }
}

void push(struct Stack* stack, char *pushee) {
    if (!isInStack(stack, pushee)) {
        stack->top++;
        stack->stack[stack->top] = pushee;
    }
}

int isInStack(struct Stack* stack, char *pushee) {
    for (int i = stack->top - 1; i >= 0; i--) {
        if (strncmp(stack->stack[i], pushee, 80) == 0) {
            return 1;
        }
    }
    return 0;
}

