#include <stdio.h>

int fibbonaci(int n, int* x) {
    if( n == 0) {
        x[0] = 0;
        return 0;
    }
    if (n == 1) {
        x[1] = 1;
        return 1;
    }
    x[n] = fibbonaci(n - 1, x) + fibbonaci(n - 2, x);
    return x[n];
}

void printVec(double* arr, int cur, int length) {
    double val = arr[cur];
    printf("vec[i] = %lf\n", val);
    if(cur == length)
        return;
    printVec(arr, cur + 1, length);
}

int main(int argc, char const *argv[]){
    int n;
    printf("n=");
    scanf("%d", &n);
    int x[n];
    fibbonaci(n, x);
    int i = 0;
    for(i = 0; i < n; ++i) {
        int valAtI = x[i];
        printf("fib[%d] = %d\n", i, valAtI);
    }

    return 0;
}
