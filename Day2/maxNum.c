#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
    int a, max = INT_MIN;
    int flag = 0;

    while(scanf("%d", &a) != EOF)
    {
        flag = 1;
        if(a > max)
        {
            max = a;
        }
    }
    if(flag == 1)
    {
        printf("%d\n", max);
    }
    else
    {
        fprintf(stderr, "No number!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}