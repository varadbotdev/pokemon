#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

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

// Function to push an element to the stack
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

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        char current = postfix[i];

        // If the character is an operand (digit), push it onto the stack
        if (isdigit(current)) {
            push(&stack, current - '0'); // Convert char to int
        }
        // If the character is an operator, pop two operands and perform the operation
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            int operand2 = pop(&stack); // First operand
            int operand1 = pop(&stack); // Second operand

            switch (current) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
        i++;
    }

    // The result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
