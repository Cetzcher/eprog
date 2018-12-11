#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cDouble {
    double real;
    double img;
} cDouble;

cDouble* newCDouble(double real, double img) {
    cDouble* cd = malloc(sizeof(cDouble));
    cd->img = img;
    cd->real = real;
    return cd;
}

void delCDouble(cDouble* ptr) {
    free(ptr);
}


void setReal(cDouble* ptr, double real) {
    ptr->real = real;
}

void setImg(cDouble* ptr, double img) {
    ptr->img = img;
}

double getReal(cDouble* ptr) {
    return ptr->real;
}

double getImg(cDouble* ptr) {
    return ptr->img;
}


cDouble* cAdd(cDouble* z, cDouble* w){
    return newCDouble(getReal(z) + getReal(w), getImg(z) + getImg(w));
}

cDouble* cSub(cDouble* z, cDouble* w){
    return newCDouble(getReal(z) - getReal(w), getImg(z) - getImg(w));
}

cDouble* cMult(cDouble* z, cDouble* w){
    return newCDouble(
        getReal(z) * getReal(w) - getImg(z) * getImg(w),
        getReal(z) * getImg(w) - getReal(w) * getImg(z)
    );
}

cDouble* cConj(cDouble* z) {
    return newCDouble(getReal(z), -getImg(z));
}

double cNorm(cDouble* z) {
    return sqrt(getReal(z) * getReal(z) + getImg(z) * getImg(z));
}

cDouble* cDiv(cDouble* z, cDouble* w){
    cDouble* di = newCDouble(0, 0);
    double wSquared = (getReal(w) * getReal(w)) + (getImg(w) * getImg(w));
    setReal(di, ((getReal(z) * getReal(w)) + (getImg(z) * getImg(w))) / wSquared);
    setImg(di, ((getReal(w) * getImg(z)) - (getReal(z) * getImg(w) )) / wSquared);
    return di;
}

cDouble* scanComplex() {
    double real, imag;
    printf("real=");
    scanf("%lf", &real);
    printf("imag=");
    scanf("%lf", &imag);
    return newCDouble(real, imag);
}

void printComplex(cDouble* ptr) {
    printf("real: %lf, imag: %lf\n", getReal(ptr), getImg(ptr));   
}

int main() {
    cDouble *w = scanComplex(), *z = scanComplex();
    printf("|w| = %lf\n", cNorm(w));   
    printf("|z| = %lf\n", cNorm(z));   
    printf("w + z: ");
    printComplex(cAdd(w, z));
    printf("w - z: ");
    printComplex(cSub(w, z));
    printf("w * z: ");
    printComplex(cMult(w, z));
    if(getReal(z) == 0 && getImg(z) == 0)
        return 1;
    printf("w / z: ");
    printComplex(cDiv(w, z));

}