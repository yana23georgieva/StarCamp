#include <stdio.h>

int secondMax(const int *, size_t, int *);

int main()
{
    int sm;
    int arr[] = {12, 34, 5, 70, 46};
    int res = secondMax(arr, 5, &sm);
    if(res == 0)
    {
        printf("%d\n", sm);
    }

    int arr1[] = {12};
    secondMax(arr1, 1, &sm);

    int arr2[] = {};
    secondMax(arr2, 0, &sm);

    int arr3[] = {12, 12, 12, 12, 12};
    secondMax(arr3, 5, &sm);
    
    return 0;
}

int secondMax(const int *arr, size_t n, int *secondMax)
{
    int max  = arr[0], sMax = arr[0];
    if(n == 0)
    {
        fprintf(stderr, "No elements\n");
        return -1;
    }
    if(n == 1)
    {
        fprintf(stderr, "Only one element\n");
        return -1;
    }

    for(int i = 1; i < n; i++)
    {   
        if(arr[i] > max)
        {
            sMax = max;
            max = arr[i];
        }
        else if(arr[i] > sMax)
        {
            sMax = arr[i];
        }
    }

    if(sMax == max)
    {
        fprintf(stderr, "All elements are equal\n");
        return -1;
    }

    *secondMax = sMax;
    return 0;
}