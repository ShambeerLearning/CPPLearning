#include <iostream>

using namespace std;

int main() {
    system("chcp 65001 > nul");
	setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Привет" << endl;
    system("pause");
}