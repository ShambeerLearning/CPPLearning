#include <iostream>
#include <cstring>
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    const int N = 10;
    char s[N];
    char b[N];
    std::cin.getline(s, N);
    std::cin.getline(b, N);
    int a = strlen(s);
    strcpy_s(b, s);
    strcat_s(s, b);
    std::cout << s << " " << b << " "  << a << std::endl;
}
