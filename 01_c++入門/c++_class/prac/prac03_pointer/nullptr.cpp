#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

class Class_x
{
public:
    int x;
    Class_x(int _x) : x(_x) {}
};

int main()
{
    int *p1 = nullptr;
    int *x;
    double *p2 = nullptr;
    string *p3 = nullptr;
    vector<int> *p4 = nullptr;
    Class_x *p5 = nullptr;
    int y = NULL;
    

    cout << "値：" << p1 << " 型：" << typeid(p1).name() << endl;
    // 値：0 型：Pi
    cout << "値：" << p2 << " 型：" << typeid(p2).name() << endl;
    // 値：0 型：Pd
    cout << "値：" << p3 << " 型：" << typeid(p3).name() << endl;
    // 値：0 型：PNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    cout << "値：" << p4 << " 型：" << typeid(p4).name() << endl;
    // 値：0 型：PSt6vectorIiSaIiEE
    cout << "値：" << p5 << " 型：" << typeid(p5).name() << endl;
    // 値：0 型：P7Class_x

    cout << "値："  << " 型：" << typeid(NULL).name() << endl;
    cout << "値："  << " 型：" << typeid(y).name() << endl;

    return 0;
}