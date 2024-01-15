#include <stdio.h>
#include <stdlib.h>

void secondLargest(int *numbers, int *index, int size);

int main(int argc, char *argv[])
{
    int position = 0;
    secondLargest(argv, position, argc);

}


void secondLargest(int *numbers, int *index, int size)
{
    int largest = 0, second_largest = 0, index2 = 0, pos = 0;

    for (int item = 1; item <= size - 1; item++)
    {
        int val = numbers[item];

        if (val >= largest)
        {
            largest = val;
        }
    }

    for (int pos = 0; pos <= size - 1; pos++)
    {
        if ((numbers[pos] != largest) && (numbers[pos] > second_largest))
        {
            second_largest = numbers[pos];
            index2 = pos;
        }
    }
    printf("%d\n", second_largest);
}

