#include <stdio.h>

void square(double *x)
{
    //double *y;  das macht keinen sinn *y kann jeder beliebige wert sein sollte daher *y = x sein
    double *y = x;
    // syntax fehler x sollte *x sein
    // x = (*y) * (*x);
    *x = (*y) * (*x);
}

int main()
{
    double x = 2.1;
    square(&x);
    printf("x^2=%f\n", x);
    return 0;
}