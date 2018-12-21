#include "a1.h"
#include <stdio.h>

// gcc a1.h a1.c a5Showcase.c -o a5Exe -lm && ./a5Exe && rm ./a5Exe

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
    int k;
    printf("Ableitung # = ");
    scanf("%d", &k);
    printf("Eva p(x), x = ");
    scanf("%lf", &evalPnt);
    printf("p^(k)(%lf) = %lf", evalPnt, evalPolyDiff(A, evalPnt, k));

}