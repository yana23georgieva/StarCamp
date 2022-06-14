#include <stdio.h>

int main()
{
    char sym = 0, prevSym;

    while(sym != 'A')
    {
        prevSym = sym;
        scanf("%c", &sym);
        if(prevSym != ' ' || sym != ' ')
        {
            printf("%c", sym);
        }
    }
    return 0;
}