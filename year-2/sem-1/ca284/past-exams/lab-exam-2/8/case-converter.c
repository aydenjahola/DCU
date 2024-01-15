#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Functions to be called
int checker(char str[30]);
void converter(char string[30]);
int string_length(char string[30]);



int main()
{
    // String 1
    char string[30];
    printf("Enter a string of upper and lower case letters\n");
    scanf("%s", string);

    // Check if String 1 is OK
    if (checker(string) == 1)
    {
        printf("Invalid character entered.\n"); // Error Code
        return 0; // Break out of process
    }
    converter(string); // Convert string if it is OK
    printf("\n");
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



// Function to check for any integers
int checker(char str[30])
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



// Function to display contents of converted array
void display(char array[], int size)
{
    for (int pos = 0; pos <= size - 1; pos++)
    {
        printf("%c", array[pos]);
    }
}



// Function to convert string
void converter(char string[30])
{
    int length = string_length(string);
    char output[length]; // Empty array

    // Check for any integers
    if (checker(string) != 1)
    {
        for (int index = 0; index <= length; index++)
        {
            int ascii = string[index];

            if (ascii >= 'a' && ascii <= 'z') // Check if ascii value is a lowercase letter
            {
                string[index] -= 32; // If it is, then get the uppercase value
                output[index] = string[index]; // append to new array
            }
            else if (ascii >= 'A' && ascii <= 'Z') // Check if ascii value is an uppercase letter
            {
                string[index] += 32; // If it is, then get lowercase value
                output[index] = string[index]; // append to new array
            }
        }
    }

    display(output, length); // Print contents of new array
}
