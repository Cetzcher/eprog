#include "a1.hpp"
#include <iostream>
#include <string>

Account::Account(int pin, double initialMoney, std::string name) {
    this->pin = pin;
    this->balance = initialMoney;
    this->name = name;
}

bool Account::checkPin() {
    int pin;
    std::cout << "Enter pin code." << std::endl;
    std::cin >> pin;
    return this->pin == pin;
}

void Account::drawMoney() {
    if(this->checkPin()) {
        double amount;
        std::cout << "enter amount to whitdraw" << std::endl;
        std::cin >> amount;
        if(this->balance - amount < 0) {
            std::cout << "amount < balance, cannot whitdraw" << std::endl;
        } else {
            this->balance -= amount;
            this->printBalance();
        } 
    }
    std::cout << "Pin incorrect" << std::endl;   
}

void Account::printBalance() {
    std::cout << "your current balance is: " << this->balance << std::endl;
}

int main(){
    Account acc(1234, 100.00, "hello world");
    acc.printBalance();
    acc.drawMoney();
    return 0;
}
