#include <iostream>
#include "unistd.h"
#include <string>
#include "goyda.h"
#include "goydafunc.cpp"
using namespace std;
int main(){
    string GOYDA;
    setlocale(LC_ALL,"ru");
    while (true){
    cout << "ГОЙДА? если ГОЙДА, то напиши ГОЙДА, если нет, то напиши нит: " << endl;
    cin >> GOYDA;
    if (GOYDA == "ГОЙДА"){
        cout << endl << endl;
        goyda1();
        sleep(2);
        cout << endl << endl;
        goyda2();
        sleep(2);
        cout << endl << endl;
        goyda3();
        sleep(2);
        cout << endl << endl;
        goyda4();
        sleep(2);
        cout << endl << endl;
        goyda5();
        cout << endl << endl;
        sleep(2);
        break;
    }
    else if (GOYDA == "нит"){
        cout << endl << endl << "Да мне пофиг" << endl;
        sleep(1);
        cout << "ГОЙДААААААААААААААААА" << endl;
        break;
    }
    else {
        cout << endl << endl << "Я СКАЗАЛ ПИШИ ГОЙДА или нит" << endl;
        system("clear");
    }
    }

    return 0;
}
