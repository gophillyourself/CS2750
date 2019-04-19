//
// Created by Phill Janowski on 2019-04-18.
//
#include "stack.h"
int pop(struct Stack* stack)  {
    int ret = stack->stack[stack->top];
    stack->top = stack->top - 1;
    return ret;
}

void push(struct Stack* stack, int pushee) {
    stack->top = stack->top++;
    stack->stack[stack->top] = pushee;
}
