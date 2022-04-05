#include "str.h"

unsigned long str::atoi(const std::string& str) {
    assert(str <= itoa(UINT_MAX));
    //assert(str >= itoa(LONG_MIN));

    unsigned long ans = (unsigned long) (str[0] - '0');

    int i = 1;
    while (i != str.length()) {
        ans *= 10;
        ans += (unsigned long) (str[i] - '0');
        i++;
    }

    return ans;
}

std::string str::operator+(const std::string& str, const char& ch) {
    long long i = str.length() - 1;

    int remainder = (ch - '0');

    std::string ans = "";

    while (i >= 0) {
        int temp = (str[i] - '0') + remainder;
        
        ans += (temp % 10 + '0');
        remainder = int(temp / 10);

        if (remainder == 0) {
            break;
        }

        i--;
        
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

std::string str::operator*(const std::string& str, const char& ch) {
    if (ch == '0'){
        return "0";
    }

    long long i = str.length() - 1;

    int remainder = 0;
    int factor = (ch - '0');

    std::string ans = "";

    while (i >= 0) {
        int temp = (str[i] - '0') * factor + remainder;
        
        ans += (temp % 10 + '0');
        remainder = int(temp / 10);
        i--;
    }

    if (remainder != 0) {
        ans += (remainder + '0');
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

std::string str::sum(const std::string& str1, const std::string& str2) {
    long long i = str1.length() - 1, j = str2.length() - 1;

    std::string ans = "";
    int remainder = 0;
    int temp = 0;
    while ((i >= 0) && (j >= 0)) {
        temp = (str1[i] - '0') + (str2[j] - '0') + remainder;
        ans += (temp % 10 + '0');
        remainder = int(temp / 10);

        i--;
        j--;
    }

    
    while (i >= 0) {
        temp = (str1[i] - '0') + remainder;
        ans += (temp % 10 + '0');
        remainder = int(temp / 10);

        i--;
    }

    while (j >= 0) {
        temp = (str2[j] - '0') + remainder;
        ans += (temp % 10 + '0');
        remainder = int(temp / 10);

        j--;
    }

    if (remainder != 0) {
        ans += (remainder + '0');
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

std::string str::mult(const std::string& str1, const std::string& str2) {
    long long i = str2.length() - 1;

    std::string ans = str1 * str2[i];
    std::string temp = "0";
    i--;

    while (i >= 0) {
        ans = str::sum(ans, str1 * str2[i] + temp);
        temp += "0";
        i--;
    }

    return ans;
}

bool str::operator<=(const std::string& str1, const std::string& str2) {
    return (str1 == str2) || (str1 < str2);
};

bool str::operator>=(const std::string& str1, const std::string& str2) {
    return (str1 == str2) || (str1 > str2);
};

bool str::operator==(const std::string& str1, const std::string& str2) {
    if (str1.length() > str2.length()) {
        return false;
    }
    if (str1.length() < str2.length()) {
        return false;
    }
    unsigned long long i = 0;

    while(i != str1.length()) {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }

    return true;
};

bool str::operator!=(const std::string& str1, const std::string& str2) {
    return !(str1 == str2);
};

bool str::operator<(const std::string& str1, const std::string& str2) {
    if (str1.length() > str2.length()) {
        return false;
    }
    if (str1.length() < str2.length()) {
        return true;
    }

    unsigned long long i = 0;

    while(i != str1.length()) {
        if (str1[i] < str2[i]) {
            return true;
        }
        if (str1[i] > str2[i])
        {
            return false;
        }

        i++;
    }

    return false;
};

bool str::operator>(const std::string& str1, const std::string& str2) {
    if (str1.length() > str2.length()) {
        return true;
    }
    if (str1.length() < str2.length()) {
        return false;
    }

    unsigned long long i = 0;

    while(i != str1.length()) {
        if (str1[i] > str2[i]) {
            return true;
        }
        if (str1[i] < str2[i])
        {
            return false;
        }

        i++;
    }

    return false;
};

std::pair<std::string, std::string> str::division(const std::string& str, const char& ch) {
    assert(ch != '0');

    if (ch == '1') {
        return std::pair<std::string, std::string>(str, "0");
    }

    if (ch == '2') {
        if (str.length() <= 2) {
            return std::pair<std::string, std::string> (itoa(atoi(str) / 2), itoa(atoi(str) % 2));
        }

        std::map<std::string, std::string> answers = {};
        for(int i = 1; i <= 9; i++) {
            answers[itoa(i * 10)] = itoa(i * 5);
        }

        std::string zeros = "";
        for (unsigned long long i = 0LL; i < str.length() - 2; i++) {
            zeros += "0";
        }

        unsigned long long i = 0ULL;

        std::string ans = "";
        std::string zeroStr = "0";

        while (i != str.length() - 1) {
            if (str[i] != '0') {
                std::string temp = answers[str[i] + zeroStr] + zeros;
                ans = sum(ans, temp);
            }

            if (zeros.length() >= 1) {
                zeros = zeros.substr(1);
            }

            i++;
        }

        int last = (str[str.length() - 1] - '0');
        ans = sum(ans, itoa(last / 2));
        std::string remainder = itoa(last % 2);
        
        return std::pair<std::string, std::string> (ans, remainder);
    }

    std::string left = "1";
    std::string right = str;
        
    while (sum(left, "1") != right) {
        std::string middle = (division(sum(left, right), '2')).first;

        if (middle * ch < str) {
            left = middle;
        } else {
            if (middle * ch > str) {
                right = middle;
            } else {
                return std::pair<std::string, std::string>(middle, "0");
            }
        }
    }

    std::string ans = left;
    std::string remainder = "0";

    while (sum(ans * ch, remainder) != str) {
        remainder = sum(remainder, "1");
    }

    return std::pair<std::string, std::string>(ans, remainder);
    
};

std::pair<std::string, std::string> str::division(const std::string& divisible, const std::string& divider) {
    assert(divider != "0");

    std::string left = "1";
    std::string right = divisible;

    if (divisible < divider) {
        return std::pair<std::string, std::string> ("0", divisible);
    }
    
    while (sum(left, "1") != right) {
        std::string middle = division(sum(left, right),'2').first;

        if (mult(middle, divider) < divisible) {
            left = middle;
        } else {
            if (mult(middle, divider) > divisible) {
                right = middle;
            } else {
                return std::pair<std::string, std::string>(middle, "0");
            }
        }
    }

    std::string ans = left;
    std::string remainder = "0";

    left = "0";
    right = divider;

    while (sum(mult(ans, divider), remainder) != divisible) {
        remainder = division(sum(left, right), '2').first;

        if (sum(mult(ans, divider), remainder) < divisible) {
            left = remainder;
        } else {
            if (sum(mult(ans, divider), remainder) > divisible) {
                right = remainder;
            } else {
                break;
            }
        }
    }

    return std::pair<std::string, std::string>(ans, remainder);
};
