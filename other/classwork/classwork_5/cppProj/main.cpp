#include "functions.h"

int main() {
    int a;
    std::cout << "Input age - ";
    std::cin >> a;
    message(a);
    std::cin.get(); 
    return 0;
}