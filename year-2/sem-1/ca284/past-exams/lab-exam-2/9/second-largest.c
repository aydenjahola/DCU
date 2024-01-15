#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
   if (argc == 1){
        printf("Insufficient arguments provided\n");
        return 0;
   }

   //declaring variables
   int i=0,num=0,large=INT_MIN, s_large=INT_MIN;


   for(i=1; i<argc; i++)
   {
     //if input is not an integer break it
     if(sscanf(argv[i], "%d", &num) !=1)
      break;

      //if input is not a positive integer exit the code
      if(num < 0)
      {
         printf("Error: only positive integers are permitted.\n");
         exit(0);
      }
      //finding the second largest number here by bboolean expression
     if(large<num)
     {
        s_large=large;
        large=num;
     }
     else if(s_large<num && num !=large)
     {
       s_large=num;
     }

   }

   printf("%d\n",s_large);

   return 0;
}
