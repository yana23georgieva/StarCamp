#include <stdio.h>

int main()
{
    int arr[32];
    unsigned n, i = 31;
    scanf("%u", &n);
    while(n != 0)
    {
        arr[i] = n&1;
        n >>= 1;
        i--;
    }
    for(int j = 0; j < 32;j++)
    {
        printf("%d", arr[j]);
    }
    putchar('\0');
    return 0;
}