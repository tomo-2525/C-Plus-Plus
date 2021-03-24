#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
        string s1 = "I am s1";
        [&] { s1 = "Overwrite s1!"; } ();
        cout << s1 << endl;
        return 0;
}