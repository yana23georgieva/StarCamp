#include <stdio.h>

int main()
{
    unsigned nrows, ncols, row, col;
    scanf("%u %u %u %u", &row, &col,&nrows,&ncols);
    unsigned n = row*ncols + col;
    printf("%u\n", n);
    return 0;
}