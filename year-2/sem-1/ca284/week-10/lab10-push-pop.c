/*
Program: lab10-push-pop.c
Author: Ayden Jahola
Description: This program demonstrates push and pop operations on a linked list. It accepts command line arguments, where the first argument is the number of integers, the next n arguments are the input integers, and the last argument is the new integer to add to the list. The program removes the last two elements (pop twice) and then adds the last two arguments to the end (push twice). Finally, the program displays all elements line by line.

Input: Command line arguments in the following format:
       ./lab10-push-pop <number_of_elements> <element1> <element2> ... <elementN> <new_element>

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

// Function to create a new node
struct Node* createNode(int data);

// Function to push a new node to the end of the list
void push(struct Node** head, int data);

// Function to pop the last node from the list
void pop(struct Node** head);

// Function to display all elements in the list
void display(struct Node* head);

int main(int argc, char* argv[]) {

    int n = atoi(argv[1]);

    struct Node* head = NULL;

    // Populate the linked list with the given integers
    for (int i = 2; i < n + 2; i++) {
        push(&head, atoi(argv[i]));
    }

    // Perform pop twice
    pop(&head);
    pop(&head);

    // Perform push twice
    push(&head, atoi(argv[n + 2]));
    push(&head, atoi(argv[n + 3]));

    // Display all elements in the list
    display(head);

    // Free the allocated memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a new node to the end of the list
void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

// Function to pop the last node from the list
void pop(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Cannot pop if the list is empty or has only one element
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Function to display all elements in the list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}