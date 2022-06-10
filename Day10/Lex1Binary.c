#include <stdio.h>
#include <stdint.h>

void uint32ToBinary(uint32_t n);

int main()
{
    uint32_t number;
    scanf("%u", &number);
    uint32ToBinary(number);
    return 0;
}

void uint32ToBinary(uint32_t n)
{
    for (int i = sizeof(n)*8-1; i >= 0; i--)
    {
        int digit = (n & (1<<i))>>i;
        printf("%d", digit);
    }
    putchar('\n');
}