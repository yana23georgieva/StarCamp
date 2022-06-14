#include <stdio.h>

void printSymbols();
char capitalize(char sym);

int main()
{
    printSymbols();
    printf("%c\n", capitalize('a'));
    printf("%c\n", capitalize('b'));
    printf("%c\n", capitalize('y'));
    printf("%c\n", capitalize('='));
    return 0;
}

void printSymbols()
{
    char sym;
    for(sym = -128; sym < 127; sym++)
    {
        printf("%c %d\n", sym, sym);
    }
}

char capitalize(char sym)
{
    if(!(sym >= 97 && sym <= 122))
    {
        return 0;
    }
    return sym - 32; //sym + ('A' -'a')
}