#include <iostream>
#include "number_divisibility.h"

void print_author_info() {
    std::cout << "Автор: Шавловский Станислав\n";
    std::cout << "Группа: 453502\n";
    std::cout << "Номер задания: 4\n";
    std::cout << "Вариант: 9\n";
    std::cout << "Описание: Проверка делимости числа на 7, 73 и 109 с использованием побитовых операций\n\n";
}

void show_menu() {
    std::cout << "Выберите действие:\n";
    std::cout << "1. Проверить делимость на 7\n";
    std::cout << "2. Проверить делимость на 73\n";
    std::cout << "3. Проверить делимость на 109\n";
    std::cout << "4. Выход\n";
}

bool input_integer(char* num) {
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { // O(n)
        num[i++] = ch; // O(1)
    }
    num[i] = '\0'; // O(1)

    if (is_integer(num)) { // O(n)
        return true;
    } else {
        std::cerr << "Ошибка ввода. Пожалуйста, введите целое число.\n";
        return false;
    }
}

bool is_valid_choice(const char* choice_input) {
    if (choice_input == nullptr || choice_input[0] < '1' || choice_input[0] > '4') {
        return false;
    }
    for (size_t i = 1; choice_input[i] != '\0'; ++i) { // O(n)
        if (!std::isspace(static_cast<unsigned char>(choice_input[i]))) { // O(1)
            return false;
        }
    }
    return true;
}

int main() {
    print_author_info();

    while (true) {
        show_menu();
        char choice_input[10];
        std::cout << "Введите номер действия: ";

        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF && i < 9) { // O(1) * 9 (bounded)
            choice_input[i++] = ch; // O(1)
        }
        choice_input[i] = '\0'; // O(1)

        if (!is_valid_choice(choice_input)) { // O(n)
            std::cerr << "Ошибка ввода. Пожалуйста, введите число от 1 до 4.\n";
            continue;
        }

        int choice = choice_input[0] - '0'; // O(1)

        if (choice >= 1 && choice <= 3) {
            char num_str[100];
            long long num;
            std::cout << "Введите число: ";
            while (!input_integer(num_str) || !string_to_ll(num_str, num)) {} // O(n)

            bool result;
            if (choice == 1) {
                result = is_divisible_by_7(num); // O(log(a))
            } else if (choice == 2) {
                result = is_divisible_by_73(num); // O(log(a))
            } else {
                result = is_divisible_by_109(num); // O(log(a))
            }

            std::cout << "Число " << num << (result ? " делится" : " не делится") << " на " << (choice == 1 ? 7 : (choice == 2 ? 73 : 109)) << ".\n";
        } else if (choice == 4) {
            std::cout << "Выход из программы.\n";
            break;
        } else {
            std::cerr << "Неверный ввод, попробуйте еще раз.\n";
        }
    }

    return 0;
}
