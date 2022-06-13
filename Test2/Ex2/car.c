#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "car.h"

#define COUNT 10

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