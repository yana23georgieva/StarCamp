#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


int main(int argc, char** argv)
{
    int fd[2];
    
    if(pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (0 == pid)
    {
        // child
        close(fd[0]);
        int num1, num2, totalChild;
        int countEl = (argc - 1) / 2;
        for (int i = 0; i < countEl; i+=2)
        {
            sscanf(argv[i + 1], "%d", &num1);
            if((i + 2) <= countEl)
            {
                sscanf(argv[i + 2], "%d", &num2);
            }
            else
            {
                num2 = 0;
            }
            totalChild += (num1 + num2);
        }
        
        printf("Sum child: %d\n", totalChild);
        write(fd[1], &totalChild, sizeof(totalChild));
        close(fd[1]);
    } 
    else 
    {
        // parent
        close(fd[1]);
        
        int num1, num2, totalP;
        int countEl = (argc - 1) / 2 + 1;
        for (int i = countEl; i < argc; i+=2)
        {
            sscanf(argv[i], "%d", &num1);
            if((i + 1) < argc)
            {
                sscanf(argv[i + 1], "%d", &num2);
            }
            else
            {
                num2 = 0;
            }
            totalP += (num1 + num2);
        }

        printf("Sum parent: %d\n", totalP);
        wait(NULL);
        int totalChild;
        read(fd[0], &totalChild, sizeof(totalChild));
        close(fd[0]);
        int total = totalP + totalChild;
        printf("Total: %d\n", total);
    }

    return EXIT_SUCCESS;
}