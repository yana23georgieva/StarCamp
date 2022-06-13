#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define COUNT 10
typedef int (*comparef_t)(const void*, const void*);

typedef struct
{
    char model[21];
    uint8_t maxSpeed;
    double price;
}Car;

int randint(int,int);
double randReal(double,double);
char* randomName(char *);
void print(const Car *);
int compareModel(const void *str1p, const void *str2p);
int compareModelDesc(const void *str1p, const void *str2p);
int compareMaxSpeed(const void *str1p, const void *str2p);
int compareMaxSpeedDesc(const void *str1p, const void *str2p);
int comparePrice(const void *str1p, const void *str2p);
int comparePriceDesc(const void *str1p, const void *str2p);

int main(){
    srand(time(NULL));
    Car cars[COUNT];
    int howToSort;
    comparef_t compfunc[] =
    {
        compareModel,
        compareModelDesc,
        compareMaxSpeed,
        compareMaxSpeedDesc,
        comparePrice,
        comparePriceDesc
    };


    for(int i = 0; i < COUNT; i++)
    {
        randomName(cars[i].model);
        cars[i].maxSpeed = randint(100, 3000);
        cars[i].price = randReal(1000.00, 100000.00);
    }

    printf("Choose how to sort: ");
    scanf("%d", &howToSort);
    if(howToSort <= 0 || howToSort > 6)
    {
        fprintf(stderr, "Not a valid input\n");
        return -1;
    }
    qsort(cars, COUNT, sizeof(*cars), compfunc[howToSort - 1]);
    print(cars);

    return 0;
}

int compareModel(const void *str1p, const void *str2p)
{
    Car *c1 = (Car*)str1p;
    Car *c2 = (Car *)str2p;

    return strcmp(c1->model, c2->model);
}

int compareModelDesc(const void *str1p, const void *str2p)
{
    Car *c1 = (Car *)str1p;
    Car *c2 = (Car *)str2p;

    return strcmp(c2->model, c1->model);
}

int compareMaxSpeed(const void *str1p, const void *str2p)
{
    Car *c1 = (Car *)str1p;
    Car *c2 = (Car *)str2p;

    return c1->maxSpeed - c2->maxSpeed;
}

int compareMaxSpeedDesc(const void *str1p, const void *str2p)
{
    Car *c1 = (Car *)str1p;
    Car *c2 = (Car *)str2p;

    return c2->maxSpeed - c1->maxSpeed;
}

int comparePriceDesc(const void *str1p, const void *str2p)
{
    Car *c1 = (Car *)str1p;
    Car *c2 = (Car *)str2p;

    if(fabs(c1->price - c2->price) < 0.001)
    {
        return 0;
    }
    else if(c1->price > c2->price)
    {
        return -1;
    }
    return 1;
}

int comparePrice(const void *str1p, const void *str2p)
{
    Car *c1 = (Car *)str1p;
    Car *c2 = (Car *)str2p;

    if(fabs(c1->price - c2->price) < 0.001)
    {
        return 0;
    }
    else if(c1->price < c2->price)
    {
        return -1;
    }
    return 1;
}

char* randomName(char *name)
{
    unsigned index = 0;
    int n = randint(4, 10);

    name[index++] = randint('A', 'Z');

    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }

    name[index] = '\0';
    return name;
}

void print(const Car *cars)
{
    for(int i = 0; i < COUNT; i++)
    {
        printf("Model: %20s, ", cars[i].model);
        printf("Max speed: %4u, ", cars[i].maxSpeed);
        printf("Price: %4.2lf\n", cars[i].price);
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