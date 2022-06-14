#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t attendance = 0;
    int option, student;

    while(1)
    {
        printf("1.Set attendance\n");
        printf("2.Clear attendance\n");
        printf("3.Attendance info absence\n");
        printf("4.Attendance info presence\n");
        printf("5.Change attendance\n");
        printf("6.Exit\n");
        scanf("%d", &option);
        if(option == 1)
        {
            printf("Choose student number:");
            scanf("%d", &student);
            if(student < 0 || student > sizeof(attendance)*8)
            {
                fprintf(stderr,"No such student\n");
                continue;
            }
            student--;
            attendance |= (1<<student);
        }
        else if(option == 2)
        {
            printf("Choose student number:");
            scanf("%d", &student);
            if(student < 0 || student > sizeof(attendance)*8)
            {
                fprintf(stderr,"No such student\n");
                continue;
            }
            student--;
            attendance &= ~(1<<student);
        }
        else if(option == 3)
        {
            for(int i = 0; i < sizeof(attendance)*8;i++)
            {
                int check =((1<<i)&attendance)>>i;
                if(check == 0)
                {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        }
        else if(option == 4)
        {
            for(int i = 0; i < sizeof(attendance)*8;i++)
            {
                int check =((1<<i)&attendance)>>i;
                if(check == 1)
                {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        }
        else if(option == 5)
        {
            printf("Choose student number:");
            scanf("%d", &student);
            if(student < 0 || student > sizeof(attendance)*8)
            {
                fprintf(stderr,"No such student\n");
                continue;
            }
            student--;
            attendance ^= (1<<student);
        }
        else if(option == 6)
        {
            break;
        }
    }
    return 0;
}