#include <stdio.h>
#include <math.h>

int main()
{
    double radius, height, volume, volume2;
    double lenghth = 0;
    int flag = 0;

    printf("Enter radius: ");
    scanf("%lf", &radius);

    printf("Enter height: ");
    scanf("%lf", &height);

    printf("Choose 1 for horizontal cylinder: ");
    scanf("%d", &flag);

    volume = pow(radius, 2)*height*M_PI;
    printf("The volume is: %.3lf\n", volume);

    if(flag == 1)
    {
        printf("Enter lenghth: ");
        scanf("%lf", &lenghth);
        
        double area = acos((radius - height)/radius)*pow(radius, 2) - (radius - height)*sqrt(2*radius*height - pow(height, 2));
        volume2 = area*lenghth;
        printf("The horizontal volume is: %.3lf\n", volume2);
    }

    return 0;
}