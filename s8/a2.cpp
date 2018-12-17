#include <iostream>
#include "a2.h"
#include <assert.h>
// g++ a2.h a2.cpp -o a2.out

Konto::Konto() {
    this->setKontonummer(1234567);
    this->setZinssatz(1);
    this->guthaben = 100;
}

double Konto::getZinssatz() {
    return this->zinssatz;
}
double Konto::getkontonummer() {
    return this->kontonummer;
}

double Konto::berrechneGuthaben() {
    return this->guthaben;
}

void Konto::setKontonummer(double val) {
    assert(val >= 0);
    this->kontonummer = val;
}
void Konto::setZinssatz(double val) {
    assert(val >= 0);
    this->zinssatz = val;
}

void Konto::abheben(double val) {
    assert(this->guthaben - val >= 0 && val >= 0);
    this->guthaben -= val;
}

void Konto::einzahlen(double val) {
    assert(val >= 0);
    this->guthaben += val;

}

int main() {
    Konto* konto = new Konto();

    std::cout << "Konto #: " << konto->getkontonummer() << std::endl;
    std::cout << "Guthaben: " <<  konto->berrechneGuthaben() << std::endl;
    konto->einzahlen(50);
    std::cout << "einzahlen (50): " << konto->berrechneGuthaben()  << std::endl;
    konto->abheben(30);
    std::cout << "abheben (30): " << konto->berrechneGuthaben() << std::endl;
}