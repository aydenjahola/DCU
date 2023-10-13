/*
Program: lab5-search-sub-string.c
Author: Ayden Jahola
Description: This program takes two arguments. The first argument is a string,
and the second argument is a substring with a smaller length than the first input string.
The program checks if the first string contains the second string and prints the
positions of the first and last character of the second string in the first string.
Input: The program expects two arguments - a string and a substring.
Output: It prints the positions of the first and last character of the substring in the string.
*/

#include <stdio.h>
#include <string.h>

int searchSubstring(const char *string, const char *substring, int *start, int *end) {
    int stringLength = strlen(string);
    int substringLength = strlen(substring);
    int found = 0;

    for (int i = 0; i <= stringLength - substringLength; i++) {
        int j;
        for (j = 0; j < substringLength; j++) {
            if (string[i + j] != substring[j]) {
                break;
            }
        }

        if (j == substringLength) {
            *start = i;
            *end = i + substringLength - 1;
            found = 1;
        }
    }

    return found;
}

int main(int argc, char *argv[]) {

    const char *string = argv[1];
    const char *substring = argv[2];
    int start, end;

    if (searchSubstring(string, substring, &start, &end)) {
        printf("%d %d\n", start, end);
    } else {
        printf("Substring not found in the string.\n");
    }

    return 0;
}
