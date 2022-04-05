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
    BigNumber abs(BigNumber);
}

class Fraction {
private:
    int _sign;
    BigNumber _numerator;
    BigNumber _denominator;
public:
    Fraction();
    Fraction(BigNumber, BigNumber);
    Fraction(int, BigNumber, BigNumber);
 
    void Reduce();

    BigNumber GetNumerator() const;
    BigNumber GetDenominator() const;
    int GetSign() const;
    Fraction Reverse();
    Fraction operator-();
    Fraction operator+();
    bool operator!() const;

    friend std::ostream& operator<<(std::ostream&, const Fraction &);    
    friend std::istream& operator>>(std::istream&, Fraction &);
    friend bool operator==(const Fraction &, const Fraction &);
    friend bool operator!=(const Fraction &, const Fraction &);
    friend bool operator<=(const Fraction &, const Fraction &);
    friend bool operator>=(const Fraction &, const Fraction &);
    friend bool operator<(const Fraction &, const Fraction &);
    friend bool operator>(const Fraction &, const Fraction &);
    
    Fraction& operator += (const Fraction &);
    Fraction& operator -= (const Fraction &);
    Fraction& operator *= (const Fraction &);
    Fraction& operator /= (const Fraction &);
};



Fraction operator+(const Fraction &, const Fraction &);
Fraction operator+(BigNumber, const Fraction &);
Fraction operator-(BigNumber, const Fraction &);
Fraction operator+(const Fraction &, BigNumber);
Fraction operator-(const Fraction &, BigNumber);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator*(BigNumber, const Fraction &);
Fraction operator*(const Fraction &, BigNumber);
Fraction Pow(const Fraction &, BigNumber);
Fraction operator/(const Fraction &, const Fraction&);
Fraction operator/(const Fraction &, BigNumber);
Fraction operator/(BigNumber, const Fraction &);

#endif