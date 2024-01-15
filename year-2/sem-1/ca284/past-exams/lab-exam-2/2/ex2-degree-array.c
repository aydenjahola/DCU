/*
* Author: Duarte Martinho
* Purpose: Accepts n number of integers and display the degree of the array.
* Degree of an array is defined as the number of appearances of the most frequent element in the array.
* Language:  C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */
#define MAX 100

/* Function Prototypes */
int searchArray(int array[], int arrayLength);

int main(int argc, char*argv[]) {
    int length = argc - 1;
    int array[MAX];
    for (int i = 0; i < length; i++) {
        array[i] = atoi(argv[i + 1]);
    }
    int apperances;
    apperances = searchArray(array, length);
    printf("%d\n", apperances);
    return 0;
}

/*
* Function Name: searchArray
* Description: checks what apperared the most and keeps track of how many times it apperared and then returned
* Args: int array, int length of the array
* Returns: int value of most apperances found in the array
*/
int searchArray(int array[], int arrayLength) {
    int i, j, currApperances = 0, mostApperances = 0;
    for (i = 0; i < arrayLength; i++) {
        currApperances = 0;
        for (j = 0; j < arrayLength; j++) {
            if (array[i] == array[j]) {
                currApperances++;
            }
        }
        if (currApperances > mostApperances) {
            mostApperances = currApperances;
        }
    }
    return mostApperances;
}
