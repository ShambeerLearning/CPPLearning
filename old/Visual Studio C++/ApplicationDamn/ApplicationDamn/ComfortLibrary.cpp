#include <iostream>
#include <Windows.h>

class Metods {
public:
	void PauseAndClean() {
		system("pause");
		system("cls");
	}
	void FixWinConsole() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "ru");
	}
};