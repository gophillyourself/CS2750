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
    Stack stack;
    FILE* inputStream;
    FILE* output;

    char in;
    char buff[255];
    char * pch;

    stack.top = 0;

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
    output = fopen(outputName, "w");
    inputStream = fopen(inputName, "r");
    while(fgets(buff, 80, inputStream) != NULL) {
      printf("%s\n", buff);
      pch = strtok (buff, " ");

      while (pch != NULL)
      { 
          push(&stack, strdup(pch));
          pch = strtok (NULL, " \n");
      }
    }

    printf("Starting to print backwards\n");
    while (stack.top > 0) {
        char *ret = pop(&stack);
        printf("%s\n", ret);
    }

    return 0;
}

//fd = fopen(name, mode);
//FILE *fd is file descriptor
//mode = w, r, a, r+, w+, a+
//returns a pointer to the stream
