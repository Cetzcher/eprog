#include <stdio.h>

int on_line(double x1, double y1, double x2, double y2, double x3, double y3) {


    // (y-y1)/(y2-y1) = (x-x1)/(x2-x1)
    double slope = (y2 - y1) / (x2 - x1);
    return y3 - y1 == slope * (x3 - x1);
}

int main() {
    
    double px, py, qx, qy, sx, sy;
    printf("px=");
    scanf("%lf", &px);
    printf("py=");
    scanf("%lf", &py);
    printf("qx=");
    scanf("%lf", &qx);
    printf("qy=");
    scanf("%lf", &qy);
    printf("sx=");
    scanf("%lf", &sx);
    printf("sy=");
    scanf("%lf", &sy);

    printf("die Punkte: (%lf, %lf), (%lf, %lf), (%lf, %lf)", px, py, qx, qy, sx, sy);
    int onLine = on_line(px, py, qx, qy, sx, sy);
    if(onLine)
        printf("leigen auf einer geraden.\n");
    else
        printf("leigen nicht auf einer geraden.\n");
}