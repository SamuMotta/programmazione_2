#include <iostream>

using namespace std;

class A {
    public:
    A() { cout << "constructor A" << endl; }
    void foo() { cout << "foo A" << endl; }
};

class B {
    public:
    B() { cout << "construcotr B" << endl; }
    void foo() { cout << "foo B" << endl; }
};

class C : public A, public B {
    public:
    C() { cout << "constructor C" << endl; };
};

int main() {
    C c;
    c.foo();
}
