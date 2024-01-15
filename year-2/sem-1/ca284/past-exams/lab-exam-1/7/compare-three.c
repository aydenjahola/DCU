#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    int num1, num2, num;
    //if you forget to put an argument it will print out No argument and exit
    if (argc == 1)
    {
      printf ("No arguments");
      return 0;
    }
    else
    {
      //atoi is used to skip all white space characters at beginning of string and convert them into integers
      int num1 = atoi(argv[1]);
      int num2 = atoi(argv[2]);
      int num3 = atoi(argv[3]);
        //first i had to make sure that there were no duplicate values in the command line arguements when comparing
        if (num1==num2)
          printf("error: two numbers entered are the same\n");
        else if (num2==num3)
          printf("error: two numbers entered are the same\n");
        else if (num1==num3)
          printf("error: two numbers entered are the same\n");
        // secondly i then used conditional logic to figure out which is the largest between the three
       else if((num1>num2)&&(num1>num3))
          printf("%d is the largest number.\n", num1);
        else if((num2>num3)&&(num2>num1))
          printf("%d is the largest number.\n", num2);
        else if ((num3>num2)&&(num3>num1))
          printf("%d is the largest number.\n", num3);
        else
          printf("error: two numbers entered are the same\n");
        return 0;
    } 
}
