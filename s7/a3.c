#include <stdlib.h>
#include <stdio.h>
#include "a3.h"

// m = row
// n = col
// {1, 2, 3, 4, 5, 6} m = 2, n = 3
//          col1    col2    col3
// row1:      1      3        5 
// row2:      2      4        6
double* mallocMatrix(int m, int n) {
    return (double*) malloc(sizeof(double) * (m * n));
}

double* freeMatrix(double* mat) {
    free(mat);
    return NULL;
}

/**
 * m => Anzahl der Spalten
 * n => Anzahl der Reihen
 * https://en.cppreference.com/w/c/memory/realloc
 * On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with free() or realloc(). The original pointer ptr is invalidated and any access to it is undefined behavior (even if reallocation was in-place).
 */
double* reallocMatrix(double* mat, int m, int n, int newM, int newN) {
    double* matNew = mallocMatrix(newM, newN);
    int i, j, col = 0, row = 0;
    for(i = 0; i < newM; i++) {
        for(j = 0; j < newN; j++) {
            int pos = i * newM + j;
            if(i < m && j < n) {
                matNew[pos] = mat[i * n + j];
                printf("index(%d): %lf \n", pos, mat[pos]);
            } else {
                matNew[pos] = 0;
                printf("NOT %d\n", pos);
            }
        }
    }
    free(mat);
    return matNew;
}

// {1, 2, 3, 4, 5, 6} m = 2, n = 3
// 1 3 5
// 2 4 6
void printmatrix(double* matrix, int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%lf\t", matrix[m * j + i]);
        }
        printf("\n");
    }
}

double* scanmatrix(int m, int n) {
    double* mat = mallocMatrix(m, n);
    int i, j, idx = 0;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            idx = m * j + i;
            printf("mat[%d, %d] index[%d] = ", i, j, idx);
            scanf("%lf", &mat[idx]);
        }
    }
    return mat;
}

// row = 0
// 2x3
//       0/0 1/0 0/1 1/1 0/2 1/2
// mit {  1,  2,  3,  4,  5,  6}
double* cutOffRowJ(double* matrix, int m, int n, int row) {
    double* mat = mallocMatrix(m - 1 , n);
    int i, j, inRow = 0;
    for(i = 0, j = 0; i < m * n; i++, j++){
        inRow = i > 0 ? i % m: 0;
        if(inRow != row) {
            mat[j] = matrix[i];
            i++;    // this skips the row
            continue;
        } 
    }

    free(matrix);
    return mat;
}

double* cutOffColK(double* matrix, int m, int n, int col) {
    double* mat = mallocMatrix(m , n - 1);
    int i, j, inCol = 0;
    for(i = 0, j = 0; i < col; i++, j++) {
        mat[j] = matrix[i];
    }
     // skip the next parts
    for(i += m; i < m * n; i++, j++) {
        mat[j] = matrix[i];
    }
    free(matrix);
    return mat;
}


//void printArray(double* arr, int len) {
//    int i;
//    for(i = 0; i < len; i++) 
//        printf("arr[%d] = %lf\n", i, arr[i]);
//    printf("\n");
//}
////
//int main() {
//   double* arr = mallocMatrix(2, 5);
//   arr[0] = 1;
//   arr[1] = 2;
//   arr[2] = 3;
//   arr[3] = 4;
//   arr[4] = 5;
//   arr[5] = 6;
//   arr[6] = 7;
//   arr[7] = 8;
//   arr[8] = 9;
//   arr[9] = 10;
//   
//   printmatrix(arr, 2, 5);
//   printArray(arr, 2* 5);
//   printf("after cut\n");
//   double* arr2 = cutOffColK(arr, 2, 5, 0);
//   printmatrix(arr2, 2, 4);
//   return 0;
//}