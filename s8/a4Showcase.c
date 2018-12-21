#include "a1.h"
#include <stdio.h>

// gcc a1.h a1.c a4Showcase.c -o a4Exe -lm && ./a4Exe && rm ./a4Exe

int main() {
    int Alen, i;
    printf("Länge von poly A");
    scanf("%d", &Alen);
    Polynomial *A = newPoly(Alen);
    double tmp;
    for(i = 0; i <= Alen; i++) {
        printf("A[%d] = ", i);
        scanf("%lf", &tmp);
        setPolyCoef(A, i, tmp);
    }

    double evalPnt;
    printf("Evalt p(x), x = ");
    scanf("%lf", &evalPnt);
    printf("p(%lf) = %lf", evalPnt, evalPoly(A, evalPnt));

}