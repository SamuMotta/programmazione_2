#include <iostream>
#include <string>

#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class Persona {
    private:
        string nome;
        string cognome;
        int eta = 0;
        string email;
        int *temperatura;

    public:
        Persona() { // Costruttore di default
            temperatura = new int[100];
        } 
        Persona(string n, string c, int e, string em) : // Costruttore completo
            nome(n), cognome(c), eta(e), email(em) {
                temperatura = new int[100];
            }
        Persona(const Persona& p) { // Costruttore copy constructor
            nome = p.nome;
            cognome = p.cognome;
            eta = p.eta;
            email = p.email;
            temperatura = new int[100];
        }

        void print();  

        ~Persona() {
            delete [] temperatura;
        }

        /*  void print() {
            cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email << endl;
        } */
        
};

void Persona::print() {
            cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email  << endl;
}

#endif