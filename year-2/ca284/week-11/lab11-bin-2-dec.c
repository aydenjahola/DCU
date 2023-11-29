/*
Program: lab11-bin-2-dec.c
Author: Ayden Jahola

Description: A program to convert a binary string to its decimal equivalent.

Input: The program reads a binary string from the command line.

Output: The program displays the decimal equivalent of the binary string.
*/

#include <stdio.h>

// Function to convert a binary string to its decimal equivalent
void binToDec(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    // Check if at least one binary digit is provided
    if (argc < 2) {
        printf("No binary digits entered.\n");
        return 1; // Return an error code
    }

    // Convert binary to decimal and print the result
    binToDec(argc, argv);

    return 0;
}


// Function to convert a binary string to its decimal equivalent
void binToDec(int argc, char *argv[]) {
    // Check if the number of binary digits is within the allowed range
    if (argc > 9) {
        printf("Too many binary digits entered.\n");
        return;
    }

    int decimal = 0;
    int power = 1;

    // Iterate through the binary digits in reverse order
    for (int i = argc - 1; i > 0; i--) {
        // Check if the current digit is a valid binary digit (0 or 1)
        if (argv[i][0] == '0' || argv[i][0] == '1') {
            decimal += (argv[i][0] - '0') * power;
            power *= 2;
        } else {
            printf("Only digits 1 and 0 are permitted.\n");
            return;
        }
    }

    // Print the decimal equivalent
    printf("%d\n", decimal);
}