#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {3, 1, 4};
    auto result = std::find(v.begin(), v.end(), 1);
    if (result == v.end())
    {
        std::cout << "not found" << std::endl;
    }
    else
    {
        std::cout << "found: " << *result << std::endl;
    }
}