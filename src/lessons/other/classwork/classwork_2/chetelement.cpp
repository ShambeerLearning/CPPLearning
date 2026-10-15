#include <iostream>

void vvod(int m[], int n) {
	for (int i = 0; i < n; i++) {
		std::cin >> m[i];
	}
}

int vivod(int m[], int n) {
	int f = 0;
	for (int i = 0; i < n; i++) {
		if (m[i] % 2 == 0) {
			f = f + m[i];
		}
	}
	return f;
}

int main() {
	setlocale(LC_ALL, "ru");
	int mas[5], n;
	std::cout << "Введите количество элементов - ";
	std::cin >> n;
	vvod(mas, n);
	std::cout << std::endl << vivod(mas, n) << std::endl;
	return 0;
}