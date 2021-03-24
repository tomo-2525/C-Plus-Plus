#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> a = {3, 1, 4, 2};
    std::vector<int> b = {2, 5, 6, 4};
    std::vector<int> result;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    // aとbをマージ
    std::merge(a.begin(), a.end(),
               b.begin(), b.end(),
               std::back_inserter(result));

    std::for_each(result.begin(), result.end(), [](int x) {
        std::cout << x << std::endl;
    });
}