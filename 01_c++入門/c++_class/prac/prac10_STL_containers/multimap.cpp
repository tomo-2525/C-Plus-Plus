#include <iostream>
#include <map>
#include <utility>

int main()
{
    // charをキー、intを値として扱う連想配列
    std::multimap<char, int> m;

    // 挿入
    m.emplace('c', 30);
    m.emplace('a', 10);
    m.emplace('b', 20);
    m.emplace('a', 40); // キー'a'に対応する値が2つ

    // 同じキーを持つ値の数を取得する
    auto count = m.count('a'); // count == 2
    std::cout << "count = " << count << std::endl;

    // キー`a`を持つ値を列挙する
    auto p = m.equal_range('a');
    for (auto it = p.first; it != p.second; ++it)
    {
        std::cout << it->second << std::endl;
    }
}