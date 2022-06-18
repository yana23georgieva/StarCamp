#include <stdio.h>
#include <math.h>

void conv(int sValue, char *pBuffer);

int main()
{
    int number;
    char str[12];
    scanf("%d", &number);
    conv(number, str);
    //sprintf(str, "%d", number);
    printf("%s\n", str);
    return 0;
}

void conv(int sValue, char *pBuffer)
{
    if(sValue < 0)
    {
        pBuffer[0] = '-';
    }
    else
    {
        pBuffer[0] = ' ';
    }

    pBuffer[12] = '\0';
    sValue = fabs(sValue);
    //sprintf(pBuffer, "%d", sValue);

    for (int i = 11; i > 0; i--)
    {
        if(sValue > 0)
        {
            int digit = sValue % 10;
            pBuffer[i] = digit + '0';
            sValue /= 10;
        }
        else
        {
            pBuffer[i] = ' ';
        }
    }
    
}