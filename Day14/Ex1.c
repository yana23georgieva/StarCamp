#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    if(n & 1)
    {
        putchar('a');
    }
    if(n & (1<<1))
    {
        putchar('b');
    }
    if(n & (1<<2))
    {
        putchar('c');
    }
    if(n & (1<<3))
    {
        putchar('d');
    }
    putchar('\n');
    
    return 0;
}

/*
int main()
{
    int n;
    scanf("%d", &n);
    char sym[] = {'a', 'b', 'c', 'd', '\0'};

    for (size_t i = 0; i < 4; i++)
    {
        int check = n & (1 << i);
        if(check != 0)
        {
            printf("%c", sym[i]);
        }
    }
    putchar('\n');
    
    return 0;
}*/