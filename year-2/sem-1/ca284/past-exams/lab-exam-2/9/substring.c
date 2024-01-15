#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    //declaring limit of character for str1 and str2
    char str1[80], str2[80];
    int l, i, j, x;

    printf("Enter the first string:\n");
    scanf("%s", str1);

    //looping to character individually to see if it contain an invalid character
    for (x = 0; str1[x] !='\0'; x++) {

        if(str1[x] >= '0' && str1[x] <= '9')
        {
            printf("Invalid character entered\n");
            exit(0);
        }
    }

    printf("Enter the second string:\n");
    scanf("%s", str2);

    //looping to character individually to see if it contain an invalid character
    for (x = 0; str1[x] !='\0'; x++) {

        if(str2[x] >= '0' && str2[x] <= '9')
        {
            printf("Invalid character entered\n");
            exit(0);
        }
    }

    //finding length of second string
    for (l = 0; str2[l] != '\0'; l++);
    for (i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++)
    {

            if (str1[i] == str2[j])
            {
                j++;
            }
            else
            {
                j = 0;
            }
    }
        if (j == l)
        {
                printf("the string '%s' is contained in the string '%s'\n",str2, str1);
        }
        else
        {
            printf("the string '%s' is not contained in the string '%s'\n",str2, str1);
        }
        return 0;
}

