#include<stdio.h>

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

    int min, loc=0; // min stores smallest elements in array and loc stores its index.
    // Selection sort
    for(int i=0; i<size; i++)
    {
        min = arr[i];
        loc = i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j] < min)
            {
                min = arr[j];
                loc = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
    }

    printf("\nAfter Sorting Array:\n");
    printArray(arr,size);
    return 0;
}