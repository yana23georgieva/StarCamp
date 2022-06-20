#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 5

typedef struct
{
    double x;
    double y;
}point_t;

typedef struct
{
    point_t A;
    point_t B;
}rectangle_t;

typedef struct node
{
    rectangle_t rect;
    struct node *next;   
}List;

void push(List **list, rectangle_t r);
double areaRect(List *list);
double areaRects(List *list);
void filterRects(List **list, double min, double max);
void print(List* list);
double randReal(double min, double max);

int main()
{
    srand(time(NULL));
    List *listReact = NULL;
    for(int i = 0; i < COUNT; i++)
    {
        rectangle_t currentRect;
        currentRect.A.x = randReal(-10.0, 10.0);
        currentRect.A.y = randReal(-10.0, 10.0);
        currentRect.B.x = randReal(-10.0, 10.0);
        currentRect.B.y = randReal(-10.0, 10.0);
        push(&listReact, currentRect);
    }
    print(listReact);
    filterRects(&listReact, 10, 26);
    printf("Filter: \n");
    print(listReact);
    return 0;
}

void push(List **list, rectangle_t r)
{
    List* n = malloc(sizeof(List));
    n->rect= r;
    n->next = *list;
    *list = n;
}

double areaRect(List *list)
{
    List* current = list;
    double a = current->rect.B.x - current->rect.A.x;
    double b = current->rect.B.y - current->rect.A.y;

    return a*b;
}

double areaRects(List *list)
{
    List* current = list;
    double sum = 0;
    while (current != NULL)
    {
        sum += areaRect(current);
        current = current->next;
    }

    return sum;
}

void filterRects(List **list, double min, double max)
{
    List* current = *list;
    List* prev = NULL;
    while (current != NULL)
    {
        double area = areaRect(current);
        if(max - area > 0.01 && area - min > 0.01)
        {
            if(prev == NULL)
            {
                *list = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
        }
        prev = current;
        current = current->next;
    }
}

void print(List* list)
{
    List* current = list;
    while (current != NULL)
    {
        printf("%lf ", current->rect.A.x);
        printf("%lf ", current->rect.A.y);
        printf("%lf ", current->rect.B.x);
        printf("%lf \n", current->rect.B.y);
        current = current->next;
    }
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}