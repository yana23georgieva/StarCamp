#include <stdio.h>
#include <stddef.h>

char* mystrncpy(char *dest, const char *str, size_t n);
char* mystrncat(char *dest, const char *str, size_t n);

int main()
{
    char str1[20], str2[6];
    mystrncpy(str1, "Hello World!!!", 19);
    mystrncpy(str2, "Hi! 2022", 5);

    printf("%s\n", str1);
    printf("%s\n", str2);

    mystrncat(str1, str2, 5);
    printf("%s\n", str1);
    return 0;
}

char* mystrncpy(char *dest, const char *str, size_t n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(*(str + i) == '\0')
        {
            return dest;
        }
        *(dest + i) = *(str + i);
    }
    *(dest + i) = '\0';
    return dest;
}

char* mystrncat(char *dest, const char *str, size_t n)
{
    int i = 0;
    while(dest[i] != '\0')
    {
        i++;
    }
    for(int j = 0; j < n; j++)
    {
        if(*(str + i) == '\0')
        {
            return dest;
        }
        *(dest + i) = *(str + j);
        i++;
    }
    *(dest + i) = '\0';
    return dest;
}