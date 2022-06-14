#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>

double MaxNum(unsigned n, ...);
double MinNum(unsigned n, ...);

int main()
{
    printf("%.2lf\n", MaxNum(4, -4.2, -2.3, -1.6, -15.0));
    printf("%.2lf\n", MinNum(3, 4.2, 2.3, 1.6));
    return 0;
}

double MaxNum(unsigned n, ...)
{
    double max;

    va_list argl;
    va_start (argl, n);
    double num = va_arg(argl, double);
    max = num;

    for(int i = 1;i < n; i++)
    {
        num = va_arg(argl, double);
        if(num > max)
        {
            max = num;
        }
    }
    va_end(argl);

    return max;
}

double MinNum(unsigned n, ...)
{
    double min = DBL_MAX;

    va_list argl;
    va_start (argl, n);

    for(int i = 0;i < n; i++)
    {
        double num = va_arg(argl, double);
        if(num < min)
        {
            min = num;
        }
    }
    va_end(argl);

    return min;
}