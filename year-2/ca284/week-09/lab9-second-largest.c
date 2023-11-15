/*
Program: lab9-second-largest.c
Author: Ayden Jahola
Description: This program finds the second-largest element in a dynamically allocated array of doubles.

Input: arguments containing the elements of the array.

Output: The second-largest element of the array with 1 digit after the decimal point.

*/


#include <stdio.h>
#include <stdlib.h>

// Function prototype
double findSecondLargest(double *arr, int size);


int main(int argc, char *argv[]) {

    // Calculate the size of the array
    int size = argc - 1;

    // Allocate memory for the array
    double *numbers = (double *)malloc(size * sizeof(double));

    // Convert arguments to double and store in the array
    for (int i = 0; i < size; i++) {
        numbers[i] = atof(argv[i + 1]);
    }

    // Find the second largest element
    double secondLargest = findSecondLargest(numbers, size);

    // Print the result with 1 digit after the decimal point
    printf("%.1f\n", secondLargest);

    // Free allocated memory
    free(numbers);

    return 0;
}

// Function to find the second largest element in an array
double findSecondLargest(double *arr, int size) {
    double largest = arr[0];
    double secondLargest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}