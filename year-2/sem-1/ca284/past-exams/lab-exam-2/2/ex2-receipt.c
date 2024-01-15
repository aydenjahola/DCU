/*
* Author: Duarte Martinho
* Purpose: Accepts the information of a list of shopping items in a cart at a grocery shop and calculates the total price for all items.
* Language:  C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Defines */
#define MAX 50

struct Cart {
    char item[20];
    int quantity;
    float price;
    int isSale;
};

typedef struct Cart Cart;


/* Function Prototypes */
void fillCart(Cart *cartItem, char *label, int quantity, float price, int isSale);
void loopCart(Cart cart[MAX], int count);
void addTotal(Cart *cartItem, float *ptotal);
void addTotalPromotion(Cart *cartItem, float *ptotal);

int main(int argc, char*argv[]) {
    int length = (argc - 1) / 4;
    int count = 0;
    Cart cart[MAX];
    for (int i = 0; i < length; i++) {
        fillCart(
            &cart[count],
            argv[(count * 4) + 1],
            atoi(argv[(count * 4) + 2]),
            atof(argv[(count * 4) + 3]),
            atoi(argv[(count * 4) + 4])
        );
        count++;
    }
    loopCart(cart, count);
    return 0;
}

/*
* Function Name: fillCart
* Description: Adds a new cart
* Args: New cart item, char item label, int quantity, float price, int isSale
* Returns: no return (void)
*/
void fillCart(Cart *cartItem, char *label, int quantity, float price, int isSale) {
    strcpy(cartItem->item, label);
    cartItem->quantity = quantity;
    cartItem->price = price;
    cartItem->isSale = isSale;
    // printf("%s %d %.2f %d\n", cartItem->item, cartItem->quantity, cartItem->price, cartItem->isSale);
}

/*
* Function Name: loopCart
* Description: loops through the cart and calls either the addTotal function or addTotalPromotion and keeps track of total price
* Args: all carts item and count of how many cart items exist
* Returns: no return (void)
*/
void loopCart(Cart cart[MAX], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        if (cart[i].isSale == 0) {
            addTotal(&cart[i], &total);
        } else {
            addTotalPromotion(&cart[i], &total);
        }
    }
    printf("%.2f\n", total);
}

/*
* Function Name: addTotal
* Description: Adds the total price for the cartitem passed to the total pointer
* Args: pointer to the cartItem, pointer to the total
* Returns: no return (void)
*/
void addTotal(Cart *cartItem, float *ptotal) {
    *ptotal += cartItem->quantity * cartItem->price;
}

/*
* Function Name: addTotalPromotion
* Description: Adds the total price for the cartitem passed to the total pointer
* Args: pointer to the cartItem, pointer to the total
* Returns: no return (void)
*/
void addTotalPromotion(Cart *cartItem, float *ptotal) {
    /* Find how many group of 3 and multiply by 2 (3 items - 1 free) */
    int quantity = cartItem->quantity / 3 * 2;
    /* Find remainder of full price items because don't fit in groups of 3 */
    int remainder = cartItem->quantity % (cartItem->quantity / 3);
    *ptotal += (quantity * cartItem->price) + (remainder * cartItem->price);
}
