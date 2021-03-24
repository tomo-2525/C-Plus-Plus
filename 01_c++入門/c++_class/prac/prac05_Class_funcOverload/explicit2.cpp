#include <iostream>
using namespace std;

class C
{
protected:
    int x;

public:
    C(int arg) : x(arg)
    {
        cout << "C::C(int)" << endl;
    }
    C &operator=(int arg)
    {
        cout << "C::operator=(int)" << endl;
        x = arg;
        return *this;
    }
};

int main(void)
{
    C obj = 10;
    return 0;
}