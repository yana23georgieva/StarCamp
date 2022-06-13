#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "car.h"

#define COUNT 10

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