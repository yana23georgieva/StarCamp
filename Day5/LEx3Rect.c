#include <stdio.h>

int rectangle(double w, double h, double *s, double *p);

int main()
{
    double num1, num2, s, p;

    while(scanf("%lf %lf", &num1, &num2) != EOF)
    {
        int res = rectangle(num1, num2, &s, &p);
        if(res == 0)
        {
            printf("S = %.2lf\n", s);
            printf("P = %.2lf\n", p);
        }
    }
    return 0;
}

int rectangle(double w, double h, double *s, double *p)
{
    if(w <= 0)
    {
        fprintf(stderr, "Width can not be less or equal to zero.\n");
        return -1;
    }
    if(h <= 0)
    {
        fprintf(stderr, "Height can not be less or equal to zero.\n");
        return -1;
    }
    *p = (w + h)*2;
    *s = w * h;
    return 0;
}