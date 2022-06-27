#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *matrix;

void* sort(void* arg);
int compare(const void *a, const void *b);
int n, m;

int main()
{   
    scanf("%d %d", &n, &m);
    fflush(stdin);
    printf("%d %d\n", n, m);
    matrix = malloc(sizeof(int)*n*m);
    for (int i = 0; i < n; i++)
    {
        char *row;
        int rowNumber;
        scanf("%s %d", row, &rowNumber);
        for (int j = 0; j < m; j++)
        {
            int num;
            scanf("%d", &n);
            *(matrix + rowNumber*m + j) = num;
        }        
    }
    char *file;
    scanf("%s", file);

    pthread_t th[n];
    for (int i = 0; i < n; i++)
    {
        if(pthread_create(&th[i], NULL, sort, (void *)&i))
        {
            perror("Pthread_create");
            return -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("join");
        } 
    } 

    FILE *fp;
    fp = fopen(file, "w");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(fp, "%d ",*(matrix + i*m + j));
        } 
        fprintf(fp, "\n");   
    }
    fclose(fp);
    
    return 0;
}

void* sort(void* arg)
{
    int row = *(int *)arg;
    qsort(matrix[row], m, sizeof(int), compare);    
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}