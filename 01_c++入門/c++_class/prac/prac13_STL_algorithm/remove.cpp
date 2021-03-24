#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {2, 3, 1, 2, 1};

    auto result = std::remove(v.begin(), v.end(), 1);

    // [v.begin(),result) の範囲に 1 を除去した結果が入っている
    std::for_each(v.begin(), result, [](int x) { std::cout << x << ","; });
    std::cout << std::endl;

    // remove を使ってもコンテナの要素数は変わらないことに注意しよう
    std::cout << "size before: " << v.size() << std::endl;

    // [v.begin(),result) の範囲に 1 を除去した結果が入っているので、
    // [result,v.end()) を erase することでサイズも変更することができる
    // （Erase-remove イディオム）
    v.erase(result, v.end());
    std::cout << "size after: " << v.size() << std::endl;
}