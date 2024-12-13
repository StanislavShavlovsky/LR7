#ifndef NUMBER_CONVERSION_H
#define NUMBER_CONVERSION_H

#include <string>

// Преобразование из естественной формы в дополнительный код
std::string natural_to_additional(const std::string& number);

// Преобразование из дополнительного кода в прямой код
std::string additional_to_direct(const std::string& additional_code);

// Сложение двоичных чисел в дополнительном коде
std::string add_additional(const std::string& num1, const std::string& num2);

// Помощная функция для вывода промежуточных значений
void print_intermediate_values(const std::string& add_code1, const std::string& add_code2, const std::string& sum_add_code);

// Проверка, является ли строка целым числом
bool is_integer(const std::string& str);

#endif 
