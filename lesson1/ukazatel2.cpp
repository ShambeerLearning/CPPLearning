#include <iostream>

void f2 (int *a, int *b) {
    *a = 1001;
    *b = 1001;

    std::cout << *a << " " << *b << std::endl;
}

int main () {
    int big = 2002, small = 0;
    std::cout << big << " " << small << std::endl;
    f2(&big, &small);
    std::cout << big << " " << small << std::endl;
}