#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mux;

void* message(void *arg);

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);
    pthread_mutex_init(&mux, NULL);
    pthread_t th[n];
    for (int i = 0; i < n; i++)
    {
        if(pthread_create(&th[i], NULL, message, NULL))
        {
            perror("Pthread_create");
            return -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (pthread_join(th[i], NULL))
        {
            perror("Pthread_join");
            return -1;
        }       
    }    
    pthread_mutex_destroy(&mux);
    return 0;
}

void* message(void *arg)
{
    pthread_mutex_lock(&mux);
    for (int i = 0; i < 10; i++)
    {
        char letter = 'a' + rand() % ('z' - 'a' + 1);
        putchar(letter);
    }
    putchar('\n');
    pthread_mutex_unlock(&mux);
}