//Student ID: s1260032
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    istream_iterator<string> is(cin);
    istream_iterator<string> last;
    ofstream of("numbers.txt");
    ostream_iterator<string> os(of);

    for (;is!=last;is++){
        string num = *is;
        if (((stoi(num) % 3) == 0) && ((stoi(num) % 5) != 0))
        {
            *os = num;
            os++;
            *os = "\n";
            os++;
        }
    }
        return 0;
}