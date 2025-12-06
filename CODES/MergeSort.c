// Q: Optimized Merge Sort with early skip when subarrays already sorted, tracking comparisons
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <stdio.h>

int comparisons = 0;

void merge(int arr[], int left, int mid, int right) {
    if (arr[mid] <= arr[mid + 1]) return;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a[n1], b[n2];
    for (int i = 0; i < n1; i++) a[i] = arr[left + i];
    for (int i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    while (i < n1) arr[k++] = a[i++];
    while (j < n2) arr[k++] = b[j++];
}

void mergesort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    mergesort(arr, 0, size - 1);

    printf("\nArray after sorting: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    printf("\nTotal comparisons: %d\n", comparisons);

    return 0;
}
