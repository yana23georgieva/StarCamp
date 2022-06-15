#include <stdio.h>

void reverse(char *ptr);

int main()
{
    char arr[] = "This is a test!";
    reverse(arr);
    printf("%s\n", arr);
    return 0;
}

void reverse(char *ptr)
{
    int count = 0;
    for (size_t i = 0; ptr[i] != '\0'; i++)
    {
        count++;
    }
    for (size_t i = 0; i < count/2; i++)
    {
        char current = ptr[i];
        ptr[i] = ptr[count- 1 - i];
        ptr[count- 1 - i] = current;
    }
}