// Kvad_2.cpp

#include "Kvad.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    std::cout << "Введите какое количество чисел введем: ";
    std::cin >> n;
    std::cout << view_main(n);
    system("pause");
    return 0;
}