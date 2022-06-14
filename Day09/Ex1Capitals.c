#include <stdio.h>

void changeLetters(char *str);

int main()
{
    char str[100];
    scanf("%s", str);
    changeLetters(str);
    printf("%s\n", str);
    return 0;
}

void changeLetters(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        char n = 'a' - 'A';
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += n;
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= n;
        }
    }
}