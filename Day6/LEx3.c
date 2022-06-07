#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void *valuePtr, uint8_t flag);

int main()
{
    int num1 = 23;
    printValue(&num1, TINT);
    double num2 = 3.14;
    printValue(&num2, TDOUBLE);
    char symbol = 'A';
    printValue(&symbol, TCHAR);
    return 0;
}

void printValue(const void *valuePtr, uint8_t flag)
{
    if(flag == 1)
    {
        printf("%d\n", *(int *)valuePtr);
    }
    else if(flag == 2)
    {
        printf("%c\n", *(char *)valuePtr);
    }
    else if(flag == 3)
    {
        printf("%lf\n", *(double*)valuePtr);
    }
    else if(flag == 4)
    {
        printf("%f\n", *(float*)valuePtr);
    }
    else if(flag == 5)
    {
        printf("%d\n", *(uint8_t*)valuePtr);
    }
    else if(flag == 6)
    {
        printf("%d\n", *(uint16_t*)valuePtr);
    }
    else if(flag == 7)
    {
        printf("%u\n", *(uint32_t*)valuePtr);
    }
    else if(flag == 8)
    {
        printf("%lu\n", *(uint64_t*)valuePtr);
    }
}