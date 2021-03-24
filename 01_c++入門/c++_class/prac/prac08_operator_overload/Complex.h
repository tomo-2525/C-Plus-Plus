#include <iostream>
#include <string>
#include <istream>
#include <ostream>

#ifndef COMPLEXH
#define COMPLEXH

class Complex
{
public:
    // Default constructor . Construct the complex : 0 + 0. i
    Complex();
    // Construct a complex from its given real and imaginary parts
    Complex(double re, double im);
    // Destructor
    ~Complex();

    // Accessors
    double getReal() const;
    double getImaginary() const;
    void setReal(double re);
    void setImaginary(double im);

    // Operations
    // Implement the compound assignment operators for complex arithmetic

    Complex &operator+=(const Complex &other);
    Complex &operator-=(const Complex &other);
    Complex &operator/=(const Complex &other);
    Complex &operator*=(const Complex &other);

private:
    double real;
    double imag;
};

// Non−member functions
// Unary operations
Complex operator- (const Complex &c);

// Binary arithmetic operations
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator- (const Complex &c1, const Complex &c2);
Complex operator* (const Complex &c1, const Complex &c2);
Complex operator/(const Complex &c1, const Complex &c2);

// Check equality of two complex numbers.
// We will assume that two complex numbers are equal if they agree

// up to a tolerance of 1e−6.
bool operator==(const Complex &c1, const Complex &c2);
bool operator!=(const Complex &c1, const Complex &c2);

// Return the conjugate of a complex number
Complex conj(const Complex &c);

// Return the absolute square of a complex number
double absSquare(const Complex &c);

// Serialization
// Write a complex number to a stream in the form:
// ( real , imaginary )
std::ostream &operator<<(std::ostream &os, const Complex &c);

// Read a complex number from a stream in one of the following forms:
// real
// (real)
// ( real , imaginary )
// The input for real and imaginary should be convertible to T.
// If an error occurs during extraction, it should set the stream
// state to ios base :: failbit by using the method std :: istream :: setstate () .
std ::istream &operator>>(std ::istream &is, Complex &c);
#endif