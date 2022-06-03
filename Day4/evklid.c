#include <stdio.h>

int main()
{
    unsigned int a, b, temp;
    scanf("%u", &a);
    scanf("%u", &b);

    while(a != 0 && b != 0)
    {
        if(a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        a %= b;
    }

    printf("%d\n", b);
    return 0;
}