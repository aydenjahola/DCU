/*
Program: lab3-calculator.c
Author: Ayden Jahola
Input: multiply or divide two floating-point numbers
Output: calculate either division or multiplication
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the product of two numbers
float multiply(float num1, float num2) { return num1 * num2; }

// Function to calculate the division of two numbers
float divide(float num1, float num2) {
  // Check for division by zero
  if (num2 == 0) {
    printf("invalid\n");
    exit(0);
  }
  return num1 / num2;
}

// Function to calculate the factorial of a number
int factorial(int num) {
  if (num == 0 || num == 1) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

int main(int argc, char *argv[]) {

  // Get the operator and convert it to lowercase for case-insensitive
  // comparison
  char operator[20];
  strcpy(operator, argv[1]);
  for (int i = 0; operator[i]; i++) {
    operator[i] = tolower(operator[i]);
  }

  // Convert the input numbers from command-line arguments to floating-point or
  // integer numbers
  float num1 = atof(argv[2]);
  float num2 = atof(argv[3]);

  // Perform the calculation based on the operator
  float result;
  if (strcmp(operator, "add") == 0) {
    result = num1 + num2;
  } else if (strcmp(operator, "subtract") == 0) {
    result = num1 - num2;
  } else if (strcmp(operator, "multiply") == 0) {
    result = multiply(num1, num2);
  } else if (strcmp(operator, "divide") == 0) {
    result = divide(num1, num2);
  } else if (strcmp(operator, "factorial") == 0) {
    if (num1 < 0) {
      printf("Factorial is undefined for negative numbers\n");
      exit(1);
    }
    result = factorial((int)num1);
  } else {
    printf("Invalid operator: %s\n", operator);
    exit(1);
  }

  // Print the result
  printf("%f\n", result);

  return 0;
}
