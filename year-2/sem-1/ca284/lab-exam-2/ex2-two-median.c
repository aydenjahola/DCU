/*
Author: Ayden Jahola
Description: the program reads list of numbers and then find the median. and list will be sorted in ascending order.
inout: list of numbers
output: median
Date: 02/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
int sort_array(int *, int);
int list_array(int *, int, char *[]);
int find_median(int *, int);


// initialise the main function
int main(int argc, char *argv[])
{
  // Initialize variables and allocate memory
  int *array = (int *)malloc(sizeof(int) * 100);
  int size = argc - 1;

  // make the array from the list
  list_array(array, size, argv);

  // sort the array
  sort_array(array, size);

  // find the median
  find_median(array, size);

  // free the allocated memory back
  free(array);

  return 0;
}

// initialise and do the function to sort the array

int sort_array(int *array, int size)
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

// initialse and do the function to list the array

int list_array(int *array, int size, char *argv[])
{
  for (int i = 0; i < size; i++)
  {
    array[i] = atoi(argv[i + 1]);
  }

  return 0;
}

// initilialse and do the fuuntion to fidn the median number

int find_median(int *array, int size)
{
  int med = (size / 2) - 1; // because index starts at 0, we do - 1
  printf("%d\n", array[med]);
  printf("%d\n", array[med + 1]);

  return 0;
}