#include <stdio.h>
#include <string.h>

double cube(double num);

int main() {

  printf("Answer: %f\n", cube(3));
  return 0;
}

double cube(double num) {
  double result = num * num * num;

  return result;
}