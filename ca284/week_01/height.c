#include <stdio.h>

int main() {
  int my_height = 169;   // Height in cm
  int your_height = 175; // Heignt in cm

  if (your_height > my_height) {
    printf("You are taller than me.\n");
  }

  if (your_height < my_height) {
    printf("I am taller than you.\n");
  }

  if (your_height == my_height) {
    printf("We are exactly the same height.\n");
  }

  return 0;
}