/*
Program: lab9-second-largest.c
Author: Ayden Jahola
Description: Finds the second-largest value in an array of floating-point numbers using dynamic memory allocation. It accepts a list of floating-point numbers as command-line arguments, dynamically allocates memory for the array, finds the second-largest value, and prints the result up to 1 digit after the decimal point. The program then frees the allocated memory.

Input: takes a list of floating-point numbers.

Output: Outputs the second-largest value in the array up to 1 digit after the decimal point.
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototype
int calculateDotProduct(int n, int *vector1, int *vector2);

int main(int argc, char *argv[]) {

    // Get the size of the vectors
    int n = atoi(argv[1]);

    // Allocate memory for vectors
    int *vector1 = (int *)malloc(n * sizeof(int));
    int *vector2 = (int *)malloc(n * sizeof(int));

    // Populate vectors with elements from command-line arguments
    for (int i = 0; i < n; i++) {
        vector1[i] = atoi(argv[i + 2]);
        vector2[i] = atoi(argv[i + 2 + n]);
    }

    // Calculate dot product
    int dotProduct = calculateDotProduct(n, vector1, vector2);

    // Print the result
    printf("%d\n", dotProduct);

    // Free allocated memory
    free(vector1);
    free(vector2);

    return EXIT_SUCCESS;
}


// Function to calculate the dot product of two vectors
int calculateDotProduct(int n, int *vector1, int *vector2) {
    int dotProduct = 0;
    for (int i = 0; i < n; i++) {
        dotProduct += vector1[i] * vector2[i];
    }
    return dotProduct;
}