#include <stdio.h>

int main()
{
    char number[501]= {"6234"};
    char symbols[] =
    {
        '!',
        '#',
        '/',
        '~',
        '=',
        '\'',
        '\\', 
        '>',
        '.',
        ',',
    };

    scanf("%s", number);

    for (size_t i = 0; number[i] != '\0' && i < 501; i++)
    {
        if(i % 2 == 0)
        {
            number[i] = number[i] + 17;
        }
        else
        {
            number[i] = symbols[number[i]];
        }
    }

    for (size_t i = 0; number[i] != '\0' && i < 501; i++)
    {
        printf("%c", number[i]);
    }
    putchar('\n');
    
    return 0;
}