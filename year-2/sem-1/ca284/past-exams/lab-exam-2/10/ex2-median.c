#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Author: James Hackett
Date: 11/11/2021
Description: This program will read in a list of numbers and then find the median of the list.
The list will always be even and will be sorted in ascending order.
*/

// Function prototypes
int sort(int *, int);
int build_array(int *, int, char *[]);
int print_median(int *, int);

// Main function calls all other functions and initializes variables
int main(int argc, char *argv[])
{
  // Initialize variables and allocate memory
  int *array = (int *)malloc(sizeof(int) * 100);
  int size = argc - 1;

  // Build array
  build_array(array, size, argv);

  // Sort the array
  sort(array, size);

  // Print middle elements
  print_median(array, size);

  // Free memory
  free(array);
  return 0;
}

// Function to sort the array in ascending order
// Parameters: array, size
// Returns: 0
int sort(int *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }

  return 0;
}

// Function to build the array from the command line arguments
// Parameters: array, size, argv
// Returns: 0
int build_array(int *array, int size, char *argv[])
{
  for (int i = 0; i < size; i++)
  {
    array[i] = atoi(argv[i + 1]);
  }

  return 0;
}

// Function to print the median of the array
// Parameters: array, size
// Returns: 0
int print_median(int *array, int size)
{
  // Take away 1 from size because c is 0 indexed
  int half = (size / 2) - 1;
  printf("%d\n", array[half]);
  printf("%d\n", array[half + 1]);

  return 0;
}