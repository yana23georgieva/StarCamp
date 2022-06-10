#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int,int);
double randReal(double,double);
void randomName(char *str, size_t n);

int main(){
    srand(time(NULL));
    char name[24];
    randomName(name, 10);
    printf("%s\n", name);
    randomName(name, 23);
    printf("%s\n", name);
    randomName(name, 5);
    printf("%s\n", name);
    randomName(name, 12);
    printf("%s\n", name);
    return 0;
}

void randomName(char *str, size_t n)
{
    int i = 0;
    str[i] = randint('A', 'Z');
    int firstLetters = (n - 3) / 2;

    for(i = 1; i <= firstLetters; i++)
    {
        str[i] = randint('a', 'z');
    }
    str[i] = ' ';
    i++;
    str[i] = randint('A', 'Z');
    i++;

    for(; i < n; i++)
    {
        str[i] = randint('a', 'z');
    }
    str[i] = '\0';
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}