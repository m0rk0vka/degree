#include "str.h"

using namespace str;

int main() {
    std::string pow1 = "1";
    std::string pow2 = itos((long long) UINT_MAX + 1);
    std::string x0 = "3917010175";
    std::string x1 = "536870";
    std::cout << "pow2 = " << pow2 << std::endl;
    std::cout << "mult1 = " << mult(pow1, x0) << std::endl;
    std::cout << "mult2 = " << mult(pow2, x1) << std::endl;
    std::cout << "sum = " << sum(mult(pow1, x0), mult(pow2, x1)) << std::endl;

    /*std::string str1 = "9";
    std::string str2 = "9";

    for (int i = 0; i < 15; i++) {
        str1 += str1;
        str2 += str2;
    }
    std::cout << "len1 = " << str1.length() << std::endl;
    std::cout << mult(str2, str1) << std::endl;*/

    std::string num = "1231231231";
    std::cout << "unsigned long = " << atoi(num) << std::endl;
    std::string str1 = "1035";
    char ch = '2';
    std::pair<std::string, std::string> ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    ch = '5';
    str1 = "2024";
    ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "1035";
    ch = '5';
    ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "1036";
    ch = '5';
    ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "1037";
    ch = '5';
    ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "1038";
    ch = '5';
    ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "1039";
    ch = '5';
    ans = division(str1, ch);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "125";
    std::string str2 = "25";
    ans = division(str1, str2);
    std::cout << ans.first << " " << ans.second << std::endl;
    str2 = "24";
    ans = division(str1, str2);
    std::cout << ans.first << " " << ans.second << std::endl;
    str2 = "26";
    ans = division(str1, str2);
    std::cout << ans.first << " " << ans.second << std::endl;
    str1 = "1111111";
    str2 = "2222";
    ans = division(str1, str2);
    std::cout << ans.first << " " << ans.second << std::endl;

}