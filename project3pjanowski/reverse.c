#include <stdio.h>
#include <string.h>

char usage[] = "Must provide at least one argument of max size 100 for the program\n-h: to display this message";
const int MAX_CHAR_ARRAY_SIZE = 100;

int main(int argc, char *argv[]) {

  printf("%d\n", argc);
  if(argc <= 1 ){
    printf("%s", usage);
    return 1;
  }

  char largest[MAX_CHAR_ARRAY_SIZE];
  char smallest[MAX_CHAR_ARRAY_SIZE];
  strncmp(largest, argv[1], MAX_CHAR_ARRAY_SIZE);
  strncmp(smallest, argv[1], MAX_CHAR_ARRAY_SIZE);

  for(int i = 1; i < argc; i++) {
    printf("%s\n", argv[argc - i]);
  }

  for(int i = 0; i < argc; i++) {
    char current[MAX_CHAR_ARRAY_SIZE];
    strncpy(current, argv[i], MAX_CHAR_ARRAY_SIZE);
    if(strcmp(current, largest) > 0) {
      if(strcmp(largest, smallest) < 0) {
        strncpy(smallest, largest, MAX_CHAR_ARRAY_SIZE);
      }
      strncpy(current, largest, MAX_CHAR_ARRAY_SIZE);
    } else {
      if(strcmp(largest, smallest) < 0) {
        strncpy(smallest, largest, MAX_CHAR_ARRAY_SIZE);
      }
      strncpy(current, largest, MAX_CHAR_ARRAY_SIZE);
    }
  }

  printf("The largest argument is %s\n", largest);
  printf("The smallest argument is %s\n", smallest);
  // if(strncmp(argv[0],"-h", 2) == 1) {
  //   usage();
  // }
  return 0;
}
