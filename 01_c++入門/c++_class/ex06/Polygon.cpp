//Student ID: s1260032
#include "Polygon.h"
#include <iostream>

string Polygon::get_name() const
{
    return "Polygon";
}
float Polygon::compute_area() const
{
    float Area = 0;
    for (int i = 0; i < N; i++)
    {
        Area += (vertices[i].x * vertices[i + 1].y) - (vertices[i].y * vertices[i + 1].x);
    }
    // return Area / 2.0f;
    return Area;
}
void Polygon::translate(float tx, float ty)
{
    for (int i = 0; i < N; i++)
    {
        vertices[i].x += tx;
        vertices[i].y += ty;
    }
}