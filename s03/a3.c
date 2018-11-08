#include <stdio.h>

double dotproduct(double u[3], double v[3]) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
}

void crossproduct(double u[3], double v[3], double w[3]) {
    w[0] = u[1] * v[2] - u[2] * v[1];
    w[1] = u[2] * v[0] - u[0] * v[2];
    w[2] = u[0] * v[1] - u[1] * v[0];
}

int main(){
    double x, y, z, a, b, c;

    printf("enter x y z followed by a b c\n");
    printf("(x, y, z)\n");
    scanf("%lf", &x);
    scanf("%lf", &y);
    scanf("%lf", &z);
    printf("===========\n");
    printf("(a, b, c)\n");
    printf("===========\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    double u[3] = {a, b, c};
    double v[3] = {x, y, z};
    double w[3];    

    double dot = dotproduct(u, v);
    crossproduct(u, v, w);


    printf(" u . v = %lf\n", dot);
    printf(" u x v = (%lf, %lf, %lf)\n" , w[0], w[1], w[2]);

    return 0;
}
