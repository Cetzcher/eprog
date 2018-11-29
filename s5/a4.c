#include <stdio.h>
#include <math.h>

double x_seq(int n, double x) {
    if(n <= 1) {
        return 1.0/2.0 * (1.0 + x);
    } else if (x <= 0 ) {
        return 0;
    } else {
        double before = x_seq(n - 1, x);
        return 1.0/2.0 * (before + ( x / before));
    }
}


double sqrt_new(double x, double tau) {
    int i = 2; 
    double xn, next; 
    while(1) {
        xn = x_seq(i, x), next = x_seq(i + 1, x);
        if(fabs(xn - next) / fabs(xn) <= tau || fabs(xn) <= tau)
            return xn;
        ++i;
    }
}


int main() {
    double x, tau;
    printf("x=");
    scanf("%lf", &x);
    printf("tau=");
    scanf("%lf", &tau);

    double root = sqrt(x);
    double root2 = sqrt_new(x, tau);
    double error = fabs(root - root2);
    printf("root: %lf\t root2: %lf\t error: %lf\n", root, root2, error);

}