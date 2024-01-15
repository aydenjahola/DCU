#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Author: James Hackett
Date: 11/11/2021
Description: This program will calculate the number of appearances of the most frequent element in an array.
*/

// Function prototypes
int sort(int *, int);
int build_array(int *, int, char *[]);
int find_most_frequent(int *, int);

int main(int argc, char *argv[])
{
  // Declare variables
  int *array = (int *)malloc(sizeof(int) * 100);
  int size = argc - 1;

  // build array
  build_array(array, size, argv);

  // sort the array
  sort(array, size);

  // find the most frequent element and print it
  printf("%d\n", find_most_frequent(array, size));

  // free the memory
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

// Function to find the most frequent element in a sorted array
// Parameters: array, size
// Returns: the most frequent element
int find_most_frequent(int *array, int size)
{
  int mostFrequent = array[0];
  int count = 1;
  int maxCount = 1;
  for (int i = 0; i < size - 1; i++)
  {
    if (array[i] == array[i + 1])
    {
      count++;
    }
    else
    {
      count = 1;
    }
    if (count > maxCount)
    {
      maxCount = count;
      mostFrequent = array[i];
    }
  }

  return maxCount;
}