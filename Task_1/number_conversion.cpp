#include "number_conversion.h"
#include <string>
#include <iostream>
#include <algorithm>

// Проверка, является ли строка целым числом
bool is_integer(const std::string& str) {
    if (str.empty() || ((str[0] != '-' && !isdigit(str[0])) && str[0] != '0'))
        return false;
    
    return std::all_of(str.begin() + 1, str.end(), ::isdigit); // O(n)
}

// Преобразование десятичного числа в двоичную строку
std::string decimal_to_binary(const std::string& num) {
    std::string binary;
    std::string number = num;
    while (number != "0") { // O(n^2), где n - количество цифр в числе
        int last_digit = (number.back() - '0') % 2; // O(1)
        binary.insert(binary.begin(), last_digit + '0'); // O(n)
        std::string new_number;
        int carry = 0;
        for (char digit : number) { // O(n)
            int current = carry * 10 + (digit - '0'); // O(1)
            carry = current % 2; // O(1)
            new_number.push_back(current / 2 + '0'); // O(1)
        }
        number = new_number;
        while (number.size() > 1 && number.front() == '0') { // O(n)
            number.erase(number.begin()); // O(n)
        }
    }
    return binary.empty() ? "0" : binary; // O(1)
}

// Преобразование из естественной формы в прямой код
std::string natural_to_direct(const std::string& number) {
    if (number == "0") return "0"; // O(1)

    bool is_negative = number[0] == '-'; // O(1)
    std::string abs_number_str = is_negative ? number.substr(1) : number; // O(n)

    std::string binary = decimal_to_binary(abs_number_str); // O(n^2)

    if (is_negative) {
        binary.insert(binary.begin(), '1'); // Добавляем знак отрицательного числа // O(n)
    }

    return binary; // O(1)
}
