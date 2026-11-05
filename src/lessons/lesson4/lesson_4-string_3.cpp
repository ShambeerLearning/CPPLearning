#include <iostream>
#include <string>
#include "windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string s;
    std::string f;
    std::string result;

    getline(std::cin, s);
    getline(std::cin, f);

    result = s + f;
    s = result;

    std::cout << result << std::endl;
    std::cout << s << std::endl;
    return 0;
}