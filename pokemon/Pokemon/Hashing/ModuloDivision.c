#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure to represent each entry in the hash table
typedef struct HashEntry {
    int key;
    int value;
    struct HashEntry* next;
} HashEntry;

// Structure for the hash table
typedef struct HashTable {
    HashEntry** table;
} HashTable;

// Function to create a new hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (HashEntry**)malloc(TABLE_SIZE * sizeof(HashEntry*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* ht, int key, int value) {
    int index = hashFunction(key);
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = ht->table[index];
    ht->table[index] = newEntry;
}

// Function to search for a value by key
int search(HashTable* ht, int key) {
    int index = hashFunction(key);
    HashEntry* entry = ht->table[index];
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1; // Not found
}

// Function to display the hash table
void displayHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashEntry* entry = ht->table[i];
        printf("Index %d: ", i);
        while (entry != NULL) {
            printf(" -> (%d, %d)", entry->key, entry->value);
            entry = entry->next;
        }
        printf("\n");
    }
}

// Function to free the hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashEntry* entry = ht->table[i];
        while (entry != NULL) {
            HashEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    HashTable* ht = createHashTable();
    int choice, key, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert key-value pair\n");
        printf("2. Search for a key\n");
        printf("3. Display hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(ht, key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                value = search(ht, key);
                if (value != -1) {
                    printf("Value for key %d: %d\n", key, value);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 3:
                displayHashTable(ht);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    freeHashTable(ht);
    return 0;
}
