#ifndef STR_H
#define STR_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <utility>
#include <map>

namespace str {
    template <typename T>
    std::string itoa(T num) {
        std::stringstream ss;
        ss << num;

        return ss.str();
    }

    unsigned long atoi(const std::string&);
    std::string operator+(const std::string&, const char&);
    std::string operator*(const std::string&, const char&);
    std::string sum(const std::string&, const std::string&);
    std::string mult(const std::string&, const std::string&);
    std::pair<std::string, std::string> division(const std::string&, const char&);
    std::pair<std::string, std::string> division(const std::string&, const std::string&);
    bool operator<=(const std::string&, const std::string&);
    bool operator>=(const std::string&, const std::string&);
    bool operator==(const std::string&, const std::string&);
    bool operator!=(const std::string&, const std::string&);
    bool operator<(const std::string&, const std::string&);
    bool operator>(const std::string&, const std::string&);
}
#endif