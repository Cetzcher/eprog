#include <stdio.h>
#include <math.h>

double P(int n) {
    double dividen = 4 * pow(-1.0, (double) n);
    double divisor = 2 * n + 1;
    double lhs = dividen / divisor; 
    if(n == 0)
        return lhs;
    else
        return lhs + P(n - 1);
}

int main(){
    int n;
    printf("n=");
    scanf("%d", &n);
    double pi = P(n);
    printf("pi=%lf", pi);
    return 0;
}
