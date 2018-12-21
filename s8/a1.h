#ifndef A1_H
#define A1_H


typedef struct Polynomial {
    int degree;
    double* coef;
} Polynomial;

// a1.h
Polynomial* newPoly(int degree);
void delPoly(Polynomial* poly);
int getPolyDegree(Polynomial* poly);
double getPolyCoef(Polynomial* poly, int idx);
void setPolyCoef(Polynomial* poly, int idx, double val);

// a2.h
Polynomial* addPoly(Polynomial* p1, Polynomial* p2);

// a3.h
Polynomial* multPoly(Polynomial* p1, Polynomial* p2);
Polynomial* multPolyDouble(Polynomial* p1, double d);   // helper

//a4.h
double evalPoly(Polynomial* p, double x);

//a5.h
double evalPolyDiff(Polynomial* p, double x, int steps);


Polynomial* taylor(Polynomial* p, int steps, double x0);

// helper functions
Polynomial* greater(Polynomial* p1, Polynomial* p2);
Polynomial* lesser(Polynomial* p1, Polynomial* p2);
Polynomial* invertPoly(Polynomial* p);

#endif