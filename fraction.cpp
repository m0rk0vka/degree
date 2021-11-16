#include "fraction.h"
#include <cassert>
#include <cmath>
#include <iostream>

template <typename T>
T frac::gcd(T a, T b) {
    return b == 0 ? a : frac::gcd(b, a % b);
}

template <typename T>
T frac::lcm(T a, T b) {
    return a * b / frac::lcm(a, b);
}

template <typename T>
int frac::sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template <typename T>
Fraction<T>::Fraction() : m_numerator(0), m_denominator(1) {
}

template <typename T>
Fraction<T>::Fraction(T numerator, T denominator) :
    m_numerator(numerator), m_denominator(denominator) {
    assert(denominator != 0);

    Fraction<T>::Reduce();

    m_sign = frac::sgn(m_denominator) * frac::sgn(m_numerator);
}

template <typename T>
void Fraction<T>::Reduce() {
    int nod = frac::gcd(m_numerator, m_denominator);
    m_numerator /= nod;
    m_denominator /= nod;
}

template <typename T>
T Fraction<T>::GetNumerator() const {
    return m_numerator;
}

template <typename T>
T Fraction<T>::GetDenominator() const {
    return m_denominator;
}

template <typename T>
Fraction<T> Fraction<T>::Reverse() {
    return Fraction(m_denominator, m_numerator);
}

template <typename T>
Fraction<T> Fraction<T>::operator-() {
    return Fraction(-m_numerator, m_denominator);
}

template <typename T>
Fraction<T> Fraction<T>::operator+() {
    return Fraction(m_numerator, m_denominator);
}

template <typename T>
bool Fraction<T>::operator!() const {
    return (m_numerator == 0);
}

template <typename T>
Fraction<T>& Fraction<T>::operator += (const Fraction &f2) {
    Fraction<T> f1 = Fraction<T>(m_numerator, m_denominator);
    m_numerator = (f1 + f2).GetNumerator();
    m_denominator = (f1 + f2).GetDenominator();
    return *this;
}

template <typename T>
Fraction<T>& Fraction<T>::operator -= (const Fraction &f2) {
    Fraction<T> f1 = Fraction<T>(m_numerator, m_denominator);
    m_numerator = (f1 - f2).GetNumerator();
    m_denominator = (f1 - f2).GetDenominator();
    return *this;
}

template <typename T>
Fraction<T>& Fraction<T>::operator *= (const Fraction &f2) {
    Fraction<T> f1 = Fraction<T>(m_numerator, m_denominator);
    m_numerator = (f1 * f2).GetNumerator();
    m_denominator = (f1 * f2).GetDenominator();
    return *this;
}

template <typename T>
Fraction<T>& Fraction<T>::operator /= (const Fraction &f2) {
    Fraction<T> f1 = Fraction<T>(m_numerator, m_denominator);
    m_numerator = (f1 / f2).GetNumerator();
    m_denominator = (f1 / f2).GetDenominator();
    return *this;
}

template <typename T>
bool operator==(const Fraction<T> &f1, const Fraction<T> &f2) {
    return f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator;
}

template <typename T>
bool operator!=(const Fraction<T> &f1, const Fraction<T> &f2) {
    return !(f1 == f2);
}

template <typename T>
bool operator<=(const Fraction<T> &f1, const Fraction<T> &f2) {
    T n1 = f1.GetNumerator();
    T n2 = f2.GetNumerator();
    T d1 = f1.GetDenominator();
    T d2 = f2.GetDenominator();

    T denominator = frac::lcm(d1, d2);
    T numerator1 = n1 * (denominator / d1);
    T numerator2 = n2 * (denominator / d2);
    return (numerator1 <= numerator2);
}

template <typename T>
bool operator>=(const Fraction<T> &f1, const Fraction<T> &f2) {
    T n1 = f1.GetNumerator();
    T n2 = f2.GetNumerator();
    T d1 = f1.GetDenominator();
    T d2 = f2.GetDenominator();

    T denominator = frac::lcm(d1, d2);
    T numerator1 = n1 * (denominator / d1);
    T numerator2 = n2 * (denominator / d2);
    return (numerator1 >= numerator2);
}

template <typename T>
bool operator>(const Fraction<T> &f1, const Fraction<T> &f2) {
    T n1 = f1.GetNumerator();
    T n2 = f2.GetNumerator();
    T d1 = f1.GetDenominator();
    T d2 = f2.GetDenominator();

    T denominator = frac::lcm(d1, d2);
    T numerator1 = n1 * (denominator / d1);
    T numerator2 = n2 * (denominator / d2);
    return (numerator1 > numerator2);
}

template <typename T>
bool operator<(const Fraction<T> &f1, const Fraction<T> &f2) {
    T n1 = f1.GetNumerator();
    T n2 = f2.GetNumerator();
    T d1 = f1.GetDenominator();
    T d2 = f2.GetDenominator();

    T denominator = frac::lcm(d1, d2);
    T numerator1 = n1 * (denominator / d1);
    T numerator2 = n2 * (denominator / d2);
    return (numerator1 < numerator2);
}

template <typename T>
std::ostream& operator<< (std::ostream &out, const Fraction<T> &f)
{
    if (f.m_sign == -1) {
        out << "-";
    }

    out << abs(f.m_numerator) << "/" << abs(f.m_denominator);

    return out;
}

template <typename T>
std::istream& operator>> (std::istream &in, Fraction<T> &f)
{
    char c;

    in >> f.m_numerator;
    in >> c;
    in >> f.m_denominator;

    f.Reduce();

    f.m_sign = frac::sgn(f.m_denominator) * frac::sgn(f.m_numerator);
    return in;
}


template <typename T>
Fraction<T> operator+(const Fraction<T> &f1, const Fraction<T> &f2) {
    T n1 = f1.GetNumerator();
    T n2 = f2.GetNumerator();
    T d1 = f1.GetDenominator();
    T d2 = f2.GetDenominator();

    T denominator = frac::lcm(d1, d2);
    T numerator = n1 * (denominator / d1) + n2 * (denominator / d2);

    return Fraction<T>(numerator, denominator);

}

template <typename T>
Fraction<T> operator+(T value, const Fraction<T> &f) {
    return Fraction<T>(value, 1) + f;
}

template <typename T>
Fraction<T> operator-(T value, const Fraction<T> &f) {
    return Fraction<T>(value, 1) - f;
}

template <typename T>
Fraction<T> operator+(const Fraction<T> &f, T value) {
    return f + Fraction<T>(value, 1);
}

template <typename T>
Fraction<T> operator-(const Fraction<T> &f, T value) {
    return f - Fraction<T>(value, 1);
}

template <typename T>
Fraction<T> operator-(const Fraction<T> &f1, const Fraction<T> &f2) {
    return f1 + Fraction<T>(-f2.GetNumerator(), f2.GetDenominator());

}

template <typename T>
Fraction<T> operator*(const Fraction<T> &f1, const Fraction<T> &f2) {
    T n1 = f1.GetNumerator();
    T n2 = f2.GetNumerator();
    T d1 = f1.GetDenominator();
    T d2 = f2.GetDenominator();

    T temp = frac::gcd(n1, d1);
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

    T numerator = n1 * n2;
    T denominator = d1 * d2;

    return Fraction<T>(numerator, denominator);
}

template <typename T>
Fraction<T> operator*(T value, const Fraction<T> &f) {
    return Fraction<T>(f.GetNumerator() * value, f.GetDenominator());
}

template <typename T>
Fraction<T> operator*(const Fraction<T> &f, T value) {
    return Fraction<T>(f.GetNumerator() * value, f.GetDenominator());
}

template <typename T>
Fraction<T> Pow(const Fraction<T> &f, T value) {
    Fraction<T> temp = Fraction<T>(f.GetNumerator(), f.GetDenominator());
    Fraction<T> ans = temp;
    for (T i = 0; i < value - 1; i++) {
        ans = ans * temp;
    }

    return ans;
}

template <typename T>
Fraction<T> operator/(const Fraction<T> &f1, const Fraction<T> &f2) {
    Fraction<T> f = Fraction<T>(f2.GetDenominator(), f2.GetNumerator());
    return f1 * f;
}

template <typename T>
Fraction<T> operator/(const Fraction<T> &f, T value) {
    return Fraction<T>(f.GetNumerator(), f.GetDenominator() * value);
}

template <typename T>
Fraction<T> operator/(T value, const Fraction<T> &f) {
    return Fraction<T>(f.GetDenominator() * value, f.GetNumerator());
}
