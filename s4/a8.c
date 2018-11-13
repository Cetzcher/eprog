#include <stdio.h>

int length = 0; 

void bubblesort(int x[length]) {
    int i, offset;
    for(offset = length - 1; offset > 0; --offset) {
        for(i = 0; i < offset; ++i) {
            int current = x[i];
            int next = x[i + 1];
            if(current > next) {
                // swap
                x[i] = next;
                x[i + 1] = current;
            }
        }
    }
}


int main(){

    printf("Länge des Arrays: ");
    scanf("%d", &length);

    int x[length];
    int i;

    for(i = 0; i < length; ++i)  {
        printf("x array [%d] = ", i);
        scanf("%d", &x[i]);
    }

    bubblesort(x);
    for(i = 0; i < length; ++i) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    return 0;
}

