// Problem: Write a C program to find the index of a target word in a sorted array of words using binary search
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <stdio.h>
#include <string.h>

int binarySearch(char words[][50], int size, char target[]) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(words[mid], target);
        if (cmp == 0) return mid;
        if (cmp < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int size;
    printf("Enter number of words: ");
    scanf("%d", &size);

    char words[size][50];
    printf("Enter %d words in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%s", words[i]);
    }

    char target[50];
    printf("Enter target word: ");
    scanf("%s", target);

    int index = binarySearch(words, size, target);
    if (index != -1) printf("Word found at index %d\n", index);
    else printf("Word not found\n");

    return 0;
}