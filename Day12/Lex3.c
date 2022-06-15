#include <stdio.h>

void vMirror(unsigned char *pImage);
int checkBit(unsigned mask, unsigned bit);
void mirrorBits(unsigned* mask);

int main()
{
    unsigned char arr[] = {0x7F, 0x40, 0x40, 
    0x40, 0x7F, 0x00, 0x00, 0x00};
    vMirror(arr);
    for (size_t i = 0; i < 8; i++)
    {
        printf("%X ", arr[i]);
    }
    putchar('\n');
    return 0;
}

void vMirror(unsigned char *pImage)
{
    int count = 0;
    for (size_t i = 0; i < 8; i++)
    {
        unsigned current = pImage[i];
        mirrorBits(&current);
        pImage[i] = current;
    }
}

int checkBit(unsigned mask, unsigned bit)
{
    return (mask & (1 << bit)) >> bit; // 0, 1
}

void mirrorBits(unsigned* mask)
{
    for (int bit = 0; bit < 4; bit++){
        int bit1 = checkBit(*mask, bit);   
        int bit2 = checkBit(*mask, 7 - bit); 
        if(bit1 != bit2)
        {
            *mask ^= (1<<bit);
            *mask ^= (1<<(7 - bit));
        }
    }
}