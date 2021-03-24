#include <iostream>
#include <set>

int main()
{
    // intをキーとして扱う集合
    std::multiset<int> s;

    // 挿入
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1); // キーを重複させることが可能

    // キー1に該当する要素数を取得する
    std::size_t count = s.count(1);
    std::cout << count << std::endl;
    // 検索 : キー(int)を指定し、対応する値を得る
    decltype(s)::iterator it = s.find(1);
    if (it != s.end())
    {
        // 発見した
        // 同じキーの要素を全て列挙する
        for (std::size_t i = 0; i < count; ++i)
        {
            int value = *it;
            std::cout << value << std::endl;
            ++it;
        }
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
}