#ifndef A1
#define A1
#include <string>

class Account {

    private:
        std::string name;        
        double balance;
        int pin;

    public: 
        Account(int pin, double initialMoney, std::string name);
        void printBalance();
        bool checkPin();
        void drawMoney();



};

#endif
