//Student ID: s1260032
#include "Circle.h"
string Circle::get_name() const
{
    return "Circle";
}

float Circle::compute_area() const
{
    const float PI = 3.141593f;
    return Circle::radius * Circle::radius * PI;
}

void Circle::translate(float tx, float ty)
{
    this->Circle::senter.x += tx;
    this->Circle::senter.y += ty;
}
