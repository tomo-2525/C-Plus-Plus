#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> v = {2, 3, 1, 2, 1};

    // 1 を除去した結果を出力する
    std::remove_copy(v.begin(), v.end(),
                     std::ostream_iterator<int>(std::cout, ","), 1);
}