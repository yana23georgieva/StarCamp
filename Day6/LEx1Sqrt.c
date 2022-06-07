#include <stdio.h>

double sqrt1(double x);

int main()
{
    printf("%lf\n", sqrt1(9.0));
    printf("%lf\n", sqrt1(77.0));
    printf("%lf\n", sqrt1(25.6));
    return 0;
}

double sqrt1(double x)
{
    double t, root = x/2;

    do
    {
        t = root;
        root = (t + (x/t)) / 2;
    }while((t - root) != 0);

    return root;
}