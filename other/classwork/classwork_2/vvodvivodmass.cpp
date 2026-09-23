#include <iostream>

void vivod(int m[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << m[i];
	}
}

void vvod(int m[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int mas[3], n;
	std::cout << "Введите количество элементов - ";
	std::cin >> n;
	vvod(mas, n);
	vivod(mas, n);
	return 0;
}