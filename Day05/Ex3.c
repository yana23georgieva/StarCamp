#include <stdio.h>

int main()
{
    unsigned n, m;
    scanf("%u", &n);
    scanf("%u", &m);
    unsigned result, remainder, mask;
    //result = n / (1<<m);
    //remainder = n % (1<<m);

    result = n >> m;
    mask = (1<<m) - 1;
    remainder = n & mask;
    
    printf("Result: %u\n", result);
    printf("Reminder: %u\n", remainder);
    return 0;
}