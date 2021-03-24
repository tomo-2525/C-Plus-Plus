#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string str = "reverse";

    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
}