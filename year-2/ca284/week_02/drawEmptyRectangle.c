#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int length = atoi(argv[1]);
  int width = atoi(argv[2]);

  for (int j = 0; j < length; ++j)
    printf("*");
  printf("\n");

  for (int i = 1; i < width - 1; ++i) {
    for (int j = 0; j < length; ++j) {
      if ((j == 0) || (j == length - 1))
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  for (int j = 0; j < length; ++j)
    printf("*");
  printf("\n");

  return 0;
}