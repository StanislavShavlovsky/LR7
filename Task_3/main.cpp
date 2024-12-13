#include <iostream>
#include "header.h"

void print_author_info() {
    std::cout << "Автор: Шавловский Станислав\n";
    std::cout << "Группа: 453502\n";
    std::cout << "Номер задания: 3\n";
    std::cout << "Вариант: 9\n";
    std::cout << "Описание: Сложение и вычитание чисел в заданной системе счисления\n\n";
}

void show_menu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Сложение чисел\n";
    std::cout << "2. Вычитание чисел\n";
    std::cout << "3. Выход\n";
}

bool input_base_and_numbers(int& base, std::string& num1, std::string& num2) {
    std::cout << "Введите основание системы счисления: ";
    if (!(std::cin >> base)) {
        std::cerr << "Ошибка ввода основания системы счисления. Пожалуйста, введите число.\n";
        std::cin.clear();
        std::string ignored;
        std::getline(std::cin, ignored); // Очистка входного потока
        return false;
    }
    
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    if (!is_integer(num1, base) || !is_integer(num2, base)) { // O(n)
        std::cerr << "Ошибка ввода. Пожалуйста, введите корректные числа в заданной системе счисления.\n";
        return false;
    }
    return true;
}

int main() {
    print_author_info();

    while (true) {
        show_menu();
        int choice;
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cerr << "Ошибка ввода. Пожалуйста, введите число.\n";
            std::cin.clear();
            std::string ignored;
            std::getline(std::cin, ignored); // Очистка входного потока
            continue;
        }

        if (choice == 1 || choice == 2) {
            int base;
            std::string num1, num2;
            if (!input_base_and_numbers(base, num1, num2)) { // O(n)
                continue;
            }

            std::string result;
            if (choice == 1) {
                result = addInBase(num1, num2, base); // O(n)
            } else {
                result = subtractInBase(num1, num2, base); // O(n)
            }

            std::cout << "Результат: " << result << "\n";
        } else if (choice == 3) {
            std::cout << "Выход из программы.\n";
            break;
        } else {
            std::cerr << "Неверный ввод, попробуйте еще раз.\n";
        }
    }

    return 0;
}
