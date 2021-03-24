#include <iostream>
#include <string>
using namespace std;

// template <typename T> と template <class T> は同じ意味だが、ここでは、一つだけだとエラーになる。
template <typename T1, typename T2>
const T1 max(const T1 &a, const T2 &b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 1, b = 2;
    cout << max(a, b) << endl;

    string c = "max", d = "what";
    cout << max(c, d) << endl;

    return 0;
}