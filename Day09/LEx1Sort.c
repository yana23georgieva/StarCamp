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
void print(const Book *books);
int compareTitle(const void *str1p, const void *str2p);
int compareTitleDesc(const void *str1p, const void *str2p);
int compareAuthor(const void *str1p, const void *str2p);
int compareAuthorDesc(const void *str1p, const void *str2p);
int comparePages(const void *str1p, const void *str2p);
int comparePagesDesc(const void *str1p, const void *str2p);
int comparePrice(const void *str1p, const void *str2p);
int comparePriceDesc(const void *str1p, const void *str2p);

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

    printf("Sort by pages:\n");
    qsort(books, COUNT, sizeof(*books), comparePages);
    print(books);

    printf("Sort by pages desc:\n");
    qsort(books, COUNT, sizeof(*books), comparePagesDesc);
    print(books);

    printf("Sort by title:\n");
    qsort(books, COUNT, sizeof(*books), compareTitle);
    print(books);

    printf("Sort by price:\n");
    qsort(books, COUNT, sizeof(*books), comparePrice);
    print(books);

    return 0;
}

int compareTitle(const void *str1p, const void *str2p)
{
    Book *b1 = (Book *)str1p;
    Book *b2 = (Book *)str2p;

    return strcmp(b1->title, b2->title);
}

int compareTitleDesc(const void *str1p, const void *str2p)
{
    Book b1 = *(Book *)str1p;
    Book b2 = *(Book *)str2p;

    return strcmp(b2.title, b1.title);
}

int compareAuthor(const void *str1p, const void *str2p)
{
    Book *b1 = (Book *)str1p;
    Book *b2 = (Book *)str2p;

    return strcmp(b1->author, b2->author);
}

int compareAuthorDesc(const void *str1p, const void *str2p)
{
    Book b1 = *(Book *)str1p;
    Book b2 = *(Book *)str2p;

    return strcmp(b2.author, b1.author);
}

int comparePages(const void *str1p, const void *str2p)
{
    Book b1 = *(Book *)str1p;
    Book b2 = *(Book *)str2p;

    return b1.pages - b2.pages;
}

int comparePagesDesc(const void *str1p, const void *str2p)
{
    Book b1 = *(Book *)str1p;
    Book b2 = *(Book *)str2p;

    return b2.pages - b1.pages;
}

int comparePrice(const void *str1p, const void *str2p)
{
    Book b1 = *(Book *)str1p;
    Book b2 = *(Book *)str2p;

    if(fabs(b1.price - b2.price) < 0.001)
    {
        return 0;
    }
    else if(b1.price > b2.price)
    {
        return -1;
    }
    return 1;
}

int comparePriceDesc(const void *str1p, const void *str2p)
{
    Book b1 = *(Book *)str1p;
    Book b2 = *(Book *)str2p;

    if(fabs(b1.price - b2.price) < 0.001)
    {
        return 0;
    }
    else if(b1.price < b2.price)
    {
        return -1;
    }
    return 1;
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

void print(const Book *books)
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