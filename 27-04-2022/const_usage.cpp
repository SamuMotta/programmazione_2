#include <iostream>

using namespace std;

const int a = 1002; // il valore assegnato alla variabile a è immutabile



int main() {

    //a = 10; // Errore: a è una variabile di solo lettura

    int b = 10;

    const int *c;

    c = &b;
    b = 20; // Puntatore a valore costante
    //*c = 30;
    
    int* const d = &b; // Puntatore costante a valore

    cout << b << ", " << *c << endl;
    cout << b << ", " << *d << endl;
}