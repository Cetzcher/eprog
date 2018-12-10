#include <stdlib.h>
#include <stdio.h>

// arr[m][n]
// m is for rows
// n is for cols
// row is left to right matrix[row]
int countValueInRow(int** matrix, int m, int n, int val, int row) {
    int i, cnt = 0;
    for(i = 0; i < n; i++)
        cnt += matrix[row][i] == val ? 1 : 0;
    return cnt;
}   

// col is up down
int countValueInCol(int** matrix, int m, int n, int val, int col) {
    int i, cnt = 0;
    for(i = 0; i < m; i++)
        cnt += matrix[i][col] == val ? 1 : 0;
    return cnt; 
}

int main() {
    int** arr = (int**) malloc(sizeof(int*) * 3);
    arr[0] = (int*) malloc(sizeof(int*) * 2);
    arr[0][0] = 2;
    arr[0][1] = 3;
    arr[1] = (int*) malloc(sizeof(int*) * 2);
    arr[1][0] = 2;
    arr[1][1] = 3;
    arr[2] = (int*) malloc(sizeof(int*) * 2);
    arr[2][0] = 2;
    arr[2][1] = 3;
    /*
        2  3
        2  3
        2  3
    */
    printf("countValueInRow(arr, 3, 2, 2, 0) = %d\n", countValueInRow(arr, 3, 2, 2, 0));
    printf("countValueInRow(arr, 3, 2, 2, 1) = %d\n", countValueInRow(arr, 3, 2, 2, 1));
    printf("countValueInCol(arr, 3, 2, 2, 0) = %d\n", countValueInCol(arr, 3, 2, 2, 0));
    printf("countValueInCol(arr, 3, 2, 2, 1) = %d\n", countValueInCol(arr, 3, 2, 2, 1));
    return 0;
}