#include <stdio.h>
#include <math.h>
#include <getopt.h>
#include <stdlib.h>

int quadEq(double a, double b, double c, double *x1, double *x2);

int main(int argc, char** argv)
{
    double num1, num2, num3, x1, x2;

    int opt;
    while ((opt = getopt(argc, argv, ":a:b:c:")) != -1)
    {
        switch (opt)
        {
            case 'a': 
                num1 = atof(optarg);
                break;
            case 'b': 
                num2 = atof(optarg);
                break;
            case 'c': 
                num3 = atof(optarg);
                break;
            case '?':
                fprintf(stderr, "Unknown option: %c\n", optopt);
                return -1;
            case ':':
                fprintf(stderr, "Missing arg for %c\n", optopt);
                return -1;
        }
    }

    int res = quadEq(num1, num2, num3, &x1, &x2);
    if(res == 0)
    {
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
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