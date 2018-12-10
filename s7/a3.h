#ifndef A3_HEADER
#define A3_HEADER

double* mallocMatrix(int m, int n);
double* freeMatrix(double* mat);
double* reallocMatrix(double* mat, int m, int n, int newM, int newN);
void printmatrix(double* matrix, int m, int n);
double* scanmatrix(int m, int n);
double* cutOffRowJ(double* matrix, int m, int n, int j);
double* cutOffColK(double* matrix, int m, int n, int k);
#endif