// Q: Time complexity comparison of Quick Sort, Merge Sort, and Bubble Sort on 10000 random integers
// Time Complexity: Quick O(n log n), Merge O(n log n), Bubble O(n^2)
// Space Complexity: Quick O(log n), Merge O(n), Bubble O(1)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++) a[i] = arr[left + i];
    for (int i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE], arr1[SIZE], arr2[SIZE], arr3[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000;
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    quicksort(arr1, 0, SIZE - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds\n", time_taken);

    start = clock();
    mergesort(arr2, 0, SIZE - 1);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort took %f seconds\n", time_taken);

    start = clock();
    bubblesort(arr3, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", time_taken);

    return 0;
}
