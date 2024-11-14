#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure to represent a polynomial term
struct Node {
    int coeff;          // Coefficient of the term
    int exp;            // Exponent of the term
    struct Node *next;  // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertNode(struct Node* head, int coeff, int exp) {
    struct Node* temp = head;
    struct Node* newNode = createNode(coeff, exp);
    if (head == NULL) {
        return newNode;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
    struct Node* temp = poly;
    if (temp == NULL) {
        printf("0\n");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to evaluate the polynomial for a given value of x
int evaluatePolynomial(struct Node* poly, int x) {
    int result = 0;
    struct Node* temp = poly;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

int main() {
    struct Node* poly = NULL;
    int n, coeff, exp, x;

    // Input polynomial terms
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms in the format 'coefficient exponent':\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly = insertNode(poly, coeff, exp);
    }

    // Display the polynomial
    printf("Polynomial: ");
    displayPolynomial(poly);

    // Input value of x for evaluation
    printf("Enter the value of x: ");
    scanf("%d", &x);

    // Evaluate the polynomial at x
    int result = evaluatePolynomial(poly, x);
    printf("Polynomial evaluated at x = %d is: %d\n", x, result);

    return 0;
}
