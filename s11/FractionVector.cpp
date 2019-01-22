#include "FractionVector.hpp"
#include "Fraction.hpp"
#include <iostream>

FractionVector::FractionVector(int n) {
    items = new Fraction[n];
    length = n;
}

FractionVector::FractionVector(const FractionVector& rhs) {
    length = rhs.getLength();
    items = new Fraction(length);
    copyValsToThis(rhs);
}

void FractionVector::copyValsToThis(const FractionVector& ref) {
    for(int i = 0; i < length; i++) {
        items[i] = Fraction(ref.getCoef(i));
    }
}

FractionVector& FractionVector::operator=(const FractionVector& rhs) {
    if(this != &rhs) {
        copyValsToThis(rhs);
    }
    return *this;
}

FractionVector::~FractionVector() {
    delete[] items;
}

int FractionVector::getLength() const {
    return length;
}

Fraction FractionVector::getCoef(int idx) const {
    return items[idx];
}

void FractionVector::setCoef(int idx, const Fraction& frac) {
    items[idx] = frac;
}

void FractionVector::sort() {
    for (int i = 0; i < getLength() - 1; i++) { 
        for (int j = 0; j < getLength() - i - 1; j++) { 
            Fraction a = getCoef(j), b = getCoef(j + 1);
            if (((double)a) > ((double)b)) {
                Fraction tmp = b;
                setCoef(j + 1, a);
                setCoef(j, tmp);
            }
        }
    } 
}

void FractionVector::print() const {
    for(int i = 0; i < getLength(); i++)
        std::cout << "[" << i << "] : " << items[i] << " double " << ((double) items[i]) << std::endl;
}

int main() {
    FractionVector vec(5);
    vec.setCoef(0, Fraction(3, 8));
    vec.setCoef(1, Fraction(14, 3));
    vec.setCoef(2, Fraction(4, 5));
    vec.setCoef(3, Fraction(2, 8));
    vec.setCoef(4, Fraction(27, 2));
    vec.print();
    std::cout << "\nsorting\n" << std::endl;
    vec.sort();
    vec.print();
    return 0;
}