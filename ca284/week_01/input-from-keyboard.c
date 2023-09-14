/* Include standard input and output */
#include <stdio.h>
/*
Function: Main
Parameters: none
returns: int
description: Get 2 input interger from keyboards, add them up and print out the
result
*/

int main()

{

  float number1, number2, sum;

  printf("Input number1:\n");
  scanf("%f", &number1);
  printf("Input number2:\n");
  scanf("%f", &number2);

  sum = number1 + number2;
  printf("The sum result is: %f\n", sum);

  return 0;
}