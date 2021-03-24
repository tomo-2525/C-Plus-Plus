//Studemt ID: s1260032
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

double compute_median(vector<int> v)
{
    int mid = v.size() / 2;
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0)
        return (v[mid] + v[mid + 1]) / 2;
    else
        return v[mid];
}

vector<int> compute_k_closest(vector<int> v, int k)
{
    double mid = compute_median(v);
    auto compare = [mid](int i, int j) -> bool {
        if (abs(i - mid) > abs(j - mid))
            return true;
        else
            return false;
    };
    priority_queue<int, vector<int>, decltype(compare)> pq{compare};
    
    vector<int> return_vector;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }

    for (int i = 0; i < k; i++)
    {
        return_vector.push_back(pq.top());
        pq.pop();
    }

    return return_vector;
}

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {7, 14, 10, 12, 2, 11, 29, 3, 4};
    int k = 3;
    cout << "median = " << compute_median(v) << endl;
    cout << "k_closest = ";
    print_vector(compute_k_closest(v, k));
    return 0;
}