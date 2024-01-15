/*
Program: lab11-longest-line.c
Author: Ayden Jahola

Description: A program to find the longest sentence in a file.

Input: The program reads data from the file "paragraph.txt" containing a paragraph of text.

Output: The program displays the following information:
    - Length of the longest sentence
    - The longest sentence
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200

// function prototype

// Function to find the longest sentence in the file
void findLongestSentence(FILE *file, char *longestSentence);


int main() {
    FILE *file;
    char longestSentence[MAX_LENGTH];

    // Open the file
    file = fopen("paragraph.txt", "r");

    // Check if the file is successfully opened
    if (file == NULL) {
        fprintf(stderr, "Unable to open the file.\n");
        return 1; // Return an error code
    }

    // Find the longest sentence
    findLongestSentence(file, longestSentence);

    // Close the file
    fclose(file);

    // Display the length of the longest sentence
    printf("%d\n", (int)strlen(longestSentence) + 1);

    // Display the longest sentence
    printf("%s\n", longestSentence);
    printf("\n");

    return 0;
}


// Function to find the longest sentence in the file
void findLongestSentence(FILE *file, char *longestSentence) {
    char sentence[MAX_LENGTH];
    int maxLength = 0;

    // Read each line from the file
    while (fgets(sentence, sizeof(sentence), file) != NULL) {
        // Remove the newline character at the end of the sentence
        sentence[strcspn(sentence, "\n")] = '\0';

        // Check if the current sentence is longer than the previous longest sentence
        if (strlen(sentence) > maxLength) {
            maxLength = strlen(sentence);
            strcpy(longestSentence, sentence);
        }
    }
}