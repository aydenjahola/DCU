/*
* Author: Duarte Martinho
* Purpose: Accepts the following arguments.
* The first argument n refers to the size of the square matrix.
* The next n x n arguments refers to each elements in the square matrix.
* The program calculates the sum of elements on the anti-diagonal of a 2D square matrix and print the result.
* Language:  C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */
#define MAX 50

/* Function Prototypes */
int getAntiDiagonal(int array[MAX][MAX], int arrayLength);

int main(int argc, char*argv[]) {
    int n = atoi(argv[1]);
    int length = argc - 2;
    int array[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // printf("%d\n",2 + j + (i * n));
            array[i][j] = atoi(argv[2 + j + (i * n)]);
        }
    }
    int result = getAntiDiagonal(array, n);
    printf("%d\n", result);
    return 0;
}

/*
* Function Name: getAntiDiagonal
* Description: loops through the array and adds the anti-diagonal items (top-right to bottom-left)
* Args: int array, int length of the array
* Returns: int value of total
*/
int getAntiDiagonal(int array[MAX][MAX], int arrayLength) {
    int total = 0;
    for (int i = 0; i < arrayLength; i++) {
        total += array[i][arrayLength - i - 1];
        // printf("%d %d\n", array[i][arrayLength - i - 1], total);
    }
    return total;
}
