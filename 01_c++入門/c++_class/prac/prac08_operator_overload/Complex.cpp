#include <istream>
#include <ostream>
#include <sstream>
#include <cmath>
#include <cctype>
#include "Complex.h"

Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double re, double im) : real(re), imag(im) {}
Complex::~Complex() {}
double Complex::getReal() const { return real; }
double Complex::getImaginary() const { return imag; }
void Complex::setReal(double re) { real = re; }
void Complex::setImaginary(double im) { imag = im; }
Complex &Complex::operator+=(const Complex &other)
{
    real += other.real;
    imag += other.imag;
    return *this;
}
Complex &Complex::operator-=(const Complex &other)
{
    real -= other.real;
    imag -= other.imag;
    return *this;
}
Complex &Complex::operator/=(const Complex &other)
{
    // Complex division :
    // (a+bi)/(c+di) = {(ac + bd) + i(bc - ad)}/(cˆ2+dˆ2)
    double a = real;
    double b = imag;
    double c = other.real;
    double d = other.imag;
    double denom = c * c + d * d;
    double num_real = a * c + b * d;
    double num_imag = b * c - a * d;
    real = num_real / denom;
    imag = num_imag / denom;
    return *this;
}

Complex &Complex::operator*=(const Complex &other)
{
    double treal = this->real;
    double timag = this->imag;
    real = (treal * other.real - timag * other.imag);
    imag = (treal * other.imag + timag * other.real);
    return *this;
}

// Non member
Complex operator-(const Complex &c) { return Complex(-c.getReal(), -c.getImaginary()); }
Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c += c2;
    return c;
}
Complex operator-(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c -= c2;
    return c;
}
Complex operator/(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c /= c2;
    return c;
}
Complex operator*(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c *= c2;
    return c;
}

bool operator==(const Complex &c1, const Complex &c2)
{
    return (std::fabs(c1.getReal() - c2.getReal()) <= 1e-6) && (std ::fabs(c1.getImaginary() - c2.getImaginary()) <= 1e-6);
}

bool operator!=(const Complex &c1, const Complex &c2)
{
    return !(c1 == c2);
}

Complex conj(const Complex &c)
{
    return Complex(c.getReal(), -c.getImaginary());
}

double absSquare(const Complex &c)
{
    Complex ccbar = c * conj(c);
    return ccbar.getReal();
}
std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    std ::ostringstream s;
    s << '(' << c.getReal() << ',' << c.getImaginary() << ')';
    return os << s.str();
}

// Skip whitespace from an istream.
// The input istream is modified.
void remove_ws(std::istream &is)
{
    while (true)
    {
        char c = is.peek();
        if (isspace(c))
        {
            is.get();
        }
        else
        {
            break;
        }
    }
}

std::istream &operator>>(std::istream &is, Complex &ct)
{
    // extract trailing whitespaces
    remove_ws(is);
    // Either (real) or (real , imaginary)
    if (is.peek() == '(')
    {
        // consumme the character
        is.get();
        double r;
        is >> r;
        // Could not extract a double
        if (is.fail())
        {
            is.setstate(std::ios_base::failbit);
            return is;
        }

        // again skip whitespaces and get the next char
        remove_ws(is);
        char c = is.peek();
        // either ’ , ’ or ’) ’ otherwise an error
        if (c == ',')
        {
            // consumme the character
            is.get();
            // get the imaginary part
            double im;
            is >> im;
            if (is.fail())
            {
                is.setstate(std::ios_base::failbit);
                return is;
            }
            // skip whitespaces
            remove_ws(is);
            // next character should be ’) ’
            if (is.peek() == ')')
            { // consumme
                is.get();
                // ( real , imaginary )
                ct = Complex(r, im);
            }
            else
            {
                is.setstate(std::ios_base::failbit);
            }
        }
        else if (c == ')')
        {
            // We are in the case (real)
            is.get();
            ct = Complex(r, 0);
        }
        else
        {
            // or in an error state
            is.setstate(std::ios_base::failbit);
        }
    }
    else
    {
        // real
        double r;
        is >> r;
        if (!is.fail())
        {
            ct = Complex(r, 0);
        }
        else
        {
            is.setstate(std::ios_base::failbit);
        }
    }
    return is;
}