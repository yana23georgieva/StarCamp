#include <stdio.h>
#include <stdint.h>

unsigned long onesCount(uint64_t mask);

int main()
{
    uint64_t mask = 64;
    unsigned long count = onesCount(mask);

    printf("Count = %lu\n", count);
    return 0;
}

unsigned long onesCount(uint64_t mask)
{
    unsigned long count = 0;

    for(unsigned long i = 0; i < sizeof(mask)*8; i++)
    {
        int check = ((1ul<<i)&mask)>>i;
        if(check == 1)
        {
            count++;
        }
    }
    return count;
}