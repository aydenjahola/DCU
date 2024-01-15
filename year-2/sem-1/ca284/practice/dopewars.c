#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DAYS 30
#define MAX_DRUGS 5

typedef struct {
  char name[20];
  int buyPrice;
  int sellPrice;
  int quantity;
} Drug;

void initializeDrugs(Drug drugs[], int numDrugs);
void printInventory(Drug drugs[], int numDrugs);
int randomPrice(int basePrice);
void randomEvent(Drug drugs[], int numDrugs);

int main() {
  int cash = 1000;
  int days = 1;

  srand(time(NULL));

  Drug drugs[MAX_DRUGS];
  initializeDrugs(drugs, MAX_DRUGS);

  printf("Welcome to Dope Wars!\n");
  printf("You have $%d to start. Good luck!\n", cash);

  while (cash > 0 && days <= MAX_DAYS) {
    printf("\nDay %d\n", days);
    printf("Cash: $%d\n", cash);

    randomEvent(drugs, MAX_DRUGS);

    printInventory(drugs, MAX_DRUGS);

    printf("What will you do?\n");
    printf("1. Buy drugs\n");
    printf("2. Sell drugs\n");
    printf("3. Skip day\n");

    int choice;
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int drugChoice;
      printf("Which drug do you want to buy (1-%d)? ", MAX_DRUGS);
      scanf("%d", &drugChoice);
      drugChoice--; // Adjust for 0-based array

      if (drugChoice >= 0 && drugChoice < MAX_DRUGS) {
        Drug *selectedDrug = &drugs[drugChoice];

        int quantity;
        printf("How many %ss do you want to buy? ", selectedDrug->name);
        scanf("%d", &quantity);

        if (selectedDrug->buyPrice * quantity <= cash) {
          selectedDrug->quantity += quantity;
          cash -= selectedDrug->buyPrice * quantity;
          printf("You bought %d %ss for $%d\n", quantity, selectedDrug->name,
                 selectedDrug->buyPrice * quantity);
        } else {
          printf("You don't have enough cash to buy that many %ss.\n",
                 selectedDrug->name);
        }
      } else {
        printf("Invalid drug choice.\n");
      }
      break;
    }
    case 2: {
      int drugChoice;
      printf("Which drug do you want to sell (1-%d)? ", MAX_DRUGS);
      scanf("%d", &drugChoice);
      drugChoice--; // Adjust for 0-based array

      if (drugChoice >= 0 && drugChoice < MAX_DRUGS) {
        Drug *selectedDrug = &drugs[drugChoice];

        int quantity;
        printf("How many %ss do you want to sell? ", selectedDrug->name);
        scanf("%d", &quantity);

        if (quantity <= selectedDrug->quantity) {
          selectedDrug->quantity -= quantity;
          cash += selectedDrug->sellPrice * quantity;
          printf("You sold %d %ss for $%d\n", quantity, selectedDrug->name,
                 selectedDrug->sellPrice * quantity);
        } else {
          printf("You don't have enough %ss to sell.\n", selectedDrug->name);
        }
      } else {
        printf("Invalid drug choice.\n");
      }
      break;
    }
    case 3:
      printf("You skipped a day.\n");
      break;
    default:
      printf("Invalid choice. Please choose 1, 2, or 3.\n");
    }

    days++;
  }

  if (cash <= 0) {
    printf("\nYou ran out of cash. Game over!\n");
  } else {
    printf("\nCongratulations! You survived %d days with $%d\n", MAX_DAYS,
           cash);
  }

  return 0;
}

void initializeDrugs(Drug drugs[], int numDrugs) {
  strcpy(drugs[0].name, "Weed");
  drugs[0].buyPrice = 10;
  drugs[0].sellPrice = 20;
  drugs[0].quantity = 0;

  strcpy(drugs[1].name, "Cocaine");
  drugs[1].buyPrice = 50;
  drugs[1].sellPrice = 100;
  drugs[1].quantity = 0;

  strcpy(drugs[2].name, "Heroin");
  drugs[2].buyPrice = 100;
  drugs[2].sellPrice = 200;
  drugs[2].quantity = 0;

  strcpy(drugs[3].name, "Meth");
  drugs[3].buyPrice = 20;
  drugs[3].sellPrice = 40;
  drugs[3].quantity = 0;

  strcpy(drugs[4].name, "Ecstasy");
  drugs[4].buyPrice = 30;
  drugs[4].sellPrice = 60;
  drugs[4].quantity = 0;
}

void printInventory(Drug drugs[], int numDrugs) {
  printf("Inventory:\n");
  for (int i = 0; i < numDrugs; i++) {
    printf("%d. %s - Buy: $%d Sell: $%d Quantity: %d\n", i + 1, drugs[i].name,
           drugs[i].buyPrice, drugs[i].sellPrice, drugs[i].quantity);
  }
}

int randomPrice(int basePrice) {
  // Simulate price fluctuations
  int variation = rand() % 21 - 10; // Random number between -10 and 10
  return basePrice + variation;
}

void randomEvent(Drug drugs[], int numDrugs) {
  int event = rand() % 100;

  // 20% chance of price increase
  if (event < 20) {
    int drugIndex = rand() % numDrugs;
    Drug *selectedDrug = &drugs[drugIndex];
    int increase = rand() % 11 + 5; // Price increases between 5 and 15
    selectedDrug->buyPrice += increase;
    selectedDrug->sellPrice += increase;
    printf("News: The price of %s has increased by $%d.\n", selectedDrug->name,
           increase);
  }

  // 10% chance of price decrease
  if (event >= 20 && event < 30) {
    int drugIndex = rand() % numDrugs;
    Drug *selectedDrug = &drugs[drugIndex];
    int decrease = rand() % 11 + 5; // Price decreases between 5 and 15
    selectedDrug->buyPrice -= decrease;
    selectedDrug->sellPrice -= decrease;
    printf("News: The price of %s has decreased by $%d.\n", selectedDrug->name,
           decrease);
  }

  // 5% chance of police encounter
  if (event >= 30 && event < 35) {
    int fine = rand() % 101 + 50; // Fine between $50 and $150
    printf("News: You encountered the police and had to pay a fine of $%d.\n",
           fine);
  }
}
