#include <iostream>
#include <string>
#include "windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string s1 = "Розовые лотосу удивительно красивые";
    std::string s2 = "можно";
    std::string s3 = "есть";
    std::string s4 = "кажется";

    std::cout << s1 << std::endl;
    return 0;
}