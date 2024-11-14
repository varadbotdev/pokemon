#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reheap Up (used after inserting an element)
void reheapUp(int heap[], int index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Reheap Down (used after deleting the root element)
void reheapDown(int heap[], int size, int index) {
    int leftChild, rightChild, largest;
    while (index < size) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largest = index;

        // Check if left child exists and is greater than current largest
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check if right child exists and is greater than current largest
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If largest is still the current index, heap property is satisfied
        if (largest == index) {
            break;
        }

        // Swap and continue to reheap down
        swap(&heap[index], &heap[largest]);
        index = largest;
    }
}

// Function to build the heap from an array
void buildHeap(int heap[], int size) {
    // Start from the last non-leaf node and apply reheap down
    for (int i = (size / 2) - 1; i >= 0; i--) {
        reheapDown(heap, size, i);
    }
}

// Function to display the heap
void displayHeap(int heap[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Function to insert an element into the heap
void insert(int heap[], int* size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap is full, cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end of the heap
    heap[*size] = value;
    (*size)++;

    // Reheap up to maintain the heap property
    reheapUp(heap, *size - 1);
}

// Function to delete the root (max element) from the heap
void deleteRoot(int heap[], int* size) {
    if (*size <= 0) {
        printf("Heap is empty, nothing to delete.\n");
        return;
    }

    // Replace the root with the last element
    heap[0] = heap[*size - 1];
    (*size)--;

    // Reheap down to maintain the heap property
    reheapDown(heap, *size, 0);
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;
    int choice, value;

    while (1) {
        printf("\nHeap Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete Root\n");
        printf("3. Build Heap\n");
        printf("4. Display Heap\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(heap, &size, value);
                break;
            case 2:
                deleteRoot(heap, &size);
                break;
            case 3:
                printf("Enter number of elements to build heap: ");
                int n;
                scanf("%d", &n);
                printf("Enter elements:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &heap[i]);
                }
                size = n;
                buildHeap(heap, size);
                break;
            case 4:
                displayHeap(heap, size);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
