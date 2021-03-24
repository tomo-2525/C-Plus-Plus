#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
        [](string const & str) // 引数の定義
        {       // 関数本体
                cout << str << endl;
        }
        ( "I am Argument!");    // 関数呼び出しと引数
        return 0;
}