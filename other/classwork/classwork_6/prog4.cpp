#include <iostream>
#include <cstring>
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    const int N = 10;
    char s[N];
    while (std::cin.getline(s, N)) {
        for (int i = 0; i < N - 1; i++) {
            s[i] = s[i + 1];
        }
        std::cout << s << std::endl;
    }
}
