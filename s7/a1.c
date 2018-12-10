#include <stdio.h>
#include <stdlib.h>

char* intToBin(int n, int* size ) {
    char* string = malloc(*size * sizeof(char));
    int i, k, arrsize = sizeof(int) * 8;
    for(i = 0; i < arrsize; i++) {
        if(n & (1 << i))
            string[i] = '1';
        else
            string[i] = '0';
    }
    *size = arrsize;    
    return string;
}

int binToInt(char* arr, int size) {
    int x = 0, i;
    for(i = 0; i < size; i++) {
        x |= ((arr[i] == '1' ? 1 : 0) << i);
    }
    return x;
}

int main() {
    int size, i, num;
    printf("num = ");
    scanf("%d", &num);
    char* str = intToBin(num, &size);
    for(i = size; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
    printf("back to int: %d", binToInt(str, size));
    printf("\n");
}