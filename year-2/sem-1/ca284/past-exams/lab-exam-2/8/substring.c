#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Functions to be called
void checker(char string[30], char checkstring[30]);
int search(char str[30]);
int string_length(char str[30]);



int main()
{
    char string1[30], string2[30];
    printf("Enter the first string:\n"); // Main string
    scanf("%s", string1);

    // Check string 1
    if (search(string1) == 1)
    {
        printf("Invalid character entered\n");
        return 0;
    }
    else
    {
        printf("Enter the second string:\n"); // substring
        scanf("%s", string2);

        // Check string 2
        if (search(string2) == 1)
        {
            printf("Invalid character entered\n");
            return 0;
        }

        // If both strings are fine then proceed with checker
        checker(string1, string2);
        return 0;
    }
}



// Function to check for any integers
int search(char str[30])
{
    int len = string_length(str);
    for (int index = 0; index <= len - 1; index++)
    {
        int val = isalpha(str[index]);

        if (val == 0) // isalpha function returns 0 if value is an integer
        {
            return 1; // Break out of loop
        }
    }
    return 0;
}



// Function to get length of string
int string_length(char string[30])
{
    int string_length = 0; // Length of string

    // Loop to get length of string (Alternative to strlen())
    for (int i = 0; string[i] != '\0'; i++)
    {
        string_length++;
    }

    return string_length; // Return Length
    return 0;
}



void checker(char string[30], char checkstring[30])
{
    // Length1 = length of main string, Length2 = length of substring
    int length1 = string_length(string) - 1, length2 = string_length(checkstring), total = 0;

    for (int index1 = 0; index1 <= length1; index1++) // Loop through main string
    {
        if (string[index1] == checkstring[0]) // Check if current value = first letter of substring
        {
            for (int check = 0; check <= length2 - 1; check++) // If it is, then begin to loop through substring
            {
                if (string[index1 + check] == checkstring[check]) // Check if values in substring corresspond to the next value in main string
                {
                    total++; // Keep count if they are equal
                }
            }
        }
    }
    // Compare string sizes
    if (total == length2)
    {
        printf("the string '%s' is contained in the string '%s'\n", checkstring, string);
    }
    else
    {
        printf("the string '%s' is not contained in the string '%s'\n", checkstring, string);
    }
}
