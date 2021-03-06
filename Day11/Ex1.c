#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// suma
int main(int argc, char** argv){
    double sum = 0;
    int j = 2;

    if (2 == argc)
    {
        if (!strcmp(argv[1], "-s"))
        {
            double sum = 0, num;
            while (scanf("%lf", &num) != EOF)
            {
                sum += num;
            }
            printf("Sum = %.2lf\n", sum);
        } 
        else if (!strcmp(argv[1], "-a"))
        {
            double sum = 0, num;
            int cnt = 0;
            while (scanf("%lf", &num) != EOF)
            {
                sum += num;
                cnt++;
            }
            printf("Avg = %.2lf\n", sum / cnt);
        }
        return 0;
    }

    if (!strcmp(argv[1], "-s"))
    {
        for (int i = 2; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            sum += num;
        }
        printf("Sum = %.2lf\n", sum);
    } 
    else if (!strcmp(argv[1], "-M"))
    {
        double max;
        sscanf(argv[2], "%lf", &max);
        for (int i = 3; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            max = (num > max) ? num : max;
        }
        printf("Max = %.2lf\n", max);
    }
    else if (!strcmp(argv[1], "-m"))
    {
        double min;
        sscanf(argv[2], "%lf", &min);
        for (int i = 3; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            min = (num < min) ? num : min;
        }
        printf("Min = %.2lf\n", min);
    }
    else if (!strcmp(argv[1], "-a"))
    {
        for (int i = 2; i < argc; i++){
            double num;
            sscanf(argv[i], "%lf", &num);
            sum += num;
        }
        printf("Average = %.2lf\n", sum / (argc - 2));
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            printf("%s ",argv[i]);
        }
        putchar('\n');
    }
    return 0;
}