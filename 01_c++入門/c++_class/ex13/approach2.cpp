//Studemt ID: s1260032
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << ", ";
    });
    cout << endl;
}

double compute_median(vector<int> v)
{
    int mid = v.size() / 2;
    nth_element(v.begin(), v.begin() + mid, v.end());

    if (v.size() % 2 == 0)
    {
        return v[mid];
    }
    else
    {
        nth_element(v.begin(), v.begin() + mid - 1, v.end());
        return (v[mid] + v[mid + 1]) / 2;
    }
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

    nth_element(v.begin(), v.end() - k, v.end(), compare);

    vector<int> return_vector;
    for (int i = 1; i <= k; i++)
    {
        return_vector.push_back(*(v.end() - i));
    }
    return return_vector;
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