#include <stdio.h>
#include <math.h>

// compile with gcc -lm for math lib

int length = 0; 

double geometricMean(double x[length]) {
    double product = 1;
    int i = 0; 
    for(i = 0; i < length; ++i) {
        product *= x[i];
    }
    double pw = pow(product, 1.0/length);
    return pw;

}


int main(){

    printf("Länge des Arrays: ");
    scanf("%d", &length);

    double x[length];
    int i;

    for(i = 0; i < length; ++i)  {
        printf("x array [%d] = ", i);
        scanf("%lf", &x[i]);
    }

    double res = geometricMean(x);
    printf("Geom Summe = %lf", res);
    return 0;
}

