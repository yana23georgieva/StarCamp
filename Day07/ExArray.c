#include <stdio.h>
#include <limits.h>

int main()
{
    int nums[10], sum = 0;
    int max = INT_MIN, min = INT_MAX;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", (nums + i));
        int number = *(nums + i);
        sum += number;
        if(number > max)
        {
            max = number;
        }
        if(number < min)
        {
            min = number;
        }
    }
    
    printf("%d\n", sum);
    printf("%d\n", max);
    printf("%d\n", min);
    return 0;
}