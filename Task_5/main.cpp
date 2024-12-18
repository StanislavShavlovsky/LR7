#include <iostream>
#include "solve.h"

int main() {
    std::cout << "Автор: Шавловский Станислав\n";
    std::cout << "Группа: 453502\n";
    std::cout << "Номер задания: 3\n";
    std::cout << "Вариант: 9\n";
    std::cout << "Описание: Сложение и вычитание чисел в заданной системе счисления\n\n";
    std::cout << "\nНа празднике 240 бочек вина. Вы можете отравить ровно одну.\nВведите номер бочки, которую вы хотите отравить(от 0 до 239)  ";
    int n;
    read(n); // O(n)
    std::cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
                 "Патриций решил устроить праздник и для этого приготовил 240 бочек "
                 "вина.\nОднако к нему пробрался недоброжелатель по имени , "
                 "который подсыпал яд в одну из бочек.\nНедоброжелателя тут же поймали, "
                 "дальнейшая его судьба неизвестна, но ходят слухи, что он проверяет "
                 "консольный ввод в аду в качестве наказания, однако сейчас не об этом.\nПро яд "
                 "известно, что человек, который его выпил, умирает в течение 24 часов.\nДо "
                 "праздника осталось два дня, то есть 48 часов.\nУ патриция есть пять рабов, "
                 "которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд.\nВы "
                 "близкий друг Патриция и совершенно не хотите стать одним из тех рабов, что "
                 "будут проверять вино на наличие яда.\nВы придумали способ, как за два дня с помощью пяти рабов определить отравленную бочку.\n\n"
                 "--------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    int* drank = new int[240]; // O(1)
    std::cout << "[День 1]\n\nОтложим бочки от 210 до 239 на следующий день.\n\n";
    int j = 0;
    for (int msk = 1; msk < 31; msk++) { // O(1)
        int cbits = __builtin_popcount(msk); // O(1)
        std::cout << "Напоим рабов ";
        for (int i = 0; i < 5; i++) { // O(5)
            if ((msk >> i) & 1) { // O(1)
                std::cout << i + 1 << ' '; // O(1)
            }
        }
        std::cout << "из бочек с номерами от " << j << " до " << j + (1 << (5 - cbits)) - 1 << '\n'; // O(1)

        for (int i = 0; i < (1 << (5 - cbits)); i++) { // O(2^5)
            drank[j++] = msk; // O(1)
        }
    }
    if (n >= 210) {
        std::cout << "\nНикто не умер. Значит, отравленная бочка среди бочек с номерами от 210 до 239.\n\n";
        std::cout << "[День 2]\n\n";
        for (int rab = 0; rab < 5; rab++) { // O(5)
            std::cout << "Напоим раба " << rab + 1 << " из бочек ";
            for (int i = 0; i < 30; i++) { // O(30)
                if ((i >> rab) & 1) { // O(1)
                    drank[210 + i] |= (1 << rab); // O(1)
                    std::cout << 210 + i << ' '; // O(1)
                }
            }
            std::cout << '\n';
        }
        std::cout << "\nУмерли рабы ";
        for (int i = 0; i < 5; i++) { // O(5)
            if ((drank[n] >> i) & 1) { // O(1)
                std::cout << i + 1 << ' '; // O(1)
            }
        }
        std::cout << "\n\nТакое могло произойти только в случае, если отравлена бочка " << n << '\n';
    }
    else {
        std::cout << "\nУмерли рабы ";
        int* ost = new int[5]; // O(1)
        int alive = 0;
        for (int i = 0; i < 5; i++) { // O(5)
            if ((drank[n] >> i) & 1) { // O(1)
                std::cout << i + 1 << ' '; // O(1)
            }
            else {
                ost[alive++] = i; // O(1)
            }
        }
        int* obo = new int[16]; // O(1)
        int alb = 0;
        for (int i = 0; i < 210; i++) { // O(210)
            if (drank[i] == drank[n]) { // O(1)
                obo[alb++] = i; // O(1)
            }
        }
        std::cout << "\n\nПод подозрением бочки: ";
        for (int i = 0; i < alb; i++) { // O(16)
            std::cout << obo[i] << ' '; // O(1)
        }
        std::cout << '\n';
        std::cout << "Живые рабы: ";
        for (int i = 0; i < alive; i++) { // O(5)
            std::cout << ost[i] + 1 << ' '; // O(1)
        }
        std::cout << "\n\n";
        std::cout << "[День 2]\n\n";
        for (int i = 0; i < 210; i++) { // O(210)
            drank[i] = 0; // O(1)
        }
        for (int rab = 0; rab < alive; rab++) { // O(5)
            std::cout << "Напоим раба " << ost[rab] + 1 << " из бочек ";
            for (int i = 0; i < alb; i++) { // O(16)
                if ((i >> rab) & 1) { // O(1)
                    drank[obo[i]] |= (1 << rab); // O(1)
                    std::cout << obo[i] << ' '; // O(1)
                }
            }
            std::cout << '\n';
        }
        std::cout << "\nУмерли рабы ";
        for (int i = 0; i < 5; i++) { // O(5)
            if ((drank[n] >> i) & 1) { // O(1)
                std::cout << ost[i] << ' '; // O(1)
            }
        }
        std::cout << "\n\nТакое могло произойти только в случае, если отравлена бочка " << n << '\n';
        delete[] ost;
        delete[] obo;
    }
    delete[] drank;
}
