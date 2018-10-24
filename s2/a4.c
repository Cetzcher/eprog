#include <stdio.h>

int quadrant(double x, double y)
{
    if (x > 0 && y > 0)
        return 1;
    else if (x < 0 && y > 0)
        return 2;
    else if (x < 0 && y < 0)
        return 3;
    else if (x > 0 && y < 0)
        return 4;
    return 0;
}

int main()
{
    double x, y;
    printf("x=");
    scanf("%lf", &x);
    printf("y=");
    scanf("%lf", &y);

    int q = quadrant(x, y);
    if (q)
        printf("Quadrant=%d \n", q);
    else
        printf("auf der Achse");

    return 0;
}