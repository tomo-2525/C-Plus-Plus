#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {3, 1, 4, 2, 5};

    // 並べ替える
    std::sort(v.begin(), v.end());

    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << std::endl;
    });
}