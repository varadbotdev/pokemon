#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Circular Queue structure
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the circular queue
void initQueue(struct CircularQueue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == NULL);
}

// Function to enqueue (add) an element to the circular queue
void enqueue(struct CircularQueue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, both front and rear point to the new node
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        newNode->next = q->front;  // Point the rear to front, forming a circular link
    } else {
        q->rear->next = newNode;   // Add the new node after rear
        q->rear = newNode;         // Update the rear to the new node
        q->rear->next = q->front;  // Point the new rear to the front to maintain circularity
    }

    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 if queue is empty
    }

    struct Node* temp = q->front;
    int value = temp->data;

    // If there's only one node in the queue
    if (q->front == q->rear) {
        q->front = q->rear = NULL;  // Queue becomes empty
    } else {
        q->front = q->front->next;  // Move the front pointer to the next node
        q->rear->next = q->front;   // Update the rear's next pointer to the new front
    }

    free(temp);
    printf("Dequeued %d\n", value);
    return value;
}

// Function to peek at the front element of the circular queue
int peek(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot peek.\n");
        return -1; // Return -1 if queue is empty
    }
    return q->front->data;
}

// Function to display all elements in the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != q->rear) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data); // Print the rear node
}

// Main function
int main() {
    struct CircularQueue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
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
