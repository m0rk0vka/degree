#include "big_number.h"
//#include "fraction.h"


using namespace std;

/*Fraction<unsigned long long> fi(Fraction<unsigned long long> x, unsigned long long a, unsigned long long m) {
    return x * ((m - 1) * Pow(x, m) + (m + 1) * a) / ((m + 1) * Pow(x, m) + (m - 1) * a);
}*/

int main()
{   
    /*for (unsigned long long j = 1; j <= 16; j++) {
        Fraction<unsigned long long> x(1, 1);

        for (int i = 0; i < 3; i++) {
            x = fi(x, j, (unsigned long long) 2);
        }

        cout << "sqrt(" << j << ") = " << fixed << showpoint << std::setprecision(50)<< (double) x.GetNumerator() / x.GetDenominator() << endl; 

    }*/

    
    /*BigNumber number(LLONG_MIN);

    long sign = number.GetSign();
    vector<unsigned long> vec = number.GetBits();
    cout << "sign = " << sign << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << "part " << i << " = " << vec[i] << endl;
    }

    cout << number << endl;
    cout << "-----------"<< endl;
    cout << "MAX_LONG = " << LONG_MIN << endl;
    cout << "MAX_LONG_LONG = " << LLONG_MIN << endl;
    cout << (unsigned long) (LLONG_MIN) << endl;
    cout << (unsigned long long) (LLONG_MIN) << endl;
    cout << (unsigned int) (LLONG_MIN) << endl;
    cout << (LLONG_MAX >> 32) << endl;*/

    /*long long ans = 6917529027641081856;
    cout << (v1 & 0xffffffff) << " " << (v2 & 0xffffffff) << endl;
    cout << v1  << endl << v2 << endl;
    cout << (v1 >= (long long) INT_MAX) << endl;
    BigNumber n3(ans);
    cout << "n1:" << endl;
    vector<unsigned long> vec1 = n1.GetBits();
    for (int i = 0; i < vec1.size(); i++) {
        cout << "part " << i << " = " << vec1[i] << endl;
    }
    cout << "n2:" << endl;
    vector<unsigned long> vec2 = n2.GetBits();
    for (int i = 0; i < vec2.size(); i++) {
        cout << "part " << i << " = " << vec2[i] << endl;
    }
    cout << "ans:" << endl;
    vector<unsigned long> vec = n3.GetBits();
    for (int i = 0; i < vec.size(); i++) {
        cout << "part " << i << " = " << vec[i] << endl;
    }*/

    long long v1 = 9223372036854780 / 4;
    long long v2 = 9223372036854780 / 2;
    cout << "v1 = " << v1 << endl << "v2 = " << v2 << endl;
    BigNumber n1(v1);
    BigNumber n2(v2);
    n1 = n1 + n2;

    v1 = -(9223372036854780 / 4);
    v2 = -(9223372036854780 / 2);
    n1 = BigNumber(v1);
    n2 = BigNumber(v2);
    n1 = n1 + n2;

    v1 = -(9223372036854780 / 4);
    v2 = 9223372036854780 / 2;
    n1 = BigNumber(v1);
    n2 = BigNumber(v2);
    n1 = n1 + n2;

    v1 = 9223372036854780 / 4;
    v2 = -(9223372036854780 / 2);
    n1 = BigNumber(v1);
    n2 = BigNumber(v2);
    n1 = n1 + n2;
    return 0;
}