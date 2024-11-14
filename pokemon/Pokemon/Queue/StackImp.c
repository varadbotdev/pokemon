#include <stdio.h>
#include <stdlib.h>

// Define the structure for Stack
struct Stack {
    int *arr;
    int top;
    int capacity;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++(stack->top)] = data;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; // Return a sentinel value when the stack is empty
    }
    return stack->arr[(stack->top)--];
}

// Function to get the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; // Return a sentinel value if the stack is empty
    }
    return stack->arr[stack->top];
}

// Queue implementation using two stacks
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

// Function to create a queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue underflow!\n");
        return -1; // Return a sentinel value when the queue is empty
    }

    // If stack2 is empty, move elements from stack1 to stack2
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }

    return pop(queue->stack2);
}

// Function to get the front element of the queue
int peekQueue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty!\n");
        return -1;
    }

    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }

    return peek(queue->stack2);
}

// Function to display the queue elements
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty!\n");
        return;
    }

    // First, transfer all elements from stack1 to stack2 if stack2 is empty
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            int data = pop(queue->stack1);
            push(queue->stack2, data);
        }
    }

    printf("Queue: ");
    while (!isEmpty(queue->stack2)) {
        printf("%d ", pop(queue->stack2));
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    struct Queue* queue = createQueue(5);

    int choice, value;
    while (1) {
        printf("\nQueue Operations using Two Stacks:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = peekQueue(queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                displayQueue(queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
