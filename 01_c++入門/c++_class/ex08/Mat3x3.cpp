#include "Mat3x3.h"

// C = A + B
Mat3x3 Mat3x3::operator+(const Mat3x3 &obj)
{
    Mat3x3 mat_tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat_tmp.Matrix[i][j] = (this->Matrix[i][j]) + (obj.Matrix[i][j]);
        }
    }
    return mat_tmp;
}

// C = A - B
Mat3x3 Mat3x3::operator-(const Mat3x3 &obj)
{
    Mat3x3 mat_tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat_tmp.Matrix[i][j] = (this->Matrix[i][j]) - (obj.Matrix[i][j]);
        }
    }
    return mat_tmp;
}

// A = -A
Mat3x3 Mat3x3::operator-()
{
    Mat3x3 mat_tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat_tmp.Matrix[i][j] = -(this->Matrix[i][j]);
        }
    }
    return mat_tmp;
}

// C = A * B
Mat3x3 Mat3x3::operator*(const Mat3x3 &obj)
{
    Mat3x3 mat_tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat_tmp.Matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                mat_tmp.Matrix[i][j] += this->Matrix[i][k] * obj.Matrix[k][j];
            }
        }
    }
    return mat_tmp;
}

// A += B
Mat3x3 &Mat3x3::operator+=(const Mat3x3 &obj)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->Matrix[i][j] += obj.Matrix[i][j];
        }
    }
    return *this;
}

// A -= B
Mat3x3 &Mat3x3::operator-=(const Mat3x3 &obj)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->Matrix[i][j] -= obj.Matrix[i][j];
        }
    }
    return *this;
}

// A *= B
Mat3x3 &Mat3x3::operator*=(const Mat3x3 &obj)
{
    Mat3x3 mat_tmp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat_tmp.Matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                mat_tmp.Matrix[i][j] += this->Matrix[i][k] * obj.Matrix[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->Matrix[i][j] = mat_tmp.Matrix[i][j];
        }
    }

    return *this;
}

// A == B
bool Mat3x3::operator==(const Mat3x3 &obj)
{
    bool flag = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->Matrix[i][j] != obj.Matrix[i][j])
                flag = false;
        }
    }
    return flag;
}

// (function) call operator
// A(1,3) and so on..
double Mat3x3::operator()(const int i, const int j)
{
    return this->Matrix[i][j];
}

// << override
ostream &operator<<(ostream &os, const Mat3x3 &m)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            os << m.Matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
