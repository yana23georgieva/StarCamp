#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double *s, double *p);

int main()
{
    double num1, num2, num3, s, p;

    while(scanf("%lf %lf %lf", &num1, &num2, &num3) != EOF)
    {
        int res = triangle(num1, num2, num3, &s, &p);
        if(res == 0)
        {
            printf("S = %.2lf\n", s);
            printf("P = %.2lf\n", p);
        }
    }
    return 0;
}

int triangle(double a, double b, double c, double *s, double *p)
{
    if(a <= 0)
    {
        fprintf(stderr, "Side a can not be less or equal to zero.\n");
        return -1;
    }
    if(b <= 0)
    {
        fprintf(stderr, "Side b can not be less or equal to zero.\n");
        return -1;
    }
    if(c <= 0)
    {
        fprintf(stderr, "Side c can not be less or equal to zero.\n");
        return -1;
    }
    *p = a + b + c;
    double semiP = (a + b + c)/2;
    *s = sqrt(semiP*(semiP - a)*(semiP - b)*(semiP - c));
    return 0;
}