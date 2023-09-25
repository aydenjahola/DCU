#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int maxArrayLength = 10;
  int oddCount = 0;

  for (int i = 1; i < argc; i++) {
    int currentNumber = atoi(argv[i]);

    if (currentNumber % 2 != 0) {
      oddCount++;
    }
  }

  printf("%d\n", oddCount);

  return 0;
}
