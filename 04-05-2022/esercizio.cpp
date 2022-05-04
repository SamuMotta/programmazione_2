/* Scrivere una classe template che prenda due tipi di dato generici e li utilizzi
    come tipi di dato per due attributi della classe stessa.
    Scrivere metodi set e get e un metodo di stampa, oltre al costruttore.
*/

#include <iostream>

using namespace std;


//Prendere l'esercizio dal file del professore Moltisanti.

template <class T1, class T2>
class A
{

private:
    T1 a;
    T2 b;

public:
    A(T1 aux1, T2 aux2) : a(aux1), b(aux2){};

    void setA(T1 aux1)(a = aux1);
    void setB(T2 aux2)(b = aux2);

    T1 getA() { return a; }
    T2 getB() { return b; }

    virtual ostream &put(ostream &os)
    {
        os << "Variabile a: " << a << endl;

        os << "Variabile b: " << b << endl;
    }
};

int main()
{

    int a = 2;

}