#include <iostream>
#include <functional>
using namespace std;

struct Foo
{
    int i_;
    Foo(const int n) : i_(n) {}
    void print_add(const int n) const { std::cout << i_ + n << std::endl; }
};

struct PrintFunctor
{
    // 引数を表示するだけの関数オブジェクト
    void operator()(int i)
    {
        std::cout << i << std::endl;
    }
};

void print_number(const int i)
{
    std::cout << i << std::endl;
}

int main(int argc, char const *argv[])
{
    // 普通の関数
    std::function<void(int)> f_func = print_number;
    f_func(3);

    // ラムダ式
    std::function<void(int)> f_lambda = [=](int i) { print_number(i); };
    f_lambda(6);

    // バインド
    std::function<void()> f_bind = std::bind(print_number, 9);
    f_bind();

    // クラスのメンバ関数
    std::function<void(const Foo &, int)> f_member = &Foo::print_add;
    Foo foo(1);
    f_member(foo, 3); // 1+3 = 4

    // 関数オブジェクト
    std::function<void(int)> f_func_obj = PrintFunctor();
    f_func_obj(11);

    return 0;
}