#include "big_number.h"

using namespace std;

int main()
{   
    
    /*BigNumber num1((long long) (9223372036854780 / 4));
    BigNumber num2((long long) (9223372036854780 / 2));
    std::cout << (num1 > num2) << std::endl;
    std::cout << (num1 < num2) << std::endl;
    std::cout << (num1 + num2).Print() << std::endl;
    std::cout << (num2 + num1).Print() << std::endl;
    std::cout << (num1 - num2).Print() << std::endl;
    std::cout << (num2 - num1).Print() << std::endl;   
    std::cout << "---------------------------" << std::endl;
    num1 = BigNumber((long long) (-9223372036854780 / 4));
    num2 = BigNumber((long long) (-9223372036854780 / 2));
    std::cout << (num1 > num2) << std::endl;
    std::cout << (num1 < num2) << std::endl;
    std::cout << (num1 + num2).Print() << std::endl;
    std::cout << (num2 + num1).Print() << std::endl;
    std::cout << (num1 - num2).Print() << std::endl;
    std::cout << (num2 - num1).Print() << std::endl; 
    std::cout << "---------------------------" << std::endl;
    num1 = BigNumber((long long) (-9223372036854780 / 4));
    num2 = BigNumber((long long) (9223372036854780 / 2));
    std::cout << (num1 > num2) << std::endl;
    std::cout << (num1 < num2) << std::endl;
    std::cout << (num1 + num2).Print() << std::endl;
    std::cout << (num2 + num1).Print() << std::endl;
    std::cout << (num1 - num2).Print() << std::endl;
    std::cout << (num2 - num1).Print() << std::endl; 
    std::cout << "---------------------------" << std::endl;
    num1 = BigNumber((long long) (9223372036854780 / 4));
    num2 = BigNumber((long long) (-9223372036854780 / 2));
    std::cout << (num1 > num2) << std::endl;
    std::cout << (num1 < num2) << std::endl;
    std::cout << (num1 + num2).Print() << std::endl;
    std::cout << (num2 + num1).Print() << std::endl;
    std::cout << (num1 - num2).Print() << std::endl;
    std::cout << (num2 - num1).Print() << std::endl;*/
    std::cout << "---------------------------" << std::endl;
    BigNumber num1, num2;
    unsigned long value;
    std::cin >> num1 >> num2;
    std::cout << "---------------------------" << std::endl;
    //std::cout << num1 << " " << num2 << std::endl;
    //std::cout << (num1 / num2).first << " " << (num1 / num2).second << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << num1 % num2 << std::endl;
    std::cout << num1 + num2 << std::endl;
    std::cout << num1 - num2 << std::endl;
    std::cout << (num1 / num2).first << std::endl;
    std::cout << num1 * num2 << std::endl;
    //std::cout << (num1 / num2).first << " " << (num1 / num2).second << std::endl;
    //std::cout << 3922646013 * num1 << std::endl;
    //std::cout << num2 * num1 << std::endl;
    //std::cin >> num1 >> num2;
    //std::cout << (num * ((unsigned long) 999)) << std::endl;
}