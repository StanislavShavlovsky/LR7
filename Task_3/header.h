#pragma once
#include <string> 

std::string addInBase(const std::string &num1, const std::string &num2, const int base); // O(n), где n - длина чисел
std::string subtractInBase(const std::string &num1, const std::string &num2, const int base); // O(n), где n - длина чисел
bool is_integer(const std::string &num, int base); // O(n)
