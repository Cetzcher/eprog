#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

double* atiken(double* x, int n) {
    assert(n >= 3);
    double* y = malloc(sizeof(double) * (n - 2));
    int i; 
    for(i = 0; i < n - 2; ++i) {
        double cur = x[i];
        double next = x[i + 1];
        double nextNext = x[i + 2];
        y[i] = cur - (pow(next - cur, 2.0)) / (nextNext - 2.0 * next + cur);
    }
    return y;
}

int main() {
    int length, i;
    printf("Länge=");
    scanf("%d", &length);
    double x[length];

    for(i = 0; i < length; ++i)  {
        x[i] = 5 + 1.0/(i + 1.0);
        printf("x array [%d] = %lf\n", i, x[i]);
        //scanf("%lf", &x[i]);
    }
    printf("\n:=========Result=========:\n\n");
    double* y = atiken(x, length);
    for(i = 0; i < length - 2; i++) {
        printf("y array [%d] = %lf\n", i, y[i]);
    }

}