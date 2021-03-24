#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <string>

template <class C>
void print(const C &c, std::ostream &os = std::cout)
{
    std::for_each(std::begin(c), std::end(c), [&os](typename C::value_type p) { os << '{' << p.first << ',' << p.second << "}, "; });
    os << std::endl;
}

int main()
{
    std::unordered_multimap<std::string, int> um{
        {"1st", 1},
        {"2nd", 2},
        {"3rd", 3},
    };

    print(um);

    um.emplace("4th", 4);

    print(um);

    um.insert({{"5th", 5}, {"2nd", 6}});

    print(um);

    um.erase("2nd");

    print(um);
}