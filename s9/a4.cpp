#include "a4.hpp"
#include <iostream>
#include <cmath>

/*
    x = a
    y = b
    z = c

       b0/b1
        /\
       /  \
      /    \
      -----
   c0/c1    a0/a1
*/

void Triangle::setX(double x0, double x1) {
    a[0] = x0, a[1] = x1;
}
void Triangle::setY(double y0, double y1) {
    b[0] = y0, b[1] = y1;

}

void Triangle::setZ(double z0, double z1) {
    c[0] = z0, c[1] = z1;

}

double Triangle::area() {
    return 0.5 * fabs( (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]));
}

double Triangle::getSideA() {
    double b0 = b[0], b1 = b[1], c0 = c[0], c1 = c[1];
    return sqrt((b0 - c0) * (b0 - c0) + (b1 - c1) * (b1 - c1));
}

double Triangle::getSideB() {
    double a0 = a[0], a1 = a[1], c0 = c[0], c1 = c[1];
    return sqrt((a0 - c0) * (a0 - c0) + (a1 - c1) * (a1 - c1));

}

double Triangle::getSideC() {
    double a0 = a[0], a1 = a[1], b0 = b[0], b1 = b[1];
    return sqrt((a0 - b0) * (a0 - b0) + (a1 - b1) * (a1 - b1));

}

double Triangle::getPerimeter() {
    // calculate side a, b, c
    double side_a = getSideA(), side_b = getSideB(), side_c = getSideC();
    return side_a + side_b + side_c;
}

bool Triangle::isEquilateral() {
    double side_a = getSideA(), side_b = getSideB(), side_c = getSideC();    
    double epsilon = 0.001;
    return fabs(side_a - side_b) < epsilon &&
           fabs(side_b - side_c) < epsilon &&
           fabs(side_c - side_a) < epsilon;   
}

int main() {
    Triangle tri;
    tri.setX(2, 0);
    tri.setY(0, sqrt(12));  // sqrt(4^2 - 2^2)
    tri.setZ(-2, 0);

    std::cout << "Area: " << tri.area() << std::endl;
    std::cout << "perimeter: " << tri.getPerimeter() << std::endl;
    std::cout << "equilateral: (1=true, 0=false) " << tri.isEquilateral() << std::endl;
}