#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence = "Example of a sentence";
    stringstream ss(sentence);
    string word;
    while (ss >> word)
    {
        cout << word << "\n";
    }
    return 0;
}

/** 出力
Example
of
a
sentence
**/ 