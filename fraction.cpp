#include "fraction.h"

BigNumber frac::gcd(BigNumber a, BigNumber b) {
    return b == 0 ? a : frac::gcd(b, a % b);
}

BigNumber frac::lcm(BigNumber a, BigNumber b) {
    return (a * b / frac::gcd(a, b)).first;
}

int frac::sgn(BigNumber val) {
    return (BigNumber(0) < val) - (val < BigNumber(0));
}


Fraction::Fraction() : m_numerator(BigNumber(0)), m_denominator(BigNumber(1)) {
}


Fraction::Fraction(BigNumber numerator, BigNumber denominator) :
    m_numerator(numerator), m_denominator(denominator) {
    assert(denominator != BigNumber(0));

    Fraction::Reduce();

    m_sign = frac::sgn(m_denominator) * frac::sgn(m_numerator);
}


void Fraction::Reduce() {
    BigNumber nod = frac::gcd(m_numerator, m_denominator);
    m_numerator /= nod;
    m_denominator /= nod;
}


BigNumber Fraction::GetNumerator() const {
    return m_numerator;
}


BigNumber Fraction::GetDenominator() const {
    return m_denominator;
}


Fraction Fraction::Reverse() {
    return Fraction(m_denominator, m_numerator);
}


Fraction Fraction::operator-() {
    return Fraction(-m_numerator, m_denominator);
}


Fraction Fraction::operator+() {
    return Fraction(m_numerator, m_denominator);
}


bool Fraction::operator!() const {
    return (m_numerator == 0);
}


Fraction& Fraction::operator += (const Fraction &f2) {
    Fraction f1 = Fraction(m_numerator, m_denominator);
    m_numerator = (f1 + f2).GetNumerator();
    m_denominator = (f1 + f2).GetDenominator();
    m_sign = frac::sgn(m_denominator) * frac::sgn(m_numerator);
    return *this;
}


Fraction& Fraction::operator -= (const Fraction &f2) {
    Fraction f1 = Fraction(m_numerator, m_denominator);
    m_numerator = (f1 - f2).GetNumerator();
    m_denominator = (f1 - f2).GetDenominator();
    m_sign = frac::sgn(m_denominator) * frac::sgn(m_numerator);
    return *this;
}


Fraction& Fraction::operator *= (const Fraction &f2) {
    Fraction f1 = Fraction(m_numerator, m_denominator);
    m_numerator = (f1 * f2).GetNumerator();
    m_denominator = (f1 * f2).GetDenominator();
    m_sign = frac::sgn(m_denominator) * frac::sgn(m_numerator);
    return *this;
}


Fraction& Fraction::operator /= (const Fraction &f2) {
    Fraction f1 = Fraction(m_numerator, m_denominator);
    m_numerator = (f1 / f2).GetNumerator();
    m_denominator = (f1 / f2).GetDenominator();
    m_sign = frac::sgn(m_denominator) * frac::sgn(m_numerator);
    return *this;
}


bool operator==(const Fraction &f1, const Fraction &f2) {
    return f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator;
}


bool operator!=(const Fraction &f1, const Fraction &f2) {
    return !(f1 == f2);
}


bool operator<=(const Fraction &f1, const Fraction &f2) {
    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber denominator = frac::lcm(d1, d2);
    BigNumber numerator1 = n1 * (denominator / d1).first;
    BigNumber numerator2 = n2 * (denominator / d2).first;
    return (numerator1 <= numerator2);
}


bool operator>=(const Fraction &f1, const Fraction &f2) {
    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber denominator = frac::lcm(d1, d2);
    BigNumber numerator1 = n1 * (denominator / d1).first;
    BigNumber numerator2 = n2 * (denominator / d2).first;
    return (numerator1 >= numerator2);
}


bool operator>(const Fraction &f1, const Fraction &f2) {
    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber denominator = frac::lcm(d1, d2);
    BigNumber numerator1 = n1 * (denominator / d1).first;
    BigNumber numerator2 = n2 * (denominator / d2).first;
    return (numerator1 > numerator2);
}


bool operator<(const Fraction &f1, const Fraction &f2) {
    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();

    BigNumber denominator = frac::lcm(d1, d2);
    BigNumber numerator1 = n1 * (denominator / d1).first;
    BigNumber numerator2 = n2 * (denominator / d2).first;
    return (numerator1 < numerator2);
}


std::ostream& operator<< (std::ostream &out, const Fraction &f)
{
    if (f.m_sign == -1) {
        out << "-";
    }

    out << f.m_numerator << "/" << f.m_denominator;

    return out;
}


std::istream& operator>> (std::istream &in, Fraction &f)
{
    char c;

    in >> f.m_numerator;
    in >> c;
    in >> f.m_denominator;

    f.Reduce();

    f.m_sign = frac::sgn(f.m_denominator) * frac::sgn(f.m_numerator);
    return in;
}



Fraction operator+(const Fraction &f1, const Fraction &f2) {
    std::cout << "hello" << std::endl;
    BigNumber n1 = f1.GetNumerator();
    BigNumber n2 = f2.GetNumerator();
    BigNumber d1 = f1.GetDenominator();
    BigNumber d2 = f2.GetDenominator();
    std::cout << "lcm there" << std::endl;
    BigNumber denominator = frac::lcm(d1, d2);
    BigNumber numerator = n1 * (denominator / d1).first + n2 * (denominator / d2).first;

    return Fraction(numerator, denominator);

}


Fraction operator+(BigNumber value, const Fraction &f) {
    return Fraction(value, 1) + f;
}


Fraction operator-(BigNumber value, const Fraction &f) {
    return Fraction(value, 1) - f;
}


Fraction operator+(const Fraction &f, BigNumber value) {
    return f + Fraction(value, 1);
}


Fraction operator-(const Fraction &f, BigNumber value) {
    return f - Fraction(value, 1);
}


Fraction operator-(const Fraction &f1, const Fraction &f2) {
    return f1 + Fraction(-f2.GetNumerator(), f2.GetDenominator());

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

    return Fraction(numerator, denominator);
}


Fraction operator*(BigNumber value, const Fraction &f) {
    return Fraction(f.GetNumerator() * value, f.GetDenominator());
}


Fraction operator*(const Fraction &f, BigNumber value) {
    return Fraction(f.GetNumerator() * value, f.GetDenominator());
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
    Fraction f = Fraction(f2.GetDenominator(), f2.GetNumerator());
    return f1 * f;
}


Fraction operator/(const Fraction &f, BigNumber value) {
    return Fraction(f.GetNumerator(), f.GetDenominator() * value);
}


Fraction operator/(BigNumber value, const Fraction &f) {
    return Fraction(f.GetDenominator() * value, f.GetNumerator());
}
