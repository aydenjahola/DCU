#include <stdio.h>
#include <string.h>

/*
// prototype funtion
void sayHi();

int main() {

  sayHi();

  return 0;
}

// Void functions dont return any value
void sayHi() { printf("Hello User\n"); } */

/*
// prototype funtion
void sayHi(char name[]);

int main() {

  sayHi("Ayden");
  sayHi("Tom");
  sayHi("Oscar");

  return 0;
}

// Void functions dont return any value
void sayHi(char name[]) { printf("Hello %s\n", name); }*/

// prototype funtion
void sayHi(char name[], int age);

int main() {

  sayHi("Ayden", 20);
  sayHi("Tom", 30);
  sayHi("Oscar", 40);

  return 0;
}

// Void functions dont return any value
void sayHi(char name[], int age) {
  printf("Hello %s, you are %d\n", name, age);
}
