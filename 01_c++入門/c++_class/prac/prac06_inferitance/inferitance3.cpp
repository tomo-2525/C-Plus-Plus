#include <iostream>
#include <string>
using namespace std;

class A
{
private:
    int a;

public:
    A() : a(1){};
    void dispa() { cout << a << endl; }
};

class B : public A
{
private:
    int b;

public:
    B() : b(2){};
    void dispb() { cout << b << endl; }
};

int main()
{
    B b;
    b.dispa(); // 1
    b.dispb(); // 2
}