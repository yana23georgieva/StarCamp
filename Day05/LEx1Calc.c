#include <stdio.h>

int main()
{
    double num1, num2, result = 0;
    char operation;

    while(1)
    {
        printf("Enter first number: ");
        if(scanf("%lf", &num1) == EOF)
        {
            break;
        } 
        printf("Enter second number: ");
        scanf("%lf", &num2); 
        printf("Enter operation: ");
        while((getchar()) != '\n');
        scanf("%c", &operation); 

        if(operation == '+')
        {
            result = num1 + num2;
        }
        else if(operation == '-')
        {
            result = num1 - num2;
        }
        else if(operation == 'x')
        {
            result = num1 * num2;
        }
        else if(operation == '/')
        {
            result = num1 / num2;
        }
        else
        {
            fprintf(stderr, "Not a valid operation\n");
        }
        printf("%.2lf\n", result);
    }
    return 0;
}