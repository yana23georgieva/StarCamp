#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 5

typedef struct
{
    char title[150];
    char author[100];
    int pages;
    double price;
}Book;

int randint(int,int);
double randReal(double,double);
char* randomName(char *name);
void print(Book *books);
int linearSearch(Book *books, double item);

int main(){
    srand(time(NULL));
    Book books[COUNT];

    for(int i = 0; i < COUNT; i++)
    {
        randomName(books[i].title);
        randomName(books[i].author);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.00, 1000.00);
    }
    print(books);

    printf("%d\n", linearSearch(books, 20.50));

    return 0;
}

int linearSearch(Book *books, double item)
{
    for(int i = 0; i < COUNT; i++)
    {
        if(fabs(books[i].price - item) < 0.01)
        {
            return i;
        }
    }

    fprintf(stderr, "Missing element");
    return -1;
}

char* randomName(char *name)
{
    unsigned index = 0;
    int n = randint(10, 20);

    for (int i = 0; i < n; i++)
    {
        int letter = randint(1, 2);
        if(letter == 1)
        {
            name[index++] = randint('a', 'z');
        }
        else
        {
            name[index++] = randint('A', 'Z');
        }
    }

    name[index] = '\0';
    return name;
}

void print(Book *books)
{
    for(int i = 0; i < COUNT; i++)
    {
        printf("Title: %s, ", books[i].title);
        printf("Author: %s, ", books[i].author);
        printf("Pages: %d, ", books[i].pages);
        printf("Price: %.2lf\n", books[i].price);
    }
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}