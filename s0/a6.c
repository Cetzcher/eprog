#include <stdio.h>

int main() {

    printf("Aufgabe 6\n");
    int sum = 0;
    for(int i = 0; i < 10; ++i) {
        printf("Wie viele Bsp wurden bei UE %d erledigt?\n=>", i + 1);
        int cur;
        scanf("%d", &cur);
        if(cur > 8 || cur < 0) {
            printf("Wert kann nicht > 8  oder < 0 sein bitte nochmals eingeben");
            --i;
            continue;
        }
        sum += cur;
    }
    float avg = (sum / 80.0F) * 100.0F;
    printf("es wurden %lf prozent erreicht", avg);
    if(avg > 50)
        printf(" sie haben damit mehr als 50 erreicht\n ");
    return 0;
}