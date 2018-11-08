#include <stdio.h>

double powN(double x, int n) {

    if(n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else if( x  == 0.0 && n <= 0) {
        return 0.0;
    } else {
        if(n > 0) {
            return x * powN(x, n - 1);
        } else if (n < 0) {
            return 1/x * powN(x, n + 1);
        }
    }
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
