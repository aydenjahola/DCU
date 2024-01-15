#include<stdio.h>
#include <stdlib.h>

//declaring the function
int Hailstone(int);

int main(int argc, char **argv)
{
    int n, i;
    //if you forget to put an argument it will print out No argument and exit
    if (argc == 1)
    {
      printf ("No arguments");
    }
    else
    {
      //atoi is used to skip all white space characters at beginning of string and convert them into integers
      int n = atoi(argv[1]);
      //using a while loop to make the sequence stop when it reaches 1
      while(n!=1)
      {
        //called the function and now printing it
        n = Hailstone(n);
        printf("%d\n", n);
      }
      return 0;
    }
}
    //made a functions that performs the sequence of hailstone
    int Hailstone(int n)
    {
        if(n%2 == 0)
        {
          return n = n / 2;
        }
        else
        {
          return n = (3 * n)+ 1;
        }
    }
