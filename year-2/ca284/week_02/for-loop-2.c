#include <stdio.h>

int main(int argc, char *argv[])

{

  int i = 1;
  for (;;) {
    if (i <= 10) {
      printf("%d\n", i++);
      continue;
    } else {
      break;
    }
  }

  return 0;
}