#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};

class B
{
private:
    A a;
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
};


int main()
{
    cout << "beginning" << endl;
    B b;
    cout << "end" << endl;
}

/*
beginning
A()
B()
end
~B()
~A()
*/