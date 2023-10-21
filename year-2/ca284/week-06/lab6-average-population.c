/*
Program: lab6-average-population.c
Author: Ayden Jahola
Description: This program accepts the information for a list of countries from the command line. It calculates the average population of all entered countries and prints the details of each country as well as the population average.
Input: The program expects command-line arguments in multiples of 4, where each set of 4 arguments represents a country's details.
Output: It prints the details of all input countries along with the population average.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNTRIES 50

// Define a struct to represent a country
struct Country {
    char name[100];
    char capital[100];
    double population;
    int size;
};

// Function to print the header
void printHeader() {
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
}

// Function to print country details
void printCountry(struct Country country) {
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country.name, country.capital, country.size, country.population);
}

// Function to calculate the average population
double calculateAveragePopulation(struct Country *countries, int numCountries) {
    double totalPopulation = 0.0;
    for (int i = 0; i < numCountries; i++) {
        totalPopulation += countries[i].population;
    }
    return totalPopulation / numCountries;
}

int main(int argc, char *argv[]) {
    int numArguments = argc - 1;

    if (numArguments % 4 != 0 || numArguments / 4 > MAX_COUNTRIES) {
        printf("Usage: %s <Name> <Capital> <Population (in million)> <Size (in km2)>\n", argv[0]);
        return 1;
    }

    int numCountries = numArguments / 4;

    // Create an array of Country structs to store the data
    struct Country countries[MAX_COUNTRIES];

    // Parse the command line arguments and populate the struct array
    for (int i = 0; i < numCountries; i++) {
        int index = i * 4 + 1;  // Calculate the starting index for each country
        sscanf(argv[index], "%99s", countries[i].name);
        sscanf(argv[index + 1], "%99s", countries[i].capital);
        sscanf(argv[index + 2], "%lf", &countries[i].population);
        sscanf(argv[index + 3], "%d", &countries[i].size);
    }

    printHeader();

    // Print the details of each country
    for (int i = 0; i < numCountries; i++) {
        printCountry(countries[i]);
    }

    double averagePopulation = calculateAveragePopulation(countries, numCountries);
    printf("Population average: %.2f\n", averagePopulation);

    return 0;
}
