//Student ID: s1260032
#include <ostream>
#include <cassert>
#include "MatNxN_template.h"
#include "MatNxN_template.cpp"

using namespace std;

void print_mat(MatNxN<double,3> obj)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << obj.Matrix[i][j] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    MatNxN<double,3> A; // A = I
    double coefficients[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    MatNxN<double,3> B(coefficients);
    MatNxN<double,3> C = A * B;
    assert(C == B);

    C += B;
    C -= A;
    assert(C(0, 0) == 1.0);
    assert(C(1, 1) == 9.0);
    assert(C(2, 2) == 17.0);

    MatNxN<double,3> D = -A;
    assert(D(0, 0) == -1.0);
    assert(D(1, 1) == -1.0);
    assert(D(2, 2) == -1.0);

    cout << "Tests passed" << endl;
    cout << "impremented << operator\n" << B;
    return 0;
}