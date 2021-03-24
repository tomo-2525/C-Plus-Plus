// student ID: s1260032
#include <iostream>
#include <unordered_set>
#include <fstream>
using namespace std;

struct Point
{
    int x, y;
    Point() : x(0), y(0){};
    Point(const int &x, const int &y) : x(x), y(y){};
    Point(const Point &other)
    {
        x = other.x;
        y = other.y;
    };

    Point &operator=(const Point &other)
    {
        x = other.x;
        y = other.y;
        return *this;
    };

    bool operator==(const Point &other) const
    {
        if (x == other.x && y == other.y)
            return true;
        return false;
    };


    // this could be moved in to std::hash<Point>::operator()
    size_t operator()(const Point &pointToHash) const noexcept
    {
        size_t hash = pointToHash.x + 10 * pointToHash.y;
        return hash;
    };
};

namespace std
{
    template <>
    struct hash<Point>
    {
        std::size_t operator()(const Point &p) const noexcept
        {
            return p(p);
        }
    };
} // namespace std

int main(void)
{
    cout << "How to use: ./a.out < polint_list.txt" << endl << endl;
    // define the hash set for storing the point
    unordered_set<Point> table;

    ifstream in("point_list.txt");
    cout << "Reading points from file" << endl;
    while (!in.eof())
    {
        int x, y;
        in >> x >> y;

        Point p{x, y};
        table.insert(p);
    }
    cout << "Points read from file. Now enter some query point." << endl;

    while (cin)
    {
        int x, y;
        cin >> x >> y;
        Point p{x, y};
        // check if p is in the table,
        // if it is print "point found"
        // otherwise print "not found"

        // I want to use table.contain but I can not use it.
        if (table.count(p) == 1)
        {
            cout << "point found" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }

    }

    return 0;
}