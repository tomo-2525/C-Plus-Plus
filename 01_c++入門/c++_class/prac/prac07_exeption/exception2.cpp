#include <iostream>
#include <vector>
#include <string>

using namespace std;

void f(int n)
{
    if (n == 1)
        throw 2;
    if (n == 2)
        throw 2.0;
    if (n == 3)
    {
        string s = "hoge";
        throw s;
    }
    if (n == 4)
    {
        vector<int> v = {0, 1, 2, 3, 4, 5};
        throw v;
    }
}

int main()
{
    try
    {
        int n;
        cout << "please input a number:";
        cin >> n;
        f(n);
    }
    catch (int e)
    {
        cout << "This is int:" << e << endl;
    }
    catch (double e)
    {
        cout << "This is double:" << e << endl;
    }
    catch (string e)
    {
        cout << "This is string:" << e << endl;
    }
    catch (vector<int> e)
    {
        cout << "This is vector<int>:";
        for (int i; i < e.size(); i++)
        {
            cout << e[i] << " ";
        }
        cout << endl;
    }
}