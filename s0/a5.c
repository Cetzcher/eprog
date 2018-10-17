#include <stdio.h>


int min(int a, int b) {
    return a < b ? a : b;
} 

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    printf("Aufgabe 5\n");
    int x, y, z;
    printf("x=");
    scanf("%d", &x);
    printf("y=");
    scanf("%d", &y);
    printf("z=");
    scanf("%d", &z);
    
    int mx = max(max(x, y), z);
    int mi = min(min(x, y), z);
    
    printf("max: %d\n", mx);
    printf("min: %d\n", mi);
    return 0;
}