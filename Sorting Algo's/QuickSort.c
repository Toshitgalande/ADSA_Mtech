#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int start, int end) {
    int pivot = arr[end];  // Pivot element
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivot_position = partition(arr, start, end);
        quickSort(arr, start, pivot_position - 1);
        quickSort(arr, pivot_position + 1, end);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {75, 10, -2, 45, 9, 12, 68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
