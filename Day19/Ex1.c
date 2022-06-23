#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int isPrime(unsigned int n);
unsigned int getIthPrime(unsigned int i); 

int main()
{
    int n;
    scanf("%d", &n);
    unsigned number;
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &number);
        int pid = fork();
        if (-1 == pid)
        {
            perror("fork");
            return -1;
        }
        if (0 == pid)
        {
            //child
            printf("Child %d: %d\n", i, getIthPrime(number));
            exit(EXIT_SUCCESS);
        }
        else
        {
            //parent
        }        
    }
    while (wait(NULL) != -1)
    {
        
    }
    
    
    return EXIT_SUCCESS;    
}

int isPrime(unsigned int N) 
{
    for(int i = 2; i < N; i++) 
    {
        if(N%i == 0) 
        {
            return 0;
        }
    }
    return 1;
}
unsigned int getIthPrime(unsigned int i) 
{
    unsigned int curN = 1;
    while(i > 0) 
    {
        curN += 1;
        if(isPrime(curN)) 
        {
            i--;
        }
    }
    return curN;
}