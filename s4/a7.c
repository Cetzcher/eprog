#include <stdio.h>

int fib(int k) {
    unsigned long long i, next, a = 0, b = 1;    
    for (i = 0; i < k; ++i){
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
    }
    return next;
}

int main() {
    unsigned int k;
    printf("k=");
    scanf("%d", &k);

    printf("fib(k) = %d", fib(k));

    return 0;
}
