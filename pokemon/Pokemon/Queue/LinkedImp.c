#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }

    // Otherwise, add the new node at the rear and update the rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 if queue is empty
    }

    struct Node* temp = q->front;
    int value = temp->data;

    // Move the front pointer to the next node
    q->front = q->front->next;

    // If the queue becomes empty, reset the rear pointer as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued %d\n", value);
    return value;
}

// Function to peek at the front element of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // Return -1 if queue is empty
    }
    return q->front->data;
}

// Function to display all elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                value = peek(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;

            case 4:
                display(&q);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
