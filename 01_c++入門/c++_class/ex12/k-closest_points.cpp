//Student ID: s1260032
#include <iostream>
#include <vector>
#include <queue> //priority_queue
#include <cmath>

using namespace std;
struct Point
{
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

vector<Point> find_k_closest(int n, vector<Point> v)
{
    vector<Point> return_vector;
    auto compare = [](Point p1, Point p2) -> bool {
        double d1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2) + pow(p1.z, 2));
        double d2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2) + pow(p2.z, 2));
        return d1 > d2;
    };

    priority_queue<Point, vector<Point>, decltype(compare)> pq{compare};
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        return_vector.push_back(pq.top());
        pq.pop();
    }
    
    return return_vector;
}

int main()
{
    vector<Point> points;
    points.push_back(Point(1.0, 2.0, 3.0));
    points.push_back(Point(5.0, 5.0, 5.0));
    points.push_back(Point(0.0, 2.0, 1.0));
    points.push_back(Point(9.0, 2.0, 1.0));
    points.push_back(Point(1.0, 2.0, 1.0));
    points.push_back(Point(2.0, 2.0, 1.0));

    vector<Point> closest = find_k_closest(3, points);
    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << closest[i].x << "," << closest[i].y << ","
                  << closest[i].z << std::endl;
    }

    return 0;
}
