#include <stdio.h>

int abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

void char_abstand(char* c1, char* c2) {
    printf("Char Abstand\nc1 Addr: %p\n", c1);
    printf("c2 Addr: %p\n", c2);
    printf("Abstand: %ld bits \n", abs(c2 - c1) * sizeof(char) * 8);
    printf("=======================================\n\n");
}

void double_abstand(double* c1, double* c2) {
    printf("Double Abstand\nc1 Addr: %p\n", c1);
    printf("c2 Addr: %p\n", c2);
    printf("Abstand: %ld bits\n", abs(c2 - c1) * sizeof(double) * 8);
    printf("=======================================\n\n");
    
}

int main() {
    char c[10];
    double d[2];
    char_abstand(&c[0], &c[9]);
    char_abstand(c, c + 1);

    double_abstand(&d[0], &d[1]);
    double_abstand(d, d + 1);
    
    printf("short (bits): %ld\n", sizeof(short) * 8);
    printf("int (bits): %ld\n", sizeof(int) * 8);
    printf("long (bits): %ld\n", sizeof(long) * 8);
}