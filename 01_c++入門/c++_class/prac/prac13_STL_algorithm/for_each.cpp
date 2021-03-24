#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {3, 1, 4};

    // vの全ての要素にラムダ式を適用する
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << std::endl; });

    std::cout << "----" << std::endl;

    // 要素の内容を書き換えても構わないし、呼び出し順序に依存した処理を書いても構わない
    int n = 0;
    std::for_each(v.begin(), v.end(), [n](int &x) mutable { x += n++; });
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << std::endl; });
}