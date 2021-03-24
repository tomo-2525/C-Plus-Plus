#include <iostream>
using namespace std;

class B
{
public:
    B() { cout << "B()" << endl; }
    virtual ~B() { cout << "~B()" << endl; }
};
class D : public B
{
public:
    D() { cout << "D()" << endl; }
    ~D() { cout << "~D()" << endl; }
};

int main()
{
    B *b = new D;
    delete b;
    return 0;
}

/*
virtual無し
B()
D()
~B()


virtual有り
B()
D()
~D()
~B()
*/