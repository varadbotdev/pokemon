#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to reverse a string using stack
void reverseString(char* str) {
    struct Stack stack;
    initStack(&stack);
    
    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }
    
    // Pop characters from the stack and put them back into the string
    int i = 0;
    while (!isEmpty(&stack)) {
        str[i++] = pop(&stack);
    }
}

// Main function
int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';
    
    // Reverse the string
    reverseString(str);
    
    // Print the reversed string
    printf("Reversed string: %s\n", str);
    
    return 0;
}
