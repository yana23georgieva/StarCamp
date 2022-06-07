#include <stdio.h>

double sinus(double x);
double pow1(double number, int power);
int factoriel(int number);

int main()
{
    double degree = 30*3.14159/180;
    printf("%lf\n", sinus(degree));
    degree = 90*3.14159/180;
    printf("%lf\n", sinus(degree));
    degree = 0*3.14159/180;
    printf("%lf\n", sinus(degree));
    return 0;
}

double sinus(double x)
{
    double result = 0.0;

    for(int i = 0; i < 15; i++)
    {
        result += (pow1(-1, i)*pow1(x, 2*i + 1))/factoriel(2*i + 1);
    }

    return result;
}

double pow1(double number, int power)
{
    double n = 1;

    for(int i = 0; i < power; i++)
    {
        n *= number;
    }

    return n;
}

int factoriel(int number)
{
    int fact = 1;

    for(int i = 2; i <= number; i++)
    {
        fact *= i;
    }
    return fact;
}