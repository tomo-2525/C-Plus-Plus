#include <iostream>
#include <string>

using namespace std;

class A
{
private:
    int a;
public:
    A(int x) : a(x){};
    // A() : a(3){}; デフォルトコンストラクタを作ればエラーがなくなる。
    void dispa() { cout << a << endl; }
};
class B : public A
{
private:
    int b;
public:
    // B() : b(2){}; エラー
    // クラスBは、クラスAを継承しているので、クラスBのコンストラクタを実行する前に、クラスAのコンストラクタを実行する。Aのコンストラクタは引数があるためエラーが起きる。
    void dispb() { cout << b << endl; }
};
int main()
{
    // B b;
    // b.dispa();
    // b.dispb();
}