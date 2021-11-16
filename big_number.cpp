#include "bignumber.h"


BigNumber::BigNumber(signed char value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(unsigned char value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(signed short value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(unsigned short value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(signed int value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(unsigned int value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(signed long value) : _sign((long) value) {
    _bits = std::vector<unsigned long> ();
}

BigNumber::BigNumber(unsigned long value){
    if (value <= (unsigned long) INT_MAX) {
        _sign = (long) value;
        _bits = std::vector<unsigned long> ();
    } else {
        _sign = 1;
        _bits = std::vector<unsigned long> ();
        _bits.push_back(value);
    }
}

BigNumber::BigNumber(long long value) {
    if (value >= (long long) INT_MIN && value <= (long long) INT_MAX) {
        _sign = (long) value;
        _bits = std::vector<unsigned long> ();
    } else {
        unsigned long long number;

        if (value < 0LL) {
            number = (unsigned long long) -value;
            _sign = -1L;
        } else {
            number = (unsigned long long) value;
            _sign = 1L;
        }

        _bits = std::vector<unsigned long> ();
        _bits.push_back((unsigned long) (number & 0xffffffff));
        _bits.push_back((unsigned long) (number >> 32));
    }
}

BigNumber::BigNumber(unsigned long long value) {
    if (value <= (unsigned long long) INT_MAX) {
        _sign = (long) value;
        _bits = std::vector<unsigned long> ();
    } else {
        _sign = 1L;
        _bits = std::vector<unsigned long> ();
        unsigned long long number = value;
        _bits.push_back((unsigned long) (number & 0xffffffff));
        _bits.push_back((unsigned long) (number >> 32));
    }
}

BigNumber operator+(const BigNumber &num1, const BigNumber &num2) {
    long sign1 = num1.GetSign();
    long sign2 = num2.GetSign();

    std::vector<unsigned long> bits1 = num1.GetBits();
    std::vector<unsigned long> bits2 = num2.GetBits();
    std::cout << "sign1 = " << sign1 << std::endl;
    std::cout << "sign2 = " << sign2 << std::endl;
    if ((sign1 == -1 || sign1 == 1) && (sign2 == -1 || sign2 == 1)) {
        long long i = 0;

        long sign;
        std::vector<unsigned long> bits;

        long long remainder = 0;
        unsigned long bit = 0;
        while (i < bits1.size() && i < bits2.size()) {
            long long resault = (long long) (sign1 * bits1[i]) + (long long) (sign2 * bits2[i]);

            if (resault < 0LL) {
                sign = -1;
                resault = -resault;
            } else {
                sign = 1;
            }

            bit = (unsigned long) ((resault + remainder) & 0xffffffff);
            remainder = (unsigned long) ((resault + remainder) >> 32);
            bits.push_back(bit);
            i++;
        }

        while (i < bits1.size()) {
            bits.push_back(bits1[i]);
            i++;
        }

        while (i < bits2.size()) {
            bits.push_back(bits2[i]);
            i++;
        }
    }

    return BigNumber(100);
}


BigNumber::~BigNumber() {
}

std::ostream& operator << (std::ostream &out, const BigNumber &num) {
    if (num._sign == -1L) {
        out << "-";
    } else {
        if (num._sign == 1L) {
            for (int i = 0; i < num._bits.size(); i++) {
                out << num._bits[i];
            }
        } else {
            out << num._sign;
        }
    }

    return out;
}

BigNumber::Print() {
    
}