#ifndef FRACTION_VECTOR
#define FRACTION_VECTOR

#include "Fraction.hpp"

class FractionVector {

    private:
        Fraction* items;
        int length;

        void copyValsToThis(const FractionVector& other);

    public:
        FractionVector(int n);
        FractionVector(const FractionVector& rhs);

        ~FractionVector();

        FractionVector& operator=(const FractionVector& rhs);

        Fraction getCoef(int idx) const;
        void setCoef(int idx, const Fraction& frac);
        int getLength() const;

        void sort();

        void print() const;
};

#endif