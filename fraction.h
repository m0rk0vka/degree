#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <cassert>
#include <iostream>
#include "big_number.h"

using namespace std;

namespace frac {
    BigNumber gcd(BigNumber, BigNumber);
    BigNumber lcm(BigNumber, BigNumber);
    int sgn(BigNumber);
}

class Fraction {
private:
    BigNumber m_numerator;
    BigNumber m_denominator;
    int m_sign;
public:
    Fraction();
    Fraction(BigNumber numerator, BigNumber denominator);
 
    void Reduce();

    BigNumber GetNumerator() const;
    BigNumber GetDenominator() const;
    Fraction Reverse();
    Fraction operator-();
    Fraction operator+();
    bool operator!() const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f);    
    friend std::istream& operator>>(std::istream& in, Fraction &f);
    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);
    friend bool operator<=(const Fraction &f1, const Fraction &f2);
    friend bool operator>=(const Fraction &f1, const Fraction &f2);
    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator>(const Fraction &f1, const Fraction &f2);
    
    Fraction& operator += (const Fraction &f2);
    Fraction& operator -= (const Fraction &f2);
    Fraction& operator *= (const Fraction &f2);
    Fraction& operator /= (const Fraction &f2);
};



Fraction operator+(const Fraction &f1, const Fraction &f2);
Fraction operator+(BigNumber value, const Fraction &f);
Fraction operator-(BigNumber value, const Fraction &f);
Fraction operator+(const Fraction &f, BigNumber value);
Fraction operator-(const Fraction &f, BigNumber value);
Fraction operator-(const Fraction &f1, const Fraction &f2);
Fraction operator*(const Fraction &f1, const Fraction &f2);
Fraction operator*(BigNumber value, const Fraction &f);
Fraction operator*(const Fraction &f, BigNumber value);
Fraction Pow(const Fraction &f, BigNumber value);
Fraction operator/(const Fraction &f1, const Fraction &f2);
Fraction operator/(const Fraction &f, BigNumber value);
Fraction operator/(BigNumber value, const Fraction &f);

#endif