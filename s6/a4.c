#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

// typedef erstellt einen typen, das ist der Typ einer Funktion die eine double als argument
// nimmt und eine double als rückgabe wert hat, Der Name des Typens ist fptr
// daher ist f vom typ fptr
typedef double (*fptr)(double);

double f(double x) {
    return x * x * x;
}

double* atiken(double* x, int n) {
    assert(n >= 3);
    double* y = malloc(sizeof(double) * (n - 2));
    int i; 
    for(i = 0; i < n - 2; ++i) {
        double cur = x[i];
        double next = x[i + 1];
        double nextNext = x[i + 2];
        y[i] = cur - (pow(next - cur, 2.0)) / (nextNext - 2.0 * next + cur);
        printf("ATIKEN: [cur]: %lf [next]: %lf, [nextNet]: %lf, [RES]: %lf\n", cur, next, nextNext, y[i]);
    }
    return y;
}

double diffHelper(fptr func, double x, double h){
    return (func(x + h) - func(x)) / h;
}

double diff(fptr func, double x, double h0, double tau) {
    int n = 0;
    double phi = 0, phiNext = 0, hn;
    while(1) {
        hn = pow(2.0, -n) * h0;
        phi = diffHelper(func, x, hn);
        // hn + 1
        phiNext = diffHelper(func, x, hn * 1/2);
        double difference = fabs(phi - phiNext);
        // wenn phi < tau und phi - phiNext < tau ODER andernfalls difference <= tau * |phi|
        printf("diff (%d) [hn] %lf [hn+1]: %lf [phi]: %lf\n", n, hn, hn * 1/2, phi);
        if((phi <= tau && difference <= tau) || (phi > tau && difference <= tau * fabs(phi)))
            return phi;
        n++;
    }
    return 0;
}

double diffAtiken(fptr func, double x, double h0, double tau) {
    int n = 0;
    double hn = 0, hnNext = 0, hnNextNext = 0;

    while(1) {
        hn = pow(2.0, -n) * h0;     // hn und hn + 1 berechnen.
        hnNext = hn * 1/2;
        // 2 arrays erstellen die mit den diff werten gebildet werden
        // wenn wir das atiken verfahren auf diese Arrays anwendne bekommen wir 
        // ein arrary das um 2 kleiner ist also eine mit länge = 1, daher führen die beiden unteren zeilen jeweils zu yn und yn + 1
        double yn[3] = {diffHelper(f, x, hn), diffHelper(f, x, hn * 1/2), diffHelper(f, x, hn * 1/4)};
        double ynNext[3] = {diffHelper(f, x, hnNext), diffHelper(f, x, hnNext * 1/2), diffHelper(f, x, hnNext * 1/4)};
        // hier rufen wir das verfahren auf und nehmen uns den ersten und einzigen wert.
        double yval = atiken(yn, 3)[0];
        double yvalNext = atiken(ynNext, 3)[0];
        double difference = fabs(yval - yvalNext);
        printf("diffAtiken (%d) [hn]: %lf, [hn + 1]: %lf, [yn]: %lf [yn + 1]: %lf [|yn - yn+1|]: %lf\n", n, hn, hnNext, yval, yvalNext, difference);
        if((fabs(yvalNext) <= tau && difference <= tau) || (fabs(yval) > tau && difference <= fabs(yval) * tau)) {
            return yvalNext;
        }
        n++;
    }

}

int main() {
    double x, tau, h0;
    printf("x=");
    scanf("%lf", &x);
    printf("tau=");
    scanf("%lf", &tau);
    printf("h0=");
    scanf("%lf", &h0);
    double y = diffAtiken(f, x, h0, tau);
    diff(f, x, h0, tau);
    printf("diffAtiken = %lf", y);

}