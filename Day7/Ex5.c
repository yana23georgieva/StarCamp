#include <stdio.h>

int combination(int n, int k);

int main()
{
    int res;
    res = combination(10, 5);
    printf("%d\n", res);
    return 0;
}

int combination(int n, int k)
{
    if(n == k || k == 0)
    {
        return 1;
    }
    return combination(n - 1, k - 1) +
    combination(n - 1, k);
}