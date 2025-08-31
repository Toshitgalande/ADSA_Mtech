#include <stdio.h>
#include <limits.h> // For INT_MAX as infinity

void merge(int A[], int start, int middle, int end)
{
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int L[n1 + 1], R[n2 + 1];  // Temporary arrays

    // Copy left half
    for(int i = 0; i < n1; i++)
        L[i] = A[start + i];

    // Copy right half
    for(int j = 0; j < n2; j++)
        R[j] = A[middle + 1 + j];

    L[n1] = INT_MAX; // last element as infinity
    R[n2] = INT_MAX; // last element as infinity

    int i = 0, j = 0; // i works for left array and j works on right array
    for(int k = start; k <= end; k++) 
    {
        if(L[i] <= R[j]) 
        {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int start, int end)
{
    if(start < end) 
    {
        int middle = (start + end) / 2; // Mid point
        mergeSort(A, start, middle);       // left half
        mergeSort(A, middle + 1, end);     // right half
        merge(A, start, middle, end);      // Merge sorted halves
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[] = {45, 1, 56, 4, -8, 7, 64, 5, 30, 36};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
