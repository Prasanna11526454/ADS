#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];
int collisions = 0;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertLinearProbing(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        collisions++;
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

void insertQuadraticProbing(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i * i) % TABLE_SIZE] != -1) {
        collisions++;
        i++;
    }
    hashTable[(index + i * i) % TABLE_SIZE] = key;
}


int secondHashFunction(int key) {
    return 7 - (key % 7);
}

void insertDoubleHashing(int key) {
    int index = hashFunction(key);
    int stepSize = secondHashFunction(key);
    while (hashTable[index] != -1) {
        collisions++;
        index = (index + stepSize) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1) {
            printf("Table[%d]: empty\n", i);
        } else {
            printf("Table[%d]: %d\n", i, hashTable[i]);
        }
    }
    printf("Number of collisions: %d\n", collisions);
}

void resetHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
    collisions = 0;
}

int main() {
    int choice;
    int keys[] = {10, 22, 31, 4, 15, 28, 17,32 ,59,42};
    int size = sizeof(keys) / sizeof(keys[0]);

    while (1) {
        printf("\nHashing Techniques Menu:\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Double Hashing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        resetHashTable();

        switch (choice) {
            case 1:
                for (int i = 0; i < size; i++) {
                    insertLinearProbing(keys[i]);
                }
                printf("\nHash Table using Linear Probing:\n");
                printHashTable();
                break;
            case 2:
                for (int i = 0; i < size; i++) {
                    insertQuadraticProbing(keys[i]);
                }
                printf("\nHash Table using Quadratic Probing:\n");
                printHashTable();
                break;
            case 3:
                for (int i = 0; i < size; i++) {
                    insertDoubleHashing(keys[i]);
                }
                printf("\nHash Table using Double Hashing:\n");
                printHashTable();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
