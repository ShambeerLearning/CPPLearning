#include <iostream>

int main() {
    int a = 25;
    float b = 2.5;

    int *a_address = &a;
    float *b_address = &b;
    std::cout << "Var: " << a << " address: " << a_address << std::endl;
    std::cout << "Var: " << b << " address: " << b_address << std::endl << std::endl;

    a = 10;
    b = 3.1;
    std::cout << "Var: " << a << " address: " << a_address << std::endl;
    std::cout << "Var: " << b << " address: " << b_address << std::endl << std::endl;

    a = 25;
    b = 2.5;
    int *a_dynamic = new int(a);
    float *b_dynamic = new float(b);
    std::cout << "Var: " << a << " address: " << a_dynamic << std::endl;
    std::cout << "Var: " << b << " address: " << b_dynamic << std::endl << std::endl;
    delete a_dynamic;
    delete b_dynamic;

    return 0;
}