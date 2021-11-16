#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

namespace frac {
    template <typename T>
    T gcd(T, T);

    template <typename T>
    T lcm(T, T);

    template <typename T>
    int sgn(T);
}

template <class T>
class Fraction {
private:
    T m_numerator;
    T m_denominator;
    int m_sign;
public:
    Fraction();
    Fraction(T numerator, T denominator);
 
    void Reduce();

    T GetNumerator() const;
    T GetDenominator() const;
    Fraction<T> Reverse();
    Fraction<T> operator-();
    Fraction<T> operator+();
    bool operator!() const;

    template <class T1>
    friend std::ostream& operator<<(std::ostream& out, const Fraction<T1> &f);
    template <class T1>
    friend std::istream& operator>>(std::istream& in, Fraction<T1> &f);
    template <class T1>
    friend bool operator==(const Fraction<T1> &f1, const Fraction<T1> &f2);
    template <class T1>
    friend bool operator!=(const Fraction<T1> &f1, const Fraction<T1> &f2);
    template <class T1>
    friend bool operator<=(const Fraction<T1> &f1, const Fraction<T1> &f2);
    template <class T1>
    friend bool operator>=(const Fraction<T1> &f1, const Fraction<T1> &f2);
    template <class T1>
    friend bool operator<(const Fraction<T1> &f1, const Fraction<T1> &f2);
    template <class T1>
    friend bool operator>(const Fraction<T1> &f1, const Fraction<T1> &f2);

    Fraction<T>& operator += (const Fraction &f2);

    Fraction<T>& operator -= (const Fraction &f2);

    Fraction<T>& operator *= (const Fraction &f2);

    Fraction<T>& operator /= (const Fraction &f2);
};


template <typename T>
Fraction<T> operator+(const Fraction<T> &f1, const Fraction<T> &f2);

template <typename T>
Fraction<T> operator+(T value, const Fraction<T> &f);

template <typename T>
Fraction<T> operator-(T value, const Fraction<T> &f);

template <typename T>
Fraction<T> operator+(const Fraction<T> &f, T value);

template <typename T>
Fraction<T> operator-(const Fraction<T> &f, T value);

template <typename T>
Fraction<T> operator-(const Fraction<T> &f1, const Fraction<T> &f2);

template <typename T>
Fraction<T> operator*(const Fraction<T> &f1, const Fraction<T> &f2);

template <typename T>
Fraction<T> operator*(T value, const Fraction<T> &f);

template <typename T>
Fraction<T> operator*(const Fraction<T> &f, T value);

template <typename T>
Fraction<T> Pow(const Fraction<T> &f, T value);

template <typename T>
Fraction<T> operator/(const Fraction<T> &f1, const Fraction<T> &f2);

template <typename T>
Fraction<T> operator/(const Fraction<T> &f, T value);

template <typename T>
Fraction<T> operator/(T value, const Fraction<T> &f);
