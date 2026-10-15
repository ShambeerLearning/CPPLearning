#include <iostream>

int main () {
    int matr[4][2];
    int* uk_matr;
    uk_matr = matr[0];

    bool aa = uk_matr == &matr[0][0];
    std::cout << aa << std::endl;
}