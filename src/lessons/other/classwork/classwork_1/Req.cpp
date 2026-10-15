#include <iostream>
using namespace std;

int sum = 0;
//Функция прибавляет к переменной sum последную цифру числа inpp и отбрасывает остаток inpp
int Sum(int inpp) {
	if (inpp == 0) {
		return sum;
	}
	else {
		sum = sum + (inpp % 10);
		Sum(inpp / 10);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int inpp;
	cout << "Введите число - ";
	cin >> inpp;
	cout << Sum(inpp) << endl;
	return 0;
}