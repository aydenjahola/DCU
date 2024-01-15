/*
Program: lab5-count-character.c
Author: Ayden Jahola
Description: This program takes two arguments. The first argument is a character,
and the second argument is a string. It counts the number of occurrences of
the character in the string (regardless of case) and prints the result. If the
character does not exist in the string, it prints 0.
Input: The program expects two arguments - a character and a string.
Output: It prints the number of occurrences of the character in the string.
*/

#include <stdio.h>
#include <ctype.h>

// Function to count the number of occurrences of a character in a string (regardless of case)
int countCharacter(char ch, const char *str) {
    int count = 0;
    char chLower = tolower(ch); // Convert the character to lowercase

    // Iterate through the string using a pointer
    while (*str != '\0') {
        if (tolower(*str) == chLower) // Convert the string character to lowercase and compare
            count++; // Increment count if the character matches
        str++; // Move the pointer to the next character
    }

    return count;
}

int main(int argc, char *argv[]) {

    char ch = argv[1][0]; // Get the first character from the first argument
    char *str = argv[2];  // Pointer to the input string

    // Call the countCharacter function to count the character in the string
    int result = countCharacter(ch, str);

    // Print the result
    printf("%d\n", result);

    return 0;
}
