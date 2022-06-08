#include <stdio.h>

void inputIntArray(int *arr, int n);
void printArr(int *arr, int n);
void sortArray(int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    inputIntArray(arr, n);
    sortArray(arr, n);
    printArr(arr, n);
    return 0;
}

void inputIntArray(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
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

void sortArray(int *arr, int n)
{
    for( int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i < j && arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}