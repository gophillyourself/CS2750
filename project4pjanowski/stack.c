//
// Created by Phill Janowski on 2019-04-18->
//
#include "stack.h"
#include <stdio.h>
char* pop(struct Stack* stack)  {
    char *ret = stack->stack[stack->top];
    stack->top = stack->top - 1;
    return ret;
}

void push(struct Stack* stack, char *pushee) {
    stack->top++;
    stack->stack[stack->top] = pushee;
}
