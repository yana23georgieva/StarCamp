#include <stdint.h>

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