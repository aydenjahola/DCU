#include <stdio.h>
#include <string.h>

struct Student {
  char name[10];
  char major[10];
  int age;
  double gpa;
};

int main() {

  struct Student student1;
  strcpy(student1.name, "Ayden");
  strcpy(student1.major, "COMSCI2");
  student1.age = 20;
  student1.gpa = 3.2;

  struct Student student2;
  strcpy(student2.name, "Henri");
  strcpy(student2.major, "COMSCI2");
  student2.age = 19;
  student2.gpa = 1.1;

  struct Student student3;
  strcpy(student3.name, "Jacky");
  strcpy(student3.major, "LMAOOOOOOOOOO");
  student3.age = 18;
  student3.gpa = 0;

  printf("Name: %s\nAge: %d\nMajor: %s\ngpa: %.1lf\n", student1.name,
         student1.age, student1.major, student1.gpa);

  printf("\n");

  printf("Name: %s\nAge: %d\nMajor: %s\ngpa: %.1lf\n", student2.name,
         student2.age, student2.major, student2.gpa);

  printf("\n");

  printf("Name: %s\nAge: %d\nMajor: %s\ngpa: %.1lf\n", student3.name,
         student3.age, student3.major, student3.gpa);
  return 0;
}
