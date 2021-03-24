#include <iostream>
// curry()はhttp://notmoon.hateblo.jp/entry/2015/08/05/115525からの引用
template <typename F>
auto curry(F f)
{
    return [f](auto a) { 
        return [f, a](auto... args) { 
            return f(a, args...); 
        }; 
    };
}
int add(int x, int y)
{
    return x + y;
}

int main()
{
    auto add1c = curry(add)(10);
    std::cout << add1c(20) << "\n";
}