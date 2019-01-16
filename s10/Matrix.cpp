#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>

Matrix::Matrix(int _n, Matrix::Type _type) {
    init(_n, _type);
}

Matrix::Matrix() {
    init(0, Matrix::Type::F);
}

Matrix::Matrix(int dim, Matrix::Type type, double lower, double upper) {
    init(dim, type);
    srand(time(NULL));
    if(lower > upper) {
        double tmp = lower;
        lower = upper;
        upper = tmp;
    }
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            if(isInBounds(i, j)) {
                double r = (double)rand() / RAND_MAX;
                setEntry(i, j, lower + r * (upper - lower));
            }
        }
    }
}


void Matrix::init(int dim, Matrix::Type type) {
    this->dim = dim;
    this->type = type;
    this->arr = new double[calcSize()];
}

Matrix::~Matrix() {
    delete[] this->arr;
}

int Matrix::calcSize() {
    switch(type) {
        case Type::F:
            return dim * dim;
        case Type::L:
        case Type::U:
            return (dim * (dim + 1)) / 2;
    }
}

int Matrix::calcIndex(int i, int j) {
        switch(type) {
        case Type::F:
            return i * dim + j;
        case Type::L:
            return (i * (i + 1)) / 2 + j;
        case Type::U:
            return (j * (j + 1)) / 2 + i;
    }    
}

bool Matrix::isInBounds(int i, int j) {
        switch(type) {
        case Type::F:
            return true;
        case Type::L:
            return j <= i;
        case Type::U:
            return i <= j;
    }        
}

double Matrix::getEntry(int i, int j) {
    if(this->isInBounds(i, j))
        return arr[calcIndex(i, j)];
    return 0;
}

void Matrix::setEntry(int i, int j, double val) {
    arr[calcIndex(i, j)] = val;
}

void Matrix::print() {
    for(int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            std::cout << getEntry(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}

double Matrix::columnSumNorm() {
    double max = 0, sum = 0, curVal = 0;
    for(int j = 0; j < dim; j++) {
        for(int k = 0; k < dim; k++) {
            sum += getEntry(k, j);
        }
        if(sum > max)
            max = sum;
        sum = 0;
    }
    return max;
}

double Matrix::rowSumNorm() {
    double max = 0, sum = 0, curVal = 0;
    for(int j = 0; j < dim; j++) {
        for(int k = 0; k < dim; k++) {
            sum += getEntry(j, k);;
        }
        if(sum > max)
            max = sum;
        sum = 0;
    }
    return max;
}

void Matrix::scan() {
    double val;
    for(int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(isInBounds(i, j)) {
                std::cout << "enter value @(" << i << " " << j << ") =";
                std::cin >> val;
                setEntry(i, j, val);
            }
        }
        std::cout << std::endl;
    }
}

int Matrix::getSize() const {
    return dim;
}

Matrix Matrix::operator* (const Vector& vec) {
    assert(this->getSize() == vec.getSize());
    Matrix mat(dim, type);
    for(int i = 0; i < getSize(); i++) {
        for(int j = 0; j < getSize(); j++) {
            double mVal = getEntry(i, j);
            double vVal = vec.get(j);
            mat.setEntry(i, j, mVal * vVal); 
        }
    }
    return mat;
}

Matrix* Matrix::createMatrix(int n, Matrix::Type type) {
    Matrix* m = new Matrix(n, type);
    m->scan();
    return m;
}

int main() {
    Matrix x(3, Matrix::Type::F);
    x.setEntry(0, 0, 1);
    x.setEntry(1, 0, 2);
    x.setEntry(2, 0, 3);
    x.setEntry(0, 1, 4);
    x.setEntry(1, 1, 5);
    x.setEntry(2, 1, 6);
    x.setEntry(0, 2, 7);
    x.setEntry(1, 2, 8);
    x.setEntry(2, 2, 9);
    std::cout << "col norm " << x.columnSumNorm() << std::endl;
    std::cout << "row norm " << x.rowSumNorm() << std::endl;
    x.print();

    //std::cout << " \nenter printed matrix" << std::endl;
    //Matrix* m = Matrix::createMatrix(2, Matrix::Type::U);
    //m->print();

    Vector vec(3);
    vec.set(0, 2);
    vec.set(1, 4);
    vec.set(2, 8);
    std::cout << "vec is: ";
    vec.print();

    std::cout << "multiplying " << std::endl;
    Matrix prod = x * vec;
    prod.print();

    std::cout << "random matrix " << std::endl;
    Matrix m(5, Matrix::Type::L, 3, 30);
    m.print();
    return 0;
}