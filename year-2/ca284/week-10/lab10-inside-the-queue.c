/*
Program: lab10-inside-the-queue.c
Author: Ayden Jahola
Description: This program accepts two command-line arguments: the member to find in the list and the integer to insert after that member. It uses a linked list to store a sequence of unique numbers, finds the specified member, inserts the given integer after that member, and displays the updated list line by line.

Input: Command line arguments in the following format:
       ./lab10-inside-the-queue <member> <integer>

Output: Display of integers in the modified linked list, each on a new line.
*/


#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes

// Function to insert a new node after a specific value
void insertAfter(struct Node* head, int findValue, int insertValue);

// Function to display the linked list
void displayList(struct Node* head);

// Function to free the memory allocated for the linked list
void freeList(struct Node* head);

int main(int argc, char* argv[]) {

    int member = atoi(argv[1]);
    int insertValue = atoi(argv[2]);

    // List initialization with the given numbers
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 8;
    head->next = NULL;

    // Add the remaining numbers to the list
    int numbers[] = {7, 3, 4, 5, 6, 9, 2, 14, 12};
    struct Node* current = head;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = numbers[i];
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }

    // Insert the integer after the specified member
    insertAfter(head, member, insertValue);

    // Display the updated list
    displayList(head);

    // Free the allocated memory for the list
    freeList(head);

    return 0;
}

// Function to insert a new node after a specific value
void insertAfter(struct Node* head, int findValue, int insertValue) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == findValue) {
            // Create a new node with the insertValue
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = insertValue;
            newNode->next = current->next;

            // Update the next pointer of the current node
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("%d not found in the list.\n", findValue);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}