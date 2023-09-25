#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

int main(int argc, char *argv[]) {

  double radius = atof(argv[1]);
  double height = atof(argv[2]);

  double area = 2 * PI * radius * (radius + height);

  printf("%.2f\n", area);

  return 0;
}
