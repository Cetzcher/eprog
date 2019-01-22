#ifndef FRACTION
#define FRACTION

#include <iostream>

class Fraction {
    private:
        int numerator;
        int denominator;

        void init(int p, int q);

    public:
        Fraction();
        Fraction(double val);
        Fraction(int num, int denom);
        Fraction(const Fraction& frac);
        ~Fraction();

        // arithmetic
        Fraction& operator=(const Fraction& rhs);
        Fraction operator+(const Fraction& other) const;
        Fraction operator-(const Fraction& other) const;
        Fraction operator*(const Fraction& other) const;
        Fraction operator/(const Fraction& other) const;

        // unary
        Fraction operator-() const;
            

        // type conversion
        operator double();
        operator int();


        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int n);
        void setDenominator(int n);
        void print() const;

        void reduce();

        static int gcd(int a, int b);
        static int lcm(int a, int b);
 };


std::ostream& operator<<(std::ostream& stream, const Fraction& ref);

 #endif