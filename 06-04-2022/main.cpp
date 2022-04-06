#include "studente.h"

using namespace std;

void func() {
    Studente s1;
    Studente s2("A", "B", 19, "a@unict.it", "1000031685");
    Studente s3 = s2;

    s1.Persona::print();
    s1.print();
    s2.print();
    s3.print();
}

int main() {

    func();
    cout << "finito" << endl;
}