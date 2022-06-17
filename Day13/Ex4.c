#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
}Point;


int isInCircle(Point, double, double, double);
double distance(double, double, double, double);

int main()
{
    unsigned n;
    Point center;
    double r;
    scanf("%lf %lf %lf", &center.x, &center.y, &r);
    scanf("%u", &n);
    Point points[100];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%lf %lf", &points[i].x, &points[i].y);  
    }
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (isInCircle(center, r, points[i].x, points[i].y))
        {
            count++;
        }.       
    }
    
    return 0;
}

double distance(double x1, double x2, double y1, double y2)
{
    double xD = x1 - x2;
    double yD = y1 - y2;
    return sqrt(xD*xD + yD*yD);
}

int isInCircle(Point c,double r, double x, double y)
{
    return distance(c.x, c.y, x, y) < r;
}