#include <iostream>
#include <Windows.h>
#include <string>
#include "gamenumberinclude.h"
#include "gamenumberfunc.cpp"
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::string gamesetting;
    int a;
    int b = 1000;

    startmenu();

    while(true){
    std::cin >> gamesetting;
    if(gamesetting == "Легкий" || gamesetting == "легкий" || gamesetting == "ЛЕГКИЙ"){
        std::cout << "В легком режиме нужно угадать число в диапазоне от 1 до 10" << std::endl;
        a = easemode();
        while(true){
        if(b == 1000){
        }
        else if(b > a){
            std::cout << "Прошлое число - " << b << ", и оно меньше" << std::endl;
        }
        else if(b < a){
            std::cout << "Прошлое число - " << b << ", и оно больше" << std::endl;
        }
        std::cout << "Введите число - ";
        std::cin >> b;
        if(b == a){
            std::cout << "ПОЗДРАВЛЯЮ С ПОБЕДОЙ" << std::endl;
            break;
        }
        else if(b < a && b > 0 && b < 11){
            std::cout << "Число больше!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else if(b > a && b > 0 && b < 11){
            std::cout << "Число меньше!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else if(b > 11 || b < 0){
            std::cout << "Число выходит из диапазона!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else{
            std::cout << "Это не число -_-" << std::endl;
            Sleep(500);
            system("cls");
        }
        }
    }
    else if(gamesetting == "Средний" || gamesetting == "средний" || gamesetting == "СРЕДНИЙ"){
        std::cout << "В среднем режиме нужно угадать число в диапазоне от 1 до 50" << std::endl;
        a = normalmode();
        while(true){
        if(b == 1000){
        }
        else if(b > a){
            std::cout << "Прошлое число - " << b << ", и оно меньше" << std::endl;
        }
        else if(b < a){
            std::cout << "Прошлое число - " << b << ", и оно больше" << std::endl;
        }
        std::cout << "Введите число - ";
        std::cin >> b;
        if(b == a){
            std::cout << "ПОЗДРАВЛЯЮ С ПОБЕДОЙ" << std::endl;
            break;
        }
        else if(b < a && b > 0 && b < 51){
            std::cout << "Число больше!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else if(b > 51 || b < 0){
            std::cout << "Число выходит из диапазона!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else{ 
            std::cout << "Это не число -_-" << std::endl;
            Sleep(500);
            system("cls");
        }
        }
    }
    else if(gamesetting == "Мастер" || gamesetting == "мастер" || gamesetting == "МАСТЕР"){
        std::cout << "В МАСТЕР режиме нужно угадать число в диапазоне от 1 до 100" << std::endl;
        a = easemode();
        while(true){
        if(b == 1000){
        }
        else if(b > a){
            std::cout << "Прошлое число - " << b << ", и оно меньше" << std::endl;
        }
        else if(b < a){
            std::cout << "Прошлое число - " << b << ", и оно больше" << std::endl;
        }
        std::cout << "Введите число - ";
        std::cin >> b;
        if(b == a){
            std::cout << "ПОЗДРАВЛЯЮ С ПОБЕДОЙ" << std::endl;
            break;
        }
        else if(b < a && b > 0 && b < 101){
            std::cout << "Число больше!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else if(b > a && b > 0 && b < 101){
            std::cout << "Число меньше!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else if(b > 101 || b < 0){
            std::cout << "Число выходит из диапазона!" << std::endl;
            Sleep(500);
            system("cls");
        }
        else{
            std::cout << "Это не число -_-" << std::endl;
            Sleep(500);
            system("cls");
        }
        }
    }
    else{
        system("cls");
        std::cout << "Такого уровня сложности не существует!" << std::endl;
        std::cout << "Введите уровень сложности ещё раз!!!(Легкий, Средний, Мастер) - ";
    }
    break;
    }
    system("pause");
}
