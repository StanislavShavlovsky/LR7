#include <iostream>
#include <string>
#include <limits>
#include "number_conversion.h"

void print_author_info() {
    std::cout << "Автор: Шавловский Станислав\n";
    std::cout << "Группа: 453502\n";
    std::cout << "Номер задания: 2\n";
    std::cout << "Вариант: 9\n";
    std::cout << "Задание: Найдите сумму двоичных чисел, заданных в естественной форме.\n Сложение выполните в дополнительном коде. \n Ответ выразите в прямом коде.\n\n";
}

void show_menu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Ввести числа для сложения\n";
    std::cout << "2. Выход\n";
}

bool is_valid_choice(const std::string& choice) {
    if (choice.empty() || (choice[0] != '1' && choice[0] != '2')) {
        return false;
    }
    for (size_t i = 1; i < choice.length(); ++i) {
        if (!std::isspace(static_cast<unsigned char>(choice[i]))) {
            return false;
        }
    }
    return true;
}

bool input_integer(std::string& num) {
    std::cin >> num; // O(1)
    if (is_integer(num)) { // O(n)
        return true;
    } else {
        std::cerr << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        return false;
    }
}

int main() {
    print_author_info(); // O(1)

    while (true) {
        show_menu(); // O(1)
        std::string choice_input;
        std::cout << "Введите номер действия: ";
        std::getline(std::cin, choice_input);

        if (!is_valid_choice(choice_input)) {
            std::cerr << "Пожалуйста, введите число 1 или 2.\n";
            continue;
        }

        int choice = choice_input[0] - '0';

        if (choice == 1) {
            std::string num1, num2;
            std::cout << "Введите первое число: ";
            while (!input_integer(num1)) {} // O(n)

            std::cout << "Введите второе число: ";
            while (!input_integer(num2)) {} // O(n)

            std::string add_code1 = natural_to_additional(num1); // O(n)
            std::string add_code2 = natural_to_additional(num2); // O(n)

            std::string sum_add_code = add_additional(add_code1, add_code2); // O(n)

            // Вывод промежуточных значений
            print_intermediate_values(add_code1, add_code2, sum_add_code); // O(1)

            std::string direct_code = additional_to_direct(sum_add_code); // O(n)

            std::cout << "Сумма в прямом коде: " << direct_code << std::endl; // O(n)
        } else if (choice == 2) {
            std::cout << "Выход из программы.\n";
            break;
        } else {
            std::cerr << "Неверный ввод, попробуйте еще раз.\n";
        }
    }

    return 0;
}
