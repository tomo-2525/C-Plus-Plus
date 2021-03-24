#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void print_vector(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << ", ";
    });
    cout << endl;
}

int main()
{
    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
    print_vector(v);
    std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    print_vector(v);
    // std::cout << "The median is " << v[v.size() / 2] << '\n';

    std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
    print_vector(v);
    // std::cout << "The second largest element is " << v[1] << '\n';
}