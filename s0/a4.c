#include <stdio.h>

int main() {

    printf("Aufgabe 4\n");
    int L;
    double x, y;

    printf("L=");
    scanf("%d", &L);
    if ( L <= 0) {
        printf("L muss größer als 0 sein\n");
        return -1;
    }
    printf("x=");
    scanf("%lf", &x);
    printf("y=");
    scanf("%lf", &y);
    if(x > 0 && y > 0 && x < L && y < L) {
        printf("Der punkt (%lf, %lf), liegt in (0, 0) bis (%d, %d)\n", x, y, L, L);
    } else {
        printf("Der punkt (%lf, %lf), liegt NICHT in (0, 0) bis (%d, %d)\n", x, y, L, L);        
    }
    return 0;
}