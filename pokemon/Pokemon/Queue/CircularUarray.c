#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
        printf("Queue is Full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

int dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("%d dequeued from queue\n", data);
    return data;
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != rear);
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}