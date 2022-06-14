#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);
unsigned long countBits(int mask);

int main()
{
    unsigned n;
    n = bitsNCount(4, 2, 0x0a, 0xff, 0, 1);
    printf("%u\n", n);
    n = bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa);
    printf("%u\n", n);
    n = bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111);
    printf("%u\n", n);
    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...)
{
    unsigned countMasks = 0;

    va_list argl;
    va_start(argl, bitscnt);
    for(int i = 0; i < count; i++)
    {
        int currentMask = va_arg(argl, int);
        int bits = countBits(currentMask);
        if(bits == bitscnt)
        {
            countMasks++;
        }
    }

    return countMasks;
}

unsigned long countBits(int mask)
{
    unsigned long count = 0;

    for(unsigned long i = 0; i < sizeof(mask)*8; i++)
    {
        int check = ((1<<i)&mask)>>i;
        if(check == 1)
        {
            count++;
        }
    }
    return count;
}