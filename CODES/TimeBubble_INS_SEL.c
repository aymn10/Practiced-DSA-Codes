// Q: Time complexity comparison of Bubble, Selection, and Insertion Sort on 10000 random integers
// Time Complexity: Bubble O(n^2), Selection O(n^2), Insertion O(n^2) worst
// Space Complexity: O(1)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxpos = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxpos]) {
                maxpos = j;
            }
        }
        int temp = arr[maxpos];
        arr[maxpos] = arr[i];
        arr[i] = temp;
    }
}

void insertionsort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[SIZE], arr2[SIZE], arr3[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100000;
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    bubblesort(arr, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", time_taken);

    start = clock();
    selectionsort(arr2, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds\n", time_taken);

    start = clock();
    insertionsort(arr3, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds\n", time_taken);

    return 0;
}
