#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int main(int argc, char *argv[]) {
  if (argc != 3) {
    if (argc == 1)
      printf("No input given!\n");
    else
      printf("Two arguments needed!\n");
    return 1;
  }

  double radius = atof(argv[1]);
  double height = atof(argv[2]);

  if (radius < 0 || height < 0) {
    printf("The radius or height cannot be negative!\n");
    return 1;
  }

  double area = 2 * PI * radius * (radius + height);

  printf("%.2f\n", area);

  return 0;
}
