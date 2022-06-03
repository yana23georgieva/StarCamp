#include <stdio.h>
#include <math.h>

int main()
{
    double mass, height, BMI, BMInew;

    printf("Enter mass: ");
    scanf("%lf", &mass);

    printf("Enter height: ");
    scanf("%lf", &height);

    BMI = mass/pow(height, 2);
    BMInew = 1.3*mass/pow(height, 2.5);

    printf("The BMI is: %.3lf\n", BMI);
    printf("The BMI new is: %.3lf\n", BMInew);
    return 0;
}