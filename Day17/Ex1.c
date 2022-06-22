#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int sumDigit(int number);

int main(int argc, char **argv)
{
    for (int i = 1; i <= argc; i++)
    {
        pid_t pid = fork();
        if(-1 == pid)
        {
            perror("fork");
            return EXIT_FAILURE;
        }
        if(0 == pid)
        {
            //in child
            int n = atoi(argv[i]);
            printf("Number %d - sum %d\n",n,sumDigit(n));
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < (argc - 1); i++)
    {
        wait(NULL);
    }
    
    
    return EXIT_SUCCESS;
}

int sumDigit(int number)
{
    int sum = 0;

    while (number > 9)
    {
        while (number > 0)
        {
            sum += (number % 10);
            number /= 10;
        }
        number = sum;
        sum = 0;
    }

    return number;
}