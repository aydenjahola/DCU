/*
Program: lab9-largest-twice.c
Author: Ayden Jahola
Description: Finds the second-largest value in an array of floating-point numbers using dynamic memory allocation.
             It accepts a list of floating-point numbers as command-line arguments, dynamically allocates
             memory for the array, finds the second-largest value, and prints the result up to 1 digit after
             the decimal point. The program then frees the allocated memory.

Input: takes a list of floating-point numbers as command-line arguments.

Output: Outputs the second-largest value in the array up to 1 digit after the decimal point.
*/

#include <stdio.h>
#include <stdlib.h>

// function prototype
int findLargestTwice(int *arr, int size);

int main(int argc, char *argv[]) {

    int size = argc - 1;
    int *numbers = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    int result = findLargestTwice(numbers, size);

    if (result != 0) {
        printf("%d\n", result);
    } else {
        printf("0\n");
    }

    // Free allocated memory
    free(numbers);

    return 0;
}

// Function to find the largest element that is at least twice as much as at least one number in the array
int findLargestTwice(int *arr, int size) {
    int largest = -1;
    
    // Find the largest element in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Check if there exists a number in the array that is at least half of the largest element
    for (int i = 0; i < size; i++) {
        if (arr[i] != largest && arr[i] * 2 <= largest) {
            return largest;
        }
    }

    return 0; // Return 0 if no such element is found
}
