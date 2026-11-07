#include <iostream>
#include "windows.h"

class EasyConfigs {
public:
    void ConsoleTitle(){
        SetConsoleTitle("Bruh");
    }
    void FixWinConsole(){
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        setlocale(LC_ALL, "ru");
    }
    void EasyBreak(){
        system("pause");
        system("cls");
    }
};