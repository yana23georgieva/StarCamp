#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pid;
    if((pid = fork()) == -1)
    {
        perror("Fork failde");
    }
    else if(0 == pid)
    {
        int fdIn = open(argv[1], O_RDONLY);
        int fdOut = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0764);
        if (fdIn < 0)
        {
            perror("Open inFile failed.");
            return -1;
        }
        if (fdOut < 0)
        {
            perror("Open inFile failed.");
            return -1;
        }
        
        //0 ---> file with name argv[1]
        //1 ---> file with name argv[2]
        dup2(fdIn, 0);
        dup2(fdOut, 1);
        execvp(argv[3], argv + 3);
        perror("EXEC FAILED");
    }
    else
    {
        int statusCode;
        wait(&statusCode);
        printf("Child reminated with status code: %d\n", WEXITSTATUS(statusCode));
    }
}