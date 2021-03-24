#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};

class B:public A
{
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
};
class C : public B
{

public:
    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
};

int main()
{
    cout << "A a;" << endl;
    if (true)
    {
        A a;
    }

    cout << endl
         << "B b;" << endl;
    if (true)
    {
        B b;
    }

    cout << endl
         << "C c;" << endl;
    if (true)
    {
        C c;
    }
}

/*
A a;
A()
~A()

B b;
A()
B()
~B()
~A()

C c;
A()
B()
C()
~C()
~B()
~A()
*/