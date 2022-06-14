#include <stdio.h>

int isBalanced(char *str);

int main()
{
    char str[50];
    scanf("%s", str);
    if(isBalanced(str) == 0)
    {
        printf("Balanced!\n");
    }
    else
    {
        printf("Not Balanced!\n");
    }
    return 0;
}

int isBalanced(char *str)
{
    int nOpen = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            nOpen++;
        }
        else if(str[i] == ')')
        {
            if(nOpen == 0)
            {
                return -1;
            }
            nOpen--;
        }
    }
    if(nOpen != 0)
    {
        return -1;
    }
    return 0;
}