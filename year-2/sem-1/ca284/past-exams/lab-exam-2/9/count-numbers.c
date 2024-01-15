#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//using function called primecheck to check if number is prime
int prime_check(int n) {
    int i;
    for(i=2; i <= n/2; ++i) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char * argv[])
{
    if (argc == 1){
        printf("insufficient command line arguments.\n");
        return 0;
    }

    int p;
    int even = 0;
    int odd = 0;
    int prime = 0;

    int i, j;
    for (i=0, j=1; (i<argc) && (j<argc); i++, j++)
    {
        //looping through the numbers individulally to see if they are all positive
        if (atoi(argv[j]) < 0)
        {
            printf("Error: Only positive integers are permitted.\n");
            exit(0);
        }

    }

    for(p = 1; p < argc; p++)
    {
        //checking if there are no letters permitted
        if (atoi(argv[p]) <= 'a' && atoi(argv[p]) >= 'z')
        {
            printf("Error: only numbers are permitted.\n");
            exit(0);
        }
        if (atoi(argv[p]) >= 'A' && atoi(argv[p]) <= 'Z')
        {
            printf("Error: only numbers are permitted.\n");
            exit(0);
        }
        //counting even numbers
        //(strtol(argv[p], NULL, 10) converts strings to long integers
        if (strtol(argv[p], NULL, 10) % 2 == 0) {
            even++;
        }
        //counting odd numbers
        else {
            odd++;
        }
        //if numbers passed primecheck counting all primes
        if (prime_check(strtol(argv[p], NULL, 10)) == 1 && strtol(argv[p], NULL, 10) != 1) {
            prime++;
        }
    }
    printf("Number of odd numbers: %d\n", odd);
    printf("Number of even numbers: %d\n", even);
    printf("Number of prime numbers: %d\n", prime);
}
