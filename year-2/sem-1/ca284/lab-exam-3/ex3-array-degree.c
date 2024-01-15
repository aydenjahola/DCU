/*
Author: Ayden Jahola
Description: This program accepts n numbers and finds the degree of the list, then prints it out.
Input: n numbers of integers
Output: The degree of the list
Date: 30/11/2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Type definition
typedef struct Node Node;

// Structure definition
struct Node
{
	int value;
	Node *next;
};

// Function prototypes

// Function that returns a new node
Node *newNode(void);

// Function to create a linked list
Node *getNodes(int *length, char *argv[]);

// Function that returns the degree of the linked list
int getDegree(int *length, Node *head);

// Main function
int main(int argc, char *argv[])
{
	int length = argc - 1; // Initialize the length variable

	Node *head = getNodes(&length, argv); // Create a linked list from the given numbers
	int degree = getDegree(&length, head); // Find the degree of the linked list
	printf("%d\n", degree); // Print the degree
	return 0; // Return 0 for success
}

// Function to create a linked list
Node *getNodes(int *length, char *argv[])
{
	Node *head, *current; // Initialize the head and current to be the first node
	head = newNode(); // Make head a new node
	current = head; // Make the current value equal to head
	for (int i = 0; i < *length; ++i) // Iterate through the values
	{
		current->next = newNode(); // Create a new node for the next value
		current->value = atoi(argv[i + 1]); // Assign the current node's value
		current = current->next; // Move to the next node
	}
	current->next = NULL; // End the linked list
	return head; // Return the head of the linked list
}

// Function that returns a new node
Node *newNode()
{
    Node *new = (Node *)calloc(1, sizeof(Node)); // Allocate dynamic memory for a new node
    if (!new) // If there's an error allocating memory
    {
        printf("Error Allocating Memory!\n"); // Print an error message
        exit(0); // Exit the program
    }
    return new; // Return the new node
}

// Function that returns the degree of the linked list
int getDegree(int *length, Node *head)
{
	Node *current, *innerCurrent; // Initialize the node pointers
	current = head; // Make the current value equal to the head
	int degree = 0, count = 0; // Initialize the degree and count to 0
	while (current->next) // Iterate through the list
	{
		innerCurrent = head; // Make the inner current value equal to the head
		count = 0; // Initialize the count as 0
		while (innerCurrent->next) // Iterate through the list to find the frequency
		{
			if (current->value == innerCurrent->value) // If the current value and inner current value are equal
			{
				count += 1; // Increment the count
			}
			innerCurrent = innerCurrent->next; // Move to the next element in the list
		}
		if (count > degree) // Compare the count to the degree to determine the highest frequency
		{
			degree = count; // Update the degree if a higher frequency is found
		}
		current = current->next; // Move to the next element in the list
	}
	return degree; // Return the highest degree
}
