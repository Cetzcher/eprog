#ifndef A1_H
#define A1_H

typedef struct Polynomial {
    double* coef;
    int degree;
} Polynomial;

Polynomial* newPoly(int degree);
void delPoly(Polynomial* poly);
int getPolyDegree(Polynomial* poly);
double getPolyCoef(Polynomial* poly, int idx);
void setPolyCoef(Polynomial* poly, int idx, double val);

#endif