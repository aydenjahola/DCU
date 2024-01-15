/*
Program: lab3-is-sorted.c
Author: Ayden Jahola
Description: This program accepts an array of integers via the command line,
sorts the array in ascending order using the Bubble Sort algorithm, and then
prints the sorted array line by line.
Input: The program takes a list of
integers as command-line arguments.
Output: It prints the sorted array line by
line.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to perform a bubble sort on an array
void bubbleSort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap the elements if they are in the wrong order
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
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

  // Sort the array in ascending order using the Bubble Sort algorithm
  bubbleSort(arr, numElements);

  // Print the sorted array line by line
  for (int i = 0; i < numElements; i++) {
    printf("%d\n", arr[i]);
  }

  // Free dynamically allocated memory
  free(arr);

  return 0;
}
