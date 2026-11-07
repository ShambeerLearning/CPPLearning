#include <iostream>
#include "calculation.h"
#include "funccalc.cpp"
using namespace std;

int main(){
    setlocale(LC_ALL,"ru");
    char operation;
    short int x, y;
    cout << "Добро пожаловать в калькулятор, выберите операцию: ";
    cin >> operation;
    cout << endl << "Впишите два числа через пробел: ";
    cin >> x;
    cin >> y;
    switch(operation){
        case '+':
        cout << endl << "Результат: " << slojenie(x,y) << endl;
        break;
        case '-':
        cout << endl << "Результат: " << vichitanie(x,y) << endl;
        break;
        case '*':
        cout << endl << "Результат: " << unmojenie(x,y) << endl;
        break;
        case '/':
        cout << endl << "Результат: " << delenie(x,y) << endl;
        break;
    }
return 0;
}
