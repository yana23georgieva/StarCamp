#include <stdio.h>

int main()
{
    unsigned int a, b, temp;
    scanf("%u", &a);
    scanf("%u", &b);

    while(a != b)
    {
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        a -= b;
    }

    printf("%d\n", a);
    return 0;
}