#include <stdio.h>

void write(double* arr, int cur, int length) {
    arr[cur] = cur;
    if(cur == length)
        return;
    write(arr, cur + 1, length); 
}

void printVec(double* arr, int cur, int length) {
    double val = arr[cur];
    printf("vec[i] = %lf\n", val);
    if(cur == length)
        return;
    printVec(arr, cur + 1, length);
}

int main(){

    double vec[1000];
    write(vec, 0, 1000);
    printVec(vec, 0, 1000);
    return 0;
}
