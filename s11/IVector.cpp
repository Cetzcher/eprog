#include "IVector.hpp"
#include <iostream>
#include <vector>

IVector::IVector(int n) {
    items = new int[n];
    length = n;
}

IVector::IVector(const IVector& rhs) {
    length = rhs.getLength();
    items = new int(length);
    copyValsToThis(rhs);
}

void IVector::copyValsToThis(const IVector& ref) {
    for(int i = 0; i < length; i++) {
        items[i] = ref.getCoef(i);
    }
}

IVector& IVector::operator=(const IVector& rhs) {
    if(this != &rhs) {
        copyValsToThis(rhs);
    }
    return *this;
}

IVector::~IVector() {
    delete[] items;
}

int IVector::getLength() const {
    return length;
}

int IVector::getCoef(int idx) const {
    return items[idx];
}

void IVector::setCoef(int idx, int frac) {
    items[idx] = frac;
}


void IVector::print() const {
    for(int i = 0; i < getLength(); i++)
        std::cout << "[" << i << "] : " << items[i] << std::endl;
}

int* eratosthenes(int n) {
    const int LENGTH = n -1;
    int* vec = new int[LENGTH];
    int i, j;
    for(i = 0; i < LENGTH; ++i) {
        vec[i] = i + 2;
    }

    for(i = 0; i < LENGTH; ++i) {
        int cur = vec[i];
        for(j = i; j < LENGTH; ++j) {
            int other = vec[j];
            if(cur == 0 || other == 0 || other == cur)
                continue;
            else if(other % cur == 0) {
                vec[j] = 0;
            }
        }
    }
    return vec;
}


IVector* IVector::primefactors(int n) {
    int* primes = eratosthenes(n);
    std::vector<int> factors;
    int i = 0;
    while(i < n - 1) {
        int cur = primes[i];
        if(cur != 0 && n % cur == 0) {
            i = 0;
            n = n / cur;
            factors.push_back(cur);
            continue;
        }
        i++;
    }

    IVector* vec = new IVector(factors.size());
    for(int i = 0; i < factors.size(); i++) {
        vec->setCoef(i, factors.at(i));
    }
    return vec;
}

int main() {
    IVector* vec = IVector::primefactors(783);
    vec->print();
    return 0;
}