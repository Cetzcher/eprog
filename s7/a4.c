#include "a3.h"
#include <stdio.h>
#include <stdlib.h>

// gcc -c a3.c -o a3.o && gcc -c a4.c -o a4.o && gcc a3.o a4.o -o a4 && ./a4

double* matrixvector(double* mat, double* vec, int m, int n) {
    // vec len = n
    double* res = mallocMatrix(m, 1);
    int i, j = 0, idx, inRow;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++) {
            idx = j * m + i;
            res[i] += mat[idx] * vec[j];
        }
    }
    return res;
}

void printArray(double* arr, int len) {
   int i;
   for(i = 0; i < len; i++) 
       printf("arr[%d] = %lf\n", i, arr[i]);
   printf("\n");
}

int main(){
    double* mat = mallocMatrix(2, 3);
    mat[0] = 1;
    mat[1] = 0;
    mat[2] = -1;
    mat[3] = -3;
    mat[4] = 2;
    mat[6] = 1;
    double* vec = malloc(sizeof(double) * 3);
    vec[0] = 2;
    vec[1] = 1;
    vec[2] = 0;
    printmatrix(mat, 2, 3);
    double* res = matrixvector(mat, vec, 2, 3);
    printf("mat * vec \n");
    printmatrix(res, 2, 1);
    freeMatrix(res);
    freeMatrix(mat);
    free(vec);
    return 0;
}
