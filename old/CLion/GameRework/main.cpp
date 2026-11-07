#include "iostream"
#include "fstream"
#include "string"

int main(){
    setlocale(LC_ALL, "ru");
    std::string msg;
    std::string readstr;
    std::ofstream write("log.txt", std::ios::app);
    std::ifstream read;
    char a;
    std::cout << "ААААА" << std::endl;
    write.open("log.txt");
    switch (a) {
        case 'y' :
            std::cout << "Введите сообщение: " <<std::endl;
            std::cin >> msg;
            write << msg;
            system("clr");
            break;
    }
    write.close();

    read.open("log.txt");
    while (getline(read,readstr)){
        std::cout << readstr << std::endl;
    }
    read.close();
    return 0;
}