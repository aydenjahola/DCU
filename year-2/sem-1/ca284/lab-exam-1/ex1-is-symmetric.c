/*
program: ex1-is-symmetric.c
Author: Ayden Jahola
Description: check whether the input is a symmetric or not and print yes if its symmetric and no otherwise
Input: string
Output: yes or no

required libraries:
<stdio.h>
<string.h>
*/

#include <stdio.h>
#include <string.h>

// prototype the functions
void check_reverse(char *string);

int main(int argc, char* argv[]) // int the main function
{
    char string[40]; // initialise variable
    char input[40]; // initialise variable

    strcpy(string, argv[1]); // make the string be command line argument

    strcpy(input, argv[1]); // make copy of it

    check_reverse(string); // then reverse the string

    // now we chek if the string reversed is the same as the user input
    if(strcmp(string, input) == 0)
    {
        printf("yes\n"); // print yes if its symmetric
    } else{
        printf("no\n"); // print no otherwise
    }

    return 0; // return success
}

// implement the check/reverse function
void check_reverse(char *string)
{
    int i, tmp, len; // initialise the variables
    len = strlen(string); // initialise the variables

    // iterate to replace letters and reverse them
    for(i = 0; i< len / 2; i++)
    {
        tmp = string[i]; // make i as tmp
        string[i] = string[len - i - 1]; // swap them around
        string[len - i - 1] = tmp; // and back again
    }
}
