#include <stdio.h>
#include <math.h>

int quadEq(double a, double b, double c, double *x1, double *x2);

int main()
{
    double num1, num2, num3, x1, x2;

    while(scanf("%lf %lf %lf", &num1, &num2, &num3) != EOF)
    {
        int res = quadEq(num1, num2, num3, &x1, &x2);
        if(res == 0)
        {
            printf("x1 = %.2lf\n", x1);
            printf("x2 = %.2lf\n", x2);
        }
    }
    return 0;
}

int quadEq(double a, double b, double c, double *x1, double *x2)
{
    double d = (b*b - 4*a*c);
    if(d < 0)
    {
        fprintf(stderr, "No real roots\n");
        return -1;
    }
    else
    {
        *x1 = (-b + sqrt(d))/(2*a);
        *x2 = (-b - sqrt(d))/(2*a);
    }
    return 0;
}