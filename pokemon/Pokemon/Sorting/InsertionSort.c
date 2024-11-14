#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
    printf("Sorted array by Insertion sort is : ");
    printArray(arr, n);
    
    free(arr);
    return 0;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
