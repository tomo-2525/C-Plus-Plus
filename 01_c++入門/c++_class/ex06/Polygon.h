//Student ID: s1260032
#ifndef POLYGON_H
#define POLYGON_H
#include "Shape2D.h"
#include "Point2D.h"

class Polygon : public Shape2D
{
private:
    int N;
    Point2D *vertices;

public:
    Polygon(Point2D *_vertices, int _NUM_VERTICES) : vertices(_vertices), N(_NUM_VERTICES){};

    virtual string get_name() const;
    virtual float compute_area() const;
    virtual void translate(float, float);
};
#endif