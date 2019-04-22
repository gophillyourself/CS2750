//
// Created by Phill Janowski on 2019-04-18.
//
#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char usage[] = "Must provide at least one argument of max size 100 for the program\n-h: to display this message-";
void printUsage() {
    printf("%s", usage);
}

int main(int argc, char* argv[]) {
    bool usedI = false;
    bool usedO = false;
    int o;
    char inputName[100];
    char outputName[100];
    while(( o = getopt (argc, argv, "i:o:h::")) != -1) {
        switch (o) {
            case 'h':
                printUsage();
                return 0;

            case 'i':
                usedI = true;
                strncpy(inputName, optarg, 100);
                break;

            case 'o':
                usedO = true;
                strncpy(outputName, optarg, 100);
                break;

            case '?':
                return 1;
        }
    }
    if ( !(usedI && usedO)) {
        printUsage();
        return 1;
    }
    struct Stack *stack;
    stack->top = 0;

    FILE* input = fopen(inputName, "r");
    FILE* output = fopen(outputName, "w");
    char buff[255];

    int in;
    while (fscanf(input, " %d", &in) == 1) {
        printf("%s\n", in);
        push(stack, in);
    }

    while (stack->top > 0) {
      printf("%d\n", pop(stack));
    }

    return 0;
}

//fd = fopen(name, mode);
//FILE *fd is file descriptor
//mode = w, r, a, r+, w+, a+
//returns a pointer to the stream
