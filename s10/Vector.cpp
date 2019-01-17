#include "Vector.hpp"
#include <iostream>

Vector::Vector(int _size) {
    size = _size;
    arr = new double[size];
}

Vector::~Vector() {
    delete[] arr;
}

double Vector::get(int i) const {
    return arr[i];
}

void Vector::set(int i, double val) {
    arr[i] = val;
}

int Vector::getSize() const {
    return size;
}

void Vector::print() {
    for(int i = 0; i < getSize(); i++) {
        std::cout << "[" << i << "] = " << get(i) << std::endl;
    }
    std::cout << std::endl;
}