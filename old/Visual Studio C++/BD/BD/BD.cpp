#include "iostream"
#include "fstream"
#include "string"
#include "Windows.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::string msg;
    std::string readstr;
    std::ofstream write;
    std::ifstream read;
    char a;

    std::cout << "Чтобы записать данные нажмите y + Enter, если же нужно начать прочтение, то n + Enter: " << std::endl;
    std::cin >> a;

    write.open("log.txt");
    while (true) {
        if (a == 'y') {
            std::cout << "Введите сообщение: " << std::endl;
            std::cin >> msg;
            write << msg;
            std::cout << "Консоль очистится через: ";
            for(int a = 0; a < 11; a++) {
                std::cout << a << "с" << " ";
                Sleep(1000);
            }
            system("cls");
        }
        else if(a == 'n') {
            std::cout << std::endl << "Окей" << std::endl;
            std::cout << std::endl << "Хотите очистить консоль? y + Enter - да, n + Enter - нет" << std::endl;
            std::cin >> a;
            if (a == 'y') {
                system("cls");
                break;
            }
            else if (a == 'n') {
                std::cout << std::endl << "Окей" << std::endl;
                break;
            }
        }
    }
    write.close();

    std::cout << "Хотите начать прочтение файла? y + Enter - да, n + Enter - нет: " << std::endl;
    std::cin >> a;

    read.open("log.txt");
    while (true) {
        if(a == 'y') {
            while (getline(read, readstr)) {
                std::cout << readstr << std::endl;
            }
            std::cout << std::endl << "Хотите очистить консоль? y + Enter - да, n + Enter - нет" << std::endl;
            std::cin >> a;
            if (a == 'y') {
                system("cls");
                break;
            }
            else if (a == 'n') {
                std::cout << std::endl << "Окей" << std::endl;
                break;
            }
        }
    }
    read.close();
    return 0;
}