#include <iostream>

void f(int& m4, int& m3, int& m2, int& m1, int& m0, int n) {
    m0 = n % 10;
    m1 = (n / 10) % 10;
    m2 = (n / 100) % 10;
    m3 = (n / 1000) % 10;
    m4 = (n / 10000) % 10;
}

int main() {
    int n;
    std::cin >> n;
    int d4, d3, d2, d1, d0;

    f(d4, d3, d2, d1, d0, n);

    std::cout << d4 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d1 << std::endl;
    std::cout << d0 << std::endl;

    return 0;
}