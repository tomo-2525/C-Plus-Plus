#include <iostream>
using namespace std;

class B
{
public:
    B() {}
    virtual void f() { 
        cout << "B" << endl;
        cout << "B::f()" << endl; }
};
class D : public B
{
public:
    D() {}
    void f()
    {
        cout << "D" << endl;
        B::f(); // or this->B::f();
        cout << "D::f()" << endl;
    }
};

void g(B *b)
{
    b->f();
}

int main()
{
    D d;
    g(&d);
    return 0;
}

/*
virtual有り
Dのfが呼ばれる
B::f()
D::f()

virtual無し
Bのfが呼ばれる
B::f()
*/

/*
virtualをつけるかどうかの判断
virtualをつけるかどうか判断している関数が全ての派生クラスに対して全く同じ動作をするならば、virtualを付けなくてよいが、もしオーバーライドするなど、同じ動作をしないならばvirtualをつけるべきで。このつけるか付けないかの判断は、基底クラスを設計する時に行うべきである。

また、クラスに少なくとも1つの仮想関数がある場合には仮想デストラクタを作成するべき。
*/