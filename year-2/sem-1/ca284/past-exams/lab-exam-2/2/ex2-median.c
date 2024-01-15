/*
* Author: Duarte Martinho
* Purpose: Center numbers are defined as the number(s) stays in the middle of the list after the list has been sorted.
* ccepts input as an array of integer.
* Given that the number of elements of the array is always even.
* The program finds the two center elements and displays both of them in the ascending order line by line.
* Language:  C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */
#define MAX 100

/* Function Prototypes */
int* sortArray(int array[], int arrayLength);
void getMiddle(int array[], int arrayLength, int *middle1, int *middle2);

int main(int argc, char*argv[]) {
    int length = argc - 1;
    int array[MAX];
    for (int i = 0; i < length; i++) {
        array[i] = atoi(argv[i + 1]);
    }

    *array = *sortArray(array, length);
    int middle1, middle2;
    getMiddle(array, length, &middle1, &middle2);
    printf("%d\n%d\n", middle1, middle2);
    return 0;
}

/*
* Function Name: sortArray
* Description: sorts the given array and returns it
* Args: int unsorted array, int length of array
* Returns: int sorted array
*/
int* sortArray(int array[], int arrayLength) {
    int i, j;
    for (i = 0; i < arrayLength; i++) {
        for (j = 0; j < arrayLength; j++) {

            // printf("%d %d\n", array[i], array[j]);
            if (array[i] < array[j]) {
                int temp;
                // printf("%d %d\n", array[i], array[j]);
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                // printf("%d %d\n", array[i], array[j]);
            }
        }
    }
    return array;
}

/*
* Function Name: getMiddle
* Description: gets the middle of the array and assigns it to the pointers
* Args: int array, int length of array, int pointer to middle left, int pointer to middle right
* Returns: no return (void)
*/
void getMiddle(int array[], int arrayLength, int *middle1, int *middle2) {
    int middle = arrayLength / 2;
    *middle1 = array[middle - 1];
    *middle2 = array[middle];
}
