#include <stdio.h>

void map(int *array, int count, int(*func)(int));
int increment(int number);

int main()
{
    int arr[] = {1, 34, 12, 5, 7};
    map(arr, 5, increment);
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void map(int *array, int count, int(*func)(int))
{
    for(int i = 0; i < count; i++)
    {
        *(array + i) = func(*(array + i));
    }
}

int increment(int number)
{
    return ++number;
}