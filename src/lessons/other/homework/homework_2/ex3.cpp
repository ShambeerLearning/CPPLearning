#include <iostream>

int piwFunc(int, int);

int main() {
	setlocale(LC_ALL, "ru");
	int inpp, piw;
	std::cout << "Введите число: ";
	std::cin >> inpp;
	std::cout << "Введите степень: ";
	std::cin >> piw;
	std::cout << "Число " << inpp << " в степени " << piw << ": " << piwFunc(inpp, piw);
	return 0;
}

int piwFunc(int inpp, int piw) {
	int res = 1;
	for (int i = 1; i <= piw; i++) {
		res = res * inpp;
	}
	return res;
}