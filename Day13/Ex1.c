#include <stdio.h>

int main()
{
    unsigned n, nrows, ncols;
    scanf("%u %u %u", &n,&nrows,&ncols);
    unsigned row, col;
    row = n/ncols;
    col = n%ncols;
    return 0;
}