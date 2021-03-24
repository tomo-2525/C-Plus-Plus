#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
        string x = "I am string";
        [&] { cout << x << endl; } (); //参照
        [=] { cout << x << endl; } (); //コピー
 
        string s1 = "I am s1";
        string s2 = "I am s2";
        [&] { s1 = "Overwrite s1!"; } ();
        [=] { s2 = "Overwrite s2!"; } ();
 
        cout << s1 << endl;
        cout << s2 << endl;
        return 0;
}