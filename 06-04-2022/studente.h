#include "persona.h"

#ifndef STUDENTE_H
#define STUDENTE_H

class Studente : public Persona {
    string matricola;

    public:

        Studente() : Persona() {} //Costruttore ereditarietà

        Studente(string n, string c, int e, string em, string m) : 
            Persona(n, c, e, em), matricola(m) {}
        Studente(const Studente &s) : Persona(s) {
            matricola = s.matricola;
            //temperatura = new int[100];
        }

        void print() {
            Persona::print();
            cout << " la mia matricola e' " << matricola << endl;
        }
};

#endif