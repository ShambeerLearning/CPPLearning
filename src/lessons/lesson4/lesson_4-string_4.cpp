#include <iostream>
#include <string>
#include "windows.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string a;
    a = "Hello world!";
    int f = a.size();
    std::cout << f << std::endl;

    a.push_back('c');
    std::cout << a << std::endl;

    a.resize(20);
    std::cout << a << std::endl;

    a.clear();
    std::cout << a << std::endl;

    a = "AJfafqwfq";
    sort(a.begin(), a.end());
    return 0;
}