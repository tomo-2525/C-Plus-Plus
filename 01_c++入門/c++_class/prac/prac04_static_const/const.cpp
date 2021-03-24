#include <iostream>

using namespace std;

/*******************/
/* constメンバ関数 */
/*******************/
class A
{
public:
    int day;
    int get_day() const { return day; } // const member function
    void set_day(int d) { day = d; }    // non-const member function
    // ...
};

int main()
{
    /*************/
    /* const変数 */
    /*************/

    int i = 1;
    int *ip;
    const int ci = 1;
    const int *cip;

    i = 2;
    // ci = 2;

    cip = &i;
    cip = &ci;

    cip = &i;
    // cip = 2;
    cip = &ci;
    // cip = 2;

    ip = &i;
    *ip = 3;
    // ip = &ci;

    /*****************/
    /* constポインタ */
    /*****************/

    int i2 = 1;
    // int *const jp;
    int *const i2pc = &i2;
    *i2pc = 10;
    cout << "i2:" << i2 << " i2pc:" << *i2pc << endl; // i2:10 i2pc:10
    // i2pc = &i2;

    const int a = 1;
    const int *const pa = &a;
    // *pa = 2;
    int b = 2;
    // pa = &b;

    return 0;
}