#include <iostream>
#include <string>
#include <limits>
#include "number_conversion.h"

void print_author_info() {
    std::cout << "Автор: Шавловский Станислав\n";
    std::cout << "Группа: 453502\n";
    std::cout << "Номер задания: 1\n";
    std::cout << "Вариант: 9\n";
    std::cout << "Описание: Перевести число из естественной формы в прямой код\n\n";
}

void show_menu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Ввести число для преобразования в прямой код\n";
    std::cout << "2. Выход\n";
}

bool is_valid_choice(const std::string& choice) {
    if (choice.empty() || (choice[0] != '1' && choice[0] != '2')) {
        return false;
    }
    for (size_t i = 1; i < choice.length(); ++i) {
        if (!std::isspace(choice[i])) {
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
            std::cerr << "Ошибка ввода. Пожалуйста, введите число 1 или 2.\n";
            continue;
        }

        int choice = choice_input[0] - '0';

        if (choice == 1) {
            std::string num;
            std::cout << "Введите число: ";
            while (!input_integer(num)) {} // O(n)

            std::string direct_code = natural_to_direct(num); // O(n)

            std::cout << "Прямой код: " << direct_code << std::endl;
        } else if (choice == 2) {
            std::cout << "Выход из программы.\n";
            break;
        } else {
            std::cerr << "Неверный ввод, попробуйте еще раз.\n";
        }
    }

    return 0;
}
