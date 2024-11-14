
#include <stdio.h>
#define MAX 100 // Maximum size of the stack

int stack[MAX]; // Stack array
int top = -1;   // Initialize top to -1 (stack is empty)

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}

// Function to peek (get the top element of the stack without removing it)
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Function to display all elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
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
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
