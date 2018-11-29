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

double bn( int n) {
    long long cur = 1, prev = 0, next, i;
    for(i = 0; i < n - 1; ++i) {
        next = cur + prev;
        int tmp = cur;
        cur = next;
        prev = tmp;
        //printf("[%d] ==> next: %d, cur: %d, prev: %d\n", i, next, cur, prev);
        
    }
    next = cur + prev;
    double diff = ((double)next) / cur - ((double)cur) / prev ;   
    if(diff < 0)
        return -diff;
    return diff;

}

int cauchy(int k) {
    double val = 1.0/k;
    int idx = 2;
    while(1) {
        double bnVal = bn(idx);
        printf("bnVal at [%d]: %lf\n", idx, bnVal);
        if(bnVal <= val )
            return idx;
        ++idx;
    }
}

int main() {
    int k;
    printf("k=");
    scanf("%d", &k);
    printf("n=%d", cauchy(k));
    return 0;
}