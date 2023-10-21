/*
Program: lab6-cal-everything.c
Author: Ayden Jahola
Description: This program accepts two non-zero integer numbers, a and b. It performs various mathematical calculations and returns the results line by line, with two digits after the decimal point. The calculations include:
- Sum a + b
- Difference a - b
- Product a * b
- Division a / b
- Power a^b
- Natural Logarithm log(a) + log(b)

The program uses function pointers to perform these calculations.
Input: The program expects two non-zero integer numbers as command-line arguments.
Output: It prints the results of the calculations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (*Operation)(double, double);

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0.0;  // Division by zero, returning 0 as a placeholder
    }
}

double power(double a, double b) {
    return pow(a, b);
}

double log_sum(double a, double b) {
    if (a > 0 && b > 0) {
        return log(a) + log(b);
    } else {
        return 0.0;  // Invalid input for logarithm, returning 0 as a placeholder
    }
}

int main(int argc, char *argv[]) {

    double a = atof(argv[1]);
    double b = atof(argv[2]);

    Operation operations[] = {add, subtract, multiply, divide, power, log_sum};

    int num_operations = sizeof(operations) / sizeof(operations[0]);

    for (int i = 0; i < num_operations; i++) {
        double result = operations[i](a, b);
        printf("%.2f\n", result);
    }

    return 0;
}
