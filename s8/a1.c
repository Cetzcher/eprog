#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/*
    gcc -c a1.h -o a1Header.out &&
    gcc -c a1.c -o a1C.out &&
    gcc a1Header.out a1C.out -o app &&
    ./app &&
    rm ./a1Header.out ./a1C.out ./app
*/

typedef struct Polynomial {
    int degree;
    double* coef;
} Polynomial;

Polynomial* newPoly(int degree);
void delPoly(Polynomial* poly);
int getPolyDegree(Polynomial* poly);
double getPolyCoef(Polynomial* poly, int idx);
void setPolyCoef(Polynomial* poly, int idx, double val);
Polynomial* addPoly(Polynomial* p1, Polynomial* p2);
Polynomial* multPoly(Polynomial* p1, Polynomial* p2);
Polynomial* multPolyDouble(Polynomial* p1, double d);
double evalPoly(Polynomial* p, double x);
double evalPolyDiff(Polynomial* p, double x, int steps);
Polynomial* taylor(Polynomial* p, int steps, double x0);

Polynomial* greater(Polynomial* p1, Polynomial* p2);
Polynomial* lesser(Polynomial* p1, Polynomial* p2);
Polynomial* invertPoly(Polynomial* p);

// Helper functions
inline Polynomial* lesser(Polynomial* p1, Polynomial* p2) {
    return getPolyDegree(p1) < getPolyDegree(p2) ? p1 : p2;
}

inline Polynomial* greater(Polynomial* p1, Polynomial* p2) {
    return getPolyDegree(p1) < getPolyDegree(p2) ? p2 : p1;
}

Polynomial* newPoly(int degree) {
    assert(degree >= 0);
    Polynomial* poly = malloc(sizeof(Polynomial));
    poly->degree = degree;
    poly->coef = calloc((degree + 1), sizeof(double) * (degree + 1));
}

void delPoly(Polynomial* poly) {
    free(poly->coef);
    free(poly);
}

int getPolyDegree(Polynomial* poly) {
    return poly->degree;
}

double getPolyCoef(Polynomial* poly, int idx) {
    assert(idx <= poly->degree  && idx >= 0);
    return poly->coef[idx];
}

void setPolyCoef(Polynomial* poly, int idx, double val) {
    assert(idx <= poly->degree  && idx >= 0);
    poly->coef[idx] = val;
}

Polynomial* addPoly(Polynomial* p1, Polynomial* p2) {
    // find bigger and smaller polynomial
    Polynomial* bigger = greater(p1, p2);
    Polynomial* smaller = lesser(p1, p2);
    Polynomial* sum = newPoly(getPolyDegree(bigger));

    int i, bDeg = getPolyDegree(bigger), sDeg = getPolyDegree(smaller);
    for(i = 0; i <= sDeg; i++) {
        setPolyCoef(sum, i, getPolyCoef(smaller, i) + getPolyCoef(bigger, i));
    }

    for(i = sDeg + 1; i <= bDeg; i++) {
        setPolyCoef(sum, i, getPolyCoef(bigger, i));
    }

    return sum;
}  

Polynomial* multPoly(Polynomial* p1, Polynomial* p2) {
    Polynomial *bigger = greater(p1, p2), *smaller = lesser(p1, p2);
    int smallDeg = getPolyDegree(smaller), bigDeg = getPolyDegree(bigger);
    Polynomial* prod = newPoly(smallDeg + bigDeg);
    int i, j;
    for(i = 0; i <= bigDeg; i++) {
        for(j = 0; j <= smallDeg; j++) {
            setPolyCoef(prod, i + j, getPolyCoef(prod, i + j) + getPolyCoef(smaller, j) * getPolyCoef(bigger, i));
        }
    }
    return prod;
}

Polynomial* multPolyDouble(Polynomial* p1, double d) {
    Polynomial* tmp = newPoly(0);
    setPolyCoef(p1, 0, d);
    tmp = multPoly(tmp, p1);
    return p1;
}

Polynomial* invertPoly(Polynomial* p1) {
    return multPolyDouble(p1, -1);
}

double diffExpr(double val, int power, int steps) {
    assert(power >= 0 && steps >= 0);
    if(steps > power)
        return 0;
    if(steps == 0)
        return val;
    int i;
    for(i = 0; i < steps; i++) {
        val *= (power - i);
    }
    return val;
}

double evalPoly(Polynomial* p, double x) {
    double sum = 0;
    int i = 0; 
    for(i = 0; i <= getPolyDegree(p); i++) {
        //double coef = getPolyCoef(p, i);
        //double aPow = pow(x, i);
        //printf("eval Poly [%d] = coef [%lf] * [%lf] = %lf\n", i, coef, aPow, coef * aPow);
        sum += (getPolyCoef(p, i) * pow(x, i));
    }
    return sum;
}

double evalPolyDiff(Polynomial* p, double x, int steps) {
    assert(steps >= 0);
    int pLen = getPolyDegree(p);

    if(steps == 0)
        return evalPoly(p, x);
    
    if(pLen < steps)
        return 0;
    
    int i, curIdx;
    double diffVal, polyVal;
    Polynomial *diff = newPoly(pLen - steps);
    for(i = 0; i <= (pLen - steps); i++) {
        curIdx = i + steps;
        polyVal = getPolyCoef(p, curIdx);
        diffVal = diffExpr(polyVal, curIdx, steps);
        setPolyCoef(diff, i, diffVal);
    }
    double ret = evalPoly(diff, x);
    delPoly(diff);
    return ret;
}

int main() {
    Polynomial *p1 = newPoly(3), *p2 = newPoly(2);
    setPolyCoef(p1, 0, 10);
    setPolyCoef(p1, 1, 3);
    setPolyCoef(p1, 2, 8);
    setPolyCoef(p1, 3, 4);
    //  (10 * x^0 + 3 * x^1 + 8 * x^2 + 4 * x^3)
    setPolyCoef(p2, 0, 10);
    setPolyCoef(p2, 1, 0);
    setPolyCoef(p2, 2, 2);
    Polynomial *res = multPoly(p1, p2);   
    printf("0: %lf  1: %lf 2: %lf 3: %lf 4: %lf\n", getPolyCoef(res, 0), getPolyCoef(res, 1), getPolyCoef(res, 2), getPolyCoef(res, 3), getPolyCoef(res, 4));
    //printf("%lf", evalPoly(p1, 3, 3));
    printf("%lf\n", evalPoly(p1, 5));
    printf("%lf", evalPolyDiff(p1, 5, 4));
}