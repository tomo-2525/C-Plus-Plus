#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // binary_search で 4 を検索する場合、
    // 4 より小さい物、4 と等しい物、4 より大きい物がその順に並んでいれば、
    // 必ずしもソートされている必要はない。
    std::vector<int> v = {3, 1, 4, 6, 5};

    if (std::binary_search(v.begin(), v.end(), 4))
    {
        std::cout << "found" << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
}