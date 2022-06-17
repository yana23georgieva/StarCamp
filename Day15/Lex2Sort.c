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
void print(Book *books, FILE *fpw);

int main(int argc, char** argv)
{
    srand(time(NULL));
    Book books[COUNT];
    FILE *fpRead;
    FILE *fpWrite;

    fpRead = fopen(argv[1], "rb");
    if(fpRead == NULL)
    {
        fprintf(stderr, "You can not create file.");
        return -1;
    }

    fread(books, sizeof(*books), COUNT, fpRead);
    fclose(fpRead); 

    //Write
    fpWrite = fopen(argv[2], "w");
    if(fpWrite == NULL)
    {
        fprintf(stderr, "You can not create file.");
        return -1;
    }

    print(books, fpWrite);
    fclose(fpWrite);

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

void print(Book *books, FILE *fpw)
{
    for(int i = 0; i < COUNT; i++)
    {
        fprintf(fpw, "Title: %25s, ", books[i].title);
        fprintf(fpw, "Author: %25s, ", books[i].author);
        fprintf(fpw, "Pages: %4u, ", books[i].pages);
        fprintf(fpw, "Price: %4.2lf\n", books[i].price);
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