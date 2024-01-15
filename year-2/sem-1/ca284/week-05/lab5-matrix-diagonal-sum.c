/*
Program: lab5-matrix-diagonal-sum.c
Author: Ayden Jahola
Description: This program takes the dimension 'n' and elements of a square matrix
as input and calculates the sum of the main diagonal of the matrix. The main diagonal
is defined as the set of elements where the row index equals the column index.
Input: The program expects 'n' followed by 'n x n' elements as command-line arguments.
Output: It prints the sum of the main diagonal elements.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a 2D matrix
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to fill the matrix with elements
void fillMatrix(int** matrix, int n, char* argv[]) {
    int elementCount = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = atoi(argv[elementCount]);
            elementCount++;
        }
    }
}

// Function to calculate the sum of the main diagonal
int calculateDiagonalSum(int** matrix, int n) {
    int diagonalSum = 0;
    for (int i = 0; i < n; i++) {
        diagonalSum += matrix[i][i];
    }
    return diagonalSum;
}

// Function to deallocate memory for the matrix
void deallocateMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]); // Get the dimension of the square matrix

    if (argc != (n * n + 2)) {
        printf("Number of matrix elements does not match the dimension.\n");
        return 1;
    }

    int** matrix = allocateMatrix(n); // Allocate memory for the matrix
    fillMatrix(matrix, n, argv); // Fill the matrix with elements from command-line arguments
    int diagonalSum = calculateDiagonalSum(matrix, n); // Calculate the sum of the main diagonal
    printf("%d\n", diagonalSum);

    deallocateMatrix(matrix, n); // Deallocate the dynamically allocated memory

    return 0;
}
