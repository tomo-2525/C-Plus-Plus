//Student ID: s1260032
#include "MatNxN_template.h"
// C = A + B
template<typename T, int N>
MatNxN<T,N> MatNxN<T,N>::operator+(const MatNxN<T,N> &obj)
{
    MatNxN<T,N> mat_tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat_tmp.Matrix[i][j] = (this->Matrix[i][j]) + (obj.Matrix[i][j]);
        }
    }
    return mat_tmp;
}

// C = A - B
template<typename T, int N>
MatNxN<T,N> MatNxN<T,N>::operator-(const MatNxN<T,N> &obj)
{
    MatNxN<T,N> mat_tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat_tmp.Matrix[i][j] = (this->Matrix[i][j]) - (obj.Matrix[i][j]);
        }
    }
    return mat_tmp;
}

// A = -A
template<typename T, int N>
MatNxN<T,N> MatNxN<T,N>::operator-()
{
    MatNxN<T,N> mat_tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat_tmp.Matrix[i][j] = -(this->Matrix[i][j]);
        }
    }
    return mat_tmp;
}

// C = A * B
template<typename T, int N>
MatNxN<T,N> MatNxN<T,N>::operator*(const MatNxN<T,N> &obj)
{
    MatNxN<T,N> mat_tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat_tmp.Matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                mat_tmp.Matrix[i][j] += this->Matrix[i][k] * obj.Matrix[k][j];
            }
        }
    }
    return mat_tmp;
}

// A += B
template<typename T, int N>
MatNxN<T,N> &MatNxN<T,N>::operator+=(const MatNxN<T,N> &obj)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            this->Matrix[i][j] += obj.Matrix[i][j];
        }
    }
    return *this;
}

// A -= B
template<typename T, int N>
MatNxN<T,N> &MatNxN<T,N>::operator-=(const MatNxN<T,N> &obj)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            this->Matrix[i][j] -= obj.Matrix[i][j];
        }
    }
    return *this;
}

// A *= B
template<typename T, int N>
MatNxN<T,N> &MatNxN<T,N>::operator*=(const MatNxN<T,N> &obj)
{
    MatNxN<T,N> mat_tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat_tmp.Matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                mat_tmp.Matrix[i][j] += this->Matrix[i][k] * obj.Matrix[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            this->Matrix[i][j] = mat_tmp.Matrix[i][j];
        }
    }

    return *this;
}

// A == B
template<typename T, int N>
bool MatNxN<T,N>::operator==(const MatNxN<T,N> &obj)
{
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (this->Matrix[i][j] != obj.Matrix[i][j])
                flag = false;
        }
    }
    return flag;
}

// (function) call operator
// A(1,3) and so on..
template<typename T, int N>
T MatNxN<T,N>::operator()(const int i, const int j)
{
    return this->Matrix[i][j];
}

// << override
template<typename T, int N>
ostream &operator<<(ostream &os, const MatNxN<T,N> &m)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            os << m.Matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
