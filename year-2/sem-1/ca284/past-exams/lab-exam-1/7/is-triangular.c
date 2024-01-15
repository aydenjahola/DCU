#include<stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])

{
    int i, sum=0;
	//if you forget to put an argument it will print out No argument and exit
    if (argc == 1)
    {
      printf ("No arguments");
      return 0;
    }
    else
      {
		//converting our string to a long integer
	    long number = strtol(argv[1], NULL, 10);
		//used a for loop  to determine if a number was a trinagular number or not
		//triangular numbers are numbers that can make a trinagular dot pattern
	    for(i=0;i < number; i++)
	    {
	      sum = sum+i;
	      if(sum == number)
	      {
	      printf("%s is a triangular number.\n", argv[1]);
	      break;
	    }
	  }
	
	  if(number == i)
	  {
	    printf("%s is not a triangular number.\n", argv[1]);
	  }
	  return(0);
    }
}
