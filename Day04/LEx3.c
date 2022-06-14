#include <stdio.h>
#include <math.h>

int main()
{
    int number, base1, base2, newNumber = 0;
    printf("Enter number: ");
    scanf("%d", &number);
    if(number < 0)
    {
        fprintf(stderr,"Incorrect number\n");
        return 1;
    }
    printf("Enter first base: ");
    scanf("%d", &base1);
    if(base1 < 2 || base1 > 36)
    {
        fprintf(stderr,"Incorrect base\n");
        return 1;
    }
    printf("Enter second base: ");
    scanf("%d", &base2);
    if(base2 < 2 || base2 > 36)
    {
        fprintf(stderr,"Incorrect base\n");
        return 1;
    }
    
    printf("%d\n", newNumber);
    return 0;
}