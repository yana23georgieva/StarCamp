#include <stdio.h>
#include <stddef.h>

size_t mystrlen(const char* str);
size_t mystrnlen(const char*, size_t);
char* mystrcpy(char *dest, const char *str);
char* mystrncpy(char *dest, const char *str, size_t n);
char* mystrcat(char *dest, const char *str);
char* mystrncat(char *dest, const char *str, size_t n);
int mystrcmp(const char* str1, const char* str2);
int mystrncmp(const char* str1, const char* str2, size_t n);
const char *mystrstr(const char* str1, const char* str2);

int main()
{
    char str1[20], str2[6], str3[20];
    mystrncpy(str1, "Hello World!!!", 19);
    
    mystrcpy(str2, "Hi!");
    printf("%s\n", str2);

    mystrncpy(str2, "Hi! 2022", 5);

    printf("%lu\n", mystrlen(str1));
    printf("%lu\n", mystrnlen(str2, 5));


    printf("%s\n", str1);
    printf("%s\n", str2);

    mystrncat(str1, str2, 5);
    printf("%s\n", str1);

    mystrcat(str2, "Unsave");
    printf("%s\n", str2);

    printf("%d\n", mystrcmp("Hello", "Hello"));
    printf("%d\n", mystrcmp("Hello", "Hi"));
    printf("%d\n", mystrcmp("Hi", "Hello"));
    printf("%d\n", mystrcmp("", "Hello"));
    printf("%d\n", mystrcmp("Hello", ""));
    printf("%d\n", mystrcmp("", ""));

    printf("--------------------\n");
    mystrncpy(str3, "Hi! My World str!", 19);
    const char* p = mystrstr(str3, "World");
    if(p != NULL)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    const char* k = mystrstr(str3, "Word");
    if(k != NULL)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

size_t mystrlen(const char* str)
{
    size_t n = 0;

    while(str[n] != '\0')
    {
        n++;
    }

    return n;
}

size_t mystrnlen(const char* str, size_t maxLen)
{
    size_t n = 0;

    while(str[n] != '\0' && n < maxLen)
    {
        n++;
    }

    return n;
}

char* mystrcpy(char *dest, const char *str)
{
    int i = 0;
    while(*(str + i) != '\0')
    {
        *(dest + i) = *(str + i);
        i++;
    }
    *(dest + i) = '\0';
    return dest;
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

char* mystrcat(char *dest, const char *str)
{
    int i = 0, j = 0;
    while(dest[i] != '\0')
    {
        i++;
    }
    while(*(str + i) != '\0')
    {
        *(dest + i) = *(str + j);
        i++;
        j++;
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

int mystrncmp(const char* str1, const char* str2, size_t n)
{
    int res = -(int)str2[0], i = 0;

    while(str1[i] != '\0' && i < n)
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

const char *mystrstr(const char* str1, const char* str2)
{
    int i = 0;

    while(str1[i] != '\0')
    {
        if(str1[i] == str2[0])
        {
            int j = 1;
            while(str2[j] == str1[i + j])
            {
                j++;
            }
            if(str2[j] == '\0')
            {
                return (str1 + i);
            }
        }
        i++;
    }

    return NULL;
}