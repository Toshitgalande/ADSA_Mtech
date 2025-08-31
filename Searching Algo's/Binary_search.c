#include<stdio.h>

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}

int Binary_search(int arr[], int size, int data)
{
    // Binary Search
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int middle = (start+end)/2;
        
        if(data == arr[middle])
            return middle;
        
        if(data < arr[middle])
            end = middle - 1;
        
        if(data > arr[middle])
            start = middle + 1;
        
    }
    // if data is not present
    return 0;
}

int main(void)
{
    int arr[] = {-9, 8, 14, 23, 25, 30, 36, 44, 52, 78};

    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);

    int data;
    printf("\nEnter the data: ");
    scanf("%d",&data);

    int result = Binary_search(arr, size, data);
    if(result)
        printf("%d is present in Array !", data);
    else
        printf("%d is absent in Array !", data);

    return 0;
}