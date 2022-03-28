#ifndef BIGNUMER_H
#define BIGNUMER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <limits>
#include <vector>
#include <typeinfo>
#include "str.h"

class BigNumber {
private:
    long _sign;
    std::vector<unsigned long> _bits;
public:
    BigNumber();
    BigNumber(signed char value);
    BigNumber(unsigned char value);
    BigNumber(signed short value);
    BigNumber(unsigned short value);
    BigNumber(signed int value);
    BigNumber(unsigned int value);
    BigNumber(signed long value);
    BigNumber(unsigned long value);
    BigNumber(signed long long value);
    BigNumber(unsigned long long value);
    BigNumber(long sign, std::vector<unsigned long> bits);

    long GetSign() const {
        return _sign;
    }

    std::vector<unsigned long> GetBits() const {
        return _bits;
    }

    BigNumber operator-();
    BigNumber operator+();

    BigNumber& operator += (const BigNumber&);
    BigNumber& operator -= (const BigNumber&);
    BigNumber& operator /= (const BigNumber&);
    BigNumber& operator *= (const BigNumber&);

    friend std::ostream& operator<<(std::ostream&, const BigNumber&);
    friend std::istream& operator>>(std::istream&, BigNumber&);
    ~BigNumber();
};

BigNumber operator+(const BigNumber&, const BigNumber&);
BigNumber operator-(const BigNumber&, const BigNumber&);
BigNumber operator*(const BigNumber&, const long&);
BigNumber operator*(const long&, const BigNumber&);
BigNumber operator*(const BigNumber&, const unsigned long&);
BigNumber operator*(const unsigned long&, const BigNumber&);
BigNumber operator*(const BigNumber&, const BigNumber&);
std::pair<BigNumber, BigNumber> operator/(const BigNumber&, const BigNumber&);
BigNumber operator%(const BigNumber&, const BigNumber&);
std::pair<BigNumber, BigNumber> operator/(const BigNumber&, const unsigned long&);
bool operator>(const BigNumber&, const BigNumber&);
bool operator<(const BigNumber&, const BigNumber&);
bool operator<=(const BigNumber&, const BigNumber&);
bool operator>=(const BigNumber&, const BigNumber&);
bool operator==(const BigNumber&, const BigNumber&);
bool operator!=(const BigNumber&, const BigNumber&);
#endif