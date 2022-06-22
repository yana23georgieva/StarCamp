#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
    int pid = fork();
    if(pid == -1)
    {
        return -1;
    }

    if(0 == pid)
    {
        //child
        execlp(argv[1], argv[1], NULL);
    }
    else
    {
        //parent
        int status;
        wait(&status);

        if(WIFEXITED(status))
        {
            int statusCode = WEXITSTATUS(status);
            if (statusCode == 0)
            {
                execlp(argv[2], argv[2], NULL);
            }
        }
    }
}