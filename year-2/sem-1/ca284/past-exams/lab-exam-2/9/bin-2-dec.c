#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void binary_to_dec(int digit);

int main(int argc, char *argv[])
{
    char binary[99];
    //adding arguement list into string through concatencation
    int x = 1;
    while (x < argc){
        strcat(binary, argv[x]);
        x++;
    }

    // making sure nothing else but digits are done
    for (int i = 0; i < strlen(binary); i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            printf("Only digits 1 and 0 are permitted.\n");
            exit(0);
        }
    }

    //finding the length of string to satify boolean expression
    if (strlen(binary) > 8)
    {
        printf("Too many binary digits entered.\n");
        exit(0);
    }
    else
    {
        // passing my void fucntion through to complete the conversion
        binary_to_dec(atoi(binary));
        exit(0);
    }
    return 0;
}
    //using maths to convert binary to decimal here
    void binary_to_dec(int digit)
    {
        int num = 0;
        int k = 0;
        int mod;

        while (digit != 0)
        {
            mod = digit % 10;
            digit = digit / 10;
            num += mod * pow(2, k);
            k++;
        }
        printf("%d\n", num);
    }
