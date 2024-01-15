/*
Program: lab9-student.c
Author: Ayden Jahola

Description: This program accepts student information, dynamically allocates memory to store the information, and then prints the details. It uses dynamic memory allocation functions like malloc, realloc, and free.

Input: The program expects command line input in the following format:
       ./lab9-student.c John CSCE 72.4 Mary Law 69.5 Peter CSCE 70.6 Jimmy Business 88.5 James CSCE 48.7 Sean Business 66.82

Output: outputs the student information line by line in the format:
        Name, Programme, Grade
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    char name[20];
    char programme[20];
    float grade;
};

int main(int argc, char *argv[]) {
    int numStudents = (argc - 1) / 3; // Calculate the number of students

    // Dynamically allocate memory for the students
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    // Initialize the students array
    for (int i = 0; i < numStudents; i++) {
        strncpy(students[i].name, argv[i * 3 + 1], sizeof(students[i].name));
        strncpy(students[i].programme, argv[i * 3 + 2], sizeof(students[i].programme));
        students[i].grade = atof(argv[i * 3 + 3]);
    }

    // Print the student information
    for (int i = 0; i < numStudents; i++) {
        printf("%s, %s, %.2f\n", students[i].name, students[i].programme, students[i].grade);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
