#include <iostream>
#include <string>
#include <sstream>
#include "Complex.cpp"

using std::cout;
using std::endl;
void testComplex();
int main(void)
{
    testComplex();
    return 0;
}

inline void check(bool expr)
{
    if (!expr)
        cout << "Failed" << endl;
}
void testComplex()
{
    // Test the constructors
    Complex c1;
    check(c1 == Complex(0.0, 0.0));
    Complex c2(1.0, 2.0);
    check(c2 == Complex(1.0, 2.0));
    Complex c3(2.0, 3.0);
    Complex c4(3.0, 5.0);
    // Test the accessors
    check(c1.getReal() == 0.0);
    check(c2.getImaginary() == 2.0);
    // Test the operations
    Complex temp = c1;
    temp += c2;
    check(temp == c2);
    temp -= c3;
    check(temp == Complex(-1.0, -1.0));
    temp = c2;
    temp /= c3;
    check(temp == Complex(0.615385, 0.0769231));
    temp = c2;
    temp *= c3;
    check(temp == Complex(-4.0, 7.0));
    // Non-member operations
    check(-c2 == Complex(-1.0, -2.0));
    check((c1 + c2) == c2);
    check((c2 - c3) == Complex(-1.0, -1.0));
    check((c2 / c3) == Complex(0.615385, 0.0769231));
    check((c2 * c3) == Complex(-4.0, 7.0));
    check(conj(c2) == Complex(1.0, -2.0));
    check(absSquare(c3) == 13.0);
    
    // Serialization
    std ::ostringstream os;
    os << c1;
    check(os.str() == "(0, 0)");
    std ::ostringstream os2;
    os2 << c2;
    check(os2.str() == "(1, 2)");
    std::istringstream is("(1, 2)");
    Complex c5;
    is >> c5;
    check(c5 == Complex(1.0, 2.0));
    std::istringstream is2("1");
    is2 >> c5;
    check(c5 == Complex(1.0, 0.0));
    std ::istringstream is3("(1)");
    is3 >> c5;
    check(c5 == Complex(1.0, 0.0));
    std ::istringstream is4("(    1   ,   3  )");
    is4 >> c5;
    check(c5 == Complex(1.0, 3.0));
    std ::ostringstream os3;
    os3 << c1 << " " << c5;
    std::istringstream is5(os3.str());
    Complex c6, c7;
    is5 >> c6;
    check(c6 == Complex(0.0, 0.0));
    is5 >> c7;
    check(c7 == Complex(1.0, 3.0));
}