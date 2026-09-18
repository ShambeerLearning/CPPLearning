#include <iostream>

int square_v(int i) {
    i++;
    return i * i;
}

void square_r(int &i) {
    i = i * i;
}

void square_p(int *i) {
    *i = *i * *i;
}

int main() {
    int v = 5, s, p = 5;
    s = square_v(p);
    std::cout << s << " " << v << std::endl;
    square_r(p);
    std::cout << p << std::endl;
    square_p(&p);
    std::cout << p << std::endl;
}