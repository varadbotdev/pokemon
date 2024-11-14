#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Pointing to itself to maintain circular nature
    return newNode;
}

// Function to insert at the end of a circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to reverse the circular linked list
void reverseList(struct Node** head) {
    if (*head == NULL || (*head)->next == *head) {
        return;
    }
    struct Node *prev = NULL, *current = *head, *next = NULL;
    struct Node *last = *head; // Track the last node for circular linkage

    // Traversing and reversing the circular linked list
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev; // Fix the last node to point to new head
    *head = prev;         // Update head to the last node visited
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data;

    // Creating a circular linked list
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("\nOriginal Circular List:\n");
    display(head);

    // Reversing the circular linked list
    reverseList(&head);

    printf("\nReversed Circular List:\n");
    display(head);

    return 0;
}
