#include <stdio.h>
#include <stdlib.h>

#define MAX 32  // Maximum number of bits for a 32-bit integer

// Stack structure
struct Stack {
    int arr[MAX];
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

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to convert a decimal number to binary
void decimalToBinary(int decimal) {
    struct Stack stack;
    initStack(&stack);
    
    // Edge case: If the number is 0
    if (decimal == 0) {
        printf("0");
        return;
    }

    // Convert decimal to binary by pushing remainders to the stack
    while (decimal > 0) {
        push(&stack, decimal % 2); // Push the remainder (0 or 1)
        decimal = decimal / 2;     // Divide the number by 2
    }

    // Pop from the stack and print the binary digits
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
}

// Main function
int main() {
    int decimal;
    
    // Input decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    printf("Binary representation: ");
    decimalToBinary(decimal);
    
    printf("\n");

    return 0;
}
