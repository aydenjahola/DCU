/*
Program: lab9-longest-sentence.c
Author: Ayden Jahola

Description: This program accepts a number of strings from the command line, dynamically allocates memory to store the information, finds and prints the longest string(s) line by line. It uses dynamic memory allocation functions like malloc, realloc, and free.

Input: The program expects command line input in the following format:
       ./lab9-longest-sentence.c afdasg fhdfgh tyuiop fds sa

Output: The program outputs the longest string(s) line by line in the format:
        String
        ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
void findLongestStrings(int numStrings, char *strings[], int *lengths, int maxLength);

int main(int argc, char *argv[]) {
    int numStrings = argc - 1; // Calculate the number of strings

    // Dynamically allocate memory for the array of strings
    char **inputStrings = (char **)malloc(numStrings * sizeof(char *));
    int *stringLengths = (int *)malloc(numStrings * sizeof(int));

    // Initialize the array of strings with command line input
    for (int i = 0; i < numStrings; i++) {
        inputStrings[i] = argv[i + 1];
        stringLengths[i] = strlen(inputStrings[i]);
    }

    // Find and print the longest string(s)
    findLongestStrings(numStrings, inputStrings, stringLengths, 0);

    // Free dynamically allocated memory
    free(inputStrings);
    free(stringLengths);

    return 0;
}

// Function to find the longest string(s)
void findLongestStrings(int numStrings, char *strings[], int *lengths, int maxLength) {
    // Find the maximum length among the strings
    for (int i = 0; i < numStrings; i++) {
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
        }
    }

    // Print the longest string(s)
    for (int i = 0; i < numStrings; i++) {
        if (lengths[i] == maxLength) {
            printf("%s\n", strings[i]);
        }
    }
}
