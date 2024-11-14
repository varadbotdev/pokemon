#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Deque structure with pointers to the front and rear nodes
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("%d inserted at the front.\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("%d inserted at the rear.\n", data);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }
    struct Node* temp = deque->front;
    if (deque->front == deque->rear) {  // Only one element in the deque
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    printf("%d deleted from the front.\n", temp->data);
    free(temp);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }
    struct Node* temp = deque->rear;
    if (deque->front == deque->rear) {  // Only one element in the deque
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    printf("%d deleted from the rear.\n", temp->data);
    free(temp);
}

// Function to get the front element of the deque
int getFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1; // Sentinel value for empty deque
    }
    return deque->front->data;
}

// Function to get the rear element of the deque
int getRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return -1; // Sentinel value for empty deque
    }
    return deque->rear->data;
}

// Function to display the elements of the deque
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = deque->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the deque implementation
int main() {
    struct Deque* deque = createDeque();
    int choice, value;

    while (1) {
        printf("\nDoubly Ended Queue Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display Deque\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the front: ");
                scanf("%d", &value);
                insertFront(deque, value);
                break;
            case 2:
                printf("Enter value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(deque, value);
                break;
            case 3:
                deleteFront(deque);
                break;
            case 4:
                deleteRear(deque);
                break;
            case 5:
                value = getFront(deque);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 6:
                value = getRear(deque);
                if (value != -1) {
                    printf("Rear element: %d\n", value);
                }
                break;
            case 7:
                displayDeque(deque);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
