#include <iostream>

int main() {
    int* ptr_a;
    float* ptr_b;

    ptr_a = new int(5);
    ptr_b = new float(1.55);
    delete ptr_a;
    delete ptr_b;

    ptr_b = new float;
    *ptr_b = 1.55;
    delete ptr_b;

    int *p;
    p = new int;
    *p = 55;
    delete p;
    p = NULL;
    *p = 8;
    std::cout << *p << std::endl;
}