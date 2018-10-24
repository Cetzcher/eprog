#include <stdio.h>
#include <math.h> 

int main(){
    
    double angle;
    printf("Winkel=");
    scanf("%lf", &angle);
    double rad = (angle / 180);
    rad = fmod(rad, 2.0);
    double rpi = rad * 3.1415;
    printf("rad=%lf * PI = %lf", rad, rpi);
    return 0;
}
