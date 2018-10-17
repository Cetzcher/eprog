#include <stdio.h>

int main() {
    printf("a=");
    int a, b, c;
    scanf("%d", &a);
    printf("\nb=");
    scanf("%d", &b);    
    printf("\nc=");
    scanf("%d", &c);
    printf("a^2 + b^2 = c^2 mit a=%d, b=%d, c=%d\n", a, b, c);
    if(a*a + b*b == c*c)
        printf("ist ein tripel\n");
    else 
        printf("ist kein tripel\n");
    return 0;
}