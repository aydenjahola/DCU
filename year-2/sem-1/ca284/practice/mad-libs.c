#include <stdio.h>
#include <string.h>

int main() {

  char color[10];
  char plural[10];
  char celeb[10];

  printf("Enter a color: "); // color input
  scanf("%s", color); // color input from keyboard

  printf("Enter a plural noun: "); // plural noun input
  scanf("%s", plural); // plural noun input from keyba

  printf("Enter a celebrity: ");
  scanf("%s", celeb);

  printf("Roses are {color}\n");
  printf("{plural-noun} are blue\n");
  printf("I love {celeb}\n");

  return 0;
}
