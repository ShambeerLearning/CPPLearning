#include <iostream>
#include "ComfortLibrary.cpp"
using namespace std;

class User {
public:
	std::string name;
	int age;
	std::string description;

	void whyyoumadebro() {
		Metods metods;

		metods.FixWinConsole();

		cout << "Введите имя - ";
		cin >> name;

		cout << "Введите возраст - ";
		cin >> age;

		cout << "Введите описание - ";
		cin >> description;

		metods.PauseAndClean();
		cout << "Привет, " << name << ", ТВОЯ МАТЬ СДОХЛА" << "!" << endl;
		cout << "Ты проебал лет: " << age << endl;
		cout << "И по мелочи: " << description << endl;
		metods.PauseAndClean();
	}
};

class Verify {
private:
	int Skebob(int a) {
		if (a >= 18) {
			return 0;
		}
		else if (a < 18 && a > 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
public:
	void damn() {
		Metods metods;
		metods.FixWinConsole();
		int a;
		cout << "Введите возраст для проверки - ";
		cin >> a;
		switch (Skebob(a))
		{
		case 0:
			cout << "Верификация пройдена" << endl;
			break;
		case 1:
			cout << "Верификация не пройдена" << endl;
			break;
		case -1:
			cout << "Ошибка проверки верификации" << endl;
			break;
		default:
			cout << "Ошибка ввода" << endl;
			break;
		}
		metods.PauseAndClean();
	}
};