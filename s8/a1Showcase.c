#include "a1.h"
#include <stdio.h>

// gcc a1.h a1.c a1Showcase.c -o a1Exe -lm && ./a1Exe && rm ./a1Exe


int main() {
    Polynomial* poly = newPoly(5);
    setPolyCoef(poly, 3, 5);
    setPolyCoef(poly, 4, 8);
    printf("coef[3] = %lf", getPolyCoef(poly, 3));
}