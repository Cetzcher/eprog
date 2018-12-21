#include "a1.h"
#include <stdio.h>

// gcc a1.h a1.c a3Showcase.c -o a3Exe -lm && ./a3Exe && rm ./a3Exe

int main() {
    int Alen, Blen, i;
    printf("Länge von poly A");
    scanf("%d", &Alen);
    printf("Länge von poly B");
    scanf("%d", &Blen);
    Polynomial *A = newPoly(Alen), *B = newPoly(Blen);
    double tmp;
    for(i = 0; i <= Alen; i++) {
        printf("A[%d] = ", i);
        scanf("%lf", &tmp);
        setPolyCoef(A, i, tmp);
    }

    for(i = 0; i <= Blen; i++) {
        printf("B[%d] = ", i);
        scanf("%lf", &tmp);
        setPolyCoef(B, i, tmp);
    }

    Polynomial* poly = multPoly(A, B);
    
    for(i = 0; i <= getPolyDegree(poly); i++) {
        printf("A * B[%d] = %lf\n", i, getPolyCoef(poly, i));
    }
}