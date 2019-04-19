// Phillip Janowski
// CS2750 Project 3
// Takes in 1 one more arguments, then prints them in reverse
// Then prints which one is the largest and which one is the smallest lexigraphcially

#include <stdio.h>
#include <string.h>

char usage[] = "Must provide at least one argument of max size 100 for the program\n-h: to display this message";
int MAX_CHAR_ARRAY_SIZE = 0;

int main(int argc, char *argv[]) {

  //checking that there is atleast one arg
  if(argc <= 1 ){
    printf("%s", usage);
    return 1;
  }

  //loop over argv and print the contents starting at the end of the array
  for(int i = 1; i < argc; i++) {
    printf("%s ", argv[argc - i]);
    int argLen = strlen(argv[argc - i]);
    if(argLen > MAX_CHAR_ARRAY_SIZE) {
      MAX_CHAR_ARRAY_SIZE = argLen;
    }
  }
  //start the new line
  printf("\n");

  //inializing the arrays that will be copied to
  char largest[MAX_CHAR_ARRAY_SIZE];
  char smallest[MAX_CHAR_ARRAY_SIZE];
  strncpy(largest, argv[1], MAX_CHAR_ARRAY_SIZE);
  strncpy(smallest, argv[1], MAX_CHAR_ARRAY_SIZE);


  for(int i = 1; i < argc; i++) {

    // set current array
    char current[MAX_CHAR_ARRAY_SIZE];
    strncpy(current, argv[i], MAX_CHAR_ARRAY_SIZE);

    // Debugging artifacts
    // printf("largest %s\n", largest);
    // printf("smallest %s\n", smallest);
    // printf("curent %s\n", current);

    // compare the largest and the smallest to current
    // if the comp is greater than zero that means current is larger than its other parameter
    int largeComp = strncmp(current, largest, MAX_CHAR_ARRAY_SIZE);
    int smallComp = strncmp(current, smallest, MAX_CHAR_ARRAY_SIZE);
    // printf("largeComp %d\n", largeComp);
    // printf("smallComp %d\n", smallComp);

    if(largeComp >= 0) {

      //copy current to largest if the comp is greater than or equal
      strncpy(largest, current, MAX_CHAR_ARRAY_SIZE);
      // printf("%s is now the largest\n", largest);
    } else if(smallComp < 0) {
      //copy current to smallest if the comp is less than
      strncpy(smallest, current, MAX_CHAR_ARRAY_SIZE);
      // printf("%s is now the largst\n", smallest);
    }
  }

  printf("The largest argument is %s\n", largest);
  printf("The smallest argument is %s\n", smallest);
  // if(strncmp(argv[0],"-h", 2) == 1) {
  //   usage();
  // }
  return 0;
}
