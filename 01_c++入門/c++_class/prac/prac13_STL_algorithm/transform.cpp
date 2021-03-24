#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

int main()
{
    std::vector<int> v = {3, 1, 4};
    std::vector<std::string> result;

    // 2倍してから文字列に変換する
    std::transform(v.begin(), v.end(), std::back_inserter(result),
                   [](int x) { return std::to_string(x * 2); });

    std::for_each(result.begin(), result.end(),
                  [](const std::string &s) { std::cout << s << std::endl; });
}