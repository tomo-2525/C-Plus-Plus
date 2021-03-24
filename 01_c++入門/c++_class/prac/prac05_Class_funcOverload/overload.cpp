#include <iostream>

using namespace std;
/*
void f(int a, int b = 1)
デフォルト引数は、通常の引数よりも全て右側にないとコンパイルエラーになる
{
    cout << "a+b= " << a + b << endl;
}
int main()
{
    f(2);    //a+b= 3
    f(2, 5); //a+b= 7
    return 0;
}
*/

class A
{
public:
    void set(int a, int b = 1);

private:
    int num;
};

void A::set(int a, int b)
{
    num = a * b;
    cout << num << endl;
}

int main()
{
    A a;
    a.set(1); // 1
    a.set(2, 2); // 4
}