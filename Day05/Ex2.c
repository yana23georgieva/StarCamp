#include <stdio.h>
#include <math.h>

int main()
{
    unsigned number, n, count = 0;
    scanf("%u", &number);
    n = number;

    while(n!= 0)
    {
        n = n >> 1;
        count++;
    }
    printf("%d -> %d\n", number, count);
    
    n = number;
    printf("%d -> %d\n", number, (int)log2(n) + 1);

    return 0;
}