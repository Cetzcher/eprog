#include <stdio.h>
#include <math.h>
#include <time.h>
// compile with -lm flag

double an_squared(int N) {
    int n;
    double res = 0; 
    for (n = 0; n < N; ++n) {
        res += 1/pow((n + 1), 2.0);
    }
    return pow(res, 2.0);
}

double bn(int N) {
    int n, k;
    double res = 0; 
    for (n = 0; n < N; ++n) {
        for (k = 0; k < n; ++k) {
            res += 1/( pow(k + 1, 2.0) * pow(n - k + 1, 2.0));
        }
    }
    return res;
}

void timestamp(int N) {
    clock_t begin = clock();
    double an_val = an_squared(N);
    clock_t end = clock();
    int an_time = end - begin;
    begin = clock();
    double bn_val = bn(N);
    end = clock();
    int bn_time = end - begin;

    printf("N = %d |\t an^2 value = %lf |\t an_time = %d |\t bn_value = %lf |\t bn_time = %d \n", N, an_val, an_time, bn_val, bn_time);
    
}

void timestamp2(int N) {
    clock_t begin = clock();
    double an_val = an_squared(N);
    clock_t end = clock();
    int an_time = end - begin;

    printf("N = %d |\t an^2 value = %lf |\t an_time = %d \n", N, an_val, an_time);
    
}



int main(){

    int N = 10;
    int i;
    for(i = 0; i < 10; ++i) {
        //timestamp(N);
        timestamp2(N);
        N *= 10;
    }

    return 0;
}

