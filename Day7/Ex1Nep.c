#include <stdio.h>

unsigned long factoriel(int number);
double NeperNumber();

int main()
{
    printf("%lf\n", NeperNumber());
    return 0;
}

double NeperNumber()
{
    double sum = 0;

    for(int i = 0; i < 20; i++)
    {
        sum += (1.0/factoriel(i));
    }
    return sum;
}

unsigned long factoriel(int number)
{
    unsigned long fact = 1;

    for(int i = 2; i <= number; i++)
    {
        fact *= i;
    }
    return fact;
}