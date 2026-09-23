#include <iostream>
using namespace std;

int MathForm(int);

int main() {
	setlocale(LC_ALL, "ru");
	int inpp;
	cout << "Введите число - ";
	cin >> inpp;
	cout << "Результат функции - " << MathForm(inpp) << endl;
}

int MathForm(int i) {
	return 3 * i + 4;
}