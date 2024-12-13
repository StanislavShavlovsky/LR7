#include "number_divisibility.h"
#include <cstring>
#include <iostream>

// Проверка, является ли строка целым числом
bool is_integer(const char* str) {
    if (str == nullptr || *str == '\0' || ((str[0] != '-' && !isdigit(str[0])) && str[0] != '0')) {
        return false;
    }
    
    for (size_t i = 1; str[i] != '\0'; ++i) { // O(n)
        if (!isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

// Преобразование строки в число
bool string_to_ll(const char* str, long long& result) {
    char* endptr;
    result = std::strtoll(str, &endptr, 10); // O(n)
    return *endptr == '\0';
}

// Проверка делимости числа на b с использованием побитовых операций
bool is_divisible(long long a, int b) {
    int c = (b + 1) >> 1; // O(1)

    while (a > b) { // O(log(a))
        a = (a >> 1) + ((a & 1) ? c : 0); // O(1)
    }

    return (a == b || a == 0); // O(1)
}

// Проверка делимости числа на 7
bool is_divisible_by_7(long long a) {
    return is_divisible(a, 7); // O(log(a))
}

// Проверка делимости числа на 73
bool is_divisible_by_73(long long a) {
    return is_divisible(a, 73); // O(log(a))
}

// Проверка делимости числа на 109
bool is_divisible_by_109(long long a) {
    return is_divisible(a, 109); // O(log(a))
}
