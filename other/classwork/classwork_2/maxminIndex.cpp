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
	std::cout << "Массив: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << m[i] << " ";
	}
}

int minNum(int m[], int n) {
	int min = m[0];
	for (int i = 0; i < n; i++) {
		if (min > m[i]) 
			min = m[i];
		}
	return min;
	}

int indexMax(int m[], int n) {
	int max = m[0], indexMax = 0;
	for (int i = 0; i < n; i++) {
		if (max < m[i]) {
			indexMax = i;
			max = m[i];
		}
	}
	return indexMax;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int mas1[30], n, choise;
	std::cout << "Выберите метод ввода 0 - Случайный выбор, 1 - Пользовательский ввод: ";
	std::cin >> choise;
	if (choise == 0) {
		std::cout << "Введите количество элементов - ";
		std::cin >> n;
		vvodRand(mas1, n);
		std::cout << std::endl;
		vivod(mas1, n);
		std::cout << std::endl << "Индекс максимального числа - " << indexMax(mas1, n) << std::endl;
		std::cout << std::endl << "Минимальное число - " << minNum(mas1, n) << std::endl;
	}
	else if (choise == 1) {
		std::cout << "Введите количество элементов - ";
		std::cin >> n;
		vvod(mas1, n);
		std::cout << std::endl;
		vivod(mas1, n);
		std::cout << std::endl;
		std::cout << std::endl << "Индекс максимального числа - " << indexMax(mas1, n) << std::endl;
		std::cout << std::endl << "Минимальное число - " << minNum(mas1, n) << std::endl;
	}
	else {
		std::cout << "Такого действия не существует" << std::endl;
	}
	return 0;
}