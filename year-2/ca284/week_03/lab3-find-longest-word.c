/*
Program: lab3-find-longest-word.c
Author: Ayden Jahola
Description: This program accepts a sentence as input via the command-line and
finds and prints the longest word in the sentence.
Input: The program takes a
sentence as a command-line argument.
Output: It prints the longest word in the
sentence followed by a newline character.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Get the input sentence
  char *sentence = argv[1];

  // Initialize variables to track the longest word and its length
  char longestWord[100]; // Assume a maximum word length of 100 characters
  int longestLength = 0;
  int currentLength = 0;
  int wordStart = 0;

  // Iterate through the characters in the sentence
  for (int i = 0; sentence[i] != '\0'; i++) {
    // Check if the current character is a space or the end of the sentence
    if (sentence[i] == ' ' || sentence[i + 1] == '\0') {
      // Calculate the length of the current word
      currentLength = i - wordStart + 1;

      // Check if the current word is longer than the longest word found so far
      if (currentLength > longestLength) {
        // Update the longest word and its length
        strncpy(longestWord, &sentence[wordStart], currentLength);
        longestWord[currentLength] = '\0'; // Null-terminate the longest word
        longestLength = currentLength;
      }

      // Move the wordStart to the next character
      wordStart = i + 1;
    }
  }

  // Print the longest word
  printf("%s\n", longestWord);

  return 0;
}
