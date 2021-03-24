#include <iostream>
using namespace std;

class B
{
public:
    B() {}
    void f() { cout << "B::f()" << endl; }
    // virtual void f() { cout << "B::f()" << endl; } // 動的型付けになる
};

class D1 : public B
{
public:
    D1() {}
    void f() { cout << "D1::f()" << endl; }
};

void g(B *b)
{
    cout << "void g(B *b)   ";
    b->f();
}

void g(B &b)
{
    cout << "void g(B &b)   ";
    b.f();
}

int main()
{
    B b;
    D1 d1;

    g(b);
    g(&b);
    g(d1); // D1、D2オブジェクトを渡しているのに、継承元のクラスであるBのメソッドが呼ばれる。
    g(&d1);

    return 0;
}

/*
void f() { cout << "B::f()" << endl; }
void g(B &b)   B::f()
void g(B *b)   B::f()
void g(B &b)   B::f()
void g(B *b)   B::f()
*/


/*
virtual void f() { cout << "B::f()" << endl; }
void g(B &b)   B::f()
void g(B *b)   B::f()
void g(B &b)   D1::f()
void g(B *b)   D1::f()
*/

/*
静的型付け：変数や、サブルーチンの引数や返り値などの値について、その型が、コンパイル時など、そのプログラムの実行よりも前にあらかじめ決められている、という型システムの性質

動的型付け：
変数や、サブルーチンの引数や返り値などの値について、その型を、コンパイル時など、そのプログラムの実行よりも前にあらかじめ決めるということをせず、実行時の実際の値による、という型システムの性質

コンパイラがメソッドを呼び出す時、引数の静的型を調べる。上の例だとB
これを静的束縛（static binding）という。動的束縛（dynamic binding）は、呼び出されるメソッドは、オブジェクトの実行時の型に基づいて実行時に選択される。

C++では、動的束縛を実現するために、virtualキーワードを使用する。
メソッド定義がクラス外にある場合は virtualをつけるとコンパイルエラーになる
そして、親クラスでvirtualで宣言すると子クラスの関数もvirtualに自動的になる。
オーバーライドは、メソッドがvirtual場合にのみ行われます。それ以外の場合は名前が隠蔽されており、問題の原因となります。
*/