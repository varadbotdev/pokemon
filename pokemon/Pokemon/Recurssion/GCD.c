#include <stdio.h>

// Function to calculate GCD using recursion
int gcd(int a, int b) {
    // Base case: if b is 0, return a as the GCD
    if (b == 0) {
        return a;
    }
    // Recursive case: GCD of b and a % b
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    
    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Calculate GCD using the gcd function
    int result = gcd(num1, num2);
    
    // Display the result
    printf("GCD of %d and %d is: %d\n", num1, num2, result);
    
    return 0;
}
