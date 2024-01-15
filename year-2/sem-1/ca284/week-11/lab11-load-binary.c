/*
Program: lab11-load-binary.c
Author: Ayden Jahola

Description: A program to read student information from a binary file and display it.

Input: The program reads data from the binary file "studentBinary.bin" containing information about students.

Output: The program displays the following information for each student:
    - Name
    - College
    - Age
    - Grade
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
typedef struct {
    int nameLength;   // Length of the student name
    char *name;       // Student name
    int collegeLength; // Length of the college name
    char *college;     // College name
    int age;           // Age of the student
    float grade;       // Grade of the student
} Student;


void displayStudent(Student student) {
    printf("Name: %s\n", student.name);
    printf("College: %s\n", student.college);
    printf("Age: %d\n", student.age);
    printf("Grade: %.2f\n", student.grade);
    }

void freeStudentMemory(Student student) {
    free(student.name);
    free(student.college);
}

Student readStudent(FILE *file) {
    Student student;

    // Read the name length
    fread(&student.nameLength, sizeof(int), 1, file);

    // Allocate memory for the name
    student.name = (char *)malloc(student.nameLength + 1);

    // Read the name
    fread(student.name, sizeof(char), student.nameLength, file);
    student.name[student.nameLength] = '\0'; // Null-terminate the string

    // Read the college length
    fread(&student.collegeLength, sizeof(int), 1, file);

    // Allocate memory for the college
    student.college = (char *)malloc(student.collegeLength + 1);

    // Read the college
    fread(student.college, sizeof(char), student.collegeLength, file);
    student.college[student.collegeLength] = '\0'; // Null-terminate the string

    // Read the age
    fread(&student.age, sizeof(int), 1, file);

    // Read the grade
    fread(&student.grade, sizeof(float), 1, file);

    return student;
}

int main() {
    FILE *file = fopen("studentBinary.bin", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (1) {
        Student student = readStudent(file);

        if (feof(file)) {
            // End of file
            break;
        }

        // Display the student data
        displayStudent(student);

        // Free allocated memory
        freeStudentMemory(student);
    }

    // Close the file
    fclose(file);

    return 0;
}
