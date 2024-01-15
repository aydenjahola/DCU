/*
Program: lab3-string-reverse.c
Author: Ayden Jahola
Description: This program takes an input string and reverses it.
Input: The program takes one argument as an input string.
Output: It prints out the reversed string.
*/

#include <stdio.h>
#include <string.h>

// Function to reverse a string in-place
void reverseString(char *str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

int main(int argc, char *argv[]) {

  // Get the input string from the command-line argument
  char *inputString = argv[1];

  // Reverse the input string in-place
  reverseString(inputString);

  // Print the reversed string
  printf("%s\n", inputString);

  return 0;
}
