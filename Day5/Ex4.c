#include <stdio.h>

int main()
{
    int n, res;
    scanf("%d", &n);
    res = -(~n);//++
    printf("%d\n", res);
    return 0;
}