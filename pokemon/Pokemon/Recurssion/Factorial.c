#include <stdio.h>

// Function to compute factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: 0! = 1 and 1! = 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

int main() {
    int num;
    
    // Input number
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    
    // Calculate factorial
    int result = factorial(num);
    
    // Output result
    printf("Factorial of %d is %d\n", num, result);
    
    return 0;
}
