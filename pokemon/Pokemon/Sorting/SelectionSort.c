#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n);
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

    selectionSort(arr, n);
    printf("Sorted array by selction sort : ");
    printArray(arr, n);
    
    free(arr);
    return 0;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
