#include<stdio.h>

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}

int main(void)
{
    int arr[] = {45, 37, -9, 78, 14, 12, 78, 20, 63, 102, 10, 8, -87, 52, 25};

    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);

    int data;
    printf("\nEnter the data: ");
    scanf("%d",&data);

    // linear search
    for(int i=0; i<=size; i++)
    {
        if(arr[i] == data)
        {
            printf("%d is present in Array !", data);
            return 0;
        }
    }
    printf("%d is absent in Array !", data);
    return 0;
}