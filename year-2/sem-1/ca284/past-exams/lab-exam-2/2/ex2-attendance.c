/*
* Author: Duarte Martinho
* Purpose: Accepts n number of attendance records for n students.
* Each record contains a sequence of characters, where each character refers to the attendance status of the student
* Language:  C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */
#define MAX 50

struct Attendance {
    int Present;
    int Absent;
};

typedef struct Attendance Attendance;

/* Function Prototypes */
void checkAward(int present, int absent);

int main(int argc, char*argv[]) {
    Attendance attendance[MAX];
    for (int i = 1; i < argc; i++) {
        attendance[i - 1].Present = 0;
        attendance[i - 1].Absent = 0;
        for (int j = 1; j < strlen(argv[i]) - 1; j++) {
            char* a = "P";
            if (strcmp(a, &argv[i][j]) < 0) {
                attendance[i - 1].Present++;
            } else {
                attendance[i - 1].Absent++;
            }
        }
        checkAward(attendance[i - 1].Present, attendance[i - 1].Absent);
    }
    return 0;
}

/*
* Function Name: checkAward
* Description: checks if the student was absent more than 2 days, then prints out the result
* Args: int count present , int count absent
* Returns: no return (void)
*/
void checkAward(int present, int absent) {
    if (absent > 2) {
        printf("0\n");
    } else {
        printf("1\n");
    }
}
