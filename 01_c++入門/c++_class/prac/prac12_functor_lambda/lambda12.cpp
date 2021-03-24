#include <iostream>
using namespace std;
// curry()はhttp://notmoon.hateblo.jp/entry/2015/08/05/115525からの引用
template <typename F>
auto curry(F f)
{
    return [f](auto a) {
        return [f, a](auto args) {
            cout << " args:  " << args << endl;
            cout << " a:  " << a << endl;
            return f(a);
        };
    };
}
int add(int x)
{
    return x + 2;
}

int main()
{
    auto add1c = curry(add)(10);
    std::cout << add1c(20) << "\n";
}