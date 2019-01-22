#include "Fraction.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Fraction::Fraction() {
    init(0, 1);
}

Fraction::Fraction(double dVal) {
    // conversion ctor
    // TODO: impl, as well as write some driver program
    const long int tenPower9 = 1000 * 1000 * 1000;

    int intPart = dVal;
    double fracPart = (dVal - intPart);

    long int num = fracPart * tenPower9;
    init(num, tenPower9);
    reduce();
    if(intPart != 0)
        setNumerator(getDenominator() * intPart + getNumerator());
}

Fraction::Fraction(int num, int denom) {
    init(num, denom);
}

Fraction::Fraction(const Fraction& frac) {
    init(frac.getNumerator(), frac.getDenominator());
}

void Fraction::init(int p, int q) {
    setNumerator(p);
    setDenominator(q);
}

void Fraction::print() const {
    std::cout << getNumerator() << "/" << getDenominator() << std::endl;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int n) {
    numerator = n;
}

void Fraction::setDenominator(int n) {
    assert(n != 0);
    if (n > 0) {
        denominator = n;
    } else {
        denominator = -n;
        numerator = -numerator;
    }
}

Fraction::~Fraction() {
    // do nothing.
}

Fraction& Fraction::operator=(const Fraction& rhs) {
    if(this != &rhs) {
        setNumerator(rhs.getNumerator());
        setDenominator(rhs.getDenominator());
    }
    return *this;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction f;
    f.setNumerator(getNumerator() * other.getNumerator());
    f.setDenominator(getDenominator() * other.getDenominator());
    return f;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction f;
    f.setNumerator(getNumerator() * other.getDenominator());
    f.setDenominator(getDenominator() * other.getNumerator());
    return f;
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction f;
    int lcm = Fraction::lcm(getDenominator(), other.getDenominator());
    int leftNum = getNumerator() * (lcm / getDenominator());
    int rightNum = other.getNumerator() * (lcm / other.getDenominator());
    f.setNumerator(leftNum + rightNum);
    f.setDenominator(lcm);
    f.reduce();
    return f;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction inverted = -other;
    return (*this) + inverted;  
}

Fraction Fraction::operator-() const {
    Fraction f(-getNumerator(), getDenominator());
    return f;
}

Fraction::operator double() {
    return (double)getNumerator() / (double)getDenominator();
}

Fraction::operator int() {
    double dVal = (*this);
    int intPart = dVal;
    double fracPart = (dVal - intPart);
    if(fracPart == -0.5)
        return --intPart;   // fracPart is negative, numerator was also neg.
    else if(fracPart == 0.5)
        return ++intPart;
    return intPart;
}

int Fraction::gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return Fraction::gcd(b, a % b);
}

int Fraction::lcm(int a, int b) {
    int gcd = Fraction::gcd(a, b);
    // gcd * lcm = a * b
    // lcm = (a * b) / gcd
    return (a * b) / gcd;
}

void Fraction::reduce() {
    int gcd = Fraction::gcd(getNumerator(), getDenominator());
    setNumerator(getNumerator() / gcd);
    setDenominator(getDenominator() / gcd);
}

std::ostream& operator<<(std::ostream& stream, const Fraction& ref) {
    return stream << ref.getNumerator() << "/" << ref.getDenominator();
}

//int main() {
//    Fraction f(22,-2), g(18, 4), h(3, 2), i(-3, 2), j(2, 12), k(2, 4);
//    f.print();
//    g.print();
//    std::cout << ((double) g) << std::endl;
//    f.reduce();
//    g.reduce();
//    f.print();
//    g.print();
//    std::cout << ((double) g) << std::endl;
//    std::cout << "int casts" << std::endl;
//    h.print();
//    std::cout << "casts to: " << ((int) h) << std::endl; 
//    i.print();
//    std::cout << "casts to: " << ((int) i) << std::endl; 
//    std::cout << "Arithmetic" << std::endl;
//    std::cout << "lcm(12, 4) = " << Fraction::lcm(3, 11) << std::endl;
//    auto res = j + k;
//    auto res2 = j - k;
//    res.print();
//    res2.print();
//    std::cout << "gcd(22, -2) = " << Fraction::gcd(22, -2) << std::endl;
//    Fraction z(22,-2);
//    std::cout << z << std::endl;
//    return 0;
//}