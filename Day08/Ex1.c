#include <stdio.h>

int isTwosPower(int n);

int main()
{
    unsigned int n, setBitCount = 0;
    scanf("%u", &n);

    /*for(; n > 0; n >>= 1)
    {
        setBitCount += n & 1;
    }*/
    if(isTwosPower(n) == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

int isTwosPower(int n)
{
    return !(n & (n - 1));
}

int multiplyBy7(int n)
{
    return (n << 3) - n;
}