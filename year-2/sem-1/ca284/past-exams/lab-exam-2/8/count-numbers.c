#include <stdlib.h>
#include <stdio.h>

// Functions to be called
int checker(char *arguments[], int size);
int even_odd(char *arguments[], int size);
int prime_check(int number);
int prime_loop(char *arguments[], int size);
int integer_size(int number);
int string_length(char string[30]);



int main(int argc, char *argv[])
{
    if (checker(argv, argc) == 1)
    {
        return 0; // If there is letter/negative value, then break out of process
    }
    else if (argc == 1)
    {
        printf("insufficient command line arguments.\n");
        return 0;
    }
    else
    {
        even_odd(argv, argc);
        prime_loop(argv, argc);
    }
    return 0;
}



// Function to check for letters and negative values
int checker(char *arguments[], int size)
{
    for (int index = 1; index <= size - 1; index++)
    {
        int check_len = string_length(arguments[index]); // Checks length of number before conversion to int
        int val = atoi(arguments[index]); // Conversion to int
        int *value = &val;
        int integer = val;

        if (*value == 0) // Non-integers get converted to 0g
        {
            printf("Error: only numbers are permitted.\n"); // Error Code
            return 1; // Break out of loop
        }
        else if (*value < 0) // Searching for negative integers
        {
            printf("Error: Only positive integers are permitted.\n"); // Error Code
            return 1; // Break out of loop
        }
        else if (check_len != integer_size(integer))
        {
            printf("Error: only numbers are permitted.\n"); // Error Code
            return 1; // Break out of loop
        }
    }
    return 0;
}



// Function to check integer size
int integer_size(int number)
{
    int count = 0;

    // Calculations
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
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



// Function to check for even and odd numbers
int even_odd(char *arguments[], int size)
{
    int even = 0, odd = 0;
    for (int indx = 1; indx <= size - 1; indx++)
    {
        int num = atoi(arguments[indx]); // convert to integer
        int *number = &num;

        if (*number % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("Number of odd numbers: %d\n", odd);
    printf("Number of even numbers: %d\n", even);
    return 0;
}



// Function check if a value is a prime number
int prime_check(int num)
{
    if (num == 2) // 2 is a prime number
    {
        return 1;
    }
    else if (num == 1) // 1 is not a prime number
    {
        return 0;
    }
    else
    {
        for (int checknum = 2; checknum <= num - 1; checknum++) // Check all factors
        {
            if (num % checknum == 0) // Check if any factor divides into number
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}



// Function to loop through array of values and return total prime numbers present
int prime_loop(char *arguments[], int size)
{
    int prime = 0; // Total prime numbers
    for (int counter= 1; counter <= size - 1; counter++)
    {
        int nbr = atoi(arguments[counter]);
        int *nubr = &nbr;

        if (prime_check(*nubr) == 1) // Check if each value in array is prime or not
        {
            prime++; // If prime then add 1 to total
        }
    }
    printf("Number of prime numbers: %d\n", prime);
    return 0;
}
