#include <iostream>

int main() {
    int a = 5, b = 10;
    int &as = a; // ссылка на а
    std::cout << as << std::endl;
    as = b;
    std::cout << as << std::endl;
    as++;
    std::cout << as << std::endl;
    std::cout << a << std::endl;
}