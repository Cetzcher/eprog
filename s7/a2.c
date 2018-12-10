#include <stdlib.h>
#include <stdio.h>
#include "a2.h"

// m = cols
// n = row
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

//      col1     col1
// row1 a        c
// row2 b        d
// row3 e        f
// mat = {a, b, c, d, e, f}

// void printArray(double* arr, int len) {
//     int i;
//     for(i = 0; i < len; i++) 
//         printf("arr[%d] = %lf\n", i, arr[i]);
//     printf("\n");
// }

// int main() {
//     double* arr = mallocMatrix(2, 3);
//     arr[0] = 1;
//     arr[1] = 2;
//     arr[2] = 3;
//     arr[3] = 4;
//     arr[4] = 5;
//     arr[5] = 6;
//     printArray(arr, 6);
//     double* arr2 = reallocMatrix(arr, 3, 2, 3, 3);
//     printArray(arr2, 9);
//     return 0;
// }