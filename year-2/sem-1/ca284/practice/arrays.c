#include <stdio.h>
#include <string.h>

int main() {

  /* Basic way of using Array of we know the numbers */
  int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
  luckyNumbers[1] = 2;
  printf("%d\n", luckyNumbers[1]);

  printf("\n");

  /* Basic way of using Array when we want to assign stuff to them */
  int luckyNumbers2[10];
  luckyNumbers2[0] = 80;
  luckyNumbers2[1] = 69;

  printf("%d\n", luckyNumbers2[1]);

  return 0;
}
