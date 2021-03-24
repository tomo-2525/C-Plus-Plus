//Student ID: s1260032
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape2D.h"
#include "Point2D.h"
class Rectangle : public Shape2D
{
private:
    Point2D left_corner;
    float width, height;

public:
    Rectangle(Point2D left_corner, float width, float height)
        : left_corner(left_corner), width(width), height(height){}
    virtual string get_name() const;
    virtual float compute_area() const;
    virtual void translate(float, float);
};
#endif