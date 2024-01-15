/*
Author: Ayden Jahola
Description: This program takes command line integers, finds the most frequent element in the array, and prints it in ascending order.
Input: Command line integers
Output: The most frequent element in the array, sorted in ascending order
Date: 30/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes

// Function to get the array from the command line. If more than 5 elements, allocates additional space for each extra element.
void getArray(int *size, char *argv[], int *numbers);

// Function to create/build a new array of duplicate numbers.
void getDuplicates(int *sizeNumbers, int *sizeDuplicates, int *numbers, int *duplicates);

// Implement selection sort function to sort the array.
void sortArray(int *sizeDuplicates, int *duplicates);

// Helper function to swap two elements of an array.
void swap(int *a, int *b);

// Function to print the array.
void printArray(int *sizeDuplicates, int *duplicates);

// Main function
int main(int argc, char *argv[])
{
    int sizeNumbers = 5; // Set the size of integers to 5
    int *numbers = (int *)calloc(sizeNumbers, sizeof(int)); // Allocate memory dynamically
    getArray(&sizeNumbers, argv, numbers); // Get the array from the command line using the getArray function

    int *duplicates = (int *)calloc(1, sizeof(int)); // Allocate memory for duplicates
    int sizeDuplicates = 0; // Set the size of duplicates to 0
    getDuplicates(&sizeNumbers, &sizeDuplicates, numbers, duplicates); // Create/build a new array of duplicate numbers

    sortArray(&sizeDuplicates, duplicates); // Sort the array of duplicates using the sortArray function
    printArray(&sizeDuplicates, duplicates); // Print the array using the printArray function
    return 0;
}

// Function to get the array from the command line. If more than 5 elements, allocates additional space for each extra element.
void getArray(int *size, char *argv[], int *numbers)
{
    int i = 0; // Initialize i to 0
    while (argv[i + 1]) // Iterate through the values
    {
        if (i == *size) // Check if i is equal to our array size
        {
            *size += 1; // If so, add 1
            int *tmpNumbers = realloc(numbers, *size * sizeof(int)); // Reallocate memory dynamically for elements greater than 5
            if (!tmpNumbers) // Check for any errors
            {
                printf("Error Allocating Memory!\n"); // Print an error if memory allocation fails
                free(tmpNumbers); // Free up the allocated memory
                tmpNumbers = NULL; // Make tmpNumbers equal to NULL
                exit(0); // Exit
            }
            numbers = tmpNumbers; // Make the array numbers equal to our new one if the elements are more than 5
        }

        *(numbers + i) = atoi(argv[i + 1]); // Allocate more memory for elements greater than 5
        i = i + 1;
    }
}

// Function to create/build a new array of duplicate numbers.
void getDuplicates(int *sizeNumbers, int *sizeDuplicates, int *numbers, int *duplicates)
{
    int number; // Initialize variable number
    for (int i = 0; i < *sizeNumbers; ++i) // Iterate through the array
    {
        number = 1; // Set number equal to 1
        for (int j = 0; j < *sizeNumbers; ++j)
        {
            if (i != j) // If i isn't equal to j
            {
                if (*(numbers + i) == *(numbers + j)) // If the two numbers are equal
                {
                    number++; // Add them to our variable
                }
            }
        }
        if (number > 3) // Check how many elements we have
        {
            *(sizeDuplicates) += 1; // Add them to our array
            duplicates = (int *)realloc(duplicates, *sizeDuplicates * sizeof(int)); // Reallocate memory
            *(duplicates + *sizeDuplicates - 1) = *(numbers + i);
        }
    }
}

// Implement selection sort function to sort the array.
void sortArray(int *sizeDuplicates, int *duplicates)
{
    for (int i = 0; i < *sizeDuplicates; ++i) // Iterate through the array size of duplicates
    {
        for (int j = i; j < *sizeDuplicates; ++j) // Check for sorting
        {
            if (*(duplicates + i) > *(duplicates + j)) // If the next element is less than the previous
            {
                swap((duplicates + i), (duplicates + j)); // Swap them around
            }
        }
    }
}

// Helper function to swap two elements of an array.
void swap(int *a, int *b)
{
    int tmp = *a; // Make tmp equal to variable a
    *a = *b; // Make the variable a equal to b so we can compare values
    *b = tmp; // Swap b (which is the next element) to be equal to tmp so we check the next
}

// Function to print the array.
void printArray(int *sizeDuplicates, int *duplicates)
{
    for (int i = 0; i < *sizeDuplicates; ++i) // Iterate through the array
    {
        if (*(duplicates + i) != 0) // Check if the array isn't empty
        {
            printf("%d\n", *(duplicates + i)); // Print the values of the array, each on a new line
        }
    }
}
