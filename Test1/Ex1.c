#include <stdio.h>
#include <math.h>

int cylinder(double r, double h, double *V, double *S);

int main()
{
    double r, h, S, V;

    while(scanf("%lf %lf", &r, &h) != EOF)
    {
        int res = cylinder(r, h, &S, &V);
        if(res == 0)
        {
            printf("V = %.2lf, S = %.2lf\n", S, V);
        }
    }

    return 0;
}

int cylinder(double r, double h, double *V, double *S)
{
    if(r < 0)
    {
        fprintf(stderr, "Not a valid radius.\n");
        return -1;
    }
    if(h < 0)
    {
        fprintf(stderr, "Not a valid height.\n");
        return -1;
    }
    *V = M_PI*r*r*h;
    double B = M_PI*r*r;
    double s = 2*M_PI*r*h;
    *S = s + 2*B;

    return 0;
}