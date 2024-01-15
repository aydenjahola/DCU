/*
Program: lab3-duplicated-number.c
Author: Ayden Jahola
Description: This program finds and prints the duplicated number from an array
of positive integers.
Input: The program takes a list of positive integers as
command-line arguments.
Output: It prints the duplicated number if found, or "no
duplicated number" if there is none.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the duplicated number in an array
int findDuplicatedNumber(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] == arr[j]) {
        return arr[i]; // Return the duplicated number
      }
    }
  }
  return -1; // Return -1 if no duplicated number is found
}

int main(int argc, char *argv[]) {

  // Get the number of elements in the array
  int numElements = argc - 1;

  // Create an array to store the elements
  int *arr = (int *)malloc(numElements * sizeof(int));

  // Convert and store command-line arguments as integers in the array
  for (int i = 1; i <= numElements; i++) {
    arr[i - 1] = atoi(argv[i]);
  }

  // Find the duplicated number in the array
  int duplicatedNumber = findDuplicatedNumber(arr, numElements);

  // Print the result
  if (duplicatedNumber != -1) {
    printf("%d\n", duplicatedNumber);
  } else {
    printf("no duplicated number\n");
  }

  // Free dynamically allocated memory
  free(arr);

  return 0;
}
