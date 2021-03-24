#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    mutable bool cache_valid;
    mutable string cache;

    string repr() const; // string representation private:
    void compute_cache() const;
};

string Date::repr() const
{
    if (!cache_valid)
    {
        compute_cache(); // fill mutable cache
        cache_valid = true;
    }
    return cache;
}

