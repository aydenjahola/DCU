/*
program: ex1-largest-smallest.c
Author: Ayden Jahola
Description: find the largest or smallest numbers in array of floats taken from command line
Input: array of float numbers
Output: the largest or smallest number in the array per user input

required libraries:
<stdio.h>
<stdlib.h>
<string.h>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototype the functions
float largest(float numbers[], int len); // define the type of function as float
float smallest(float numbers[], int len); // define the type of function as flaot

int main(int argc, char* argv[]) // int the main function
{

    int i; // assign variable i
    float result; // define variable result as float
    float numbers[argc - 1]; // take the float numbers from command line
    int len = argc - 2; // check the length of the array with only the float numbers
    int j = 0; // define variable j as integer

        for(i = 2; i < argc; i++) // convert elements of argv array to new array of integers
        {
            numbers[j] = atof(argv[i]);
            j++;
        }

    // check which input/function the user input to use, so smallest or largest
    if(strcmp(argv[1], "largest") == 0) 
    {
        result = largest(numbers, len);
        printf("%.2f\n", result);
    } else {
        result = smallest(numbers, len);
        printf("%.2f\n", result);
    }

    return 0; // return success
}

// implement the largest function and add the logic/algorithm
float largest(float numbers[], int len)
{
    int i; // define variable i 
    float largest_num; // define variable largest num as float to keep track of our largest number

    // iterate through the numbers and fine the largest number 
    for(i = 0; i < len; i++)
    {
        if(numbers[i] > largest_num)
        {
            largest_num = numbers[i]; // store the larget number in the largest_num variable
        }
    }

    return largest_num; // return the result of the function aka the largest number
}

// implement the smallest function and add the logic/algorithm
float smallest(float numbers[], int len)
{
    int i; // define variable i
    float smallest_num = numbers[0]; // define variable smallest num as float and assign the first number as the smallest
    // iterate through the numbers and fine the smallest number 
    for(i = 0; i < len; i++)
    {
        if(numbers[i] < smallest_num)
        {
            smallest_num = numbers[i]; // store the larget number in the largest_num variable
        }
    }

    return smallest_num; // return the result of the function aka the largest number

}
