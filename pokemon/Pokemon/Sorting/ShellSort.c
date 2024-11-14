#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n);
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

    shellSort(arr, n);
    printf("Sorted array by Shell sort : ");
    printArray(arr, n);
    
    free(arr);
    return 0;
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
