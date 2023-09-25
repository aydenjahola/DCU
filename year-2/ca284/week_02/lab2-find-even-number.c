#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int maxArrayLength = 10;
  int evenFound = 0;

  for (int i = 1; i < argc; i++) {
    int currentNumber = atoi(argv[i]);

    if (currentNumber % 2 == 0) {
      printf("%d - %d\n", i - 1,
             currentNumber); // Subtract 1 from i to get the index
      evenFound = 1;
    }
  }

  if (!evenFound) {
    printf("Not found!\n");
  }

  return 0;
}
