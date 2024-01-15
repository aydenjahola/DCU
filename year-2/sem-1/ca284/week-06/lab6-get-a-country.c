/*
Program: lab6-get-a-country.c
Author: Ayden Jahola
Description: This program gets the details of a country from the command line, including:
- Name
- Capital
- Population (in million)
- Size (in km2)
The program then prints the information of the country line by line in the specified order.
Input: The program expects four command-line arguments: Name, Capital, Population (in million), and Size (in km2).
Output: It prints the details of the country.
*/

#include <stdio.h>
#include <stdlib.h>

void printCountryDetails(char *name, char *capital, double population, int size) {
    printf("%s\n", name);
    printf("%s\n", capital);
    printf("%.2f million people\n", population);
    printf("%d km2\n", size);
}

int main(int argc, char *argv[]) {

    char *name = argv[1];
    char *capital = argv[2];
    double population = atof(argv[3]);
    int size = atoi(argv[4]);

    printCountryDetails(name, capital, population, size);

    return 0;
}
