#include<stdio.h>

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}

// Non comparison sorting algo
int main(void)
{
    int range = 5;
    int range_array[range];

    int arr[6] = {3, 4, 5, 1, 2, 3}; // Elements must be in given range

    printf("Original Array:\n");
    printArray(arr,6);

    // Putting rangearray with '0'
    for(int i=0; i<5; i++)
        range_array[i] = 0;

    // Counting occurrence of arr elements
    for(int i = 0; i < 6; i++)
        range_array[arr[i] - 1]++;

    //printArray(range_array, 5);
    
    // building original array with range_arrray
    int j = 0;
    for(int i = 0; i < range; i++) {
        while(range_array[i] > 0) {
            arr[j] = i + 1;
            j++;
            range_array[i]--;
        }
    }
    printf("\nAfter sorting Array:\n");
    printArray(arr,6);

    return 0;
}