#include <stdio.h>

int main()
{
    unsigned int a, b, min;
    scanf("%u", &a);
    scanf("%u", &b);

    if(a > b)
    {
        min = b;
    }
    else
    {
        min = a;
    }

    for(int i = min; i > 0;i--)
    {
        if(a % i == 0 && b % i == 0)
        {
            printf("%u\n", i);
            break;
        }
    }
    return 0;
}