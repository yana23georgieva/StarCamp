#include <stdio.h>

int mystrcmp(const char* str1, const char* str2);

int main()
{
    printf("%d\n", mystrcmp("Hello", "Hello"));
    printf("%d\n", mystrcmp("Hello", "Hi"));
    printf("%d\n", mystrcmp("Hi", "Hello"));
    printf("%d\n", mystrcmp("", "Hello"));
    printf("%d\n", mystrcmp("Hello", ""));
    printf("%d\n", mystrcmp("", ""));
    return 0;
}

int mystrcmp(const char* str1, const char* str2)
{
    int res = -(int)str2[0], i = 0;

    while(str1[i] != '\0')
    {
        res = str1[i] - str2[i];
        if(res != 0)
        {
            return res;
        }
        i++;
    }

    return res;
}