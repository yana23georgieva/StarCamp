#include <stdio.h>

int main()
{
    double num1, num2, num3, max;

    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if(num1 > num2)
    {
        if(num1 > num3)
        {
            max = num1;
        }
        else
        {
            max = num3;
        }
    }
    else
    {
        if(num2 > num3)
        {
            max = num2;
        }
        else
        {
            max = num3;
        }
    }

    printf("%.2lf\n", max);

    return 0;
}