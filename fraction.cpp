#include "fraction.h"

BigNumber frac::gcd(BigNumber a, BigNumber b) {
    return b == 0 ? a : frac::gcd(b, a % b);
}

BigNumber frac::lcm(BigNumber a, BigNumber b) {
    return (a / frac::gcd(a, b)).first * b;
}

int frac::sgn(BigNumber val) {
    return (BigNumber(0) < val) - (val < BigNumber(0));
}

BigNumber frac::abs(BigNumber num) {
    if (num < BigNumber(0)) {
        return -num;
    }

    return num;
}

Fraction::Fraction() : _sign(1), _numerator(BigNumber(0)), _denominator(BigNumber(1)) {
}


Fraction::Fraction(BigNumber numerator, BigNumber denominator) {
    using namespace frac;

    assert(denominator != BigNumber(0));

    _sign = sgn(denominator) * sgn(numerator);

    _numerator = abs(numerator);
    _denominator = abs(denominator);

    Fraction::Reduce();
}

Fraction::Fraction(int sign, BigNumber numerator, BigNumber denominator) {
    assert(denominator != BigNumber(0));

    _sign = sign;
    _numerator = numerator;
    _denominator = denominator;

    Fraction::Reduce();
}

void Fraction::Reduce() {
    BigNumber nod = frac::gcd(_numerator, _denominator);
    _numerator /= nod;
    _denominator /= nod;
}


BigNumber Fraction::GetNumerator() const {
    return _numerator;
}


BigNumber Fraction::GetDenominator() const {
    return _denominator;
}

int Fraction::GetSign() const {
    return _sign;
}

Fraction Fraction::Reverse() {
    return Fraction(_sign, _denominator, _numerator);
}


Fraction Fraction::operator-() {
    return Fraction(-_sign, _numerator, _denominator);
}


Fraction Fraction::operator+() {
    return Fraction(_sign, _numerator, _denominator);
}


bool Fraction::operator!() const {
    return (_numerator == BigNumber(0));
}


Fraction& Fraction::operator += (const Fraction &f2) {
    Fraction f1 = Fraction(_sign, _numerator, _denominator);
    _numerator = (f1 + f2).GetNumerator();
    _denominator = (f1 + f2).GetDenominator();
    _sign = (f1 + f2).GetSign();
    return *this;
}


Fraction& Fraction::operator -= (const Fraction &f2) {
    Fraction f1 = Fraction(_sign, _numerator, _denominator);
    _numerator = (f1 - f2).GetNumerator();
    _denominator = (f1 - f2).GetDenominator();
    _sign = (f1 - f2).GetSign();
    return *this;
}


Fraction& Fraction::operator *= (const Fraction &f2) {
    Fraction f1 = Fraction(_sign, _numerator, _denominator);
    _numerator = (f1 * f2).GetNumerator();
    _denominator = (f1 * f2).GetDenominator();
    _sign = (f1 * f2).GetSign();
    return *this;
}


Fraction& Fraction::operator /= (const Fraction &f2) {
    Fraction f1 = Fraction(_sign, _numerator, _denominator);
    _numerator = (f1 / f2).GetNumerator();
    _denominator = (f1 / f2).GetDenominator();
    _sign = (f1 / f2).GetSign();
    return *this;
}


bool operator==(const Fraction &f1, const Fraction &f2) {
    return f1._numerator == f2._numerator && f1._denominator == f2._denominator && f1._sign == f2._sign;
}


bool operator!=(const Fraction &f1, const Fraction &f2) {
    return !(f1 == f2);
}


bool operator<=(const Fraction &f1, const Fraction &f2) {
    return (f1 < f2) || (f1 == f2);
}


bool operator>=(const Fraction &f1, const Fraction &f2) {
    return (f1 > f2) || (f1 == f2);
}


bool operator>(const Fraction &f1, const Fraction &f2) {
    int sign1 = f1.GetSign();
    int sign2 = f2.GetSign();

    if (sign1 < sign2) {
        return false;
    }

    if (sign1 > sign2) {
        return true;
    }

    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber denominator = frac::lcm(d1, d2);
    
    BigNumber numerator1 = n1 * (denominator / d1).first;
    BigNumber numerator2 = n2 * (denominator / d2).first;
    
    if (sign1 == -1) {
        return (numerator1 < numerator2);
    }

    return numerator1 > numerator2;
}


bool operator<(const Fraction &f1, const Fraction &f2) {
    int sign1 = f1.GetSign();
    int sign2 = f2.GetSign();

    if (sign1 < sign2) {
        return true;
    }

    if (sign1 > sign2) {
        return false;
    }

    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber denominator = frac::lcm(d1, d2);
    BigNumber numerator1 = n1 * (denominator / d1).first;
    BigNumber numerator2 = n2 * (denominator / d2).first;
    
    if (sign1 == 1) {
        return (numerator1 < numerator2);
    }

    return numerator1 > numerator2;
}


std::ostream& operator<<(std::ostream &out, const Fraction &f) {
    if (f._sign == -1) {
        out << "-";
    }

    out << f._numerator << "/" << f._denominator;

    return out;
}


std::istream& operator>>(std::istream &in, Fraction &f) {   
    using namespace frac;

    char c;

    in >> f._numerator;
    in.get(c);
    in >> f._denominator;

    f._sign = sgn(f._denominator) * sgn(f._numerator);

    f._numerator = abs(f._numerator);
    f._denominator = abs(f._denominator);

    f.Reduce();
    
    return in;
}



Fraction operator+(const Fraction &f1, const Fraction &f2) {
    int sign1 = f1.GetSign();
    int sign2 = f2.GetSign();
    if (sign1 == 1 && sign2 == 1) {
        BigNumber n1 = f1.GetNumerator();
        BigNumber n2 = f2.GetNumerator();
        BigNumber d1 = f1.GetDenominator();
        BigNumber d2 = f2.GetDenominator();
        
        BigNumber denominator = frac::lcm(d1, d2);

        BigNumber numerator = n1 * (denominator / d1).first + n2 * (denominator / d2).first;

        return Fraction(1, numerator, denominator);
    }

    if (sign1 == 1 && sign2 == -1) {
        return f1 - Fraction(1, f2.GetNumerator(), f2.GetDenominator());
    }

    if (sign1 == -1 && sign2 == 1) {
        return f2 - Fraction(1, f1.GetNumerator(), f1.GetDenominator());
    }

    return -(Fraction(1, f1.GetNumerator(), f1.GetDenominator()) + Fraction(1, f2.GetNumerator(), f2.GetDenominator()));
}


Fraction operator+(BigNumber value, const Fraction &f) {
    return Fraction(value, BigNumber(1)) + f;
}


Fraction operator-(BigNumber value, const Fraction &f) {
    return Fraction(value, BigNumber(1)) - f;
}


Fraction operator+(const Fraction &f, BigNumber value) {
    return f + Fraction(value, BigNumber(1));
}


Fraction operator-(const Fraction &f, BigNumber value) {
    return f - Fraction(value, BigNumber(1));
}


Fraction operator-(const Fraction &f1, const Fraction &f2) {
    int sign1 = f1.GetSign();
    int sign2 = f2.GetSign();

    if (sign1 == 1 && sign2 == 1) {
        BigNumber n1 = f1.GetNumerator();
        BigNumber n2 = f2.GetNumerator();
        BigNumber d1 = f1.GetDenominator();
        BigNumber d2 = f2.GetDenominator();
        BigNumber denominator = frac::lcm(d1, d2);
        BigNumber numerator = n1 * (denominator / d1).first - n2 * (denominator / d2).first;
        
        int sign = 1;

        if (numerator < BigNumber(0)) {
            sign *= -1;
            numerator = -numerator;
        }

        return Fraction(sign, numerator, denominator);
    }

    if (sign1 == 1 && sign2 == -1) {
        return f1 + Fraction(1, f2.GetNumerator(), f2.GetDenominator());
    }

    if (sign1 == -1 && sign2 == 1) {
        return -(Fraction(1, f1.GetNumerator(), f1.GetDenominator()) + f2);
    }

    return Fraction(1, f2.GetNumerator(), f2.GetDenominator()) - Fraction(1, f1.GetNumerator(), f1.GetDenominator());
}


Fraction operator*(const Fraction &f1, const Fraction &f2) {
    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber temp = frac::gcd(n1, d1);
    n1 /= temp;
    d1 /= temp;

    temp = frac::gcd(n1, d2);
    n1 /= temp;
    d2 /= temp;

    temp = frac::gcd(n2, d1);
    n2 /= temp;
    d1 /= temp;

    temp = frac::gcd(n2, d2);
    n2 /= temp;
    d2 /= temp;

    BigNumber numerator = n1 * n2;
    BigNumber denominator = d1 * d2;

    int sign1 = f1.GetSign();
    int sign2 = f2.GetSign();
    return Fraction(sign1 * sign2, numerator, denominator);
}


Fraction operator*(BigNumber value, const Fraction &f) {
    return Fraction(value, BigNumber(1)) * f;
}


Fraction operator*(const Fraction &f, BigNumber value) {
    return value * f;
}


Fraction Pow(const Fraction &f, BigNumber value) {
    Fraction temp = Fraction(f.GetNumerator(), f.GetDenominator());
    Fraction ans = temp;
    for (BigNumber i = 0; i < value - 1; i += 1) {
        ans *= temp;
    }

    return ans;
}


Fraction operator/(const Fraction &f1, const Fraction &f2) {
    Fraction f = Fraction(f2.GetSign(), f2.GetDenominator(), f2.GetNumerator());
    return f1 * f;
}


Fraction operator/(const Fraction &f, BigNumber value) {
    return Fraction(BigNumber(1), value) * f;
}


Fraction operator/(BigNumber value, const Fraction &f) {
    return Fraction(value, BigNumber(1)) / f;
}
