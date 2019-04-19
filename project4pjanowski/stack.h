//
// Created by Phill Janowski on 2019-04-18.
//

#ifndef CS2750_STACK_H
#define CS2750_STACK_H

struct Stack {
    int top;
    int stack[100];
};

int pop(struct Stack* stack);

void push(struct Stack* stack, int pushee);
#endif //CS2750_STACK_H
