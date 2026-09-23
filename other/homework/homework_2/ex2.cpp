#include <iostream>

int fact(int);

int main() {
	setlocale(LC_ALL, "ru");
	int a;
	std::cout << "Напишите число для вычисление его факториала: ";
	std::cin >> a;
	std::cout << "Факториал числа " << a << ": " << fact(a);
	return 0;
}

int fact(int inpp) {
	int res = 1;
	for (int i = 1; i <= inpp; i++) {
		res = res * i;
	}
	return res;
}