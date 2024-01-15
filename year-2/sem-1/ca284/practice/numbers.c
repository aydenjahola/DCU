#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("%f\n", 8.9);
  printf("%f\n", 5.0 + 4.5);
  printf("%f\n", 5.0 - 4.5);
  printf("%f\n", 5.0 * 4.5);
  printf("%f\n", 5.0 / 4.5);

  printf("\n");

  printf("%f\n", 5 + 4.5); // this is fine we get float back
  // printf("%f\n", 5 + 4);   // Error becuase of two int

  printf("\n");

  printf("%d\n", 5 + 4); // This returns the int sum or math

  int num = 9;
  printf("%d\n", num); // this print the variable

  printf("%f\n", pow(2, 3)); // this gives 2^3
  printf("%f\n", pow(9, 6)); // this gives 9^6

  printf("\n");

  printf("%f\n", sqrt(36)); // this gives square root of 36

  printf("\n");

  printf("%f\n", ceil(36.356));  // gives the next highest number, round up
  printf("%f\n", floor(36.356)); // gives the next lowest number, round down

  return 0;
}