#include <stdio.h>

// Recursive function to solve Tower of Hanoi problem
// It also counts the number of steps
void towerOfHanoi(int n, char source, char auxiliary, char destination, int* stepCount) {
    // Base case: when there is only one disk, move it directly
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*stepCount)++;  // Increment step count
        return;
    }

    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary, stepCount);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*stepCount)++;  // Increment step count

    // Move n-1 disks from auxiliary to destination, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, source, destination, stepCount);
}

int main() {
    int n;  // Number of disks
    int stepCount = 0;  // Variable to store the number of steps

    // Input number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the recursive function
    printf("\nSolution for Tower of Hanoi:\n");
    towerOfHanoi(n, 'A', 'B', 'C', &stepCount);  // A is source, B is auxiliary, C is destination

    // Output the total number of steps
    printf("\nTotal steps taken: %d\n", stepCount);

    return 0;
}
