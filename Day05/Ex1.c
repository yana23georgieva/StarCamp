#include <stdio.h>

int main()
{
    unsigned number, index, result;
    scanf("%u", &number);
    scanf("%u", &index);
    index--;

    result = number & (1<<index);
    result = result>>index;
    printf("%u bit is: %u\n", (index + 1), result);
    return 0;
}