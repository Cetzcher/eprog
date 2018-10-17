#include <stdio.h>

int main() {

    printf("Aufgabe 7\n");
    int a, b, c;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    printf("c=");
    scanf("%d", &c);
    
    // check ob a, b, c ein tri erzeugen.

    if(a + b > c && a + c > b && b + c > a) {
        printf("a, b, c, formen ein Dreieck \n");
    } else {
        printf("a, b, c, formen kein Dreieck somit entartet oder unmöglich\n");
    }

    if(a == b && b == c) {
        printf("Gleichseitig");
    } else if (a == b && b != c) {
        printf("Gleichschenkelig\n");
    } else if(a*a + b*b == c*c) {
        printf("Rechtwinkelig\n");
    }

    if(a != b && b != c && a != c) {
        printf("es ist unregelmäßig\n");
    }

    return 0;
}