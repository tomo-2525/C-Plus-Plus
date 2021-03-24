#ifndef MAT3X3_h
#define MAT3X3_h
#include <iostream>
using namespace std;

class Mat3x3
{
public:
    double Matrix[3][3];

    Mat3x3()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                    Matrix[i][j] = 1.0;
                else
                    Matrix[i][j] = 0.0;
            }
        }
    }

    explicit Mat3x3(double matrix[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Matrix[i][j] = matrix[i][j];
            }
        }
    }

    Mat3x3 operator+(const Mat3x3 &);
    Mat3x3 operator-(const Mat3x3 &);
    Mat3x3 operator-();
    Mat3x3 operator*(const Mat3x3 &);
    Mat3x3 &operator+=(const Mat3x3 &);
    Mat3x3 &operator-=(const Mat3x3 &);
    Mat3x3 &operator*=(const Mat3x3 &);
    double operator()(int, int);
    bool operator==(const Mat3x3 &);

    friend ostream &operator<<(ostream &, const Mat3x3&);
};
#endif //MAT3X3_h