//student ID: s1260032
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int eval(string str)
{
    stringstream ss;
    stack<int> s;
    string output;
    ss << str;

    while (!ss.eof())
    {
        int in;
        ss >> output;
        if (output == "+" || output == "-" || output == "*" || output == "/")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if (output == "+")
                s.push(a + b);
            if (output == "-")
                s.push(a - b);
            if (output == "*")
                s.push(a * b);
            if (output == "/")
                s.push(a / b);
            continue;
        }

        in = stoi(output);
        s.push(in);
    }

    return s.top();
}

int main()
{
    string str = "-2 3 4 * 2 / - 7 +";
    cout << "in: " << str << endl;
    cout << "output: " << eval(str) << endl;
    return 0;
}