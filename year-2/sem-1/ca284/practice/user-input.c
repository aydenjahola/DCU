#include <stdio.h>
#include <stdlib.h>

int main() {

  char name[20];
  printf("What is your name: ");
  fgets(name, 20, stdin); // we cannot use scanf with line of text
  printf("Your name is %s\n", name);

  return 0;
}