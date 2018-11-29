#include <stdio.h>
#include <math.h>

#define N 3

unsigned long factorial(unsigned long f)
{
    if ( f == 0 ) 
        return 1;
    return f * factorial(f - 1);
}

double Cn(double x) {
    int i;
    double sum = 0;
    for(i = 0; i < N; ++i) {
        sum += pow(-1, (double) i) * ( pow(x, 2.0 * i) / factorial(2.0 * i)) ;
    }    
    return sum;
}

double absolute(double x) {
    if (x < 0)
        return -x;
    return x;
}

int cos_new(double x, double tau, double* res) {
    double cAtX = Cn(x), cAtXMinus = Cn(x - 1);
    if (absolute(cAtX - cAtXMinus) / absolute(cAtX) <= tau 
        || absolute(cAtX) <= tau)  {
        *res = cAtX;
        return 0;
    }
    return 1;  // error
       
}

double scanfPositiv() {
    double num;
    while(1) {
        printf("positive zahl: ");
        scanf("%lf", &num);
        if(num > 0)
            return num;
    }
}

int main() {
    double x, res, tau;
    printf("x=");
    scanf("%lf", &x);
    printf("Tau > 0\n");
    tau = scanfPositiv();

    if(cos_new(x, tau, &res)) {
        printf("Cn > tau");
        return 1;
    }

    printf("COS      ====    COS_NEW    ====     Fehler\n");
    printf("%lf ====   %lf    ====  %lf", cos(x), res, absolute(res - cos(x)));

    return 0;
}