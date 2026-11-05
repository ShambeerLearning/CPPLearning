#include <iostream>
#include <string>
#include "windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string s;
    getline(std::cin, s);
    std::cout << s << std::endl;
    return 0;
}