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

#include <stdbool.h>
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
  bool inWord = false; // Flag to track if we are inside a word

  // Iterate through the characters in the sentence, including the null
  // terminator
  for (int i = 0; sentence[i] != '\0'; i++) {
    // Check if the current character is not a space
    if (sentence[i] != ' ') {
      if (!inWord) {
        // We are entering a new word, so update the wordStart
        wordStart = i;
        inWord = true;
      }
      currentLength++;
    } else if (inWord) {
      // Calculate the length of the current word
      if (currentLength > longestLength) {
        // Update the longest word and its length
        strncpy(longestWord, &sentence[wordStart], currentLength);
        longestWord[currentLength] = '\0'; // Null-terminate the longest word
        longestLength = currentLength;
      }
      // Reset current word length and flag
      currentLength = 0;
      inWord = false;
    }
  }

  // Check the last word (if any) after the loop ends
  if (inWord && currentLength > longestLength) {
    strncpy(longestWord, &sentence[wordStart], currentLength);
    longestWord[currentLength] = '\0';
  }

  // Print the longest word
  printf("%s\n", longestWord);

  return 0;
}
