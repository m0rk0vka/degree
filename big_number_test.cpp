#include "big_number.h"

using namespace std;

int main()
{   
    std::cout << "---------------------------" << std::endl;
    BigNumber num1, num2;
    //std::cin >> num3;
    //std::cout << "num3 = " << num3 << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cin >> num1 >> num2;
    std::cout << "sum = " << num1 + num2 << std::endl;
    std::cout << ((num1 + num2) / 2).first << std::endl;
    std::cout << (num1 / num2).first << " " << (num1 / num2).second << std::endl;
    /*std::cout << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "razn = " << (num1 - num2) << std::endl;
    std::cout << "sum = " << num1 + num2 << std::endl;
    std::cout << "divis = " << (num1 / num2).first << std::endl;
    std::cout << "mult = " << num1 * num2 << std::endl;
    */
    //std::cout << (num1 / num2).first << " " << (num1 / num2).second << std::endl;
    //std::cout << 3922646013 * num1 << std::endl;
    //std::cout << num2 * num1 << std::endl;
    //std::cin >> num1 >> num2;
    //std::cout << (num * ((unsigned long) 999)) << std::endl;
}