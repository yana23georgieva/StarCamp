#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

void* sum(void *arg);

int main(int argc, char **argv)
{
    int all = 0;
    int n = argc;
    pthread_t th[n];
    for (int i = 1; i < n; i++)
    {
        char *msg = argv[i];
        char *buff = malloc(sizeof(char)*(strlen(msg)+ 1));
        strcpy(buff, msg);
        if(pthread_create(&th[i], NULL, sum, buff))
        {
            perror("Pthread_create");
            return -1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        int number;
        if (pthread_join(th[i], (void *)&number) != 0)
        {
            perror("join");
        } 
        all += number;
    } 

    printf("Sum: %d\n", all);
    return 0;
}

void* sum(void *arg)
{
    FILE * fp;
    fp = fopen(arg, "r");
    if (fp == NULL)
    {
        perror("File not exist!");
        //return (void *)false;
    }
    
    int number;
    int total = 0;
    while (fscanf(fp, "%d", &number) != EOF)
    {
        total += number;
    }     
    fclose(fp);
    printf("Sum child: %d\n", total);
}