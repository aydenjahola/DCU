#include <stdio.h>
#include <stdlib.h>

int main() {

  char name[] = "Tom";
  int age = 75;

  printf("There once was a man named %s.\n", name);
  printf("he was %d years old.\n", age);

  age = 99;
  printf("He really liked the name %s.\n", name);
  printf("but did not like being %d.\n", age);

  return 0;
}