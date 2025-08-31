#include<stdio.h>
#include<stdbool.h> 

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}

int main(void)
{
    int arr[] ={45, 1, 56, 4, -8, 7, 64, 5, 30, 36};
    int size = sizeof(arr)/sizeof(int);

    printf("Original Array:\n");
    printArray(arr,size);

    // Normal Bubble Sort
    for(int i=0; i<size; i++)
        for(int j=0; j<size-i; j++)
        {
            if(arr[j] > arr[j+1])
                {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
        }

    // optimized version
    bool swap;
    for(int i=0; i<size; i++)
    {
        swap = false;
        for(int j=0; j<size-i; j++)
        {
            if(arr[j] > arr[j+1])
                {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swap = true;
                }
            // if no single swap taken place in 1 iteration then break as array is sorted.
            if(swap == false)
                break;
        }
    }

    printf("\nAfter Sorting Array:\n");
    printArray(arr,size);
    return 0;
}