#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 5

int randint(int,int);
double randReal(double,double);
int binarySearch(int *arr, size_t n, int key);

int main(){
    srand(time(NULL));
    int arr[] = {2, 4 ,12, 24, 62, 93};

    printf("%d\n", binarySearch(arr, 6, 93));

    return 0;
}

int binarySearch(int *arr, size_t n, int key)
{
    int mid = n / 2, l = 0, r = n;

    while (mid != l && mid != r)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
        mid = l + ((r - l) / 2);
    }

    return - 1;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}