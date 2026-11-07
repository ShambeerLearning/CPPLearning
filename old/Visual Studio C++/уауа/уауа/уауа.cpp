#include <iostream>
#include "calculation.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    char oper;
    int x, y;
    cout << "Добро пожаловать в калькулятор, выберите операцию: ";
    cin >> oper;
    cout << endl << "Впишите два числа: ";
    cin >> x;
    cin >> y;
    switch (oper) {
    case '+':
        slojenie(x, y);
        break;
    case '-':
        vichitanie(x, y);
        break;
    case '*':
        cout << unmojenie(x, y);
        break;
    case '/':
        cout << delenie(x, y);
        break;
    }
    system("pause");
}