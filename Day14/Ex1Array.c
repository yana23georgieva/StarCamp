#include <stdio.h>
#include <stdlib.h>

#define N 10

void addValues(int **arr);
void printValues(int **arr);
int randint(int min, int max);
void freeMemory(int **arr);

int main()
{
    int **array = malloc(N *sizeof(int *));

    for(int i = 0; i < N; i++)
    {
        int q = randint(1, 10);
        *(array + i) = malloc(q*sizeof(int));
    }

    addValues(array);

    printValues(array);
    freeMemory(array);

    return 0;
}

void addValues(int **arr)
{
    for(int i = 0; i < N; i++)
    {
        int q = randint(1, 10);
        *(arr+i) = malloc((q + 1)*sizeof(int));
        *(*(arr + i) + 0) = q;
        for (int j = 1; j < (q + 1); j++)
        {
            *(*(arr + i) + j) = randint(1, 10);
        }
        
    }
}

void printValues(int **arr)
{
    for(int i = 0; i < N; i++)
    {
        int q = *(*(arr + i) + 0);
        for (int j = 1; j < (q + 1); j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        putchar('\n');      
    }
}

void freeMemory(int **arr)
{
    for(int i = 0; i < N; i++)
    {
        free(arr[i]);  
    }
    free(arr);
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}