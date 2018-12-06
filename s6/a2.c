#include <stdio.h>
#include <math.h>

// typedef erstellt einen typen, das ist der Typ einer Funktion die eine double als argument
// nimmt und eine double als rückgabe wert hat, Der Name des Typens ist fptr
// daher ist f vom typ fptr
typedef double (*fptr)(double);

double f(double x) {
    return x * x;
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
        phiNext = diffHelper(func, x, pow(2.0, -(n + 1.0)) * h0);
        double difference = fabs(phi - phiNext);
        // wenn phi < tau und phi - phiNext < tau ODER andernfalls difference <= tau * |phi|
        if((phi <= tau && difference <= tau) || (phi > tau && difference <= tau * fabs(phi)))
            return phi;
        n++;
    }
    return 0;
}

int main() {
    double x, tau, h0;
    printf("x=");
    scanf("%lf", &x);
    printf("tau=");
    scanf("%lf", &tau);
    printf("h0=");
    scanf("%lf", &h0);
    // bei diff übergeben wir jetzt nicht f(...) sondern nur f OHNE KLAMMERN
    // wenn man f ohne klammern schreibt meint man damit die Adresse der Funktion
    // deswegen kann diff bzw diffHelper die funktion f(x) aufrufen.
    printf("f'(x) = %lf", diff(f, x, h0, tau));
}