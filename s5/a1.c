#include <stdio.h>

double scanfPositiv() {
    double num;
    while(1) {
        printf("positive zahl: ");
        scanf("%lf", &num);
        if(num > 0)
            return num;
    }
}

int main() {
    printf("die positive zahl ist: %lf", scanfPositiv());
    return 0;
}