#include <stdio.h>
#include <stdint.h>

unsigned long long bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void flipOddBits(uint64_t *mask);
void mirrorBits(uint16_t *mask);

int main()
{
    uint64_t mask1 = -1;
    uint32_t mask2 = -1;
    uint16_t mask3 = -1;
    uint8_t mask4 = -1;

    unsigned long long count = bitsNCount(mask1, mask2, mask3, mask4);
    printf("%llu\n", count);
    flipOddBits(&mask1);
    printf("%lu\n", mask1);

    flipOddBits(&mask3);
    printf("%u\n", mask6);
    return 0;
}

unsigned long long bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
    unsigned long long count = 0;

    for(unsigned long long i = 0; i < sizeof(mask1)*8; i++)
    {
        int check = ((1llu<<i)&mask1)>>i;
        if(check == 1)
        {
            count++;
        }
    }
    for(unsigned long i = 0; i < sizeof(mask2)*8; i++)
    {
        int check = ((1ul<<i)&mask2)>>i;
        if(check == 1)
        {
            count++;
        }
    }
    for(unsigned long i = 0; i < sizeof(mask3)*8; i++)
    {
        int check = ((1ul<<i)&mask3)>>i;
        if(check == 1)
        {
            count++;
        }
    }
    for(unsigned long i = 0; i < sizeof(mask4)*8; i++)
    {
        int check = ((1ul<<i)&mask4)>>i;
        if(check == 1)
        {
            count++;
        }
    }

    return count;
}

void flipOddBits(uint64_t *mask)
{
    for(unsigned long long i = 1; i < sizeof(mask)*8; i+=2)
    {
        *mask ^= (1llu << i);
    }
}

void mirrorBits(uint16_t *mask)
{
    uint16_t newMask = 0;
    int j = 0;

    for(int i = sizeof(mask)*8 - 1; i >= 0; i--)
    {
        int n = ((1 << i)&mask)>>i;
        newMask = (n<<j)|newMask;
        j++;
    }
    *mask = newMask;
}