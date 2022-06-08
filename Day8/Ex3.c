#include <stdio.h>

void printArr(int *arr, int n);

int main()
{
    int arr[] = {1, 2, 3, 4};
    printArr(arr, 4);
    return 0;
}

void printArr(int *arr, int n)
{
    printf("Length = %d, elements = [", n);

    for(int i = 0; i < n; i++)
    {
        printf("%d", *(arr + i));
        if(i == n - 1)
        {
            printf("]\n");
        }
        else
        {
            printf(", ");
        }
    }
}