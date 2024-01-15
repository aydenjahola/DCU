#include <stdio.h>
#include <stdlib.h>

int main() {

  const int NUM = 5; // const makes the variable a constant, give uppercase name
                     // for constants, common in dev
  printf("%d\n", NUM);

  // num = 8; ==> cannot edit or modify the value because its a constant, will
  // throw an error.

  return 0;
}