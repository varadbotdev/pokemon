#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, key;

    // Get number of elements from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search for
    printf("Enter the value to search for: ");
    scanf("%d", &key);

    // Perform linear search
    int result = linearSearch(arr, n, key);

    // Output result
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
