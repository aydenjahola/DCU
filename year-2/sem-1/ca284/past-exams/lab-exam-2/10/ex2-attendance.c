#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Author: James Hackett
Date: 11/11/2021
Description: This program will take a string of letters and return a 1 or 0 based on the number of appearances of the letter 'a'
*/

// Function Prototypes
int get_attendance(char *);

int main(int argc, char *argv[])
{
  // Declare Variables
  char attendance[50][50];
  // Allocate memory for the attendance array
  char *attendance_ptr = (char *)malloc(sizeof(char) * 50);

  // Read in the attendance records
  for (int i = 1; i < argc; i++)
  {
    strcpy(attendance[i - 1], argv[i]);
  }

  // Print out the attendance status of each student
  for (int i = 0; i < argc - 1; i++)
  {
    printf("%d\n", get_attendance(attendance[i]));
  }

  // Free the memory
  free(attendance_ptr);

  return 0;
}

// Function to get the attendance status of a student
// Input: A string of letters
// Output: A 1 or 0 based on the number of appearances of the letter 'a'
int get_attendance(char *attendance)
{
  // Declare Variables
  int count = 0;
  int status = 0;

  // Count the number of 'A'
  for (int i = 0; i < strlen(attendance); i++)
  {
    if (attendance[i] == 'A')
    {
      count++;
    }
  }

  // If the number of 'A' is less than or equal to 2, set the status to 1
  if (count <= 2)
  {
    status = 1;
  }

  return status;
}
