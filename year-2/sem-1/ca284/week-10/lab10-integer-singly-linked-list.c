/*
Program: lab10-integer-singly-linked-list.c
Author: Ayden Jahola
Description: This program implements a singly linked list to store integer elements. It accepts command line arguments, where the first argument is the number of integer elements, and the subsequent arguments are the input integers. The program uses dynamic memory allocation to create nodes for each integer in the linked list and then displays the numbers line by line.

Input: Command line arguments in the following format:
       ./lab10-integer-singly-linked-list <number_of_elements> <element1> <element2> ... <elementN>

Output: Display of input integers in the linked list, each on a new line.
*/


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int value;
    struct Node* next;
};

// function prototypes

// Function to create a new node with the given value
struct Node* createNode(int val);

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int val);

// Function to display all numbers in the linked list
void displayList(struct Node* head);

// Function to free the memory allocated for the linked list
void freeList(struct Node* head);


int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);

    struct Node* head = NULL;

    // Parse and insert elements into the linked list
    for (int i = 2; i < argc; i++) {
        int element = atoi(argv[i]);
        insertNode(&head, element);
    }

    // Display the linked list
    displayList(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}

// Function to create a new node with the given value
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display all numbers in the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}