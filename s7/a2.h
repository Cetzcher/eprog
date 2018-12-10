#ifndef A2_HEADER
#define A2_HEADER

double* mallocMatrix(int m, int n);
double* freeMatrix(double* mat);
double* reallocMatrix(double* mat, int m, int n, int newM, int newN);

#endif