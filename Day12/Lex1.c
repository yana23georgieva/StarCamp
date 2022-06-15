#include <stdio.h>

unsigned char checkForBit(unsigned int uValue);

int main()
{
    unsigned n;
    scanf("%u", &n);
    printf("%d\n", checkForBit(n));
    return 0;
}

unsigned char checkForBit(unsigned int uValue)
{
    int bits = 0;
    for (size_t i = 0; i < sizeof(uValue)*8; i++)
    {
        if((uValue & (1u << i)) != 0)
        {
            bits++;
        }
        if(bits == 2)
        {
            return 0;
        }
    }
    if(bits == 0)
    {
        return 0;
    }
    return 1;
}