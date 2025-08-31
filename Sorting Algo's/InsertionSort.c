#include<stdio.h>

void InsertionSort(int A[], int n) {
    for(int j = 1; j < n; j++) // j=1 because for index 0 it is alwayas sorted
    { 
        int key = A[j]; // that elements whose approprite location needs to find
        int i = j - 1;

        // Traversing backward till we found key's appropraite position  
        while(i >= 0 && A[i] > key) 
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        // Insert key at its correct position
        A[i + 1] = key;
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

    InsertionSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}


