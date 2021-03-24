#include <iostream>
using namespace std;
int main(int argc, char const* argv[])
{
        auto a = [] { return 0;} (); // 戻り値を推測させる
        auto b = [] () -> float { return 3.14; } (); //明示的に戻り値を定義
 
        cout << a << endl;
        cout << b << endl;
        return 0;
}
