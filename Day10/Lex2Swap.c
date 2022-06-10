#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t *word);
void uint16ToBinary(uint16_t n);

int main()
{
    uint16_t number;
    scanf("%hu", &number);
    uint16ToBinary(number);
    swapBytes(&number);
    uint16ToBinary(number);
    return 0;
}

void swapBytes(uint16_t *word)
{
    int firstDigit = *word & 1;
    int lastIndex = sizeof(uint16_t)*8 - 1;
    int lastDigit = (*word & (1<<lastIndex))>>lastIndex;

    if(firstDigit != lastDigit)
    {
        *word ^= 1;
        *word ^= (1<<lastIndex);
    }
}

void uint16ToBinary(uint16_t n)
{
    for (int i = sizeof(n)*8-1; i >= 0; i--)
    {
        int digit = (n & (1<<i))>>i;
        printf("%d", digit);
    }
    putchar('\n');
}