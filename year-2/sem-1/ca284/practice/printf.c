#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("%d\n", 5 + 5);

  printf("Hello\nWorld\n");
  printf("Hello, \"World\"!\n");

  int favNum = 69;
  double favDec = 69.69;
  printf("My favourite %s is %d\n", "number", favNum);
  printf("My favourite %s is %f\n", "number", favDec);

  return 0;
}