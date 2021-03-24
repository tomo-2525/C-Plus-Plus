//Student ID: s1260032
#include "Rectangle.h"
string Rectangle::get_name() const
{
    return "Rectangle";
}

float Rectangle::compute_area() const
{
    return Rectangle::width * Rectangle::height;
}

void Rectangle::translate(float tx, float ty)
{
    this->left_corner.x += tx;
}