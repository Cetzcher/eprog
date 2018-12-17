#pragma once

class Konto {

    private:
        double kontonummer;
        double zinssatz;
        double guthaben;

    public: 
        Konto();

        double getZinssatz();
        double getkontonummer();
        double berrechneGuthaben();

        void setKontonummer(double val);
        void setZinssatz(double val);
        
        void abheben(double val);
        void einzahlen(double val);

};