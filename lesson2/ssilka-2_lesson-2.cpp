#include <iostream>

void zamena(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int main () {
    int a = 2;
    int b = 3;
    std::cout << a << std::endl;
    std::cout << b << std::endl << std::endl;
    zamena(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}