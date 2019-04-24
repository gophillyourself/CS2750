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
    // if ( !(usedI && usedO)) {
    //     printUsage();
    //     return 1;
    // }
    Stack stack;
    // stack->top = 0;
    stack.top = 0;
    FILE* inputStream;
    FILE* output;
    output = fopen(outputName, "w");
    inputStream = fopen(inputName, "r");
    // if (inputStream == NULL) {
    //   perror("fopen()");
    //   return EXIT_FAILURE;
    // }
    char in;
    char buff[255];
    char * pch;
    while(fgets(buff, 255, inputStream)) {
      printf("%s\n", buff);
      pch = strtok (buff," ");
      while (pch != NULL)
      {
          push(&stack, pch);
          pch = strtok (NULL, " ,.-");
      }
    }

    while (stack.top > 0) {
      printf("%s\n", pop(&stack));
    }

    return 0;
}

//fd = fopen(name, mode);
//FILE *fd is file descriptor
//mode = w, r, a, r+, w+, a+
//returns a pointer to the stream
