#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>

pthread_mutex_t mux;

void* message(void *arg);

int main(int argc, char * argv[])
{
    int p = atoi(argv[1]);
    int t = atoi(argv[2]);
    pthread_mutex_init(&mux, NULL);
    pthread_t th[t];

    for (int i = 0; i < p; i++)
    {
        pid_t pid = fork();
        if (-1 == pid)
        {
            perror("Create process error");
            return -1;
        }
        if (0 == pid)
        {
            //child
            for (int i = 0; i < t; i++)
            {
                char *msg = argv[3];
                char *buff = malloc(sizeof(char)*(strlen(msg)+ 1));
                strcpy(buff, msg);
                if(pthread_create(&th[i], NULL, message, buff))
                {
                    perror("Pthread_create");
                    return -1;
                }
            }

            for (int i = 0; i < t; i++)
            {
                if (pthread_join(th[i], NULL))
                {
                    perror("Pthread_join");
                    return -1;
                }       
            }
            exit(-1);
        }
        else
        {
            //parent
        }        
    }

    for (int i = 0; i < p; i++)
    {
        wait(NULL);
    }
    
        
    pthread_mutex_destroy(&mux);
    return 0;
}

void* message(void *arg)
{
    printf("Process %d, Thread %lu, Message %s\n", 
    getpid(), pthread_self(), (char *)arg);
    free(arg);
}