#include <stdio.h>
#include <stdlib.h>

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

// Function to add two polynomials represented by linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;

    // Traverse both polynomials
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            // If exponents are equal, add the coefficients
            result = insertNode(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            // If p1's exponent is greater, add p1's term to the result
            result = insertNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            // If p2's exponent is greater, add p2's term to the result
            result = insertNode(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    // If poly1 has remaining terms
    while (p1 != NULL) {
        result = insertNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // If poly2 has remaining terms
    while (p2 != NULL) {
        result = insertNode(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
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

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    int n1, n2, coeff, exp;

    // Input first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the terms in the format 'coefficient exponent':\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly1 = insertNode(poly1, coeff, exp);
    }

    // Input second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the terms in the format 'coefficient exponent':\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly2 = insertNode(poly2, coeff, exp);
    }

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    printf("Sum of the Polynomials: ");
    displayPolynomial(result);

    return 0;
}
