#include "number_conversion.h"
#include <string>
#include <iostream>
#include <algorithm>

// Проверка, является ли строка целым числом
bool is_integer(const std::string& str) {
    if (str.empty() || ((str[0] != '-' && !isdigit(str[0])) && str[0] != '0'))
        return false;
    
    return std::all_of(str.begin() + 1, str.end(), ::isdigit);
}

// Преобразование десятичного числа в двоичную строку
std::string decimal_to_binary(const std::string& number) {
    std::string binary;
    std::string num = number;

    // Пока число больше 0
    while (num != "0") {
        int remainder = 0;
        std::string quotient;

        // Деление строки на 2
        for (char digit : num) {
            int value = remainder * 10 + (digit - '0');
            quotient += (value / 2) + '0';
            remainder = value % 2;
        }

        binary.insert(binary.begin(), remainder + '0');
        num = quotient;
        
        // Удаление ведущих нулей
        size_t first_non_zero = num.find_first_not_of('0');
        if (first_non_zero != std::string::npos) {
            num = num.substr(first_non_zero);
        } else {
            num = "0";
        }
    }
    
    return binary.empty() ? "0" : binary;
}

// Преобразование из естественной формы в дополнительный код
std::string natural_to_additional(const std::string& number) {
    if (number == "0") return "0";
    
    bool is_negative = number[0] == '-';
    std::string abs_number_str = is_negative ? number.substr(1) : number;
    std::string binary = decimal_to_binary(abs_number_str);

    if (is_negative) {
        // Инвертируем биты
        for (char& bit : binary) {
            bit = (bit == '0') ? '1' : '0';
        }

        // Добавляем 1 к результату
        bool carry = true;
        for (int i = binary.length() - 1; i >= 0 && carry; --i) {
            if (binary[i] == '1') {
                binary[i] = '0';
            } else {
                binary[i] = '1';
                carry = false;
            }
        }
    }

    return binary;
}

// Преобразование из дополнительного кода в прямой код
std::string additional_to_direct(const std::string& additional_code) {
    return additional_code; // Нет необходимости изменять для прямого кода
}

// Сложение двоичных чисел в дополнительном коде
std::string add_additional(const std::string& num1, const std::string& num2) {
    int max_bits = std::max(num1.length(), num2.length()) + 1;
    std::string result(max_bits, '0');
    bool carry = false;

    for (int i = max_bits - 1, j = num1.length() - 1, k = num2.length() - 1; i >= 0; --i, --j, --k) {
        int bit1 = (j >= 0) ? (num1[j] - '0') : 0;
        int bit2 = (k >= 0) ? (num2[k] - '0') : 0;
        int sum = bit1 + bit2 + carry;
        result[i] = (sum % 2) + '0';
        carry = (sum / 2);
    }

    return result;
}

// Помощная функция для вывода промежуточных значений
void print_intermediate_values(const std::string& add_code1, const std::string& add_code2, const std::string& sum_add_code) {
    std::cout << "Дополнительный код первого числа: " << add_code1 << std::endl;
    std::cout << "Дополнительный код второго числа: " << add_code2 << std::endl;
    std::cout << "Сумма в дополнительном коде: " << sum_add_code << std::endl;
}
