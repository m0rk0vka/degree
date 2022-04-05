#include "big_number.h"

BigNumber::BigNumber() : _sign(0L), _bits(std::vector<unsigned long> ()) {
}

BigNumber::BigNumber(signed char value) : _sign((long) value), _bits(std::vector<unsigned long> ()) {
}

BigNumber::BigNumber(long sign, std::vector<unsigned long> bits) {
    if ((bits.size() == 1) && (bits[0] <= (unsigned long) (INT_MAX))) {
        _sign = sign * bits[0];
        _bits.clear();
        _bits = std::vector<unsigned long> ();
    } else {
        if (bits.size() > 0) {
            while(bits[bits.size() - 1] == 0UL) {
                bits.erase(bits.end() - 1);
                if (bits.size() == 0) {
                    break;
                }
            }

            if (bits.size() == 0) {
                _sign = 0;
                _bits = bits;
            } else {
                _sign = sign;
                _bits = bits;
            }
        } else {
            _sign = sign;
            _bits = std::vector<unsigned long> ();
        }
    }
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

BigNumber::BigNumber(signed long long value) {
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

        if ((unsigned long) (number >> 32) != 0UL) {
            _bits.push_back((unsigned long) (number >> 32));
        }
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
        if ((unsigned long) (number >> 32) != 0UL) {
            _bits.push_back((unsigned long) (number >> 32));
        }
    }
}

BigNumber operator+(const BigNumber &num1, const BigNumber &num2) {
    long sign1 = num1.GetSign();
    long sign2 = num2.GetSign();

    std::vector<unsigned long> bits1 = num1.GetBits();
    std::vector<unsigned long> bits2 = num2.GetBits();

    if ((sign1 == -1) && (sign2 == -1)) {
        return (BigNumber(1, bits1) + BigNumber(1, bits2)) * BigNumber(-1);
    }

    if ((sign1 == -1) && (sign2 == 1)) {
        return BigNumber(1, bits2) - BigNumber(1, bits1);
    }

    if ((sign1 == 1) && (sign2 == -1)) {
        return BigNumber(1, bits1) - BigNumber(1, bits2);
    }

    if (bits1.size() == 0) {
        bits1.push_back((unsigned long) sign1);
    }

    if (bits2.size() == 0) {
        bits2.push_back((unsigned long) sign2);
    }


    std::vector<unsigned long> bits;

    unsigned long long i = 0;

    unsigned long long remainder = 0;
    unsigned long bit = 0;
    while ((i < bits1.size()) && (i < bits2.size())) {
        unsigned long long resault = (unsigned long long) (bits1[i]) + (unsigned long long) (bits2[i]) + remainder;

        bit = (unsigned long) (resault & 0xffffffff);
        remainder = (unsigned long long) (resault >> 32);
        bits.push_back(bit);
        i++;
    }

    while (i < bits1.size()) {
        unsigned long long resault = (unsigned long long) (bits1[i]) + remainder;

        bit = (unsigned long) (resault & 0xffffffff);
        remainder = (unsigned long long) (resault >> 32);
        bits.push_back(bit);
        i++;
    }

    while (i < bits2.size()) {
        unsigned long long resault = (unsigned long long) (bits2[i]) + remainder;

        bit = (unsigned long) (resault & 0xffffffff);
        remainder = (unsigned long long) (resault >> 32);
        bits.push_back(bit);
        i++;
    }

    if (remainder != 0) {
        bits.push_back((unsigned long) remainder);
    }

    while(bits[bits.size() - 1] == 0UL) {
        bits.erase(bits.end() - 1);
        if (bits.size() == 0) {
            return BigNumber(0);
        }
    }
    return BigNumber(1, bits);
}


BigNumber operator-(const BigNumber &num1, const BigNumber &num2) {
    long sign1 = num1.GetSign();
    long sign2 = num2.GetSign();

    std::vector<unsigned long> bits1 = num1.GetBits();
    std::vector<unsigned long> bits2 = num2.GetBits();

    if ((sign1 == -1) && (sign2 == 1)) {
        return (BigNumber(1, bits2) + BigNumber(1, bits1)) * BigNumber(-1);
    }

    if ((sign1 == 1) && (sign2 == -1)) {
        return BigNumber(1, bits1) + BigNumber(1, bits2);
    }

    if ((sign1 == -1) && (sign2 == -1)) {
        return BigNumber(1, bits2) - BigNumber(1, bits1);
    }

    if (num1 < num2) {
        return (num2 - num1) * BigNumber(-1);
    }

    if (bits1.size() == 0) {
        bits1.push_back((unsigned long) sign1);
    }

    if (bits2.size() == 0) {
        bits2.push_back((unsigned long) sign2);
    }

    unsigned long long i = 0;

    unsigned long long remainder = 0;
    unsigned long bit = 0;
    unsigned long long resault = 0;

    std::vector<unsigned long> bits;

    while (i < bits2.size()) {
        if (bits1[i] >= bits2[i] + remainder) {
            resault = (unsigned long long) (bits1[i]) - (unsigned long long) (bits2[i]) - remainder;
            remainder = 0ULL;
        } else {
            resault = ((unsigned long long) (UINT_MAX) + 1) + (unsigned long long) (bits1[i]) - (long long) (bits2[i]) - remainder;
            remainder = 1ULL;
        }

        bit = (unsigned long) (resault & 0xffffffff);
        bits.push_back(bit);
        i++;
    }

    while(i < bits1.size()) {
        if (bits1[i] >= remainder) {
            resault = (unsigned long long) (bits1[i]) - remainder;
            remainder = 0;
        } else {
            resault = ((unsigned long long) (UINT_MAX) + 1) + (unsigned long long) (bits1[i]) - remainder;
            remainder += 1;
        }

        bit = (unsigned long) (resault & 0xffffffff);
        bits.push_back(bit);
        i++;
    }

    while(bits[bits.size() - 1] == 0UL) {
        bits.erase(bits.end() - 1);
        if (bits.size() == 0) {
            return BigNumber(0);
        }
    }

    return BigNumber(1, bits);
}

BigNumber operator*(const BigNumber& num, const long& val) {
        long sign = num.GetSign();
        std::vector<unsigned long> bits = num.GetBits();

        if (bits.size() == 0) {
            return BigNumber((long long) (sign) * (long long) (val));
        }

        unsigned long value = 0UL;
        if (val < 0L) {
            sign = sign * (-1);
            value = (unsigned long) (-(long long)(val));
        } else {
            value = (unsigned long) (val);
        }

        return BigNumber(sign, bits) * value;
}

BigNumber operator*(const long& val, const BigNumber& num) {
    return num * val;
}

BigNumber operator*(const BigNumber& num, const unsigned long& val) {
        long sign = num.GetSign();
        std::vector<unsigned long> bits = num.GetBits();

        if (bits.size() == 0) {
            return BigNumber((long long) (sign) * (long long) (val));
        }

        unsigned long long remainder = 0ULL;
        unsigned long long resault = 0ULL;

        for (int i = 0; i < bits.size(); i++) {
            resault = (unsigned long long) (bits[i]) * (unsigned long long) (val) + remainder;
            
            bits[i] = (unsigned long) (resault & 0xffffffff);
            remainder = (unsigned long long)(resault >> 32);
        }

        if (remainder != 0ULL) {
            bits.push_back((unsigned long) remainder);
        }

        while(bits[bits.size() - 1] == 0UL) {
            bits.erase(bits.end() - 1);
            if (bits.size() == 0) {
                return BigNumber(0);
            }
        }

        return BigNumber(sign, bits);
}

BigNumber operator*(const unsigned long& val, const BigNumber& num) {
    return num * val;
}

BigNumber operator*(const BigNumber& num1, const BigNumber& num2) {
    long sign1 = num1.GetSign();
    std::vector<unsigned long> bits1 = num1.GetBits();
    long sign2 = num2.GetSign();
    std::vector<unsigned long> bits2 = num2.GetBits();

    if (bits1.size() == 0) {
        return sign1 * num2;
    }

    if (bits2.size() == 0) {
        return num1 * sign2;
    }

    if (num1 > num2) {
        return num2 * num1;
    }

    long sign = sign1 * sign2;

    std::vector<BigNumber> tempMult = {};
    std::vector<unsigned long> tempZero = {};
    for (auto el : bits1) {
        BigNumber tempBigNumber = el * num2;
        std::vector<unsigned long> tempBits = tempBigNumber.GetBits();
        for (auto elem : tempZero) {
            auto beg = tempBits.cbegin();
            tempBits.insert(beg, elem);
        }
        tempMult.push_back(BigNumber(1L, tempBits));
        tempZero.push_back(0UL);
    }
    
    BigNumber tempSum = tempMult[0];
    for (int i = 1; i < tempMult.size(); i++) {
        tempSum = tempSum + tempMult[i];
    }

    std::vector<unsigned long> bits = tempSum.GetBits();

    while(bits[bits.size() - 1] == 0UL) {
        bits.erase(bits.end() - 1);
        if (bits.size() == 0) {
            return BigNumber(0);
        }
    }

    return BigNumber(sign, bits);
}

std::pair<BigNumber, BigNumber> operator/(const BigNumber& num, const unsigned long& val) {
    assert(val != 0);
    
    long sign = num.GetSign();
    std::vector<unsigned long> bits = num.GetBits();

    if (bits.size() == 0) {
        return std::pair<BigNumber, BigNumber> (BigNumber((unsigned long) (sign) / val), (unsigned long) (sign) % val);
    }

    if (val == 1UL) {
        return std::pair<BigNumber, BigNumber> (num, BigNumber(0));
    }

    if (val == 2UL) {
        if (bits.size() == 0) {
            return std::pair<BigNumber, BigNumber> (BigNumber(sign / 2), BigNumber(sign % 2));
        }

        long long i = bits.size() - 1;

        unsigned long base_2_in_31 = ((unsigned long) (UINT_MAX) + 1) / 2;
        
        unsigned long remainder = 0UL;

        while (i >= 0) {
            if (bits[i] % 2 == 0) {
                bits[i] /= 2;
                bits[i] += remainder;
                remainder = 0UL;
            } else {
                bits[i] -= 1;
                bits[i] /= 2;
                bits[i] += remainder;
                remainder = base_2_in_31;
            }
            i--;
        }
        
        while(bits[bits.size() - 1] == 0UL) {
            bits.erase(bits.end() - 1);
        }

        return std::pair<BigNumber, BigNumber> (BigNumber(sign, bits), BigNumber(remainder != 0UL));
    }

    BigNumber left = BigNumber(1);
    BigNumber right = num + BigNumber(1);

    while (left + 1 != right) {
        BigNumber middle = ((left + right) / 2).first;
        if (middle * val < num) {
            left = middle;
        } else {
            if (middle * val > num) {
                right = middle;
            } else {
                return std::pair<BigNumber, BigNumber> (middle, BigNumber(0));
            }
        }
    }
    
    return std::pair<BigNumber, BigNumber> (left, num - left * val);
};

std::pair<BigNumber, BigNumber> operator/(const BigNumber& num1, const BigNumber& num2) {
    long sign1 = num1.GetSign();
    std::vector<unsigned long> bits1 = num1.GetBits();
    long sign2 = num2.GetSign();
    std::vector<unsigned long> bits2 = num2.GetBits();

    if (bits2.size() == 0) {
        if (bits1.size() == 0) {
            assert(sign2 != 0);
            return std::pair<BigNumber, BigNumber> (BigNumber(sign1 / sign2), BigNumber(sign1 % sign2));
        }

        if (sign2 < 0) {
            sign1 *= -1;
        }

        std::pair<BigNumber, BigNumber> temp = num1 / ((unsigned long)(sign2));

        return std::pair<BigNumber, BigNumber> (BigNumber(sign1) * temp.first, temp.second);
    }

    long sign = sign1 * sign2;

    BigNumber temp1, temp2;

    if (sign1 < 0L) {
        temp1 = num1 * BigNumber(-1);
    } else {
        temp1 = num1;
    }

    if (sign2 < 0L) {
        temp2 = num2 * BigNumber(-1);
    } else {
        temp2 = num2;
    }

    if (temp1 < temp2) {
        return std::pair<BigNumber, BigNumber> (BigNumber(0), temp1);
    }

    if (temp1 == temp2) {
        return std::pair<BigNumber, BigNumber> (BigNumber(1 * sign), BigNumber(0));   
    }

    BigNumber left = BigNumber(1);
    BigNumber right = temp1 + BigNumber(1);

    while (left + BigNumber(1) != right) {
        BigNumber middle = ((left + right) / 2).first;
        if (middle * temp2 < temp1) {
            left = middle;
        } else {
            if (middle * temp2 > temp1) {
                right = middle;
            } else {
                return std::pair<BigNumber, BigNumber> (BigNumber(sign) * middle, BigNumber(0));
            }
        }
    }

    BigNumber ans = left;

    return std::pair<BigNumber, BigNumber> (BigNumber(sign) * ans, temp1 - ans * temp2);
};

bool operator>(const BigNumber& num1, const BigNumber& num2) {
    long sign1 = num1.GetSign();
    long sign2 = num2.GetSign();

    std::vector<unsigned long> bits1 = num1.GetBits();
    std::vector<unsigned long> bits2 = num2.GetBits();
    
    if (bits1.size() == 0) {
        if (sign1 < 0L) {
            bits1.push_back((unsigned long) sign1);
            sign1 = -1;
        } else {
            bits1.push_back((unsigned long) sign1);
            sign1 = 1;
        }
    }

    if (bits2.size() == 0) {
        if (sign2 < 0L) {
            bits2.push_back((unsigned long) sign2);
            sign2 = -1;
        } else {
            bits2.push_back((unsigned long) sign2);
            sign2 = 1;
        }
    }

    if ((sign1 == -1) && (sign2 == 1)) {
        return false;
    }

    if ((sign1 == 1) && (sign2 == -1)) {
        return true;
    }

    if (bits1.size() > bits2.size()) {
        return sign1 == 1;
    }

    if (bits1.size() < bits2.size()) {
        return sign1 == -1;
    }

    long long i = bits1.size() - 1;

    while(i >= 0) {
        if (bits1[i] > bits2[i]) {
            return sign1 == 1;
        }

        if (bits1[i] < bits2[i]) {
            return sign1 == -1;
        }

        i--;
    }

    return false;
}

bool operator<(const BigNumber& num1, const BigNumber& num2) {
    return num2 > num1;
}

bool operator<=(const BigNumber& num1, const BigNumber& num2) {
    return !(num1 > num2);
}

bool operator>=(const BigNumber& num1, const BigNumber& num2) {
    return !(num2 > num1);
}

bool operator==(const BigNumber& num1, const BigNumber& num2) {
    long sign1 = num1.GetSign();
    std::vector<unsigned long> bits1 = num1.GetBits();
    long sign2 = num2.GetSign();
    std::vector<unsigned long> bits2 = num2.GetBits();

    if (bits1.size() != bits2.size()) {
        return false;
    }

    if (bits1.size() == 0) {
        return sign1 == sign2;
    }

    if (sign1 != sign2) {
        return false;
    }

    unsigned long i = 0UL;

    while (i != bits1.size()) {
        if (bits1[i] != bits2[i]) {
            return false;
        }

        i++;
    }

    return true;
}

bool operator!=(const BigNumber& num1, const BigNumber& num2) {
    return !(num1 == num2);
}

BigNumber BigNumber::operator+() {
    return BigNumber(_sign, _bits);
}

BigNumber BigNumber::operator-() {
    return BigNumber(-_sign, _bits);
}

BigNumber& BigNumber::operator+=(const BigNumber& num2) {
    BigNumber num1 = BigNumber(_sign, _bits);
    
    _sign = (num1 + num2).GetSign();
    _bits = (num1 + num2).GetBits();

    return *this;
}

BigNumber& BigNumber::operator-=(const BigNumber& num2) {
    BigNumber num1 = BigNumber(_sign, _bits);
    
    _sign = (num1 - num2).GetSign();
    _bits = (num1 - num2).GetBits();

    return *this;
}

BigNumber& BigNumber::operator*=(const BigNumber& num2) {
    BigNumber num1 = BigNumber(_sign, _bits);
    
    _sign = (num1 * num2).GetSign();
    _bits = (num1 * num2).GetBits();

    return *this;
}

BigNumber& BigNumber::operator/=(const BigNumber& num2) {
    BigNumber num1 = BigNumber(_sign, _bits);
    
    _sign = (num1 / num2).first.GetSign();
    _bits = (num1 / num2).first.GetBits();

    return *this;
}

BigNumber operator%(const BigNumber& num1, const BigNumber& num2) {
    return (num1 / num2).second;
}

BigNumber::~BigNumber() {
}

std::ostream& operator << (std::ostream& out, const BigNumber& num) {
    if (num._bits.size() == 0) {
        out << num._sign;
    } else {
        if (num._sign == -1L) {
            out << "-";
        }

        std::string ans = str::itoa(num._bits[0]);
        std::string base = str::itoa((unsigned long long)(UINT_MAX) + 1);
        for (int i = 1; i < num._bits.size(); i++) {
            ans = str::sum(ans, str::mult(str::itoa(num._bits[i]),base));
            base = str::mult(base, str::itoa((unsigned long long) (UINT_MAX) + 1));
        }
        out << ans;
    }

    return out;
}

std::istream& operator>> (std::istream& in, BigNumber& num) {
    using namespace str;

    char c;

    in.get(c);
    std::string number = "";

    long sign = 1L;
    if (c == '-') {
        sign *= (-1);
    } else {
        number += c;
    }

    in.get(c);
    while (std::isdigit(c)) {
        number += c;
        in.get(c);
    }

    if (c != ' ' && c != '\n') {
        in.putback(c);
    }
    
    std::string to_long = str::itoa((unsigned long) (INT_MAX));

    if (number < to_long) {
        num._sign = sign * (unsigned long) (atoi(number.c_str()));
    } else {
        num._sign = sign;
        std::vector<unsigned long> bits = {};

        std::string base = str::itoa((unsigned long) (UINT_MAX) + 1);

        std::pair<std::string, std::string> temp = division(number, base);
        std::string remainder = temp.second;
        number = temp.first;
        bits.push_back(atoi(remainder));
        while(number >= base) {
            temp = division(number, base);
            remainder = temp.second;
            number = temp.first;
            bits.push_back(atoi(remainder));
        }

        if (number != "0") {
            bits.push_back(atoi(number));
        }

        num._bits = bits;
    }

    return in;
}
