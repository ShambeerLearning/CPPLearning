#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include "goyda.h"
#include "goydafunc.cpp"

using namespace std;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string GOYDA;
    while (true){
    cout << "√Œ…ƒ¿!!!!, ÂÒÎË √Œ…ƒ¿, ÚÓ ÔË¯Ë √Œ…ƒ¿, ÂÒÎË ÌÂ √Œ…ƒ¿, ÔË¯Ë ÌËÚ" << endl;
    cin >> GOYDA;
    if (GOYDA == "√Œ…ƒ¿"){
        cout << endl << endl;
        goyda1();
        Sleep(1000);
        cout << endl << endl;
        goyda2();
        Sleep(1000);
        cout << endl << endl;
        goyda3();
        Sleep(1000);
        cout << endl << endl;
        goyda4();
        Sleep(1000);
        cout << endl << endl;
        goyda5();
        cout << endl << endl;
        Sleep(1000);
        break;
    }
    else if (GOYDA == "ÌËÚ"){
        cout << endl << endl << "ƒ‡ ÏÌÂ ÔÓÙË„" << endl;
        Sleep(1000);
        cout << "√Œ…ƒ¿¿¿¿¿¿¿¿¿¿¿¿¿¿!!!!!!!!!!!!" << endl;
        break;
    }
    else {
        cout << endl << endl << "¡€ÀŒ — ¿«¿ÕŒ œ»—¿“‹ √Œ…ƒ¿, ÌÛ ËÎË ÌËÚ" << endl;
        Sleep(1000);
        system("cls");
    }
    }

    system("pause");
}
