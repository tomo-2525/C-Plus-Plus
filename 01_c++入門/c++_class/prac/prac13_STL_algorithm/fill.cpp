#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(5);

    // v を 3 の値で埋める
    std::fill(v.begin(), v.end(), 3);

    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << ","; });
}