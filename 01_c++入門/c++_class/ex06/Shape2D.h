//Student ID: s1260032
#ifndef SHAPE2D_CPP
#define SHAPE2D_CPP
#include <string>
#include <cmath>
#include <cassert>
using namespace std;
class Shape2D
{
public:
    virtual string get_name() const { return NULL; }
    virtual float compute_area() const { return 0; }
    virtual void translate(float, float) {}
};

inline void assertFloat(float x, float y, float eps = 1e-5)
{
    assert(std::fabs(x - y) < eps);
}
#endif