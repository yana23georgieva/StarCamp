#include <stdio.h>

unsigned int sum_digit(unsigned int n);
unsigned int sumDigitRecursive(unsigned int n);

int main()
{
    printf("%u\n", sum_digit(12345));
    printf("%u\n", sumDigitRecursive(12345));
}

unsigned int sum_digit(unsigned int n)
{
    unsigned int sum = 0;
    for(;n > 0;n /= 10)
    {
        sum += n % 10;
    }

    return sum;
}

unsigned int sumDigitRecursive(unsigned int n)
{
    if(n == 0)
    {
        return 0;
    }
    return sumDigitRecursive(n / 10) + n % 10;
}