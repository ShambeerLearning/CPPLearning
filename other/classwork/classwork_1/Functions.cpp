#include <iostream>
using namespace std;

bool isPositiv(double);

int main() {
	setlocale(LC_ALL, "ru");
	double inpp;
	cout << "Введите число - ";
	cin >> inpp;
	cout << "Результат функции - " << isPositiv(inpp) << endl;
}

bool isPositiv(double i) {
	if (i > 0) {
		return true;
	}
	else {
		return false;
	}
}