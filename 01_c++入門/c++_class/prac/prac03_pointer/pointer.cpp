#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x;
    int *y;

    x = 2;
    y = new int(2);

    cout << "x: " << x << endl;  // 2
    cout << "y: " << *y << endl; // 2

    int a[5] = {1, 2, 3, 4, 5};
    int *a_p = a;
    cout << a_p[1] << endl;         // 2
    cout << 1 [a_p] << endl;        // 2
    cout << (a_p + 1)[0] << endl;   // 2
    cout << *(a_p + 1) << endl;     // 2
    cout << *(&a_p[0] + 1) << endl; // 2
    delete a_p;

    int *p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = i;
    }
    delete[] p;

    x = 0;
    // lvalue reference
    int &lvalue_ref_1 = x; // OK
    // int& lvalue_ref_2 = 0;           // Error 右辺値を左辺値参照で束縛している

    // rvalue reference
    // int&& rvalue_ref_1 = x;          // Error 左辺値を右辺値参照で束縛している
    int &&rvalue_ref_2 = 0; // OK

    // const lvalue reference
    const int &const_lvalue_ref_1 = x; // OK
    const int &const_lvalue_ref_2 = 0; // OK constな左辺値参照は右辺値を束縛できる
    return 0;
}
