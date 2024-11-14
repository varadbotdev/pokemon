#include <stdio.h>
#include <stdlib.h>

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

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (stack->top == MAX - 1) {
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

// Function to check if the parentheses are balanced
int areParenthesesBalanced(char* expr) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        char current = expr[i];

        // If the current character is an opening parenthesis, push it onto the stack
        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        }
        // If the current character is a closing parenthesis
        else if (current == ')' || current == '}' || current == ']') {
            // Check if the stack is empty, or if the top of the stack doesn't match the corresponding opening parenthesis
            if (isEmpty(&stack)) {
                return 0; // Unbalanced
            }
            char top = pop(&stack);
            if ((current == ')' && top != '(') || 
                (current == '}' && top != '{') || 
                (current == ']' && top != '[')) {
                return 0; // Unbalanced
            }
        }
    }

    // If the stack is empty, all parentheses are balanced
    return isEmpty(&stack);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
