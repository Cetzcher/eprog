#include <iostream>
#include "Fraction.hpp"

int main() {
    std::cout << "Creating fractions" << std::endl;
    Fraction f(22,-2), g(18, 4), h(3, 2), i(-3, 2), j(2, 12), k(2, 4);

    std::cout << "Printing\n" << std::endl;
    f.print();
    g.print();
    std::cout << "to double" << std::endl;
    std::cout << ((double) g) << std::endl;
    std::cout << "======================" << std::endl;

    std::cout << "reduce: \n" << std::endl;    
    f.reduce();
    g.reduce();
    f.print();
    g.print();
    std::cout << "reduced double\n" << std::endl;
    std::cout << ((double) g) << std::endl;
    std::cout << "======================" << std::endl;

    std::cout << "int casts" << std::endl;
    h.print();
    std::cout << "casts to: " << ((int) h) << std::endl; 
    i.print();
    std::cout << "casts to: " << ((int) i) << std::endl; 
    std::cout << "======================" << std::endl;

    std::cout << "Arithmetic" << std::endl;
    std::cout << "gcd(22, -2) = " << Fraction::gcd(22, -2) << std::endl;
    std::cout << "lcm(12, 4) = " << Fraction::lcm(3, 11) << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << j << " + " << k << " = " << (j + k) << std::endl;
    std::cout << j << " - " << k << " = " << (j - k) << std::endl;
    std::cout << j << " * " << k << " = " << (j * k) << std::endl;
    std::cout << j << " / " << k << " = " << (j / k) << std::endl;

    std::cout << Fraction(0.25) <<  " " << Fraction(0.125) << " " << Fraction(0.5) << " " << Fraction(5) << " " << Fraction(1.125) << std::endl;
    return 0;
}