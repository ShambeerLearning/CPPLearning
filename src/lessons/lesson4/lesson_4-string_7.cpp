#include <iostream>
#include <string>
#include "windows.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::string st, w, v;

    std::cout << "Введите исходную строку st: ";
    std::getline(std::cin, st);

    std::cout << "Введите подстроку w (что ищем): ";
    std::getline(std::cin, w);

    std::cout << "Введите подстроку v (на что заменяем): ";
    std::getline(std::cin, v);

    if (w.length() > 0) {
        size_t pos = 0;
        while (pos + w.length() <= st.length()) {
            if (st.substr(pos, w.length()) == w) {
                st.replace(pos, w.length(), v);
                pos += v.length();
            } else {
                pos++;
            }
        }
    }
    else {
        std::cout << "Пустая строка" << std::endl;
        return 0;
    }

    std::cout << "Результат: " << st << "\n";

    return 0;
}