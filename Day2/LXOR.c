#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    d = a^b;
    printf("%d\n", d);
    printf("%d\n", c^d);
    return 0;
}