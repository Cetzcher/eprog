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
            } else {
                matNew[pos] = 0;
            }
        }
    }
    free(mat);
    return matNew;
}

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

double* cutOffRowJ(double* matrix, int m, int n, int row) {
    double* mat = mallocMatrix(m - 1, n );
    int i, j, inRow;
    for(i = 0, j = 0; i < m * n; i++) {
        inRow = i > 0 ? i % m: 0;
        if(row == inRow) {
            // we want to skip this row entirely
            continue;
        }
        // otherwise we write into the mat array
        mat[j] = matrix[i];
        j++;
    }
    freeMatrix(matrix);
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
