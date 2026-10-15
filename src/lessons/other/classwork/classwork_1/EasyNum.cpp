#include <iostream>
using namespace std;

//Функция проверяет простой множитель начиная с наибольшего
void Rasklad(int inpp) {
//В функцию передаётся один аргумент, а именно ввод пользователя
	if (inpp % 7 == 0) {
		cout << "7" << endl;
		Rasklad(inpp / 7);
	}
	else if (inpp % 5 == 0) {
		cout << "5" << endl;
		Rasklad(inpp / 5);
	}
	else if (inpp % 3 == 0) {
		cout << "3" << endl;
		Rasklad(inpp / 3);
	}
	else if (inpp % 2 == 0) {
		cout << "2" << endl;
		Rasklad(inpp / 2);
	}
	else {
		if (inpp == 1) {
			cout << endl;
		}
		else {
			cout << inpp << endl;
			cout << endl;
		}
		
		return;
	}
}

int main() {
	int num1, num2;
	setlocale(LC_ALL, "ru");
	cout << "Введите 2 числа: " << endl;
	cin >> num1;
	cin >> num2;
	cout << endl;
	Rasklad(num1);
	Rasklad(num2);
	return 0;
}