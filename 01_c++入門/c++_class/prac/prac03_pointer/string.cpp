#include <iostream>
#include <string>

using namespace std;

int main()
{
    string tmp = "hoge";
    string *myString = &tmp;
    // cout << *myString.length() << endl;
    // エラーになる .は*よりも優先順位が高いので
    //  *(mystring.length())と同じになる

    cout << (*myString).length() << endl; // 4
    cout << myString->length() << endl; // 4


    return 0;
}
