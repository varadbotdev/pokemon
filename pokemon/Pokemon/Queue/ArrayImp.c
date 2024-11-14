#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    // If the queue is empty, set front and rear to 0
    if (q->front == -1) {
        q->front = 0;
    }

    // Move rear to the next position and add the element
    q->rear++;
    q->arr[q->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 if queue is empty
    }

    int value = q->arr[q->front];

    // If there is only one element in the queue, reset the queue
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        // Move front to the next position
        q->front++;
    }

    printf("Dequeued %d\n", value);
    return value;
}

// Function to peek at the front element of the queue
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // Return -1 if queue is empty
    }

    return q->arr[q->front];
}

// Function to display all elements of the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
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
