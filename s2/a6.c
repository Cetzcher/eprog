#include <stdio.h>

int q = 0;

int div(int m, int n) {
    // divides m by n
    // x / y = 1 + (x - y) / y
    if(m >= n) {
        q++;
        m -= n;
        div(m, n);
    }    
    return q;
}

int main() {

    int m, n;
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    if(n <= 0) {
        printf("n <= 0 darf nicht sein");
        return -1;
    }

    int x = div(m, n);
    printf("quot=%d", x);

    return 0;
}