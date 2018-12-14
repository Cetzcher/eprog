#include <stdio.h>
#include "a3.h"

// gcc -c a3.c -o a3.o && gcc -c a3test.c -o a3test.o && gcc a3.o a3test.o -o a3testExe && ./a3testExe

double* init3x3Mat() {
    double* mat = mallocMatrix(3, 3);
    mat[0] = 1;
    mat[1] = 2;
    mat[2] = 3;
    mat[3] = 4;
    mat[4] = 5;
    mat[5] = 6;
    mat[6] = 7;
    mat[7] = 8;
    mat[8] = 9;
    return mat;
}

int main() {
    
    double* mat = init3x3Mat();
    printf("3x3 matrix: \n");
    printmatrix(mat, 3, 3);
    printf("realloc matrix 2x2 \n");
    mat = reallocMatrix(mat, 3, 3, 2, 2);
    printmatrix(mat, 2, 2);
    freeMatrix(mat);
    // recreate 3x3 mat and free old
    mat = init3x3Mat();
    mat = cutOffColK(mat, 3, 3, 1); // cut out the middle
    printf("After cut: 3x2 matrix: \n");
    printmatrix(mat, 3, 2);
    freeMatrix(mat);
    mat = init3x3Mat();
    printf("Cutting 2nd row: \n");
    mat = cutOffRowJ(mat, 3, 3, 1);
    printmatrix(mat, 2, 3);
    freeMatrix(mat);

    int m, n;
    printf("scan matrix: \n");
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    mat = scanmatrix(m, n);
    printmatrix(mat, m, n);
    freeMatrix(mat);
    
    return 0;
}