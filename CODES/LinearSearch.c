// Problem: Find the smallest positive integer missing from an unsorted array of integers
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <stdio.h>

int firstMissingPositive(int arr[], int n) {
    for (int num = 1; ; num++) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == num) {
                found = 1;
                break;
            }
        }
        if (!found) return num;
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = firstMissingPositive(arr, n);
    printf("The smallest missing positive integer is %d\n", missing);

    return 0;
}