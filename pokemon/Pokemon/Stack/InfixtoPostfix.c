#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Function to push an element to the stack
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

// Function to peek the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to check if the character is an operand
int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int k = 0; // Index for postfix array

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        // If the character is an operand, add it to the output
        if (isOperand(current)) {
            postfix[k++] = current;
        }
        // If the character is '(', push it to the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If the character is ')', pop until '('
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Pop '('
        }
        // If the character is an operator
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(current)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, current);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0'; // Null terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
