#include <stdio.h>

// Function to calculate nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base cases: F(0) = 0, F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
}

int main() {
    int num;
    
    // Input number to find its Fibonacci number
    printf("Enter a number to find its Fibonacci value: ");
    scanf("%d", &num);
    
    // Calculate the nth Fibonacci number
    int result = fibonacci(num);
    
    // Output result
    printf("Fibonacci(%d) = %d\n", num, result);
    
    return 0;
}
