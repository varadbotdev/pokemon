#include <stdio.h>
#include <stdlib.h>

// Structure for a heap node
struct HeapNode {
    int value;
    struct HeapNode* next;
};

// Function to create a new heap node
struct HeapNode* createNode(int value) {
    struct HeapNode* newNode = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct HeapNode** head, int value) {
    struct HeapNode* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct HeapNode* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the heap
void displayHeap(struct HeapNode* head) {
    if (!head) {
        printf("Heap is empty.\n");
        return;
    }
    struct HeapNode* temp = head;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Function to swap two nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

// Reheap-up operation for min-heap
void reheapUp(struct HeapNode* head) {
    if (!head || !head->next) return;
    
    struct HeapNode* temp = head;
    while (temp->next) {
        if (temp->value > temp->next->value) {
            swap(temp, temp->next);
        }
        temp = temp->next;
    }
}

// Reheap-down operation for min-heap
void reheapDown(struct HeapNode* head) {
    if (!head) return;

    struct HeapNode* temp = head;
    while (temp && temp->next) {
        if (temp->value > temp->next->value) {
            swap(temp, temp->next);
        }
        temp = temp->next;
    }
}

// Build the heap by calling reheapDown
void buildHeap(struct HeapNode* head) {
    if (!head) return;
    
    struct HeapNode* temp = head;
    while (temp) {
        reheapDown(temp);
        temp = temp->next;
    }
}

// Main function with switch-case for menu
int main() {
    struct HeapNode* heap = NULL;
    int choice, value;

    while (1) {
        printf("\nHeap Operations Menu:\n");
        printf("1. Insert element\n");
        printf("2. Display heap\n");
        printf("3. Build heap\n");
        printf("4. Reheap Up\n");
        printf("5. Reheap Down\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&heap, value);
                break;

            case 2:
                printf("Heap: ");
                displayHeap(heap);
                break;

            case 3:
                buildHeap(heap);
                printf("Heap built.\n");
                break;

            case 4:
                reheapUp(heap);
                printf("Reheap Up operation complete.\n");
                break;

            case 5:
                reheapDown(heap);
                printf("Reheap Down operation complete.\n");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
