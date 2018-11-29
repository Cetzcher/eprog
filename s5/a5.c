#include <stdio.h>

#define NMAX 20
#define LENGTH NMAX - 1

void print_array(int *array, int length){
    int num = 0;
    for (int i = 0; i < length; i++) { 
        if(array[i] != 0)
            ++num;
        printf("val: %d\n", array[i]); 
    }
    printf("Total: %d \n", num);
}

void eratosthenes() {

    int vec[LENGTH];
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

    print_array(vec, LENGTH);
}


int main() {
    eratosthenes();
    return 0;
}