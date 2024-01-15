/*
Program: lab10-float-doubly-linked-list.c
Author: Ayden Jahola
Description: This program implements a doubly linked list to store floating-point elements. It accepts command line arguments, where the first argument is the number of floating-point elements, and the subsequent arguments are the input floating-point numbers. The program uses dynamic memory allocation to create nodes for each float in the doubly linked list and then displays the numbers in reversed order.

Input: Command line arguments in the following format:
       ./lab10-float-doubly-linked-list <number_of_elements> <float1> <float2> ... <floatN>

Output: Display of input floating-point numbers in reversed order, each on a new line.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    float value;
    struct Node* next;
    struct Node* prev;
};

// function prototypes

// Function to create a new node with the given value
struct Node* createNode(float val);

// Function to insert a new node at the end of the doubly linked list
void insertNode(struct Node** head, float val);

// Function to display all numbers in reversed order in the doubly linked list
void displayListReversed(struct Node* head);

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head);


int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);

    struct Node* head = NULL;

    // Parse and insert elements into the doubly linked list
    for (int i = 2; i < argc; i++) {
        float element = atof(argv[i]);
        insertNode(&head, element);
    }

    // Display the doubly linked list in reversed order
    displayListReversed(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}


// Function to create a new node with the given value
struct Node* createNode(float val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertNode(struct Node** head, float val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display all numbers in reversed order in the doubly linked list
void displayListReversed(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%.2f\n", current->value);
        current = current->prev;
    }
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}