#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;   // Left child index (0-based indexing)
    int right = 2 * i + 2;  // Right child index

    if (left < heapSize && arr[left] > arr[largest])
        largest = left;

    if (right < heapSize && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, heapSize, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node beacuse the last non leaft will be at length/2 and heapify each
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i); // we check parent and child property 
    }
}

void heapSort(int arr[], int n) 
{    
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // Call max heapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {15, 10, 20, 45, 9, 12, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
