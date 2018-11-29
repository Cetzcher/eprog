#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int length){
    int num = 0;
    for (int i = 0; i < length; i++) { 
        if(array[i] != 0) {
            printf("val: %d\n", array[i]); 
            ++num;
        }
    }
    printf("Total: %d \n", num);
}

int* eratosthenes(int n) {
    const int LENGTH = n -1;
    int* vec = malloc(sizeof(int) * LENGTH);
    int i, j;
    for(i = 0; i < LENGTH; ++i) {
        vec[i] = i + 2;
    }

    for(i = 0; i < LENGTH; ++i) {
        int cur = vec[i];
        for(j = i; j < LENGTH; ++j) {
            int other = vec[j];
            if(cur == 0 || other == 0 || other == cur)
                continue;
            else if(other % cur == 0) {
                vec[j] = 0;
            }
        }
    }
    //print_array(vec, LENGTH);
    return vec;
}

void primefactors(int n) {
    int* arr = eratosthenes(n);
    int i, rest;
    if(n == 1) {
        return;
    }
    for(i = 0; i < n - 1; ++i) {
        int cur = arr[i];
        if(cur != 0 && n % cur == 0) {
            printf("%d is a primefactor of %d\n", cur, n);
            rest = n / cur;
            primefactors(rest);
            break;
        }
    }
    free(arr);
}

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);
    primefactors(n);    
    return 0;
}