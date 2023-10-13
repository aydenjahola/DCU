/*
Program: lab5-multiple-matrix.c
Author: Ayden Jahola
Description: This program takes two matrices as input, multiplies them, and prints the resulting matrix.
Input: The program expects two sets of arguments for the two matrices. The first two arguments indicate
the dimensions of the first matrix (m1 rows, n1 columns), followed by m1 x n1 elements. The next two
arguments indicate the dimensions of the second matrix (m2 rows, n2 columns), followed by m2 x n2 elements.
Output: It prints the resulting matrix of the product of the two given matrices.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply two matrices
int** multiplyMatrices(int m1, int n1, int m2, int n2, int** matrix1, int** matrix2) {
    if (n1 != m2) {
        printf("Matrix multiplication is not possible. Inner dimensions must match.\n");
        return NULL;
    }

    int** result = createMatrix(m1, n2);

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}


int main(int argc, char *argv[]) {

    int m1 = atoi(argv[1]);
    int n1 = atoi(argv[2]);

    int index = 3;
    int** matrix1 = createMatrix(m1, n1);

    // Read the first matrix
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            matrix1[i][j] = atoi(argv[index]);
            index++;
        }
    }

    int m2 = atoi(argv[index]);
    int n2 = atoi(argv[index + 1]);
    index += 2;

    if (argc < index + m2 * n2) {
        printf("Insufficient elements for the second matrix.\n");
        freeMatrix(matrix1, m1);
        return 1;
    }

    int** matrix2 = createMatrix(m2, n2);

    // Read the second matrix
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            matrix2[i][j] = atoi(argv[index]);
            index++;
        }
    }

    // Multiply the matrices and print the result
    int** result = multiplyMatrices(m1, n1, m2, n2, matrix1, matrix2);

    if (result) {
        printMatrix(result, m1, n2);
        freeMatrix(result, m1);
    }

    freeMatrix(matrix1, m1);
    freeMatrix(matrix2, m2);

    return 0;
}
