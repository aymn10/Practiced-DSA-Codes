// Q: Bubble Sort in descending order with early termination if already sorted
// Time Complexity: O(n^2) worst, O(n) best (already sorted)
// Space Complexity: O(1)

#include <stdio.h>

void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int sorted = 1;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted) break;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bubblesort(arr, size);

    printf("\nArray after sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
