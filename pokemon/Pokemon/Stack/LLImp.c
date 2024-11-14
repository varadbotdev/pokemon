#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! No element to pop.\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped %d from the stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// Function to peek the top element of the stack
void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

// Function to display all elements of the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements are: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;  // Initially the stack is empty
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
