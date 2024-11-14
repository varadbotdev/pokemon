#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index if found
        }

        // If the key is greater, ignore the left half
        if (arr[mid] < key) {
            left = mid + 1;
        } 
        // If the key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, key;

    // Get number of elements from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1;
    }

    int arr[n]; // Declare array of size n

    // Input sorted elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search for
    printf("Enter the value to search for: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, n, key);

    // Output result
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
