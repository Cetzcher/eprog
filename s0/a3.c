#include <stdio.h>
#include <math.h>

double f(int n) {
    return pow(-1, n) / (n + 2);
}

int main() {
    int n;
    printf("bestimmt an und an+1\nn=");
    scanf("%d", &n);
    float atN = f(n), atN1 = f(n+1);
    printf("an=%lf, an+1 = %lf\n", atN, atN1);
    return 0;
}

