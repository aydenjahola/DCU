#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Author: James Hackett
Date: 11/11/2021
Description: This program will read in a matrix of integers and print out the
anti-diagonal of the matrix.
*/

// Function Prototypes
int anti_diagonal(int num_rows, int num_cols, int *matrix);

// Main Function
int main(int argc, char *argv[])
{
  // Declare Variables
  int num_rows = atoi(argv[1]);
  int num_cols = atoi(argv[1]);
  int i, j;
  int sum = 0;
  int *matrix = (int *)malloc(num_rows * num_cols * sizeof(int));

  // Read in Matrix
  for (i = 2; i < argc; i++)
  {
    matrix[i - 2] = atoi(argv[i]);
  }

  // Print out Anti-Diagonal
  sum = anti_diagonal(num_rows, num_cols, matrix);
  printf("%d\n", sum);

  // Free Memory
  free(matrix);

  return 0;
}

// Function to Print Anti-Diagonal
// Parameters: num_rows, num_cols, matrix
// Returns: sum
int anti_diagonal(int num_rows, int num_cols, int *matrix)
{
  int i, j;
  int sum = 0;
  for (i = 0; i < num_rows; i++)
  {
    for (j = 0; j < num_cols; j++)
    {
      if ((i + j) == (num_cols - 1))
      {
        sum += matrix[i * num_cols + j];
      }
    }
  }
  return sum;
}