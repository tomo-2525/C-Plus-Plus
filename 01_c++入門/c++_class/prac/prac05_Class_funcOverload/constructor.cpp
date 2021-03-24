#include <iostream>
using namespace std;

class A
{
public:
    int a;
};

A a3;

int main()
{
    A a1;
    std::cout << a1.a << std::endl; // warning a1.A::a uninitialized
    A a2 = A();
    std::cout << a2.a << std::endl; // print 0 
    std::cout << a3.a << std::endl; // print 0 
    
    return 0;
}