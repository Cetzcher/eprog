#include "a6.hpp"
#include <iostream>
#include <cmath>

MatrixL::MatrixL(int n) {
    dim = n;
    coeff = new double[calcSize()];
}

int MatrixL::calcSize() {
    return ((dim * (dim+1)) / 2);
}

int MatrixL::calcIndex(int j, int k) {
    return j * (j + 1) / 2 + k;
}

bool MatrixL::isWithinBounds(int j, int k) {
    return k <= j;
}

MatrixL::~MatrixL() {
    delete coeff;
}

void MatrixL::setVal(int j, int k, double val) {
    coeff[calcIndex(j, k)] = val;
}

double MatrixL::getVal(int j, int k) {
    return coeff[calcIndex(j, k)];
}

int MatrixL::getDimension() {
    return dim;
}

MatrixL* MatrixL::scan(int n) {
    MatrixL* ptr = new MatrixL(n);
    double val;
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            if(ptr->isWithinBounds(j, k)) {
                std::cout << "enter val @(" << j << "," << k << ") ="; 
                std::cin >> val;
                ptr->setVal(j, k, val);
            } else {
                std::cout << "ignoring val @(" << j << "," << k << ")" << std::endl;                 
            }
        }
    }
    return ptr;
}

void MatrixL::print() {
    int n = getDimension();
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
            if(isWithinBounds(j, k))
                std::cout  << getVal(j, k) << "\t"; 
            else 
                std::cout << 0 << "\t"; 
        }
        std::cout << std::endl;
    }
}

double MatrixL::colSumNorm() {
    double max = 0, sum = 0, curVal = 0;
    for(int j = 0; j < getDimension(); j++) {
        for(int k = 0; k < getDimension(); k++) {
            if(isWithinBounds(k, j)) {
                curVal = getVal(k, j);
                sum += curVal;
            }
        }
        if(sum > max)
            max = sum;
        sum = 0;
    }
    return max;
}

double MatrixL::rowSumNorm() {
    double max = 0, sum = 0, curVal = 0;
    for(int j = 0; j < getDimension(); j++) {
        for(int k = 0; k < getDimension(); k++) {
            if(isWithinBounds(j, k)) {
                curVal = getVal(j, k);
                sum += curVal;
            }
        }
        if(sum > max)
            max = sum;
        sum = 0;
    }
    return max;
}

int main() {

    MatrixL* mat = MatrixL::scan(3);
    mat->print();
    std::cout << std::endl;
    std::cout << "colSumNorm " << mat->colSumNorm() << std::endl;
    std::cout << "rowSumNorm " << mat->rowSumNorm() << std::endl;
    return 0;
}