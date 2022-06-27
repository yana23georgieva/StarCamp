#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int all = 0;
    int fd[2];
    if(pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        int pid = fork();

        if (-1 == pid)
        {
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid)
        {
            //child
            //close(fd[0]);
            FILE * fp;
            fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                perror("File not exist!");
                exit(EXIT_FAILURE);
            }
            
            int number;
            int total = 0;
            while (fscanf(fp, "%d", &number) != EOF)
            {
                total += number;
            }     
            fclose(fp);
            write(fd[1], &total, sizeof(total));
            //close(fd[1]);
            printf("Sum child: %d\n", total);
            exit(EXIT_SUCCESS);
        }
        else
        {
            //parent
            int totalChild;
            int status;
            wait(&status);
            if(WIFEXITED(status))
            {
                int statusCode = WEXITSTATUS(status);
                if (statusCode == 0)
                {
                    read(fd[0], &totalChild, sizeof(totalChild));
                    all += totalChild;
                }
            }
            //printf("Sum: %d\n", all);
        }
    }

    close(fd[1]);
    close(fd[0]);
    printf("Sum: %d\n", all);
    return 0;
}