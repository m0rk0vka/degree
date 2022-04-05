#include "fraction.h"

int main() {
    Fraction a;
    Fraction b;

    /*BigNumber num1, num2;
    //std::cin >> num3;
    //std::cout << "num3 = " << num3 << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cin >> num1 >> num2;
    BigNumber gsd = frac::gcd(num1, num2);
    BigNumber temp1 = (num1 / gsd).first;
    BigNumber temp2 = temp1 * num2;
    BigNumber lsm = frac::lcm(num1, num2);*/
    
    std::cin >> a >> b;
    std::cout << a << " " << b << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    
    /*std::cout << "-" << a << " + " << b << " = " << (-a + b) << std::endl;
    std::cout << "-" << a << " - " << b << " = " << (-a - b) << std::endl;
    std::cout << "-" << a << " * " << b << " = " << (-a * b) << std::endl;
    std::cout << "-" << a << " / " << b << " = " << (-a / b) << std::endl;
    std::cout << "-" << a << " + " << "-" << b << " = " << (-a + -b) << std::endl;
    std::cout << "-" << a << " - " << "-" << b << " = " << (-a - -b) << std::endl;
    std::cout << "-" << a << " * " << "-" << b << " = " << (-a * -b) << std::endl;
    std::cout << "-" << a << " / " << "-" << b << " = " << (-a / -b) << std::endl;
    std::cout << a << " + " << "-" << b << " = " << (a + -b) << std::endl;
    std::cout << a << " - " << "-" << b << " = " << (a - -b) << std::endl;
    std::cout << a << " * " << "-" << b << " = " << (a * -b) << std::endl;
    std::cout << a << " / " << "-" << b << " = " << (a / -b) << std::endl;
    */
    return 0;
}
