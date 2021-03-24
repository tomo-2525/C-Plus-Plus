#include <iostream>
#include <string>

using namespace std;
class A
{
private:
    int a;

public:
    A(int x) : a(x){};
    void dispa() { cout << a << endl; }
};
class B : public A
{
private:
    int b;

public:
    B(int x, int y) : A(x), b(y){};
    void dispb() { cout << b << endl; }
};
int main()
{
    B b(1, 2);
    b.dispa(); // 1
    b.dispb(); // 2
}


