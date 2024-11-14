#include <stdio.h>
#include <stdlib.h>

#define DIGIT_COUNT 10

// Structure to represent a hash table for digit counts
typedef struct HashTable {
    int count[DIGIT_COUNT];
} HashTable;

// Function to create a new hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < DIGIT_COUNT; i++) {
        ht->count[i] = 0; // Initialize counts to 0
    }
    return ht;
}

// Function to extract digits and update their counts
void extractDigits(HashTable* ht, long long number) {
    while (number > 0) {
        int digit = number % 10; // Extract the last digit
        ht->count[digit]++;      // Increment the count for the digit
        number /= 10;            // Remove the last digit
    }
}

// Function to display the digit counts
void displayCounts(HashTable* ht) {
    printf("Digit counts:\n");
    for (int i = 0; i < DIGIT_COUNT; i++) {
        printf("Digit %d: %d\n", i, ht->count[i]);
    }
}

// Function to free the hash table
void freeHashTable(HashTable* ht) {
    free(ht);
}

int main() {
    long long number;
    
    printf("Enter a number: ");
    scanf("%lld", &number);
    
    HashTable* ht = createHashTable();
    extractDigits(ht, number);
    
    displayCounts(ht);
    
    freeHashTable(ht);
    return 0;
}
