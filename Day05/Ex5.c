#include <stdio.h>

int main()
{
    int num1, num2, res;
    scanf("%d", &num1);
    scanf("%d", &num2);
    res = (num1 ^ num2) < 0;

    printf("%d\n", res);
    return 0;
}