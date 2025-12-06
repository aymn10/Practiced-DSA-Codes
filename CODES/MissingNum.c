// Problem: Write a C program to find the smallest missing positive integer from a sorted array of integers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>

int findSmallestMissingPositive(int arr[], int size) {
    int expected = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == expected) {
            expected++;
        } else if (arr[i] > expected) {
            return expected;
        }
    }
    return expected;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findSmallestMissingPositive(arr, size);
    printf("The smallest missing positive integer is %d\n", missing);

    return 0;
}