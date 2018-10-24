#include <stdio.h>

int fibbonaci(int n) {
    if( n == 0 || n == 1)
        return 1;
    return fibbonaci(n - 1) + fibbonaci(n - 2);
}

int main(){
    int n;
    printf("n=");
    scanf("%d", &n);
    int x = fibbonaci(n);
    printf("Fib(n) = %d", x);
    return 0;
}
