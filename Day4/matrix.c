#include <stdio.h>

int main()
{
    int n, s = 0;
    scanf("%d", &n);

    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < n;j++)
        {
            s =(i + j)%2;
            printf("%d ", s);
        }
        printf("\n");
    }
}