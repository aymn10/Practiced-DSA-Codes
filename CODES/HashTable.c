// Q: Implement Hash Table with Insertion, Search, and Deletion using Linear Probing
// Time Complexity: O(1) average, O(n) worst
// Space Complexity: O(n)

#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int insert(int key) {
    int index = key % SIZE;
    int start = index;

    if (hashTable[index] == -1 || hashTable[index] == -2) {
        hashTable[index] = key;
        return index;
    }

    int i = (index + 1) % SIZE;

    while (i != start) {
        if (hashTable[i] == -1 || hashTable[i] == -2) {
            hashTable[i] = key;
            return i;
        }
        i = (i + 1) % SIZE;
    }

    return -1;
}

int search(int key) {
    int index = key % SIZE;
    int start = index;

    if (hashTable[index] == key)
        return index;

    int i = (index + 1) % SIZE;

    while (i != start) {
        if (hashTable[i] == key)
            return i;
        if (hashTable[i] == -1)
            return -1;
        i = (i + 1) % SIZE;
    }
    return -1;
}

int deleteKey(int key) {
    int index = search(key);
    if (index != -1) {
        hashTable[index] = -2;
        return index;
    }
    return -1;
}

void display() {
    printf("Hash Table:\nIndex: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);

    printf("\nValue: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", hashTable[i]);

    printf("\n");
}

int main() {
    init();

    int i1 = insert(5);
    printf("Inserted 5 at index %d\n", i1);

    int i2 = insert(15);
    printf("Collision at index 5 → inserted 15 at index %d\n", i2);

    int i3 = insert(25);
    printf("Collision at index 5 → inserted 25 at index %d\n", i3);

    int i4 = insert(35);
    printf("Collision at index 5 → inserted 35 at index %d\n", i4);

    int s = search(25);
    if (s != -1)
        printf("\nSearch 25: Found at index %d\n", s);

    int d = deleteKey(15);
    if (d != -1)
        printf("\nDeleted 15 from index %d\n", d);

    int i5 = insert(45);
    printf("\nInserted 45 at index %d\n", i5);

    printf("\n");
    display();

    return 0;
}
