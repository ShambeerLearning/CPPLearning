#include <iostream>
#include "Windows.h"
using namespace std;
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    for (int a = 0; a < 1000; a++){
        Sleep(1000);
        cout << a << "." << " " << "Я устал босс" << endl;
    }
        return 0;
}