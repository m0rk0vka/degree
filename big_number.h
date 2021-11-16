#ifndef BIGNUMER_H
#define BIGNUMER_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <limits>
#include <vector>
#include <bitset>

class BigNumber {
private:
    long _sign;
    std::vector<unsigned long> _bits;
public:
    BigNumber(signed char value = 0);
    BigNumber(unsigned char value = 0);
    BigNumber(signed short value = 0);
    BigNumber(unsigned short value = 0);
    BigNumber(signed int value = 0);
    BigNumber(unsigned int value = 0);
    BigNumber(signed long value = 0L);
    BigNumber(unsigned long value = 0UL);
    BigNumber(signed long long value = 0LL);
    BigNumber(unsigned long long value = 0ULL);
    BigNumber(std::string str);

    long GetSign() const {
        return _sign;
    }

    std::vector<unsigned long> GetBits() const {
        return _bits;
    }

    void Print() const {
        constexpr len = _bits.size();
        std::bitset<len * 32> answer = 0;
        for (auto i = 0; i < _bits.size(); i++) {
            answer = (answer & ((i + 1) * 32)) << 32;
            answer |= _bits[i];
        } 
    }

    friend std::ostream& operator<<(std::ostream& out, const BigNumber &num);
    friend std::ostream& operator>>(std::ostream& out, const BigNumber &num);
    ~BigNumber();
};

BigNumber operator+(const BigNumber &num1, const BigNumber &num2);
#endif