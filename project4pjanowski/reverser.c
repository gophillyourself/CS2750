//
// Created by Phill Janowski on 2019-04-18.
// CS2750
// Reads an input file, places text on a stack seperated by a space
// outputs to the specified output file in reverse
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
    //loop over options
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

    //open read and write file streams
    output = fopen(outputName, "w");
    inputStream = fopen(inputName, "r");
    //loop till EOF 
    while(fgets(buff, 80, inputStream) != NULL) {
      printf("%s\n", buff);
      pch = strtok (buff, " ");

      while (pch != NULL)
      { 
	  //creates a new pointer to the string or else the strings in the stack get over written
          push(&stack, strdup(pch));
          pch = strtok (NULL, " \n");
      }
      //add a new line delimiter to keep track of the file lines
      push(&stack, "\n");
    }
	
    //loop over stack starting at the top to output to stdio and the defined output file
    while (stack.top > 0) {
        char *ret = pop(&stack);
	fputs(ret, output);
	fputs(" ", output);
        printf("%s ", ret);
    }
    //close everything
    fclose(output);
    fclose(inputStream);
    return 0;
}
