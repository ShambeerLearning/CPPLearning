#include <iostream>
#include "EasyLibraries.cpp"
using namespace std;

class Classed{
public:
    std::string name;
    int age;
    std::string description;
};

class Test{
public:
    void start(){
        Classed classed;
        EasyConfigs easyConfigs;

        easyConfigs.ConsoleTitle();
        easyConfigs.FixWinConsole();

        cout << "Введите имя - ";
        cin >> classed.name;
        cout << "Введите возраст - ";
        cin >> classed.age;
        cout << "Введите описание - ";
        cin >> classed.description;

        easyConfigs.EasyBreak();

        cout << "Ваше имя - " << classed.name << endl;
        cout << "Ваш возраст - " << classed.age << endl;
        cout << "Ваше описание - " << classed.description << endl;

        easyConfigs.EasyBreak();
    }

    void Rekursiya(){
        EasyConfigs easyConfigs;
        easyConfigs.FixWinConsole();
        cout << "Рекурсия" << endl;
        Rekursiya();
    }
};

class TrueRek {
public:
    int a;
    int Rec(){
        EasyConfigs easyConfigs;
        easyConfigs.FixWinConsole();
        if (a < 10){
            cout << "Рекурсия" << endl;
            a = a + 1;
            Rec();
            easyConfigs.EasyBreak();
            return 0;
        }
        else {
            cout << "Рекурсия" << endl;
            easyConfigs.EasyBreak();
            return 0;
        }
    }
};