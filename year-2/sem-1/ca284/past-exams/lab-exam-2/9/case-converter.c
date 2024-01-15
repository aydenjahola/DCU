#include <stdio.h>
int main ()
{
    //giving our string a limit of how many characters it should take
   int i = 0;
   char str, a[1000];

   printf("Enter a string of upper and lower case letters\n");
   scanf("%s", a);

   //signify the end of a string called as the null terminator
   while (a[i] != '\0') {
      str = a[i];
      //checking if its a smaller letter convert to large letter
      // if its a big letter convert it to small letter
      if (str >= 'a' && str <= 'z'){
          a[i] = a[i] - 32;
      }
      else if (str >= 'A' && str <= 'Z'){
          a[i] = a[i] + 32;
      }
      //numbers are not permitted
      else if (str >= '0' && str <= '9'){
          printf("Invalid character entered.\n");
          return 0;
      }
      //anything else thats not a letter is not perrmitted also
      else{
          printf("Invalid character entered.\n");
          return 0;
      }
      i++;
   }
   printf("%s\n", a);
   return 0;
}
