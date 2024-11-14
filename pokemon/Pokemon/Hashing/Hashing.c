#include <stdio.h>
#include <math.h>

#define TABLE_SIZE 10

// Hash function using the Golden Ratio
int hash_function(int key) {
    float A = (sqrt(5) - 1) / 2; // Golden ratio
    float fractional_part = key * A - (int)(key * A); // Get the fractional part
    return (int)(TABLE_SIZE * fractional_part); // Scale to table size
}

// Function to insert a key into the hash table
void insert(int hash_table[], int key) {
    int index = hash_function(key);
    int i = 0;
    // Find an empty slot using linear probing
    while (hash_table[(index + i) % TABLE_SIZE] != -1) {
        i++;
    }
    hash_table[(index + i) % TABLE_SIZE] = key; // Insert key into the hash table
}

// Function to display the contents of the hash table
void display(int hash_table[]) {
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != -1) {
            printf("Index %d: %d\n", i, hash_table[i]); // Display occupied indices
        } else {
            printf("Index %d: NULL\n", i); // Display empty indices
        }
    }
}

int main() {
    int hash_table[TABLE_SIZE];
    // Initialize the hash table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
    }

    // Keys to be inserted into the hash table
    int keys[] = {23, 43, 13, 27, 35, 47, 33};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    // Insert each key into the hash table
    for (int i = 0; i < num_keys; i++) {
        insert(hash_table, keys[i]);
    }

    // Display the contents of the hash table
    display(hash_table);

    return 0;
}
