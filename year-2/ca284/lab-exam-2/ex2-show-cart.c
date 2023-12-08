/*
Author: Ayden Jahola
Description: This program reads a list of items in the cart and prints the information for each item, indicating whether it's on sale or not.
Input: List of items in the shopping cart
Output: Cart items with their information
Date: 02/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure for items in the cart
struct Items
{
  char name[50];
  unsigned int amount;
  float price;
  unsigned int promotion; // Promotion flag (0 for no promotion, 1 for promotion)
};

// Function prototype
int showCart(struct Items cart[50], int size);

// Main function
int main(int argc, char *argv[])
{
  // Declare variables
  int i = 0;
  struct Items cart[50];

  // Take in the arguments from the command line
  for (i = 0; i < (argc - 1) / 4; i++)
  {
    // Parse and store item details
    strcpy(cart[i].name, argv[i * 4 + 1]);
    cart[i].amount = atoi(argv[i * 4 + 2]);
    cart[i].price = atof(argv[i * 4 + 3]);
    cart[i].promotion = atoi(argv[i * 4 + 4]);
  }

  // Show the items in the cart and print their information
  showCart(cart, (argc - 1) / 4);

  return 0;
}

// Function to print or show the cart items
int showCart(struct Items cart[50], int size)
{
  // Declare variables
  int i = 0;

  // Show and print the items in the cart along with sale information
  for (i = 0; i < size; i++)
  {
    if (cart[i].promotion == 1)
    {
      printf("%s, %d, %.2f, On Sale\n", cart[i].name, cart[i].amount, cart[i].price);
    }
    else
    {
      printf("%s, %d, %.2f, No Sale\n", cart[i].name, cart[i].amount, cart[i].price);
    }
  }

  return 0;
}
