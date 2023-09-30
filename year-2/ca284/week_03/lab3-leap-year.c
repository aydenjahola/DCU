/*
Program: lab3-leap-year.c
Author: Ayden Jahola
Description: This program takes two integer arguments representing a range of
years, and it prints out all the leap years within that range, one per line.
Input: The program expects two integer arguments representing the start year and
end year (inclusive).
Output: It prints the leap years within the specified
range.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return 1;
  } else {
    return 0;
  }
}

// Function to print leap years between two years (inclusive)
void printLeapYears(int startYear, int endYear) {
  for (int year = startYear; year <= endYear; year++) {
    if (isLeapYear(year)) {
      printf("%d\n", year);
    }
  }
}

int main(int argc, char *argv[]) {

  // Convert command-line arguments to integers
  int startYear = atoi(argv[1]);
  int endYear = atoi(argv[2]);

  // Check if the years are within the valid range
  if (startYear < 1582 || startYear > 2020 || endYear < 1582 ||
      endYear > 2020) {
    printf("Invalid input. Years should be between 1582 and 2020.\n");
    return 1;
  }

  // Call the function to print leap years
  printLeapYears(startYear, endYear);

  return 0;
}
