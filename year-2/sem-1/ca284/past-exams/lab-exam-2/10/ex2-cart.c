#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Author: James Hackett
Date: 11/11/2021
Description: This program will take a string of letters and return a 1 or 0 based on the number of appearances of the letter 'a'
*/

// Structs
struct Item
{
  char name[50];
  unsigned int amount;
  float price;
  unsigned int promotion;
};

// Function to print the cart
// Input: The cart
// Output: 0
int print(struct Item cart[50], int size)
{
  // Declare Variables
  int i = 0;

  // print the items
  for (i = 0; i < size; i++)
  {
    if (cart[i].promotion == 1)
    {
      printf("%s,%d,%.2f,On Sale\n", cart[i].name, cart[i].amount, cart[i].price);
    }
    else
    {
      printf("%s,%d,%.2f,No Sale\n", cart[i].name, cart[i].amount, cart[i].price);
    }
  }

  return 0;
}

// Main Function
int main(int argc, char *argv[])
{
  // Declare Variables
  int i = 0;
  struct Item cart[50];

  // read in the arguments
  for (i = 0; i < (argc - 1) / 4; i++)
  {
    strcpy(cart[i].name, argv[i * 4 + 1]);
    cart[i].amount = atoi(argv[i * 4 + 2]);
    cart[i].price = atof(argv[i * 4 + 3]);
    cart[i].promotion = atoi(argv[i * 4 + 4]);
  }

  // print the information of the items
  print(cart, (argc - 1) / 4);

  return 0;
}
