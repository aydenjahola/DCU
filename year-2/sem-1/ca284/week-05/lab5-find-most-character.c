/*
Program: lab5-find-most-character.c
Author: Ayden Jahola
Description: This program takes a string as input and finds the alphanumeric character
that has the most number of appearances in the string (regardless of case). It then
prints the character with the highest count. The program assumes there is only one
most frequent character.
Input: The program expects one argument - a string.
Output: It prints the alphanumeric character with the most appearances in the string.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char findMostCharacter(const char *str) {
    int charCount[26] = {0}; // Assuming only alphabetic characters

    while (*str != '\0') {
        if (isalpha(*str)) { // Consider only alphabetic characters
            charCount[tolower(*str) - 'a']++;
        }
        str++;
    }

    char mostCharacter = '\0';
    int maxCount = 0;

    for (int i = 0; i < 26; i++) {
        if (charCount[i] > maxCount) {
            maxCount = charCount[i];
            mostCharacter = 'a' + i;
        }
    }

    return mostCharacter;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    char mostCharacter = findMostCharacter(str);

    if (mostCharacter != '\0') {
        printf("%c\n", mostCharacter);
    } else {
        printf("No alphanumeric characters in the input string.\n");
    }

    return 0;
}
