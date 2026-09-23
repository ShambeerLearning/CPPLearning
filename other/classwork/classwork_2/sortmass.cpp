#include <iostream>
#include <cstdlib>
#include <ctime>

void vvod(int m[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
}

void vvodRand(int m[], int n) {
	for (int i = 0; i < n; i++) {
		m[i] = rand() % 100;
	}
}

void vivod(int m[], int n) {
	int f = 0;
	for (int i = 0; i < n; i++) {
		std::cout << m[i] << " ";
	}
}

void swapNum(int m1[], int m2[], int n) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (m1[i] % 2 == 0) {
			m2[j] = m1[i];
			j++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (m1[i] % 2 != 0) {
			m2[j] = m1[i];
			j++;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int mas1[30], mas2[30], n, choise;
	std::cout << "Выберите метод ввода 0 - Случайный выбор, 1 - Пользовательский ввод: ";
	std::cin >> choise;
	if (choise == 0) {
		std::cout << "Введите количество элементов - ";
		std::cin >> n;
		vvodRand(mas1, n);
		std::cout << std::endl;
		vivod(mas1, n);
		swapNum(mas1, mas2, n);
		std::cout << std::endl;
		vivod(mas2, n);
	}
	else if (choise == 1) {
		std::cout << "Введите количество элементов - ";
		std::cin >> n;
		vvod(mas1, n);
		std::cout << std::endl;
		vivod(mas1, n);
		swapNum(mas1, mas2, n);
		std::cout << std::endl;
		vivod(mas2, n);
	}
	else {
		std::cout << "Такого действия не существует" << std::endl;
	}
	return 0;
}