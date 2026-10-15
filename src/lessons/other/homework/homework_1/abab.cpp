#include <iostream>
#include "windows.h"
using namespace std;

int RandNumber();
void Ananlize(int);
void StartGame();
int SecurityInput(int);

int scorePlayer = 0, scoreRobot = 0;

int main() {
	setlocale(LC_ALL, "ru");
	StartGame();
	system("pause");
	return 0;
}

int RandNumber() {
	srand(time(0));
	int x = rand() % (3 - 1 + 1) + 1;
	return x;
}

void Analize(int movePlayer) {
	int moveRobot = RandNumber();
	if (movePlayer == 1 && moveRobot == 1) {
		cout << "Ничья!" << endl << endl;
	}
	else if (movePlayer == 1 && moveRobot == 2) {
		cout << "Игрок выиграл!" << endl << endl;
		scorePlayer++;
	}
	else if (movePlayer == 1 && moveRobot == 3) {
		cout << "Робот выиграл!" << endl << endl;
		scoreRobot++;
	}
	else if (movePlayer == 2 && moveRobot == 1) {
		cout << "Робот выиграл!" << endl << endl;
		scoreRobot++;
	} 
	else if (movePlayer == 2 && moveRobot == 2) {
		cout << "Ничья!" << endl << endl;
	}
	else if (movePlayer == 2 && moveRobot == 3) {
		cout << "Игрок выиграл!" << endl << endl;
		scorePlayer++;
	}
	else if (movePlayer == 3 && moveRobot == 1) {
		cout << "Игрок выиграл!" << endl << endl;
		scorePlayer++;
	}
	else if (movePlayer == 3 && moveRobot == 2) {
		cout << "Робот выиграл!" << endl << endl;
		scoreRobot++;
	}
	else if (movePlayer == 3 && moveRobot == 3) {
		cout << "Ничья!" << endl << endl;
	}
}

void StartGame() {
	int inp, SecInp;
	while (true)
	{
		cout << "Игрок - " << scorePlayer << "  " << "Робот - " << scoreRobot << endl;
		cout << "Камень, ножницы, бумага!" << endl;
		cout << "1 - камень, 2 - ножницы, 3 - бумага, 10 - Выход" << endl;
		cout << "Ходите: ";
		cin >> inp;
		SecInp = SecurityInput(inp);
		if (SecInp != -1) {
			if (SecInp == 10) {
				break;
			}
			system("cls");
			Analize(inp);
			Sleep(2000);
		}
		else {
			system("cls");
			cout << "Некорректный ввод" << endl << endl;
			continue;
		}
	}
}

int SecurityInput(int inpp) {
	if (!cin.fail() && inpp == 1 || inpp == 2 || inpp == 3 || inpp == 10) {
		return inpp;
	}
	else {
		cin.clear();
		cin.ignore();
		return -1;
	}
}