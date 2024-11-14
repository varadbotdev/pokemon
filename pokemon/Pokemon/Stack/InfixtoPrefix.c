#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

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

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Function to perform the actual conversion of infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[k++] = current;  // If operand, add it to the result
        } else if (current == '(') {
            push(&stack, current);  // If '(', push it onto the stack
        } else if (current == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[k++] = pop(&stack);  // Pop operators until '(' is found
            }
            pop(&stack);  // Pop '('
        } else if (isOperator(current)) {
            while (!isEmpty(&stack) && precedence(current) <= precedence(stack.arr[stack.top])) {
                postfix[k++] = pop(&stack);  // Pop operators with higher or equal precedence
            }
            push(&stack, current);  // Push current operator
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression
}

// Function to reverse a string
void reverseString(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Reverse the infix expression
    reverseString(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert the reversed infix to postfix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Reverse the postfix expression to get the prefix expression
    reverseString(postfix);

    // Copy the result to prefix
    strcpy(prefix, postfix);
}

// Helper function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Helper function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Main function
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert the infix expression to prefix
    infixToPrefix(infix, prefix);

    // Display the result
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
