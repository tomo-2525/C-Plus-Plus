#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void print_vector(vector<int> v)
{
    cout << "print:";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << ", ";
    });
    cout << endl;
}

double compute_median(vector<int> v)
{
    vector<int>::iterator begin = v.begin();
    vector<int>::iterator end = v.end();
    vector<int>::iterator med = begin;
    cout << endl;
    print_vector(v);
    cout << "med:" << *med << endl;
    advance(med, v.size() / 2);
    cout << "med:" << *med  << endl;
    print_vector(v);
    nth_element(begin, med, end);
    print_vector(v);

    int mid = v.size() / 2;
    if (v.size() % 2 == 0)
    {
        (v[mid] + v[mid + 1]) / 2;
    }
    else
    {
        return v[mid];
    }
}

vector<int> compute_k_closest(vector<int> v, int k)
{
    double mid = compute_median(v);
    auto compare = [mid](int a, int b) -> bool {
        if (abs(a - mid) > abs(b - mid))
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    priority_queue<int, vector<int>, decltype(compare)> que{compare};
    vector<int> vector;
    for (int i = 0; i < v.size(); i++)
    {
        que.push(v[i]);
    }

    for (int i = 0; i < k; i++)
    {
        vector.push_back(que.top());
        que.pop();
    }

    return vector;
}

int main()
{
    vector<int> v = {7, 14, 10, 12, 2, 11, 29, 3, 4};
    int k = 3;

    cout << "median : " << compute_median(v) << endl;

    vector<int> vector = compute_k_closest(v, k);
    for (int i = 0; i < k; i++)
    {
        cout << "kClosest : " << vector[i] << endl;
    }

    return 0;
}