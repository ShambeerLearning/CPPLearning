#include <iostream>

void zamena(float *a, float *b) {
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float a = 10.5, b = 20.1;
    std::cout << a << " " << b << std::endl;
    zamena(&a, &b);
    std::cout << a << " " << b << std::endl;
}