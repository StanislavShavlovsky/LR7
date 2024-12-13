#include "header.h"
#include <string>
#include <algorithm>
#include <cctype>

// Проверка, является ли строка допустимым числом в заданной системе счисления
bool is_integer(const std::string &num, int base) { // O(n)
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (char c : num) {
        if (digits.find(std::toupper(c)) >= base) { // O(1)
            return false;
        }
    }
    return true;
}

// Сложение чисел в заданной системе счисления
std::string addInBase(const std::string &num1, const std::string &num2, const int base) { // O(n)
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool isNegativeResult = false;
    std::string n1 = num1;
    std::string n2 = num2;

    if (num1[0] == '-' && num2[0] != '-') {
        return subtractInBase(num2, num1.substr(1), base); // O(n)
    } else if (num2[0] == '-' && num1[0] != '-') {
        return subtractInBase(num1, num2.substr(1), base); // O(n)
    } else if (num1[0] == '-' && num2[0] == '-') {
        isNegativeResult = true;
        n1 = num1.substr(1); // O(n)
        n2 = num2.substr(1); // O(n)
    }

    int maxLen = std::max(n1.size(), n2.size()); // O(1)
    n1 = std::string(maxLen - n1.size(), '0') + n1; // O(n)
    n2 = std::string(maxLen - n2.size(), '0') + n2; // O(n)

    std::string result;
    int carry = 0;

    for (int i = maxLen - 1; i >= 0; --i) { // O(n)
        int digit1 = std::find(digits.begin(), digits.end(), n1[i]) - digits.begin(); // O(1)
        int digit2 = std::find(digits.begin(), digits.end(), n2[i]) - digits.begin(); // O(1)

        int sum = digit1 + digit2 + carry; // O(1)
        carry = sum / base; // O(1)
        sum %= base; // O(1)

        result += digits[sum]; // O(1)
    }

    if (carry > 0) {
        result += digits[carry]; // O(1)
    }

    std::reverse(result.begin(), result.end()); // O(n)
    if (isNegativeResult) {
        result.insert(result.begin(), '-'); // O(n)
    }

    return result; // O(1)
}

// Вычитание чисел в заданной системе счисления
std::string subtractInBase(const std::string &num1, const std::string &num2, const int base) { // O(n)
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool isNegativeResult = false;
    std::string n1 = num1;
    std::string n2 = num2;

    if (num1[0] == '-' && num2[0] != '-') {
        return "-" + addInBase(num1.substr(1), num2, base); // O(n)
    } else if (num2[0] == '-' && num1[0] != '-') {
        return addInBase(num1, num2.substr(1), base); // O(n)
    } else if (num1[0] == '-' && num2[0] == '-') {
        return subtractInBase(num2.substr(1), num1.substr(1), base); // O(n)
    }

    int maxLen = std::max(n1.size(), n2.size()); // O(1)
    n1 = std::string(maxLen - n1.size(), '0') + n1; // O(n)
    n2 = std::string(maxLen - n2.size(), '0') + n2; // O(n)

    if (n1 < n2) {
        std::swap(n1, n2); // O(n)
        isNegativeResult = true;
    }

    std::string result;
    int borrow = 0;

    for (int i = maxLen - 1; i >= 0; --i) { // O(n)
        int digit1 = std::find(digits.begin(), digits.end(), n1[i]) - digits.begin(); // O(1)
        int digit2 = std::find(digits.begin(), digits.end(), n2[i]) - digits.begin(); // O(1)

        int diff = digit1 - digit2 - borrow; // O(1)
        if (diff < 0) {
            diff += base; // O(1)
            borrow = 1; // O(1)
        } else {
            borrow = 0; // O(1)
        }

        result += digits[diff]; // O(1)
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back(); // O(n)
    }

    std::reverse(result.begin(), result.end()); // O(n)
    if (isNegativeResult) {
        result.insert(result.begin(), '-'); // O(n)
    }

    return result; // O(1)
}
