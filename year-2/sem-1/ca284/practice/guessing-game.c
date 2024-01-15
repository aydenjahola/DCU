#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int secret_number;
  int guess;
  int guessCount = 0;
  const int guessLim = 3;
  int outOfGuesses = 0;

  srand(time(NULL));

  // Generate a random secret number between 1 and 100
  secret_number = (rand() % 100) + 1;

  do {
    if (guessCount < guessLim) {
      printf("Enter your guess (between 1 and 100): ");
      scanf("%d", &guess);

      if (guess < 1 || guess > 100) {
        printf("Please enter a valid guess between 1 and 100.\n");
        continue;
      }

      guessCount++;

      if (guess < secret_number) {
        printf("Too low. Try again.\n");
      } else if (guess > secret_number) {
        printf("Too high. Try again.\n");
      }
    } else {
      outOfGuesses = 1;
      break;
    }
  } while (guess != secret_number);

  if (outOfGuesses) {
    printf("Out of guesses. The secret number was %d.\n", secret_number);
  } else {
    printf(
        "Congratulations! You guessed the secret number %d in %d attempts!\n",
        secret_number, guessCount);
  }

  return 0;
}