#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Functions to be called
int checker(char *array[], int size);
void bin_converter(char *array[], int size, int *total);

int main(int argc, char *argv[])
{
    int tot = 0;

    if (checker(argv, argc) == 1 || checker(argv, argc) == 2)
    {
        printf("Only digits 1 and 0 are permitted.\n"); // Error Code
        return 0; // Break
    }
    else if (checker(argv, argc) == 3)
    {
        printf("Too many binary digits entered.\n"); // Error Code
        return 0; // Break
    }
    else // Conversion process
    {
        bin_converter(argv, argc, &tot);
        printf("%d\n", tot);
        return 0;
    }
}



// Function to check size and also for invalid characters
int checker(char *array[], int size)
{
    int count = 0;

    // Check for letters
    for (int ind = 1; ind <= size - 1; ind++)
    {
        if (isalpha(*array[ind]) != 0)
        {
            return 2;
        }
        else
        {
            // Convert to integer
            int val = atoi(array[ind]);
            int *value = &val;

            // Check if there's a non-binary integer
            if (*value != 0 && *value != 1)
            {
                return 1;
            }
            else
            {
                count++;
            }

            // Check if length exceeds 8
            if (count > 8)
            {
                return 3;
            }
        }
    }
    return 0;
}


// Function to convert to decimal
void bin_converter(char *array[], int size, int *total)
{
    // Loop through array backwards
    // Index2 keeps record of the powers E.g If last item in array is 1, then it value would be 2 raised to power of 0
    for (int index = size - 1, index2 = 0; index >= 1; index--, index2++)
    {
        int val = atoi(array[index]);
        int *value = &val;

        if (*value == 1)
        {
            double power = pow(2, index2);
            *total = *total + power; // Update total value
        }
    }
}
