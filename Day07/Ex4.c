#include <stdio.h>

void storeLetter(int n, char *resPointer);

int main()
{
    char res;
    storeLetter(5, &res);
    printf("%c\n", res);
    return 0;
}

void storeLetter(int n, char *resPointer)
{
    *resPointer = 'a' + n - 1;
}