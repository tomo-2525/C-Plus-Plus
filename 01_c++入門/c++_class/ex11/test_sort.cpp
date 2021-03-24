//StudentID :s1260032
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template <class Ran>
void sort(Ran begin, Ran end)
{
    long long N = end - begin;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j; j--)
        {
            if (*(begin + j) < *(begin + j - 1))
            {
                swap(*(begin + j), *(begin + j - 1));
                flag = true;
            }
        }
    }
}

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);

    cout << "before sort!" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "]:" << v[i] << endl;
    }

    sort(v.begin(), v.end());

    cout << "after sort!" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "]:" << v[i] << endl;
    }

    return 0;
}
