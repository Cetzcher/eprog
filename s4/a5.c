#include <stdio.h>
#include <math.h>
// compile with -lm flag

int m = 0; 
int n = 0;

double forbinusnorm(double A[m][n]) {

    int j, k;
    double sum = 0;
    for (j = 0; j < m; ++j) {
        for (k = 0; k < n; ++k) {
            sum += ( A[j][k] * A[j][k]);
        }
    }
    return pow(sum, 1.0/2.0);

}


int main(){

    printf("m=: ");
    scanf("%d", &m);

    printf("n=: ");
    scanf("%d", &n);

    double A[m][n];
    int i, j;    
    for(i = 0; i < m; ++i)  {
        for(j = 0; j < n; ++j) {
            printf("x array [%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    double res = forbinusnorm(A);

    printf("res=%lf", res);

    return 0;
}

