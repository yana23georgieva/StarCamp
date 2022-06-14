#include <stdio.h>
#include <string.h>

int sToUint(char *str, unsigned *res);

int main()
{
    unsigned int res;
    char str[100];
    scanf("%s", str);
    if(sToUint(str, &res) == 0)
    {
        printf("%u\n", res);
    }
    return 0;
}

int sToUint(char *str, unsigned *res)
{
    unsigned int pow10 = 1, sum = 0;
    unsigned int digitValue;

    for(int i = strlen(str) - 1; i >= 0;i--)
    {
        digitValue = str[i] - '0';
        if(!(digitValue >= 0 && digitValue <= 9))
        {
            fprintf(stderr, "Not a valid number\n");
            return -1;
        }
        sum += pow10 * digitValue;
        pow10 *= 10;
    }
    *res = sum;
    return 0;
}