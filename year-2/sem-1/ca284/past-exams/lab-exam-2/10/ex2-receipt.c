#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Author: James Hackett
Date: 11/11/2021
Description: This program will calculate the total cost of a receipt.
*/

// Structs
struct Item
{
  char name[50];
  unsigned int amount;
  float price;
  unsigned int promotion;
};

// Function will calculate the total cost of a receipt
int calculate_receipt(struct Item cart[], int num_items)
{
  // Declare Variables
  int i = 0;
  int j = 0;
  float total_price = 0;
  float total_price_promotion = 0;

  // calculate the total price of the items
  for (i = 0; i < num_items; i++)
  {
    if (cart[i].promotion == 0)
    {
      total_price += cart[i].amount * cart[i].price;
    }
  }

  // calculate the total price of the promotional items
  for (i = 0; i < num_items; i++)
  {
    if (cart[i].promotion == 1)
    {
      total_price_promotion += (cart[i].amount * cart[i].price) - (cart[i].amount / 3 * cart[i].price);
    }
  }

  // calculate the final price
  total_price = total_price + total_price_promotion;

  // print the final price
  printf("%.2f\n", total_price);

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
  calculate_receipt(cart, (argc - 1) / 4);

  return 0;
}
