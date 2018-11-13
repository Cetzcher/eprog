#include <stdio.h>

double powN(double x, int n) {

    if(x == 0 && n > 0)
        return 0;
    else if (x == 0 && n <= 0)
        return 0.0 / 0.0;  // either that or literally 0 / 0 to cause a floating point exception.
    else if (n == 0)
        return 1;

    double product = 1;
    int i = 0;
    if ( n < 0 ) {
        for(i = 0; i < -n; ++i) {
            product *= 1/x;
        }
    } else {
        for(i = 0; i < n; ++i) {
            product *= x;
        }
    }

    return product;
}


int main(int argc, char const *argv[]){
    double x;
    int n; 
    printf("base=");
    scanf("%lf", &x);
    printf("exp=");
    scanf("%d", &n);
    double res = powN(x, n);
    printf("res=%lf", res);
    return 0;
}
