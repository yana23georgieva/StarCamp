#include <stdio.h>

unsigned sumArrayDigits(const int *arr, size_t n);

int main()
{
    int arr[] = {12, 34, 5, 170};
    int sum = sumArrayDigits(arr, 4);
    printf("%d\n", sum);
    
    return 0;
}

unsigned sumArrayDigits(const int *arr, size_t n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        int number = arr[i];
        while(number != 0)
        {
            sum += (number % 10);
            number /= 10;
        }
    }

    return sum;
}