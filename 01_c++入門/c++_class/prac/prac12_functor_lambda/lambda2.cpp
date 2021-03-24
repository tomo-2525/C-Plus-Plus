#include <iostream>
#include <functional>
using namespace std;

void f(int n1, int n2, int n3)
{
    cout << n1 << " " << n2
         << " " << n3 << "\n";
}
int main(void)
{
    using namespace std::placeholders;
    auto f2 = bind(f, 10, _2, _1);
    f2(11, 12); // will print 10 12 11 return 0;
}