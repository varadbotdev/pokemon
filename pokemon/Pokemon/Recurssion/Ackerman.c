#include <stdio.h>

// Ackermann function using recursion
int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;  // Base case 1
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);  // Base case 2
    } else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));  // Recursive case
    }
}

int main() {
    int m, n;
    
    // Input values for m and n
    printf("Enter two positive integers m and n for Ackermann function: ");
    scanf("%d %d", &m, &n);
    
    // Calculate the Ackermann function result
    int result = ackermann(m, n);
    
    // Output result
    printf("Ackermann(%d, %d) = %d\n", m, n, result);
    
    return 0;
}
