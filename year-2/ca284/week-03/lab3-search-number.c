/*
Program: lab3-search-number.c
Author: Ayden Jahola
Description: This program searches for a number in an array and prints the
result.
Input: The program takes a number and a list of integers as command-line
arguments.
Output: It prints "Found <value> at <index>" if the number is found,
or "<value> not found" if it's not.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to search for a number in an array and return its index
int searchNumber(int target, int *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i; // Return the index where the number is found
    }
  }
  return -1; // Return -1 if the number is not found
}

int main(int argc, char *argv[]) {

  // Get the number to search for
  int target = atoi(argv[1]);

  // Get the number of elements in the array
  int numElements = argc - 2;

  // Create an array to store the elements
  int *arr = (int *)malloc(numElements * sizeof(int));

  // Convert and store command-line arguments as integers in the array
  for (int i = 2; i < argc; i++) {
    arr[i - 2] = atoi(argv[i]);
  }

  // Search for the target number in the array
  int index = searchNumber(target, arr, numElements);

  // Print the result
  if (index != -1) {
    printf("Found %d at %d\n", target, index);
  } else {
    printf("%d not found\n", target);
  }

  // Free dynamically allocated memory
  free(arr);

  return 0;
}
