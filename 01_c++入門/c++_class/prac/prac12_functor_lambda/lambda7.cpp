#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string x = "I am string";
    [&] { cout << x << endl; }(); //参照
    [=] { cout << x << endl; }(); //コピー

    int a = 0, b = 0, c = 0, d = 0;

    // a,bを参照、それ以外はコピー
    [=, &a, &b]() mutable {}();

    // a,bはコピー、それ以外は参照
    [&, a, b]() mutable {}();
    return 0;
}
