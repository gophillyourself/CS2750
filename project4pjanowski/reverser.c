//
// Created by Phill Janowski on 2019-04-18.
//
#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

struct Stack stack;

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
    while(( o = getopt (argc, argv, "hio:")) != -1) {
        switch (o) {
            case 'h':
                printUsage();
                return 0;

            case 'i':
                usedI = true;
                printf("%s", optarg);
                strncpy(inputName, optarg, sizeof(optarg));
                break;

            case 'o':
                usedO = true;
                printf("%s", optarg);
                strncpy(outputName, optarg, sizeof(optarg));
                break;

            case '?':
                return 1;
        }
    }
    if ( !(usedI && usedO)) {
        printUsage();
        return 1;
    }

    return 0;
}

//fd = fopen(name, mode);
//FILE *fd is file descriptor
//mode = w, r, a, r+, w+, a+
//returns a pointer to the stream