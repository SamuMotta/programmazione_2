#include <iostream>
#include <string>

using namespace std;

class Persona {
    private:
        string nome;
        string cognome;
        int eta;
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
            cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email << endl;
}

void func() {

    Persona p1;
    p1.print();

    Persona p2("Marco", "Moltisanti", 38, "moltisanti@dmi.unict.it");
    p2.print();

    Persona p3 = p2;
    p3.print();

    cout << &p2 << " " << &p3 << endl;
}

int main () {
    
    func();
    cout << "ciao" << endl;
}

