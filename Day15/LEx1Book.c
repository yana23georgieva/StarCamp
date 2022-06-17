#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 5

typedef struct
{
    char title[151];
    char author[101];
    unsigned pages;
    double price;
}Book;

int randint(int,int);
double randReal(double,double);
char* randomName(char *name);
void print(Book *books);

int main(int argc, char** argv)
{
    srand(time(NULL));
    Book books[COUNT];
    FILE *fp;

    for(int i = 0; i < COUNT; i++)
    {
        randomName(books[i].title);
        randomName(books[i].author);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.00, 1000.00);
    }

    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        fprintf(stderr, "You can not create file.");
        return -1;
    }

    fwrite(books, sizeof(*books), COUNT, fp);
    fclose(fp);
    print(books);

    return 0;
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
        printf("Title: %25s, ", books[i].title);
        printf("Author: %25s, ", books[i].author);
        printf("Pages: %4u, ", books[i].pages);
        printf("Price: %4.2lf\n", books[i].price);
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