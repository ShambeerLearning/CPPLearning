#include <iostream>
#include "gamenumberinclude.h"
#include <Windows.h>

int easemode(){
    int a;
    srand(time(0));
    a = 0 + rand() % (10 - 0);
    return a;
}

int normalmode(){
    int a;
    srand(time(0));
    a = 0 + rand() % (50 - 0);
    return a;
}

int mastermode(){
    int a;
    srand(time(0));
    a = 0 + rand() % (100 - 0);
    return a;
}

void startmenu(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    std::cout << "Привет игрок, добро пожаловать в игру Угадай число!" << std::endl;
    std::cout << "Ты можешь выбрать 3 уровня сложности - Легкий(от 0 до 10), Средний(от 0 до 50), Мастер(0 до 100), естетественно, чем меньше ходов, тем лучше" << std::endl;
    std::cout << "P.S. Когда начнётся игра, все подсказки пропадут" << std::endl;
    std::cout << "Чтобы выбрать уровень сложности, нужно его записать сюда - ";
}