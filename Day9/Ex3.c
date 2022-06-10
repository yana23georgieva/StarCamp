#include <stdio.h>

void storeSubstring(char *, int, int, char *);

int main()
{
    char arr[] = {"Heloo1114254657"};
    char dest[30];
    storeSubstring(arr, 2, 8, dest);
    printf("%s\n", dest);
    return 0;
}

void storeSubstring(char *str, int begin, int length, char *dest)
{
    char subArr[length + 1];
    for(int i = begin; i < begin + length; i++)
    {
        dest[i - begin] = str[i];
    }
    subArr[length] = '\0';
}