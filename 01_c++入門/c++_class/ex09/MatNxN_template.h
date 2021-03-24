//Student ID: s1260032
#ifndef MatNxN_h
#define MatNxN_h
#include <iostream>
using namespace std;
template <typename T, int N>
class MatNxN
{
public:
    T Matrix[N][N];

    MatNxN()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    Matrix[i][j] = 1.0;
                else
                    Matrix[i][j] = 0.0;
            }
        }
    }

    explicit MatNxN(double matrix[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Matrix[i][j] = matrix[i][j];
            }
        }
    }

    MatNxN<T, N> operator+(const MatNxN<T, N> &);
    MatNxN<T, N> operator-(const MatNxN<T, N> &);
    MatNxN<T, N> operator-();
    MatNxN<T, N> operator*(const MatNxN<T, N> &);
    MatNxN<T, N> &operator+=(const MatNxN<T, N> &);
    MatNxN<T, N> &operator-=(const MatNxN<T, N> &);
    MatNxN<T, N> &operator*=(const MatNxN<T, N> &);
    T operator()(const int, const int);
    bool operator==(const MatNxN<T, N> &);
    template <typename A, int B> friend ostream &operator<<(ostream &, const MatNxN<A, B> &);
};
// template <typename T, int N>
// ostream &operator<<(ostream &, const MatNxN<T, N> &);
#endif //MatNxN_h